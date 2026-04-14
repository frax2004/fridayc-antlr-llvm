
java -jar antlr.jar -o generated -Dlanguage=Cpp FridayScanner.g4
java -jar antlr.jar -o generated -Dlanguage=Cpp -visitor -listener FridayParser.g4

cd generated
move *.h ../include/api/parser/
move * ../src/
cd ..
