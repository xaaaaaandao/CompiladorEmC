all : parser.tab.c scanner.c build

parser.tab.c : parser.y
	bison -y -d -t $^ -o parser.tab.c

scanner.c : scanner.l
	flex -d -T $^
	
build :
	gcc -c parser.tab.c lex.yy.c
	gcc parser.tab.o lex.yy.o syntaxtree.c semantic.c -o analiseSemantica
