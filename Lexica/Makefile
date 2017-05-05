all:
	lex scanner.l
	gcc lex.yy.c -o scanner
	./scanner teste-completo.tpp

clear:
	rm scanner
