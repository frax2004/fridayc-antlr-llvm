// #include <TypeChecker.hpp>
// #include <OperationNotSupportedError.hpp>

// namespace friday::inline api::inline typechecker {

//   TypeChecker::TypeChecker(CompilationContext& ctx) noexcept
//     : M_ctx { &ctx }
//   {}
  
//   auto TypeChecker::check() -> Vector<SemanticError> {
//     Namespace GLOBAL{};

//     this->INT = Type::getIntType(GLOBAL, this->M_ctx->mod->getContext());
//     this->FLOAT = Type::getFloatType(GLOBAL, this->M_ctx->mod->getContext());
//     this->BYTE = Type::getByteType(GLOBAL, this->M_ctx->mod->getContext());
//     this->BOOL = Type::getBoolType(GLOBAL, this->M_ctx->mod->getContext());
//     this->VOID = Type::getVoidType(GLOBAL, this->M_ctx->mod->getContext());
//     this->ERROR = Type::getErrorType();

//     GLOBAL.define(rtti::cast<Struct>(this->INT));
//     GLOBAL.define(rtti::cast<Struct>(this->FLOAT));
//     GLOBAL.define(rtti::cast<Struct>(this->BYTE));
//     GLOBAL.define(rtti::cast<Struct>(this->BOOL));
//     GLOBAL.define(rtti::cast<Struct>(this->VOID));

//     this->pushScope(GLOBAL);
//     auto result = this->visit(this->M_ctx->ast);
//     this->popScope();
    
//     return this->M_errors;
//   }

//   auto TypeChecker::pushScope(ISymbolTable& scope) -> void {
//     this->M_symbolTables.push(&scope);
//   }

//   auto TypeChecker::popScope() -> ISymbolTable* {
//     ISymbolTable* first = this->topScope();
//     this->M_symbolTables.pop();
//     return first;
//   }

//   auto TypeChecker::topScope() -> ISymbolTable* {
//     return this->M_symbolTables.top();
//   }

//   auto TypeChecker::errorAt(ant::Token* token, String message) -> void {
//     this->M_errors.push_back(
//       SemanticError{
//         SourceLocation {
//           this->M_ctx->path,
//           token->getLine(),
//           token->getCharPositionInLine()+1
//         },
//         std::move(message) 
//       }
//     );
//   }

// }