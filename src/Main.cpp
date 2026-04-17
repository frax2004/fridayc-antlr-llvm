#include "Friday.hpp"

using namespace friday;

auto Main(Vector<StringRef> args) -> void {

  Console::setDebugEnabled(true);

  Opt<Config> config = cmd::parse(std::move(args));
  if(not config.has_value()) return;

  auto ctx = std::make_unique<llvm::LLVMContext>();
  auto unit = TranslationUnit{ config->input.value(), *ctx };

  Compiler{}.compile(unit);

}

