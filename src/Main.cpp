#include <FridayScanner.h>
#include <FridayParser.h>


using namespace friday;


auto Main(vector<string_ref> args) -> void {

  auto inputStream = ifstream(string(args[0]));
  auto input = ant::ANTLRInputStream(inputStream);
  auto lexer = FridayScanner(&input);
  auto tokens = ant::CommonTokenStream(&lexer);
  auto parser = FridayParser(&tokens);

  auto ast = parser.program();
}