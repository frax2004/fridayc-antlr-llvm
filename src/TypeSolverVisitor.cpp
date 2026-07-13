#include <TypeSolverVisitor.hpp>
#include <ErrorType.hpp>
#include <PointerType.hpp>
#include <ArrayType.hpp>
#include <OperationNotSupportedError.hpp>

namespace friday::inline api::inline pipeline {

  TypeSolverVisitor::TypeSolverVisitor(CompilationContext& ctx)
    : StaticAnalyzer { ctx }
  {}
  
  auto TypeSolverVisitor::on_unit_begin(TranslationUnit& _) -> void {
    (void)_;
    // this->M_dependencyGraph = {};
  }

  auto TypeSolverVisitor::on_unit_end(TranslationUnit& _) -> void {
    (void)_;

    auto reportDependency = [this](tuple<Pointer<Struct>, Pointer<Struct>> pair) {

      auto [strct, field] = pair;
      auto fieldToken = this->M_properties.at(field);

      this->error_at(
        fieldToken->getStart(),
        "Note: struct \"{}\" depends from struct \"{}\""_f.format(
          strct->get_qualified_id(),
          field->get_qualified_id()
        )
      );
    };
    
    auto reportCycle = [&](vector<Pointer<Struct>> const& cycle) {
      this->error_at(
        this->M_properties[cycle[0]]->getStart(),
        "In declaration of struct \"{}\", detected cyclic struct dependency."_f.format(
          cycle[0]->get_qualified_id()
        )
      );
      ranges::for_each(cycle | views::pairwise, reportDependency);
    };

    ranges::for_each(this->M_dependencyGraph.detect_cycles(), reportCycle);
  }

  auto TypeSolverVisitor::visitStructStatement(FridayParser::StructStatementContext *ctx) -> any {
    this->visitChildren(ctx);
    string structName = ctx->structName->getText();
    
    if(ctx->structDecl.expired()) throw OperationNotSupportedError("Internal error.");
    rc<Struct> asStruct = ctx->structDecl.lock();

    auto fields = views::zip(
      ctx->fieldsNames | views::transform(&ant::Token::getText),
      ctx->fieldsTypes | views::transform(&FridayParser::TypeContext::typeId)
    );

    for(u64 i = 0; auto [fieldName, fieldType] : fields) {
      if(asStruct->is_defined(fieldName, &Variable::is_variable)) {
        this->error_at(
          ctx->fieldsNames[i],
          "In definition of struct \"{}\", redeclaration of field \"{}\"."_f.format(
            structName,
            fieldName
          )
        );
      } else if(ErrorType::is_error_type(fieldType)) {
        this->error_at(
          ctx->fieldsTypes[i]->getStart(),
          "In definition of struct \"{}\", field named \"{}\" as an invalid error type \"{}\""_f.format(
            structName,
            fieldName,
            ctx->fieldsTypes[i]->getText()
          )
        );
      } else {
        rc<Variable> field = make_shared<Variable>(*asStruct, fieldName, *fieldType);
        asStruct->define(field);
        if(auto fieldAsStruct = rtti::cast<Struct>(fieldType)) {
          this->M_dependencyGraph.add_edge(asStruct.get(), fieldAsStruct);
          this->M_properties.insert(make_pair(asStruct.get(), ctx));
          this->M_properties.insert(make_pair(fieldAsStruct, ctx->fieldsTypes[i]));
        }
      }

      i++;
    }

    return {};
  }

  auto TypeSolverVisitor::visitSimpleType(FridayParser::SimpleTypeContext *ctx) -> any {

    auto is_struct = static_cast<bool(*)(Pointer<ISymbol>)>(&rtti::instance_of<Struct>);

    Pointer<TranslationUnit> unit = this->get_current_unit();
    Pointer<ant::Token> token = ctx->IDENTIFIER()->getSymbol();
    string id = token->getText();

    weak<ISymbol> candidate = unit->look_up_if(id, is_struct, {});

    if(not candidate.expired()) {
      ctx->typeId = rtti::cast<Type>(candidate.lock().get());
    } else {
      // auto toSuggestion = [](string const& message) {
      //   return format(" Did you mean '{}'?", message);
      // };

      this->error_at(token, "There is no type named '{}' in the current scope."_f.format(id));
    }

    return {};
  }

  auto TypeSolverVisitor::visitFunctionType(FridayParser::FunctionTypeContext *ctx) -> any {

    auto isErrorType = [](Pointer<Type> type) {
      return type == ErrorType::get();
    };

    Pointer<Type> retType = any_cast<Pointer<Type>>(this->visit(ctx->returnType));
    vector<Pointer<Type>> paramsTypes = ctx->paramsTypes
    | views::transform([this](auto typeCtx) { return this->to_type(typeCtx); })
    | ranges::to<vector>();

    bool ok = true;
    for(auto [i, T] : paramsTypes | views::filter(isErrorType) | views::enumerate) {
      ok = false;
      this->error_at(
        ctx->paramsTypes[i]->getStart(),
        "The function-type '{}' has an invalid parameter-type '{}' for the {}-th parameter"_f.format(
          ctx->getText(),
          ctx->paramsTypes[i]->getText(),
          i+1
        )
      );
    }


    if(retType == ErrorType::get()) {
      ok = false;
      this->error_at(
        ctx->returnType->getStart(),
        "The function-type '{}' has an invalid return-type '{}'"_f.format(
          ctx->getText(),
          ctx->returnType->getText()
        )
      );
    } 
    
    if(ok) {
      ctx->typeId = FunctionType::get(*retType, move(paramsTypes));
    }

    return {};
  }

  auto TypeSolverVisitor::visitPointerType(FridayParser::PointerTypeContext *ctx) -> any {

    Pointer<Type> type = this->to_type(ctx->pointedType);
    u64 dimensions = ctx->STAR().size();

    if(type == ErrorType::get()) {
      this->error_at(
        ctx->pointedType->getStart(), 
        "Cannot form {}-th dimensional pointer '{}' from non-existent pointed-type '{}'"_f.format(
          dimensions,
          ctx->getText(),
          ctx->pointedType->getText()
        )
      );
    } else {
      type = PointerType::get(*type, dimensions);
      ctx->typeId = type;
    }

    return {};
  }

  auto TypeSolverVisitor::visitArrayType(FridayParser::ArrayTypeContext *ctx) -> any {

    Pointer<Type> type = this->to_type(ctx->elementType);
    u64 length = ctx->LEFT_SQUARE().size();

    if(type == ErrorType::get()) {
      this->error_at(
        ctx->elementType->getStart(), 
        "Cannot form {}-th dimensional array type '{}' from non-existent element-type '{}'"_f.format(
          length,
          ctx->getText(),
          ctx->elementType->getText()
        )
      );
    } else {
      type = ArrayType::get(*type, length);
      ctx->typeId = type;
    }

    return {};
  }

}
