all:
	lex scanner.l
	gcc lex.yy.c -o scanner
	bison -y -d -t parser.y -o parser.tab.c 
#	gcc -c parser.tab.c lex.yy.c
#	gcc parser.tab.o lex.yy.o -o tppc.exe
#	./scanner teste-completo.tpp

clear:
	rm yytokentype.o
	rm scanner
