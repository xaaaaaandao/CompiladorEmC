#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "syntaxtree.h"
#include "generate.h"

char *nomeModulo(char *nomeArquivo){
	char *novoNome = (char*)calloc(MAX, sizeof(char));
	int i = strlen(nomeArquivo), j = 0;
	while(i >= 0){
		if(nomeArquivo[i] == '.')
			break;
		i--;
	}
	while(j < i){
		novoNome[j] = nomeArquivo[i];
		j++;
	}
	nomeArquivo[j] ='\0';
	return strcat(nomeArquivo, ".bc");
}

void cabecalhoCode(char* nomeArquivo, FILE *arquivo){
	fprintf(arquivo, "#include <stdio.h>\n#include <stdlib.h>\n#include <stdbool.h>\n#include <llvm-c/Core.h>\n#include <llvm-c/BitWriter.h>\n\nint main(int argc, char *argv[]) {\n 	LLVMContextRef context = LLVMGetGlobalContext();\n	LLVMModuleRef module = LLVMModuleCreateWithNameInContext(\"%s\", context);\n	LLVMBuilderRef builder = LLVMCreateBuilderInContext(context);\n\n", nomeModulo(nomeArquivo));
}

void caudaCode(char *nomeArquivo, FILE *arquivo){
	fprintf(arquivo, "\n	LLVMDumpModule(module);\n	if (LLVMWriteBitcodeToFile(module, \"%s\") != 0) {\n 		fprintf(stderr, \"error writing bitcode to file, skipping\");\n 	}\n}", nomeModulo(nomeArquivo));	
}


void preencheCodeGlobal(FILE *arquivo, ListaVariaveis *v, ListaInicializacao *i){
	char type[MAX], type0[MAX], array[MAX];
	int valor1, valor2;
	NoVariaveis *variaveis = v -> primeiro;
	while(variaveis != NULL){
		if(variaveis -> ehUnidimensional){
			strcpy(type, "type");
			strcpy(array, "array");
			strcat(type, variaveis -> nome);
			strcat(array, variaveis -> nome);
			valor1 = atoi(variaveis -> valor1);
			if(compareString(variaveis -> tipo, "inteiro") == 0){
				fprintf(arquivo, "	LLVMTypeRef %s = LLVMArrayType(LLVMInt64Type(), %d);\n	LLVMValueRef %s = LLVMAddGlobal (module, %s, \"%s\");\n	LLVMSetInitializer(%s, LLVMConstInt(LLVMInt64Type(), 0, false));\n	LLVMSetLinkage(%s, LLVMCommonLinkage);\n	LLVMSetAlignment(%s, 16);\n", type, valor1, array, type, variaveis -> nome, array, array, array);
									//LLVMTypeRef typeA = LLVMArrayType(LLVMInt64Type(), 1024); LLVMValueRef arrayA = LLVMAddGlobal (module, typeA, "A"); LLVMSetInitializer(arrayA, LLVMConstInt(LLVMInt64Type(), 0, false));  LLVMSetLinkage(arrayA, LLVMCommonLinkage); LLVMSetAlignment(arrayA, 16);
			} else if(compareString(variaveis -> tipo, "flutuante") == 0){
				fprintf(arquivo, "	LLVMTypeRef %s = LLVMArrayType(LLVMFloatType(), %d);\n	LLVMValueRef %s = LLVMAddGlobal (module, %s, \"%s\");\n	LLVMSetInitializer(%s, LLVMConstInt(LLVMInt64Type(), 0, false));\n	LLVMSetLinkage(%s, LLVMCommonLinkage);\n	LLVMSetAlignment(%s, 16);\n", type, valor1, array, type, variaveis -> nome, array, array, array);
			}
		} else if(variaveis -> ehBidimensional){
			if(compareString(variaveis -> tipo, "inteiro") == 0){

			} else if(compareString(variaveis -> tipo, "flutuante") == 0){

			}
		} else {
			if(compareString(variaveis -> tipo, "inteiro") == 0){
				fprintf(arquivo, "	LLVMValueRef %s = LLVMBuildAlloca(builder, LLVMInt64Type(), \"%s\");\n	LLVMSetInitializer(%s, LLVMConstInt(LLVMInt64Type(), 0, false));\n	LLVMSetLinkage(%s, LLVMCommonLinkage);\n	LLVMSetAlignment(%s, 16);\n", variaveis -> nome, variaveis -> nome, variaveis -> nome, variaveis -> nome, variaveis -> nome);		
			} else if(compareString(variaveis -> tipo, "flutuante") == 0){
				fprintf(arquivo, "	LLVMValueRef %s = LLVMBuildAlloca(builder, LLVMFloatType(), \"%s\");\n	LLVMSetInitializer(%s, LLVMConstInt(LLVMFloatType(), 0, false));\n	LLVMSetLinkage(%s, LLVMCommonLinkage);\n	LLVMSetAlignment(%s, 16);\n", variaveis -> nome, variaveis -> nome, variaveis -> nome, variaveis -> nome, variaveis -> nome);		
			}
		}
		variaveis = variaveis -> proximo;
	}
}
