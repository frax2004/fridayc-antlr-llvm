#include <TypeSolverVisitor.hpp>
#include <ErrorType.hpp>
#include <PointerType.hpp>
#include <ArrayType.hpp>

namespace friday::inline api::inline pipeline {
  TypeSolverVisitor::TypeSolverVisitor(CompilationContext& ctx)
    : context { &ctx }
  {}

  auto TypeSolverVisitor::solve() -> TypeSolverVisitor& {

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


    for(auto& unit : this->context->units) {
      this->setCurrentUnit(unit.get());
      this->M_dependencyGraph = {};

      this->visit(unit->ast);

      ranges::for_each(this->M_dependencyGraph.getCycles(), reportCycle);

      this->setCurrentUnit(nullptr);
    }



    return *this;
  }

  auto TypeSolverVisitor::visitStructStatement(FridayParser::StructStatementContext* ctx) -> any {
    auto isStruct = (bool(*)(ISymbol*))&rtti::instanceOf<Struct>;

    TranslationUnit* unit = this->getCurrentUnit();
    string structName = ctx->structName->getText();

    Struct* asStruct = rtti::cast<Struct>(unit->lookUpIf(structName, isStruct));
    if(asStruct == nullptr) throw runtime_error("Internal error.");

    auto toType = [this](FridayParser::TypeContext* type) { return any_cast<Type*>(this->visit(type)); };
    auto fieldsNames = ctx->fieldsNames | views::transform(ant::Token::getText);
    auto fieldsTypes = ctx->fieldsTypes | views::transform(toType);

    bool ok = true;
    for(u64 i = 0; auto [field, T] : views::zip(fieldsNames, fieldsTypes)) {
      if(asStruct->isDefined(field)) {
        this->errorAt(
          ctx->fieldsNames[i],
          "In definition of struct \"{}\", redeclaration of entity \"{}\" already defined in the current scope."_f.format(
            structName,
            field
          )
        );
        ok = false;
      } else if(T == nullptr or T == ErrorType::get()) {
        this->errorAt(
          ctx->fieldsTypes[i]->getStart(),
          "In definition of struct \"{}\", field named \"{}\" as an invalid error type \"{}\""_f.format(
            structName,
            field,
            ctx->fieldsTypes[i]->getText()
          )
        );
        ok = false;
      } else {
        asStruct->define(new Variable(*asStruct, field, *T));
        if(auto fieldAsStruct = rtti::cast<Struct>(T)) {
          this->M_dependencyGraph.addEdge(asStruct, fieldAsStruct);
          this->M_properties.insert(make_pair(asStruct, ctx));
          this->M_properties.insert(make_pair(fieldAsStruct, ctx->fieldsTypes[i]));
        }
      }

      i++;
    }

    return (Type*)(ok ? rtti::cast<Type>(asStruct) : ErrorType::get());
  }

  
  auto TypeSolverVisitor::visitSimpleType(FridayParser::SimpleTypeContext *ctx) -> any {
    auto isStruct = (bool(*)(ISymbol*))&rtti::instanceOf<Struct>;

    TranslationUnit* unit = this->getCurrentUnit();
    ant::Token* token = ctx->IDENTIFIER()->getSymbol();
    string id = token->getText();

    Type* T = ErrorType::get();

    if(auto asStruct = rtti::cast<Struct>(unit->lookUpIf(id, isStruct))) {
      T = rtti::cast<Type>(asStruct);
    } else {
      auto toSuggestion = [](string const& message) {
        return format(" Did you mean '{}'?", message);
      };
  
      this->errorAt(token, "There is no type named '{}' in the current scope."_f.format(id));
    }

    return (Type*)T;
  }

  auto TypeSolverVisitor::visitFunctionType(FridayParser::FunctionTypeContext *ctx) -> any {
    
    auto toType = [this](FridayParser::TypeContext* type) { return any_cast<Type*>(this->visit(type)); };

    Type* retType = any_cast<Type*>(this->visit(ctx->returnType));
    vector<Type*> paramsTypes = ctx->paramsTypes
    | views::transform(toType)
    | ranges::to<vector>();

    bool ok = true;
    for(u64 i = 0; auto T : paramsTypes) {
      if(T == ErrorType::get()) {
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
      i++;
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

    return (Type*)(ok ? FunctionType::get(*retType, move(paramsTypes)) : ErrorType::get());
  }

  auto TypeSolverVisitor::visitPointerType(FridayParser::PointerTypeContext *ctx) -> any {
    
    Type* type = any_cast<Type*>(this->visit(ctx->pointedType));
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
    } else type = PointerType::get(*type, dimensions);

    return (Type*)type;
  }

  auto TypeSolverVisitor::visitArrayType(FridayParser::ArrayTypeContext* ctx) -> any {
    Type* type = any_cast<Type*>(this->visit(ctx->elementType));
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
    } else type = ArrayType::get(*type, length);

    return (Type*)type;
  }

}
