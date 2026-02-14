all:
	flex -o lex.yy.cpp lexer.l
	bison -d parser.y -o parser.tab.cpp --defines=parser.tab.h
	g++ -std=c++17 parser.tab.cpp lex.yy.cpp -o compiler

clean:
	rm -f parser.tab.cpp parser.tab.h lex.yy.cpp compiler tables.txt