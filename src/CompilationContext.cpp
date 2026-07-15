#include <CompilationContext.hpp>
#include <Primitive.hpp>
#include <BinaryOperatorBuilder.hpp>
#include <UnaryOperatorBuilder.hpp>

namespace friday::inline api::inline pipeline {

  CompilationContext::CompilationContext(vector<string> const& paths) {
    this->M_global = make_shared<Namespace>("");

    auto parse = [this](string path) {
      return async(launch::async, [this, path]() {
        Console::log("Parsing '{}'"_f.format(path));
        flush(cout);
        return TranslationUnit::parse(*this, path);
      });
    };

    auto futures = paths
    | views::transform([](string const& s) { return filesystem::absolute(s).generic_string(); })
    | views::transform(parse)
    | ranges::to<vector>();

    this->M_units = futures
    | views::transform(&future<rc<TranslationUnit>>::get)
    | ranges::to<vector>();

    auto intType = make_shared<Primitive>(*this->M_global, "int", llvm::Type::getInt64Ty(this->M_llvmContext));
    auto byteType = make_shared<Primitive>(*this->M_global, "byte", llvm::Type::getInt8Ty(this->M_llvmContext));
    auto boolType = make_shared<Primitive>(*this->M_global, "bool", llvm::Type::getInt1Ty(this->M_llvmContext));
    auto floatType = make_shared<Primitive>(*this->M_global, "float", llvm::Type::getDoubleTy(this->M_llvmContext));
    auto voidType = make_shared<Primitive>(*this->M_global, "void", llvm::Type::getVoidTy(this->M_llvmContext));

    intType->define(BinaryOperatorBuilder{"operator+"}.within(*this->M_global).returns(intType).left(intType).right(intType).build());
    intType->define(BinaryOperatorBuilder{"operator-"}.within(*this->M_global).returns(intType).left(intType).right(intType).build());
    intType->define(BinaryOperatorBuilder{"operator*"}.within(*this->M_global).returns(intType).left(intType).right(intType).build());
    intType->define(BinaryOperatorBuilder{"operator/"}.within(*this->M_global).returns(intType).left(intType).right(intType).build());
    intType->define(BinaryOperatorBuilder{"operator%"}.within(*this->M_global).returns(intType).left(intType).right(intType).build());
    intType->define(BinaryOperatorBuilder{"operator=="}.within(*this->M_global).returns(intType).left(intType).right(intType).build());
    intType->define(BinaryOperatorBuilder{"operator!="}.within(*this->M_global).returns(intType).left(intType).right(intType).build());
    intType->define(BinaryOperatorBuilder{"operator<"}.within(*this->M_global).returns(boolType).left(intType).right(intType).build());
    intType->define(BinaryOperatorBuilder{"operator<="}.within(*this->M_global).returns(boolType).left(intType).right(intType).build());
    intType->define(BinaryOperatorBuilder{"operator>"}.within(*this->M_global).returns(boolType).left(intType).right(intType).build());
    intType->define(BinaryOperatorBuilder{"operator>="}.within(*this->M_global).returns(boolType).left(intType).right(intType).build());
    intType->define(BinaryOperatorBuilder{"operator&"}.within(*this->M_global).returns(intType).left(intType).right(intType).build());
    intType->define(BinaryOperatorBuilder{"operator|"}.within(*this->M_global).returns(intType).left(intType).right(intType).build());
    intType->define(UnaryOperatorBuilder("operator+").within(*this->M_global).returns(intType).takes(intType).build());
    intType->define(UnaryOperatorBuilder("operator-").within(*this->M_global).returns(intType).takes(intType).build());
    intType->define(UnaryOperatorBuilder("operator~").within(*this->M_global).returns(intType).takes(intType).build());

    floatType->define(BinaryOperatorBuilder{"operator+"}.within(*this->M_global).returns(floatType).left(floatType).right(floatType).build());
    floatType->define(BinaryOperatorBuilder{"operator-"}.within(*this->M_global).returns(floatType).left(floatType).right(floatType).build());
    floatType->define(BinaryOperatorBuilder{"operator*"}.within(*this->M_global).returns(floatType).left(floatType).right(floatType).build());
    floatType->define(BinaryOperatorBuilder{"operator/"}.within(*this->M_global).returns(floatType).left(floatType).right(floatType).build());
    floatType->define(BinaryOperatorBuilder{"operator%"}.within(*this->M_global).returns(floatType).left(floatType).right(floatType).build());
    floatType->define(BinaryOperatorBuilder{"operator=="}.within(*this->M_global).returns(floatType).left(floatType).right(floatType).build());
    floatType->define(BinaryOperatorBuilder{"operator!="}.within(*this->M_global).returns(floatType).left(floatType).right(floatType).build());
    floatType->define(BinaryOperatorBuilder{"operator<"}.within(*this->M_global).returns(boolType).left(floatType).right(floatType).build());
    floatType->define(BinaryOperatorBuilder{"operator<="}.within(*this->M_global).returns(boolType).left(floatType).right(floatType).build());
    floatType->define(BinaryOperatorBuilder{"operator>"}.within(*this->M_global).returns(boolType).left(floatType).right(floatType).build());
    floatType->define(BinaryOperatorBuilder{"operator>="}.within(*this->M_global).returns(boolType).left(floatType).right(floatType).build());
    floatType->define(UnaryOperatorBuilder("operator+").within(*this->M_global).returns(floatType).takes(floatType).build());
    floatType->define(UnaryOperatorBuilder("operator-").within(*this->M_global).returns(floatType).takes(floatType).build());

    byteType->define(BinaryOperatorBuilder{"operator+"}.within(*this->M_global).returns(byteType).left(byteType).right(byteType).build());
    byteType->define(BinaryOperatorBuilder{"operator-"}.within(*this->M_global).returns(byteType).left(byteType).right(byteType).build());
    byteType->define(BinaryOperatorBuilder{"operator*"}.within(*this->M_global).returns(byteType).left(byteType).right(byteType).build());
    byteType->define(BinaryOperatorBuilder{"operator/"}.within(*this->M_global).returns(byteType).left(byteType).right(byteType).build());
    byteType->define(BinaryOperatorBuilder{"operator%"}.within(*this->M_global).returns(byteType).left(byteType).right(byteType).build());
    byteType->define(BinaryOperatorBuilder{"operator=="}.within(*this->M_global).returns(byteType).left(byteType).right(byteType).build());
    byteType->define(BinaryOperatorBuilder{"operator!="}.within(*this->M_global).returns(byteType).left(byteType).right(byteType).build());
    byteType->define(BinaryOperatorBuilder{"operator<"}.within(*this->M_global).returns(boolType).left(byteType).right(byteType).build());
    byteType->define(BinaryOperatorBuilder{"operator<="}.within(*this->M_global).returns(boolType).left(byteType).right(byteType).build());
    byteType->define(BinaryOperatorBuilder{"operator>"}.within(*this->M_global).returns(boolType).left(byteType).right(byteType).build());
    byteType->define(BinaryOperatorBuilder{"operator>="}.within(*this->M_global).returns(boolType).left(byteType).right(byteType).build());
    byteType->define(BinaryOperatorBuilder{"operator&"}.within(*this->M_global).returns(byteType).left(byteType).right(byteType).build());
    byteType->define(BinaryOperatorBuilder{"operator|"}.within(*this->M_global).returns(byteType).left(byteType).right(byteType).build());
    byteType->define(UnaryOperatorBuilder("operator~").within(*this->M_global).returns(byteType).takes(byteType).build());

    boolType->define(BinaryOperatorBuilder{"operator=="}.within(*this->M_global).returns(boolType).left(boolType).right(boolType).build());
    boolType->define(BinaryOperatorBuilder{"operator!="}.within(*this->M_global).returns(boolType).left(boolType).right(boolType).build());
    boolType->define(BinaryOperatorBuilder{"operatorand"}.within(*this->M_global).returns(boolType).left(boolType).right(boolType).build());
    boolType->define(BinaryOperatorBuilder{"operatoror"}.within(*this->M_global).returns(boolType).left(boolType).right(boolType).build());
    boolType->define(BinaryOperatorBuilder{"operator&"}.within(*this->M_global).returns(boolType).left(boolType).right(boolType).build());
    boolType->define(BinaryOperatorBuilder{"operator|"}.within(*this->M_global).returns(boolType).left(boolType).right(boolType).build());
    boolType->define(UnaryOperatorBuilder("operatornot").within(*this->M_global).returns(boolType).takes(boolType).build());
    boolType->define(UnaryOperatorBuilder("operator~").within(*this->M_global).returns(boolType).takes(boolType).build());


    this->M_global->define(intType);
    this->M_global->define(byteType);
    this->M_global->define(boolType);
    this->M_global->define(floatType);
    this->M_global->define(voidType);
  }

