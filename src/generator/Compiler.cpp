#include <fridayc.hpp>

namespace friday::inline api {
  
  Compiler::Compiler(CompilationContext& ctx, CompilationSettings settings)
    : M_ctx { &ctx }
    , M_settings { settings }
  {}

  auto Compiler::create(CompilationContext& ctx, CompilationSettings settings) noexcept -> unique_ptr<Compiler> {
    return unique_ptr<Compiler>(new Compiler(ctx, settings));
  }

  auto Compiler::compile() -> void {
    Console::set_channel(Console::Channel::LOG, this->M_settings.get_log_stream()); 
    Console::set_channel(Console::Channel::DEBUG, this->M_settings.get_debug_stream()); 
    Console::set_channel(Console::Channel::NOTE, this->M_settings.get_note_stream()); 
    Console::set_channel(Console::Channel::WARNING, this->M_settings.get_warning_stream()); 
    Console::set_channel(Console::Channel::ERROR, this->M_settings.get_error_stream());
    Console::set_debug_enabled(this->M_settings.is_debug_enabled());

    DiscoveryVisitor v1 { *this->M_ctx };
    NamespaceBindingVisitor v2 { *this->M_ctx };
    TypeSolverVisitor v3 { *this->M_ctx };
    OverloadSolverVisitor v4 { *this->M_ctx };
    TypeCheckerVisitor v5 { *this->M_ctx };
    LLVMObjectEmitterVisitor v6 { *this->M_ctx };

    auto visitors = array{
      dynamic_cast<StaticAnalyzer*>(&v1),
      dynamic_cast<StaticAnalyzer*>(&v2),
      dynamic_cast<StaticAnalyzer*>(&v3),
      dynamic_cast<StaticAnalyzer*>(&v4),
      dynamic_cast<StaticAnalyzer*>(&v5),
      dynamic_cast<StaticAnalyzer*>(&v6)
    };

    auto descriptions = array{
      "Collecting Symbols..."sv,
      "Solving Namespace Imports..."sv,
      "Resolving Types..."sv,
      "Resolving Overloaded Functions..."sv,
      "Running Static Analysis..."sv,
      "Emitting LLVM Object..."sv,
    };

    bool ok = true;
    u64 total_errors = 0;

    for(auto [i, visitor, desc] : views::zip(views::iota(1zu, descriptions.size()+1zu), visitors, descriptions)) {
      Console::log(
        format(
          "[{:3}%] | {}{}{}{}", 
          static_cast<u32>(round(i/static_cast<f32>(descriptions.size())*100)),
          Console::Color::GREEN,
          Console::Color::BOLD,
          desc,
          Console::Color::RESET
        )
      );

      auto errors = visitor->analyze().errors();
      if(not errors.empty()) {
        ranges::for_each(errors, &SemanticError::report);
        total_errors += errors.size();
        ok = false;
        break;
      }
    }

    if(not ok) {
      Console::error(
        format(
          "Compilation interrupted: {} {}{}error(s){} occurred!", 
          total_errors,
          Console::Color::RED,
          Console::Color::BOLD,
          Console::Color::RESET
        )
      );
      return;
    }

    namespace fs = filesystem;
    auto cur = fs::current_path();
    auto out = fs::path{ cur/"out" };
    auto llvm = fs::path{ cur/out/"llvm" };
    auto bin = fs::path{ cur/out/"bin" };
    auto ir = fs::path{ cur/llvm/"out.ll" };
    auto exe = fs::path{ cur/bin/"a.exe" };

    fs::create_directory(out); {
      fs::create_directory(llvm);
      fs::create_directory(bin);
    }

    ofstream ostream { ir };
    llvm::raw_os_ostream stream{ ostream };

    LLVMWrapper::instance().module().print(stream, nullptr);
    stream.flush();
    ostream.close();

    string command = format(
      "clang++ -Wno-override-module -std=c++23 -o {} {} -L{} -l{}",
      exe,
      ir,
      cur/"lib",
      "friday-runtime"
    );

    system(command.c_str());

    Console::log("Compilation termined.");
  }

}