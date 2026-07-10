#include <CompilationContext.hpp>
#include <Primitive.hpp>
#include <BinaryOperatorBuilder.hpp>

namespace friday::inline api::inline pipeline {

  CompilationContext::CompilationContext(vector<string> const& paths) {
    this->global = make_shared<Namespace>("");

    auto parse = [this](string path) {
      return async(launch::async, [this, path]() {
        return TranslationUnit::parse(*this, path);
      });
    };

    auto futures = paths
    | views::transform(parse)
    | ranges::to<vector>();

    this->units = futures
    | views::transform(&future<rc<TranslationUnit>>::get)
    | ranges::to<vector>();

    auto intType = make_shared<Primitive>(*this->global, "int", llvm::Type::getInt64Ty(this->llvmContext));
    auto byteType = make_shared<Primitive>(*this->global, "byte", llvm::Type::getInt8Ty(this->llvmContext));
    auto boolType = make_shared<Primitive>(*this->global, "bool", llvm::Type::getInt1Ty(this->llvmContext));
    auto floatType = make_shared<Primitive>(*this->global, "float", llvm::Type::getDoubleTy(this->llvmContext));
    auto voidType = make_shared<Primitive>(*this->global, "void", llvm::Type::getVoidTy(this->llvmContext));

    intType->define(BinaryOperatorBuilder{"operator+"}.inside(*this->global).returns(intType).left(intType).right(intType).build());
    intType->define(BinaryOperatorBuilder{"operator-"}.inside(*this->global).returns(intType).left(intType).right(intType).build());
    intType->define(BinaryOperatorBuilder{"operator*"}.inside(*this->global).returns(intType).left(intType).right(intType).build());
    intType->define(BinaryOperatorBuilder{"operator/"}.inside(*this->global).returns(intType).left(intType).right(intType).build());
    intType->define(BinaryOperatorBuilder{"operator%"}.inside(*this->global).returns(intType).left(intType).right(intType).build());
    intType->define(BinaryOperatorBuilder{"operator=="}.inside(*this->global).returns(intType).left(intType).right(intType).build());
    intType->define(BinaryOperatorBuilder{"operator!="}.inside(*this->global).returns(intType).left(intType).right(intType).build());
    intType->define(BinaryOperatorBuilder{"operator<"}.inside(*this->global).returns(boolType).left(intType).right(intType).build());
    intType->define(BinaryOperatorBuilder{"operator<="}.inside(*this->global).returns(boolType).left(intType).right(intType).build());
    intType->define(BinaryOperatorBuilder{"operator>"}.inside(*this->global).returns(boolType).left(intType).right(intType).build());
    intType->define(BinaryOperatorBuilder{"operator>="}.inside(*this->global).returns(boolType).left(intType).right(intType).build());

    floatType->define(BinaryOperatorBuilder{"operator+"}.inside(*this->global).returns(floatType).left(floatType).right(floatType).build());
    floatType->define(BinaryOperatorBuilder{"operator-"}.inside(*this->global).returns(floatType).left(floatType).right(floatType).build());
    floatType->define(BinaryOperatorBuilder{"operator*"}.inside(*this->global).returns(floatType).left(floatType).right(floatType).build());
    floatType->define(BinaryOperatorBuilder{"operator/"}.inside(*this->global).returns(floatType).left(floatType).right(floatType).build());
    floatType->define(BinaryOperatorBuilder{"operator%"}.inside(*this->global).returns(floatType).left(floatType).right(floatType).build());
    floatType->define(BinaryOperatorBuilder{"operator=="}.inside(*this->global).returns(floatType).left(floatType).right(floatType).build());
    floatType->define(BinaryOperatorBuilder{"operator!="}.inside(*this->global).returns(floatType).left(floatType).right(floatType).build());
    floatType->define(BinaryOperatorBuilder{"operator<"}.inside(*this->global).returns(boolType).left(floatType).right(floatType).build());
    floatType->define(BinaryOperatorBuilder{"operator<="}.inside(*this->global).returns(boolType).left(floatType).right(floatType).build());
    floatType->define(BinaryOperatorBuilder{"operator>"}.inside(*this->global).returns(boolType).left(floatType).right(floatType).build());
    floatType->define(BinaryOperatorBuilder{"operator>="}.inside(*this->global).returns(boolType).left(floatType).right(floatType).build());

    byteType->define(BinaryOperatorBuilder{"operator+"}.inside(*this->global).returns(byteType).left(byteType).right(byteType).build());
    byteType->define(BinaryOperatorBuilder{"operator-"}.inside(*this->global).returns(byteType).left(byteType).right(byteType).build());
    byteType->define(BinaryOperatorBuilder{"operator*"}.inside(*this->global).returns(byteType).left(byteType).right(byteType).build());
    byteType->define(BinaryOperatorBuilder{"operator/"}.inside(*this->global).returns(byteType).left(byteType).right(byteType).build());
    byteType->define(BinaryOperatorBuilder{"operator%"}.inside(*this->global).returns(byteType).left(byteType).right(byteType).build());
    byteType->define(BinaryOperatorBuilder{"operator=="}.inside(*this->global).returns(byteType).left(byteType).right(byteType).build());
    byteType->define(BinaryOperatorBuilder{"operator!="}.inside(*this->global).returns(byteType).left(byteType).right(byteType).build());
    byteType->define(BinaryOperatorBuilder{"operator<"}.inside(*this->global).returns(boolType).left(byteType).right(byteType).build());
    byteType->define(BinaryOperatorBuilder{"operator<="}.inside(*this->global).returns(boolType).left(byteType).right(byteType).build());
    byteType->define(BinaryOperatorBuilder{"operator>"}.inside(*this->global).returns(boolType).left(byteType).right(byteType).build());
    byteType->define(BinaryOperatorBuilder{"operator>="}.inside(*this->global).returns(boolType).left(byteType).right(byteType).build());

    boolType->define(BinaryOperatorBuilder{"operator=="}.inside(*this->global).returns(boolType).left(boolType).right(boolType).build());
    boolType->define(BinaryOperatorBuilder{"operator!="}.inside(*this->global).returns(boolType).left(boolType).right(boolType).build());

    this->global->define(intType);
    this->global->define(byteType);
    this->global->define(boolType);
    this->global->define(floatType);
    this->global->define(voidType);
  }

  auto CompilationContext::print() -> void {
    auto toString = json::stringify<Namespace>{}; 

    auto table = "[{}, {}]"_f.format(
      toString(*this->global),
      this->namespaces
      | views::values
      | views::transform(&rc<Namespace>::operator*)
      | views::transform(toString)
      | views::join_with(", "s)
      | ranges::to<string>()
    );

    FILE* output = fopen("table.json", "w+");
    println(output, "{}", table);
    fclose(output);

  }

}
