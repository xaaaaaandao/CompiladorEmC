all : parser.tab.c scanner.c build 

parser.tab.c : parser.y
	bison -y -d -t $^ -o parser.tab.c

scanner.c : scanner.l
	flex -d -T $^

build :
	clang-3.5 -c generate.c syntaxtree.c semantic.c lista.c parser.tab.c lex.yy.c `llvm-config-3.5 --cflags`
	clang++-3.5 parser.tab.o lex.yy.o generate.o syntaxtree.o semantic.o lista.o -lm -o generate `llvm-config-3.5 --ldflags --libs core executionengine jit interpreter analysis native bitwriter --system-libs`
