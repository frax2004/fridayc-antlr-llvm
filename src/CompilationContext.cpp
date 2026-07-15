#include <CompilationContext.hpp>
#include <Primitive.hpp>
#include <BinaryOperatorBuilder.hpp>
#include <UnaryOperatorBuilder.hpp>
#include <PointerType.hpp>

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
    auto voidPtrType = PointerType::get(*voidType, 1);
    
    auto opminus = BinaryOperatorBuilder{"operator-"}
    .within(*this->M_global)
    .returns(voidPtrType)
    .left(voidPtrType)
    .right(intType.get())
    .build();

    opminus->add(
      make_shared<Function>(
        *opminus, 
        *intType.get(), 
        vector{
          pair{"lhs"s, voidPtrType}, 
          pair{"rhs"s, voidPtrType}
        }
      )
    );

    this->M_global->define(intType);
    this->M_global->define(byteType);
    this->M_global->define(boolType);
    this->M_global->define(floatType);
    this->M_global->define(voidType);
    this->M_global->define(BinaryOperatorBuilder{"operator<"}.within(*this->M_global).returns(boolType.get()).left(voidPtrType).right(voidPtrType).build());
    this->M_global->define(BinaryOperatorBuilder{"operator>"}.within(*this->M_global).returns(boolType.get()).left(voidPtrType).right(voidPtrType).build());
    this->M_global->define(BinaryOperatorBuilder{"operator<="}.within(*this->M_global).returns(boolType.get()).left(voidPtrType).right(voidPtrType).build());
    this->M_global->define(BinaryOperatorBuilder{"operator>="}.within(*this->M_global).returns(boolType.get()).left(voidPtrType).right(voidPtrType).build());
    this->M_global->define(BinaryOperatorBuilder{"operator=="}.within(*this->M_global).returns(boolType.get()).left(voidPtrType).right(voidPtrType).build());
    this->M_global->define(BinaryOperatorBuilder{"operator!="}.within(*this->M_global).returns(boolType.get()).left(voidPtrType).right(voidPtrType).build());
    this->M_global->define(BinaryOperatorBuilder{"operator+"}.within(*this->M_global).returns(voidPtrType).left(voidPtrType).right(intType.get()).build());
    this->M_global->define(opminus);



    auto Int = dynamic_pointer_cast<ISymbolTable>(intType);
    auto Float = dynamic_pointer_cast<ISymbolTable>(floatType);
    auto Byte = dynamic_pointer_cast<ISymbolTable>(byteType);
    auto Bool = dynamic_pointer_cast<ISymbolTable>(boolType);
    auto Void = dynamic_pointer_cast<ISymbolTable>(voidType);

    Int->define(BinaryOperatorBuilder{"operator+"}.within(*Int).returns(intType.get()).left(intType.get()).right(intType.get()).build());
    Int->define(BinaryOperatorBuilder{"operator-"}.within(*Int).returns(intType.get()).left(intType.get()).right(intType.get()).build());
    Int->define(BinaryOperatorBuilder{"operator*"}.within(*Int).returns(intType.get()).left(intType.get()).right(intType.get()).build());
    Int->define(BinaryOperatorBuilder{"operator/"}.within(*Int).returns(intType.get()).left(intType.get()).right(intType.get()).build());
    Int->define(BinaryOperatorBuilder{"operator%"}.within(*Int).returns(intType.get()).left(intType.get()).right(intType.get()).build());
    Int->define(BinaryOperatorBuilder{"operator=="}.within(*Int).returns(boolType.get()).left(intType.get()).right(intType.get()).build());
    Int->define(BinaryOperatorBuilder{"operator!="}.within(*Int).returns(boolType.get()).left(intType.get()).right(intType.get()).build());
    Int->define(BinaryOperatorBuilder{"operator<"}.within(*Int).returns(boolType.get()).left(intType.get()).right(intType.get()).build());
    Int->define(BinaryOperatorBuilder{"operator<="}.within(*Int).returns(boolType.get()).left(intType.get()).right(intType.get()).build());
    Int->define(BinaryOperatorBuilder{"operator>"}.within(*Int).returns(boolType.get()).left(intType.get()).right(intType.get()).build());
    Int->define(BinaryOperatorBuilder{"operator>="}.within(*Int).returns(boolType.get()).left(intType.get()).right(intType.get()).build());
    Int->define(BinaryOperatorBuilder{"operator&"}.within(*Int).returns(intType.get()).left(intType.get()).right(intType.get()).build());
    Int->define(BinaryOperatorBuilder{"operator|"}.within(*Int).returns(intType.get()).left(intType.get()).right(intType.get()).build());
    Int->define(UnaryOperatorBuilder("operator+").within(*Int).returns(intType.get()).takes(intType.get()).build());
    Int->define(UnaryOperatorBuilder("operator-").within(*Int).returns(intType.get()).takes(intType.get()).build());
    Int->define(UnaryOperatorBuilder("operator++").within(*Int).returns(intType.get()).takes(intType.get()).build());
    Int->define(UnaryOperatorBuilder("operator--").within(*Int).returns(intType.get()).takes(intType.get()).build());
    Int->define(UnaryOperatorBuilder("operator~").within(*Int).returns(intType.get()).takes(intType.get()).build());

    Float->define(BinaryOperatorBuilder{"operator+"}.within(*Float).returns(floatType.get()).left(floatType.get()).right(floatType.get()).build());
    Float->define(BinaryOperatorBuilder{"operator-"}.within(*Float).returns(floatType.get()).left(floatType.get()).right(floatType.get()).build());
    Float->define(BinaryOperatorBuilder{"operator*"}.within(*Float).returns(floatType.get()).left(floatType.get()).right(floatType.get()).build());
    Float->define(BinaryOperatorBuilder{"operator/"}.within(*Float).returns(floatType.get()).left(floatType.get()).right(floatType.get()).build());
    Float->define(BinaryOperatorBuilder{"operator%"}.within(*Float).returns(floatType.get()).left(floatType.get()).right(floatType.get()).build());
    Float->define(BinaryOperatorBuilder{"operator=="}.within(*Float).returns(boolType.get()).left(floatType.get()).right(floatType.get()).build());
    Float->define(BinaryOperatorBuilder{"operator!="}.within(*Float).returns(boolType.get()).left(floatType.get()).right(floatType.get()).build());
    Float->define(BinaryOperatorBuilder{"operator<"}.within(*Float).returns(boolType.get()).left(floatType.get()).right(floatType.get()).build());
    Float->define(BinaryOperatorBuilder{"operator<="}.within(*Float).returns(boolType.get()).left(floatType.get()).right(floatType.get()).build());
    Float->define(BinaryOperatorBuilder{"operator>"}.within(*Float).returns(boolType.get()).left(floatType.get()).right(floatType.get()).build());
    Float->define(BinaryOperatorBuilder{"operator>="}.within(*Float).returns(boolType.get()).left(floatType.get()).right(floatType.get()).build());
    Float->define(UnaryOperatorBuilder("operator+").within(*Float).returns(floatType.get()).takes(floatType.get()).build());
    Float->define(UnaryOperatorBuilder("operator-").within(*Float).returns(floatType.get()).takes(floatType.get()).build());
    Float->define(UnaryOperatorBuilder("operator++").within(*Float).returns(floatType.get()).takes(floatType.get()).build());
    Float->define(UnaryOperatorBuilder("operator--").within(*Float).returns(floatType.get()).takes(floatType.get()).build());

    Byte->define(BinaryOperatorBuilder{"operator+"}.within(*Byte).returns(byteType.get()).left(byteType.get()).right(byteType.get()).build());
    Byte->define(BinaryOperatorBuilder{"operator-"}.within(*Byte).returns(byteType.get()).left(byteType.get()).right(byteType.get()).build());
    Byte->define(BinaryOperatorBuilder{"operator*"}.within(*Byte).returns(byteType.get()).left(byteType.get()).right(byteType.get()).build());
    Byte->define(BinaryOperatorBuilder{"operator/"}.within(*Byte).returns(byteType.get()).left(byteType.get()).right(byteType.get()).build());
    Byte->define(BinaryOperatorBuilder{"operator%"}.within(*Byte).returns(byteType.get()).left(byteType.get()).right(byteType.get()).build());
    Byte->define(BinaryOperatorBuilder{"operator=="}.within(*Byte).returns(boolType.get()).left(byteType.get()).right(byteType.get()).build());
    Byte->define(BinaryOperatorBuilder{"operator!="}.within(*Byte).returns(boolType.get()).left(byteType.get()).right(byteType.get()).build());
    Byte->define(BinaryOperatorBuilder{"operator<"}.within(*Byte).returns(boolType.get()).left(byteType.get()).right(byteType.get()).build());
    Byte->define(BinaryOperatorBuilder{"operator<="}.within(*Byte).returns(boolType.get()).left(byteType.get()).right(byteType.get()).build());
    Byte->define(BinaryOperatorBuilder{"operator>"}.within(*Byte).returns(boolType.get()).left(byteType.get()).right(byteType.get()).build());
    Byte->define(BinaryOperatorBuilder{"operator>="}.within(*Byte).returns(boolType.get()).left(byteType.get()).right(byteType.get()).build());
    Byte->define(BinaryOperatorBuilder{"operator&"}.within(*Byte).returns(byteType.get()).left(byteType.get()).right(byteType.get()).build());
    Byte->define(BinaryOperatorBuilder{"operator|"}.within(*Byte).returns(byteType.get()).left(byteType.get()).right(byteType.get()).build());
    Byte->define(UnaryOperatorBuilder("operator~").within(*Byte).returns(byteType.get()).takes(byteType.get()).build());

    Bool->define(BinaryOperatorBuilder{"operator=="}.within(*Bool).returns(boolType.get()).left(boolType.get()).right(boolType.get()).build());
    Bool->define(BinaryOperatorBuilder{"operator!="}.within(*Bool).returns(boolType.get()).left(boolType.get()).right(boolType.get()).build());
    Bool->define(BinaryOperatorBuilder{"operatorand"}.within(*Bool).returns(boolType.get()).left(boolType.get()).right(boolType.get()).build());
    Bool->define(BinaryOperatorBuilder{"operatoror"}.within(*Bool).returns(boolType.get()).left(boolType.get()).right(boolType.get()).build());
    Bool->define(BinaryOperatorBuilder{"operator&"}.within(*Bool).returns(boolType.get()).left(boolType.get()).right(boolType.get()).build());
    Bool->define(BinaryOperatorBuilder{"operator|"}.within(*Bool).returns(boolType.get()).left(boolType.get()).right(boolType.get()).build());
    Bool->define(UnaryOperatorBuilder("operatornot").within(*Bool).returns(boolType.get()).takes(boolType.get()).build());
    Bool->define(UnaryOperatorBuilder("operator~").within(*Bool).returns(boolType.get()).takes(boolType.get()).build());

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
