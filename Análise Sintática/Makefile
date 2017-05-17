all:
	bison -y -d -t parser.y -o parser.tab.c 
	flex -d -T scanner.l
	gcc -c parser.tab.c lex.yy.c -lfl
	gcc parser.tab.o lex.yy.o -lm -o arvoreSintatica.exe
	bison -y -d -t parser.y -o parser.tab.c --verbose

bison:
	bison -y -d -t parser.y -o parser.tab.c 	

lex:
	flex -d -T scanner.l

clean:
	rm yytokentype.o
	rm scanner
