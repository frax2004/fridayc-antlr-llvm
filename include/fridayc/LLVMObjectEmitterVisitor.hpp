#pragma once
#include "StaticAnalyzer.hpp"


namespace friday::inline api {

  struct TranslationUnit;
  struct ISymbol;

  // will emit the llvm object files
  struct LLVMObjectEmitterVisitor final : StaticAnalyzer {
  private:
    stack<FridayParser::StatementContext*>* M_deferred = nullptr;
    unordered_map<ISymbol*, llvm::Value*> M_values { };

  public:
    LLVMObjectEmitterVisitor(CompilationContext& ctx);
    ~LLVMObjectEmitterVisitor() override = default;

    auto visitFreeFunctionStatement(FridayParser::FreeFunctionStatementContext *ctx) -> any override;
    auto visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext *ctx) -> any override;
    auto visitStructStatement(FridayParser::StructStatementContext *ctx) -> any override;
    auto visitPrintStatement(FridayParser::PrintStatementContext *ctx) -> any override;
    auto visitReturnStatement(FridayParser::ReturnStatementContext *ctx) -> any override;
    auto visitExpressionStatement(FridayParser::ExpressionStatementContext *ctx) -> any override;
    auto visitIfStatement(FridayParser::IfStatementContext *ctx) -> any override;
    auto visitForStatement(FridayParser::ForStatementContext *ctx) -> any override;
    auto visitWhileStatement(FridayParser::WhileStatementContext *ctx) -> any override;
    auto visitDeclarationStatement(FridayParser::DeclarationStatementContext *ctx) -> any override;
    auto visitDeferStatement(FridayParser::DeferStatementContext *ctx) -> any override;
    auto visitScopeStatement(FridayParser::ScopeStatementContext *ctx) -> any override;
    auto visitSyntacticalScope(FridayParser::SyntacticalScopeContext *ctx) -> any override;
    auto visitBasicBlock(FridayParser::BasicBlockContext *ctx) -> any override;
    auto visitTrailingBlock(FridayParser::TrailingBlockContext *ctx) -> any override;

    auto visitArrayLiteralExpression(FridayParser::ArrayLiteralExpressionContext *ctx) -> any override;
    auto visitIdentifierExpression(FridayParser::IdentifierExpressionContext *ctx) -> any override;

    auto visitExplicitCastExpression(FridayParser::ExplicitCastExpressionContext *ctx) -> any override;
    auto visitBinaryExpression(FridayParser::BinaryExpressionContext *ctx) -> any override;
    auto visitAssignmentExpression(FridayParser::AssignmentExpressionContext *ctx) -> any override;
    auto visitSubscriptExpression(FridayParser::SubscriptExpressionContext *ctx) -> any override;
    auto visitCallExpression(FridayParser::CallExpressionContext *ctx) -> any override;
    auto visitMemberAccessExpression(FridayParser::MemberAccessExpressionContext *ctx) -> any override;
    
    auto visitNewExpression(FridayParser::NewExpressionContext *ctx) -> any override;
    auto visitUnaryPrefixExpression(FridayParser::UnaryPrefixExpressionContext *ctx) -> any override;
    auto visitUnaryPostfixExpression(FridayParser::UnaryPostfixExpressionContext *ctx) -> any override;
    auto visitGroupingExpression(FridayParser::GroupingExpressionContext *ctx) -> any override;
    auto visitCompTimeUnaryPrefixExpression(FridayParser::CompTimeUnaryPrefixExpressionContext *ctx) -> any override;

    auto on_unit_begin(TranslationUnit& unit) -> void override;
    auto on_unit_end(TranslationUnit& unit) -> void override;

  private:
    // Helpers
    auto get_printf() -> llvm::Function*;
    auto coerce_value(Value const& value) -> llvm::Value*;

    // Emitters
    auto emit_builtins() -> void;
    auto emit_native_functions() -> void;
    auto emit_functions() -> void;

    auto emit_function(Function* func, llvm::GlobalValue::LinkageTypes linkage, function<string(Function*)> get_name) -> llvm::Value*;
    auto emit_value(Value value) -> llvm::Value*;
    auto emit_alloca(llvm::Type* type, llvm::Value* arraySize = nullptr) -> llvm::AllocaInst*;
    auto emit_call(llvm::Function* func, llvm::ArrayRef<llvm::Value*> args) -> llvm::CallInst*;
    auto emit_call(llvm::FunctionCallee callee, llvm::ArrayRef<llvm::Value*> args) -> llvm::CallInst*;

    // Value queries
    auto query(ISymbol* symbol) -> llvm::Value*;
    auto bind(ISymbol* symbol, llvm::Value* value) -> void;
    auto has_binding(ISymbol* symbol) const -> bool;

  protected:
    auto setup() -> void override;
  };
}
