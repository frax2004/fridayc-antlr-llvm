#include <fridayc.hpp>


namespace friday::inline api {

  TypeSolverVisitor::TypeSolverVisitor(CompilationContext& ctx)
    : StaticAnalyzer { ctx }
  {}
  
  auto TypeSolverVisitor::on_unit_begin(TranslationUnit& _) -> void {
    (void)_;
    // this->M_dependencyGraph = {};
  }

  auto TypeSolverVisitor::on_unit_end(TranslationUnit& _) -> void {
    (void)_;

    auto reportDependency = [this](tuple<void*, void*> pair) {

      auto strct = static_cast<Struct*>(get<0>(pair));
      auto field = static_cast<Struct*>(get<1>(pair));

      auto fieldToken = this->M_properties.at(field);

      this->error_at(
        fieldToken,
        fieldToken->getStart(),
        format(
          "Note: struct \"{}\" depends from struct \"{}\"",
          strct->get_qualified_id(),
          field->get_qualified_id()
        )
      );
    };
    
    auto reportCycle = [&](vector<void*> const& cycle) {
      Struct* first = static_cast<Struct*>(cycle[0]);
      this->error_at(
        this->M_properties[first],
        this->M_properties[first]->getStart(),
        format(
          "In declaration of struct \"{}\", detected cyclic struct dependency.",
          first->get_qualified_id()
        )
      );

      ranges::for_each(cycle | views::pairwise, reportDependency);
    };

    ranges::for_each(this->M_dependencyGraph.detect_cycles(), reportCycle);
  }

  auto TypeSolverVisitor::visitStructStatement(FridayParser::StructStatementContext *ctx) -> any {
    this->visitChildren(ctx);
    string structName = ctx->structName->getText();

    if($(ctx).struct_ == nullptr) {
      throw InvalidArgumentError{};
    }

    Struct* asStruct = $(ctx).struct_;

    auto fields = views::zip(
      ctx->fieldsNames | views::transform(&ant::Token::getText),
      ctx->fieldsTypes | views::transform([](FridayParser::TypeContext* typeCtx) { return $(typeCtx).type; })
    );

    for(u64 i = 0; auto [fieldName, fieldType] : fields) {
      if(asStruct->is_defined(fieldName, &Variable::is_variable)) {
        this->error_at(
          ctx,
          ctx->fieldsNames[i],
          format(
            "In definition of struct \"{}\", redeclaration of field \"{}\".",
            structName,
            fieldName
          )
        );
      } else if(ErrorType::is_error_type(fieldType)) {
        this->error_at(
          ctx,
          ctx->fieldsTypes[i]->getStart(),
          format(
            "In definition of struct \"{}\", field named \"{}\" as an invalid error type \"{}\"",
            structName,
            fieldName,
            ctx->fieldsTypes[i]->getText()
          )
        );
      } else {
        Variable* field = Variable::Factory::create(*asStruct, fieldName, *fieldType);
        asStruct->define(field);
        if(auto fieldAsStruct = dynamic_cast<Struct*>(fieldType)) {
          this->M_dependencyGraph.add_edge(
            static_cast<void*>(asStruct), 
            static_cast<void*>(fieldAsStruct)
          );
          this->M_properties.insert(make_pair(asStruct, ctx));
          this->M_properties.insert(make_pair(fieldAsStruct, ctx->fieldsTypes[i]));
        }
      }

      i++;
    }

    return {};
  }

  auto TypeSolverVisitor::visitSimpleType(FridayParser::SimpleTypeContext *ctx) -> any {

    TranslationUnit* unit = this->get_current_unit();
    ant::Token* token = ctx->IDENTIFIER()->getSymbol();
    string id = token->getText();

    ISymbol* candidate = unit->look_up_if(
      id, 
      dynamic_cast<ISymbolTable*>(unit->get_owned_namespace()), 
      &Struct::is_struct, 
      {}
    );

    if(candidate != nullptr) {
      $(ctx).type = dynamic_cast<Type*>(candidate);
    } else {
      this->error_at(ctx, token, format("There is no type named '{}' in the current scope.", id));
    }

    return {};
  }

  auto TypeSolverVisitor::visitFunctionType(FridayParser::FunctionTypeContext *ctx) -> any {
    this->visitChildren(ctx);

    Type* retType = $(ctx->returnType).type;
    vector<Type*> paramsTypes = ctx->paramsTypes
    | views::transform([](auto typeCtx) { return $(typeCtx).type; })
    | ranges::to<vector>();

    bool ok = true;
    for(auto [i, T] : paramsTypes | views::filter(&ErrorType::is_error_type) | views::enumerate) {
      ok = false;
      this->error_at(
        ctx,
        ctx->paramsTypes[i]->getStart(),
        format(
          "The function-type '{}' has an invalid parameter-type '{}' for the {}-th parameter",
          ctx->getText(),
          ctx->paramsTypes[i]->getText(),
          i+1
        )
      );
    }


    if(ErrorType::is_error_type(retType)) {
      ok = false;
      this->error_at(
        ctx,
        ctx->returnType->getStart(),
        format(
          "The function-type '{}' has an invalid return-type '{}'",
          ctx->getText(),
          ctx->returnType->getText()
        )
      );
    } 
    
    if(ok) {
      $(ctx).type = FunctionType::get(*retType, move(paramsTypes));
    }

    return {};
  }

  auto TypeSolverVisitor::visitPointerType(FridayParser::PointerTypeContext *ctx) -> any {
    this->visitChildren(ctx);

    Type* type = $(ctx->pointedType).type;
    u64 dimensions = ctx->STAR().size();

    if(type == ErrorType::get()) {
      this->error_at(
        ctx,
        ctx->pointedType->getStart(), 
        format(
          "Cannot form {}-th dimensional pointer '{}' from non-existent pointed-type '{}'",
          dimensions,
          ctx->getText(),
          ctx->pointedType->getText()
        )
      );
    } else {
      type = PointerType::get(*type, dimensions);
      $(ctx).type = type;
    }

    return {};
  }

  auto TypeSolverVisitor::visitArrayType(FridayParser::ArrayTypeContext *ctx) -> any {
    this->visitChildren(ctx);
    
    Type* type = $(ctx->elementType).type;
    if(ErrorType::is_error_type(type)) {
      this->error_at(
        ctx,
        ctx->elementType->getStart(), 
        format(
          "Cannot form array type '{}' from non-existent element-type '{}'",
          ctx->getText(),
          ctx->elementType->getText()
        )
      );
    } else $(ctx).type = ArrayType::get(*type);

    return {};
  }

}