  auto CompilationContext::print() -> void {
    auto toString = json::stringify<Namespace>{}; 

    auto table = "[{}, {}]"_f.format(
      toString(*this->M_global),
      this->M_namespaces
      | views::values
      | views::transform(&rc<Namespace>::operator*)
      | views::transform(toString)
      | views::join_with(", "s)
      | ranges::to<string>()
    );

    Pointer<FILE> output = fopen("table.json", "w+");
    println(output, "{}", table);
    fclose(output);

  }

  auto CompilationContext::get_units() const -> ranges::ref_view<const vector<rc<TranslationUnit>>> {
    return this->M_units;
  }

  auto CompilationContext::add_unit(rc<TranslationUnit> unit) -> void {
    this->M_units.push_back(unit);
  }

  auto CompilationContext::get_or_emplace_namespace(string_view name) -> weak<Namespace> {
    if(auto it = this->M_namespaces.find(name); it != this->M_namespaces.end()) {
      return it->second;
    } else return this->M_namespaces.emplace(
      string{ name }, 
      make_shared<Namespace>(*this->M_global, string{ name })
    ).first->second;
  }

  auto CompilationContext::get_llvm_context() -> llvm::LLVMContext& {
    return this->M_llvmContext;
  }

  auto CompilationContext::get_global() const -> rc<Namespace> {
    return this->M_global;
  }

  auto CompilationContext::find_namespace(string_view name) -> weak<Namespace> {
    auto it = this->M_namespaces.find(name);
    return it != this->M_namespaces.end() ? it->second : weak<Namespace>{};
  }

}
