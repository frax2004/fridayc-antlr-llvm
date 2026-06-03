// #include <TypeCheckerVisitor.hpp>
// #include <OperationNotSupportedError.hpp>

// namespace friday::inline api::inline pipeline {
//   auto TypeChecker::visitCallExpression(FridayParser::CallExpressionContext *ctx) -> any {
//     Console::debug("CallExpressionContext: {}"_f.format(ctx->getText()));

//     constexpr auto toType = (Type*(*)(any const&))&any_cast<Type*>;

//     auto candidate = any_cast<Type*>(this->visit(ctx->func));
//     if(candidate == this->ERROR or not rtti::instanceOf<FunctionType>(candidate)) {
//       this->errorAt(
//         ctx->getStart(),
//         "The underlined expression '{}' of type '{}' is not a function and cannot be called."_f.format(
//           candidate->getName(),
//           ctx->func->getText()
//         )
//       );
//       return this->ERROR;
//     }

//     auto funcType = (FunctionType*)candidate;

//     auto argsTypes = ctx->args
//     | views::transform(this->byVisiting<FridayParser::ExpressionContext>())
//     | views::transform(toType)
//     | ranges::to<vector>();

//     bool ok = true;
//     if(funcType->getParametersCount() != argsTypes.size()) {
//       ok = false;
//       this->errorAt(
//         ctx->RIGHT_PAREN()->getSymbol(),
//         "In function call '{}' of type '{}' : the function expects {} arguments but {} where given."_f.format(
//           ctx->func->getText(),
//           funcType->getName(),
//           funcType->getParametersCount(),
//           argsTypes.size()
//         )
//       );
//     }

//     for(u64 i = 0; i < min(argsTypes.size(), funcType->getParametersCount()); i++) {
//       Type* T = argsTypes[i];

//       if(T != funcType->getParameterType(i)) {
//         ok = false;
//         this->errorAt(
//           ctx->args[i]->getStart(),
//           "In function call '{}' of type '{}' : argument type mismatch. Expected '{}', got '{}'"_f.format(
//             ctx->getText(),
//             funcType->getName(),
//             funcType->getParameterType(i)->getName(),
//             T->getName()
//           )
//         );
//       }
//     }
  
//     return (Type*)(ok ? funcType->getReturnType() : this->ERROR);
//   }

//   auto TypeChecker::visitIdentifierExpression(FridayParser::IdentifierExpressionContext *ctx) -> any {
//     Console::debug("IdentifierExpressionContext: {}"_f.format(ctx->getText()));
    
//     auto isVariableOrFunction = [](ISymbol* symbol) -> bool {
//       return rtti::instanceOf<Variable>(symbol) or rtti::instanceOf<Function>(symbol);
//     };
    
//     string id = ctx->IDENTIFIER()->getText();
//     ISymbol* symbol = this->topScope()->lookUpIf(id, isVariableOrFunction);

//     bool ok = true;
//     if(symbol == nullptr) {
//       ok = false;

//       auto toSuggestion = [](string const& message) {
//         return format(" Did you mean '{}'?", message);
//       };

//       string suggestion = this->topScope()->mostSimilar(id, isVariableOrFunction, 3)
//       .transform(toSuggestion)
//       .value_or("");

//       this->errorAt(
//         ctx->getStart(),
//         "There is no variable or function named '{}' in the current scope.{}"_f.format(
//           id,
//           suggestion
//         )
//       );
//     }

//     return (Type*)(ok ? ((TypedEntity*)symbol)->getType() : this->ERROR);
//   }

//   auto TypeChecker::visitCharLiteralExpression(FridayParser::CharLiteralExpressionContext *ctx) -> any {
//     Console::debug("CharLiteralExpressionContext: {}"_f.format(ctx->getText()));
//     return (Type*)this->BYTE;
//   }

//   auto TypeChecker::visitstringLiteralExpression(FridayParser::stringLiteralExpressionContext *ctx) -> any {
//     Console::debug("stringLiteralExpressionContext: {}"_f.format(ctx->getText()));
//     return (Type*)PointerType::get(*this->BYTE, 1);
//   }

