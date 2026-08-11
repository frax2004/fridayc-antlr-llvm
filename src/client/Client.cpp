#include <fridayc.hpp>

using namespace friday;


auto to_string(Namespace* self) -> string;
auto to_string(Struct* self) -> string;
auto to_string(Variable* self) -> string;
auto to_string(Overload* self) -> string;


auto Main(vector<string> paths) -> void {
  auto settings = CompilationSettings::builder()
  .enable_debug(false)
  .redirect_notes_to(stdout)
  .redirect_logs_to(stdout)
  .redirect_debugs_to(stderr)
  .redirect_errors_to(stderr)
  .redirect_warnings_to(stderr)
  .build();

  auto context = CompilationContext::create(paths);
  auto compiler = Compiler::create(*context, settings);
  compiler->compile();
}

auto to_string(Namespace* self) -> string {
  return format(
    "{}namespace{} {}{}{}\n{}\n{}\n{}",
    Console::Color::RED,
    Console::Color::RESET,
    Console::Color::rgb(255, 183, 0),
    self->get_qualified_id(),
    Console::Color::RESET,
    self->get_symbols()
    | views::filter(Struct::is_struct)
    | views::transform(Struct::to_struct)
    | views::transform(static_cast<string(*)(Struct*)>(&to_string))
    | views::join_with("\n"sv) 
    | ranges::to<string>(),
    self->get_symbols()
    | views::filter(Overload::is_overload)
    | views::transform(Overload::to_overload)
    | views::transform(static_cast<string(*)(Overload*)>(&to_string))
    | views::join_with("\n"sv) 
    | ranges::to<string>(),
    self->get_symbols()
    | views::filter(Variable::is_variable)
    | views::transform(Variable::to_variable)
    | views::transform(static_cast<string(*)(Variable*)>(&to_string))
    | views::join_with("\n"sv) 
    | ranges::to<string>()
  );
}

auto to_string(Struct* self) -> string {
  return format(
    "{}struct{} {}{}{}\n{}\n{}",
    Console::Color::RED,
    Console::Color::RESET,
    Console::Color::rgb(255, 183, 0),
    self->get_qualified_id(),
    Console::Color::RESET,
    self->get_symbols()
    | views::filter(Overload::is_overload)
    | views::transform(Overload::to_overload)
    | views::transform(static_cast<string(*)(Overload*)>(&to_string))
    | views::join_with("\n"sv) 
    | ranges::to<string>(),
    self->get_symbols()
    | views::filter(Variable::is_variable)
    | views::transform(Variable::to_variable)
    | views::transform(static_cast<string(*)(Variable*)>(&to_string))
    | views::join_with("\n"sv) 
    | ranges::to<string>()
  );
}

auto to_string(Overload* self) -> string {
  return format(
    "{}overload{} {}{}{}\n{}{}{}",
    Console::Color::RED,
    Console::Color::RESET,
    Console::Color::BLUE,
    self->get_qualified_id(),
    Console::Color::RESET,
    Console::Color::rgb(255, 183, 0),
    self->get_instances()
    | views::transform(Function::get_type)
    | views::transform(Type::get_name)
    | views::join_with("\n"sv) 
    | ranges::to<string>(),
    Console::Color::RESET
  );
}

auto to_string(Variable* self) -> string {
  return format(
    "{}variable{} {}{}{} : {}{}{}",
    Console::Color::RED,
    Console::Color::RESET,
    Console::Color::rgb(200, 200, 200),
    self->get_qualified_id(),
    Console::Color::RESET,
    Console::Color::rgb(255, 183, 0),
    self->get_type()->get_name(),
    Console::Color::RESET
  );
}
