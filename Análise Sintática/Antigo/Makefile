all:
	bison -y -d -t parser.y -o parser.tab.c 
	flex -d -T scanner.l
	gcc pTree.c -c
	gcc files.c -c
	gcc -c parser.tab.c lex.yy.c -lfl
	gcc parser.tab.o lex.yy.o pTree.o files.o -lm -o arvoreSintatica

bison:
	bison -y -d -t parser.y -o parser.tab.c 	

lex:
	flex -d -T scanner.l

clean:
	rm yytokentype.o
	rm scanner