//   auto TypeChecker::visitBoolLiteralExpression(FridayParser::BoolLiteralExpressionContext *ctx) -> any {
//     Console::debug("BoolLiteralExpressionContext: {}"_f.format(ctx->getText()));
//     return (Type*)this->BOOL;
//   }

//   auto TypeChecker::visitFloatLiteralExpression(FridayParser::FloatLiteralExpressionContext *ctx) -> any {
//     Console::debug("FloatLiteralExpressionContext: {}"_f.format(ctx->getText()));
//     return (Type*)this->FLOAT;
//   }

//   auto TypeChecker::visitIntLiteralExpression(FridayParser::IntLiteralExpressionContext *ctx) -> any {
//     Console::debug("IntLiteralExpressionContext: {}"_f.format(ctx->getText()));
//     return (Type*)this->INT;
//   }

//   auto TypeChecker::visitGroupingExpression(FridayParser::GroupingExpressionContext *ctx) -> any {
//     Console::debug("GroupingExpressionContext: {}"_f.format(ctx->getText()));
//     return (Type*)any_cast<Type*>(this->visit(ctx->expression()));
//   }

//   auto TypeChecker::visitSubscriptExpression(FridayParser::SubscriptExpressionContext *ctx) -> any {
//     Console::debug("SubscriptExpressionContext: {}"_f.format(ctx->getText()));

//     Type* arrayType = any_cast<Type*>(this->visit(ctx->array));
//     Type* indexType = any_cast<Type*>(this->visit(ctx->index));

//     ArrayType* asArrayType = rtti::cast<ArrayType>(arrayType);

//     bool ok = true;
//     if(
//       asArrayType == nullptr
//       or (Type*)asArrayType == this->ERROR  
//       or asArrayType->getElementType() == this->VOID
//     ) {
//       ok = false;
//       this->errorAt(
//         ctx->array->getStart(),
//         "Array expression '{}' of type '{}' is not a valid array or pointer that can be dereferenced."_f.format(
//           ctx->array->getText(),
//           arrayType->getName()
//         )
//       );
//     }

//     if(indexType != this->INT) {
//       ok = false;
//       this->errorAt(
//         ctx->index->getStart(),
//         "Array subcript index expression '{}' of type '{}' is not convertible to int. Implicit cast are not permitted, if this is the problem, try adding an explicit cast."_f.format(
//           ctx->index->getText(),
//           indexType->getName()
//         )
//       );
//     }

//     return (Type*)(ok ? asArrayType->getElementType() : this->ERROR);
//   }

//   auto TypeChecker::visitBinaryExpression(FridayParser::BinaryExpressionContext *ctx) -> any {
//     Console::debug("BinaryExpressionContext: {}"_f.format(ctx->getText()));

//     Type* lhsType = any_cast<Type*>(this->visit(ctx->left));
//     Type* rhsType = any_cast<Type*>(this->visit(ctx->right));

//     auto operatorName = "operator{}({}, {})"_f.format(
//       ctx->binaryOperator->getText(),
//       lhsType->getName(),
//       rhsType->getName()
//     );

//     string suggestion = "";

//     if(rtti::instanceOf<Struct>(lhsType) and rtti::instanceOf<Struct>(rhsType)) {
//       if(lhsType == rhsType) {
//         if(const Function* binaryOperator = lhsType->as<Struct>()->getMethod(binaryOperatorName)) {
//           return (Type*)binaryOperator->getType()->as<const FunctionType>()->getReturnType();
//         }
//       } else suggestion = " Implicit casts are not permitted so, if this is a cast problem, try adding an explicit cast.";
//     }

//     this->errorAt(
//       ctx->binaryOperator,
//       "No matching function for call to '{}' with operands of types '{}' and '{}'.{}"_f.format(
//         binaryOperatorName,
//         lhsType->getName(),
//         rhsType->getName(),
//         suggestion
//       )
//     );

//     return this->ERROR;
//   }

//   auto TypeChecker::visitUnaryPrefixExpression(FridayParser::UnaryPrefixExpressionContext *ctx) -> any {
//     Console::debug("UnaryPrefixExpressionContext: {}"_f.format(ctx->getText()));

