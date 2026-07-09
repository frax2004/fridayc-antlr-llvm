#include <TypeSolverVisitor.hpp>
#include <ErrorType.hpp>
#include <PointerType.hpp>
#include <ArrayType.hpp>
#include <OperationNotSupportedError.hpp>

namespace friday::inline api::inline pipeline {

  TypeSolverVisitor::TypeSolverVisitor(CompilationContext& ctx)
    : StaticAnalyzer { ctx }
  {}
  
  auto TypeSolverVisitor::beginUnit(TranslationUnit& unit) -> void {
    // this->M_dependencyGraph = {};
  }

  auto TypeSolverVisitor::endUnit(TranslationUnit& _) -> void {
    auto reportDependency = [this](tuple<Struct*, Struct*> pair) {
      auto toToken = [this](Struct* item) { return this->M_properties.at(item); };

      auto [strct, field] = pair;
      auto typeToken = toToken(strct), fieldToken = toToken(field);

      this->errorAt(
        fieldToken->getStart(),
        "Note: struct \"{}\" depends from struct \"{}\""_f.format(
          strct->getQualifiedId(),
          field->getQualifiedId()
        )
      );
    };
    
    auto reportCycle = [&](vector<Struct*> const& cycle) {
      this->errorAt(
        this->M_properties[cycle[0]]->getStart(),
        "In declaration of struct \"{}\", detected cyclic struct dependency."_f.format(
          cycle[0]->getQualifiedId()
        )
      );
      ranges::for_each(cycle | views::pairwise, reportDependency);
    };

    ranges::for_each(this->M_dependencyGraph.getCycles(), reportCycle);
  }

  auto TypeSolverVisitor::visitStructStatement(FridayParser::StructStatementContext* ctx) -> any {
    auto isStruct = static_cast<bool(*)(ISymbol*)>(&rtti::instanceOf<Struct>);

    string structName = ctx->structName->getText();
    
    if(ctx->structDecl.expired()) throw OperationNotSupportedError("Internal error.");
    rc<Struct> asStruct = ctx->structDecl.lock();

    auto fieldsNames = ctx->fieldsNames | views::transform(&ant::Token::getText);
    auto fieldsTypes = ctx->fieldsTypes | views::transform([this](auto typeCtx) { return this->toType(typeCtx); });

    bool ok = true;
    for(u64 i = 0; auto [fieldName, fieldType] : views::zip(fieldsNames, fieldsTypes)) {
      if(asStruct->isDefined(fieldName)) {
        this->errorAt(
          ctx->fieldsNames[i],
          "In definition of struct \"{}\", redeclaration of entity \"{}\" already defined in the current scope."_f.format(
            structName,
            fieldName
          )
        );
        ok = false;
      } else if(fieldType == nullptr or fieldType == ErrorType::get()) {
        this->errorAt(
          ctx->fieldsTypes[i]->getStart(),
          "In definition of struct \"{}\", field named \"{}\" as an invalid error type \"{}\""_f.format(
            structName,
            fieldName,
            ctx->fieldsTypes[i]->getText()
          )
        );
        ok = false;
      } else {
        rc<Variable> field = make_shared<Variable>(*asStruct, fieldName, *fieldType);
        asStruct->define(field);
        if(auto fieldAsStruct = rtti::cast<Struct>(fieldType)) {
          this->M_dependencyGraph.addEdge(asStruct.get(), fieldAsStruct);
          this->M_properties.insert(make_pair(asStruct.get(), ctx));
          this->M_properties.insert(make_pair(fieldAsStruct, ctx->fieldsTypes[i]));
        }
      }

      i++;
    }

    for(auto method : ctx->methods) this->visit(method); // to register all types

    return {};
  }

  auto TypeSolverVisitor::visitSimpleType(FridayParser::SimpleTypeContext *ctx) -> any {

    auto isStruct = static_cast<bool(*)(ISymbol*)>(&rtti::instanceOf<Struct>);

    TranslationUnit* unit = this->getCurrentUnit();
    ant::Token* token = ctx->IDENTIFIER()->getSymbol();
    string id = token->getText();

    weak<ISymbol> candidate = unit->lookUpIf(id, isStruct, {});

    if(not candidate.expired()) {
      ctx->typeId = rtti::cast<Type>(candidate.lock().get());
    } else {
      auto toSuggestion = [](string const& message) {
        return format(" Did you mean '{}'?", message);
      };

      this->errorAt(token, "There is no type named '{}' in the current scope."_f.format(id));
    }

    return {};
  }

  auto TypeSolverVisitor::visitFunctionType(FridayParser::FunctionTypeContext *ctx) -> any {

    auto isErrorType = [](Type* type) {
      return type == ErrorType::get();
    };

    Type* retType = any_cast<Type*>(this->visit(ctx->returnType));
    vector<Type*> paramsTypes = ctx->paramsTypes
    | views::transform([this](auto typeCtx) { return this->toType(typeCtx); })
    | ranges::to<vector>();

    bool ok = true;
    for(auto [i, T] : paramsTypes | views::filter(isErrorType) | views::enumerate) {
      ok = false;
      this->errorAt(
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
      this->errorAt(
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

    Type* type = this->toType(ctx->pointedType);
    u64 dimensions = ctx->STAR().size();

    if(type == ErrorType::get()) {
      this->errorAt(
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

  auto TypeSolverVisitor::visitArrayType(FridayParser::ArrayTypeContext* ctx) -> any {

    Type* type = this->toType(ctx->elementType);
    u64 length = ctx->LEFT_SQUARE().size();

    if(type == ErrorType::get()) {
      this->errorAt(
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