//     Type* type = any_cast<Type*>(this->visit(ctx->expression()));
//     u64 oper = ctx->unaryOperator->getType();
//     string unaryOperatorName = Type::getUnaryPrefixExpressionOperatorName(oper, type);


//     if(Struct* asStruct = type->as<Struct>()) {
//       if(const Function* unaryOperator = asStruct->getMethod(unaryOperatorName)) {
//         return (Type*)unaryOperator->getType()->as<const FunctionType>()->getReturnType();
//       }
//     }

//     this->errorAt(
//       ctx->unaryOperator,
//       "No matching function for call to '{}' with operand of type '{}'"_f.format(
//         unaryOperatorName,
//         type->getName()
//       )
//     );
    
//     return this->ERROR;
//   }

//   auto TypeChecker::visitSimpleType(FridayParser::SimpleTypeContext *ctx) -> any {
//     Console::debug("SimpleTypeContext: {}"_f.format(ctx->getText()));

//     auto token = ctx->IDENTIFIER()->getSymbol();
//     auto id = token->getText();
//     auto isType = (bool(*)(ISymbol*))&rtti::instanceOf<Struct>;

//     Type* T = rtti::cast<Struct>(this->topScope()->lookUpIf(id, isType));

//     if(T == nullptr or T == this->ERROR) {
//       auto toSuggestion = [](string const& message) {
//         return format(" Did you mean '{}'?", message);
//       };

//       string suggestion = this
//       ->topScope()
//       ->mostSimilar(id, isType, 3)
//       .transform(toSuggestion)
//       .value_or("");

//       this->errorAt(token, "There is no type named '{}' in the current scope.{}"_f.format(
//         id,
//         suggestion
//       ));
//     }

//     return (Type*)T;
//   }

//   auto TypeChecker::visitFunctionType(FridayParser::FunctionTypeContext *ctx) -> any {
//     Console::debug("FunctionTypeContext: {}"_f.format(ctx->getText()));

//     constexpr auto toType = (Type*(*)(any const&))&any_cast<Type*>;

//     Type* retType = any_cast<Type*>(this->visit(ctx->returnType));
//     vector<Type*> paramsTypes = ctx->paramsTypes
//     | views::transform(this->byVisiting<FridayParser::TypeContext>())
//     | views::transform(toType)
//     | ranges::to<vector>();


//     bool ok = true;
//     for(u64 i = 0; auto T : paramsTypes) {
//       if(T == this->ERROR) {
//         ok = false;
//         this->errorAt(
//           ctx->paramsTypes[i]->getStart(),
//           "The function-type '{}' has an invalid parameter-type '{}' for the {}-th parameter"_f.format(
//             ctx->getText(),
//             ctx->paramsTypes[i]->getText(),
//             i+1
//           )
//         );
//       }
//       i++;
//     }

//     if(retType == this->ERROR) {
//       ok = false;
//       this->errorAt(
//         ctx->returnType->getStart(),
//         "The function-type '{}' has an invalid return-type '{}'"_f.format(
//           ctx->getText(),
//           ctx->returnType->getText()
//         )
//       );
//     }

//     return (Type*)(ok ? FunctionType::get(*retType, move(paramsTypes)) : this->ERROR);
//   }

//   auto TypeChecker::visitPointerType(FridayParser::PointerTypeContext *ctx) -> any {
//     Console::debug("PointerTypeTypeContext: {}"_f.format(ctx->getText()));
    
//     Type* type = any_cast<Type*>(this->visit(ctx->pointedType));
//     u64 dimensions = ctx->STAR().size();

//     if(type == this->ERROR) {
//       this->errorAt(
//         ctx->pointedType->getStart(), 
//         "Cannot form {}-th dimensional pointer '{}' from non-existent pointed-type '{}'"_f.format(
//           dimensions,
//           ctx->getText(),
//           ctx->pointedType->getText()
//         )
//       );
//     } else type = PointerType::get(*type, dimensions);

//     return type;
//   }

// }