#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generate.h"

float existeAtribuicaoFlutuante(char *origem, ListaInicializacao *inicializacao){
    NoInicializacao *auxiliar = inicializacao -> primeiro;
    float valor = 0;
    while(auxiliar != NULL){
        if(compareString(auxiliar -> origem, origem) == 0){
            valor = atof(auxiliar -> destino);
        }
        auxiliar = auxiliar -> proximo;
    }
    return valor;
}

int existeAtribuicaoInteiro(char *origem, ListaInicializacao *inicializacao){
    NoInicializacao *auxiliar = inicializacao -> primeiro;
    int valor = 0;
    while(auxiliar != NULL){
        if(compareString(auxiliar -> origem, origem) == 0){
            valor = atoi(auxiliar -> destino);
        }
        auxiliar = auxiliar -> proximo;
    }
    return valor;
}

void codigoIRVariaveis(LLVMContextRef context, LLVMModuleRef module, LLVMBuilderRef  builder, ListaVariaveis *globais, ListaInicializacao *inicializacao){
    char nomeVariavel[MAX];
    int valor1, valor2;
    NoVariaveis *auxiliar = globais -> primeiro;
    while(auxiliar != NULL){
        memset(nomeVariavel, 0, sizeof(nomeVariavel));
        if(compareString(auxiliar -> tipo, "inteiro") == 0){
            strcpy(nomeVariavel, auxiliar -> nome);
            if(auxiliar -> ehUnidimensional){
                valor1 = atoi(auxiliar -> valor1);
                LLVMTypeRef type = LLVMArrayType(LLVMInt64Type(), valor1);
                LLVMValueRef array =  LLVMBuildArrayAlloca (builder, type, LLVMConstInt(LLVMInt64Type(), 0, false), nomeVariavel);
                LLVMSetAlignment(array, 16);
            } else if(auxiliar -> ehBidimensional){
                valor1 = atoi(auxiliar -> valor1);
                valor2 = atoi(auxiliar -> valor2);
                LLVMTypeRef type_0 = LLVMArrayType(LLVMInt64Type(), valor1);
                LLVMTypeRef type = LLVMArrayType(type_0, valor2);
                LLVMValueRef array =  LLVMBuildArrayAlloca (builder, type, LLVMConstInt(LLVMInt64Type(), 0, false), nomeVariavel);
                LLVMSetAlignment(array, 16);
            } else if((auxiliar -> ehUnidimensional == false) && (auxiliar -> ehBidimensional == false)){
                LLVMValueRef array = LLVMBuildAlloca (builder, LLVMInt64Type(), nomeVariavel);
                LLVMBuildStore(builder, LLVMConstInt(LLVMInt64Type(), existeAtribuicaoInteiro(auxiliar -> nome, inicializacao), false), array);
                LLVMValueRef args[1] = { LLVMBuildLoad(builder, array, "") };
            }
        } else if(compareString(auxiliar -> tipo, "flutuante") == 0){
            strcpy(nomeVariavel, auxiliar -> nome);
            if(auxiliar -> ehUnidimensional){
                valor1 = atoi(auxiliar -> valor1);
                LLVMTypeRef type = LLVMArrayType(LLVMFloatType(), valor1);
                LLVMValueRef array =  LLVMBuildArrayAlloca (builder, type, LLVMConstInt(LLVMFloatType(), 0, false), nomeVariavel);
                LLVMSetAlignment(array, 16);
            } else if(auxiliar -> ehBidimensional){
                valor1 = atoi(auxiliar -> valor1);
                valor2 = atoi(auxiliar -> valor2);
                LLVMTypeRef type_0 = LLVMArrayType(LLVMFloatType(), valor1);
                LLVMTypeRef type = LLVMArrayType(type_0, valor2);
                LLVMValueRef array =  LLVMBuildArrayAlloca (builder, type, LLVMConstInt(LLVMFloatType(), 0, false), nomeVariavel);
                LLVMSetAlignment(array, 16);
            } else if((auxiliar -> ehUnidimensional == false) && (auxiliar -> ehBidimensional == false)){
                LLVMValueRef array = LLVMBuildAlloca (builder, LLVMFloatType(), nomeVariavel);
                LLVMBuildStore(builder, LLVMConstInt(LLVMFloatType(), existeAtribuicaoInteiro(auxiliar -> nome, inicializacao), false), array);
                LLVMValueRef args[1] = { LLVMBuildLoad(builder, array, "") };                
            }
        } 
        auxiliar = auxiliar -> proximo;
    }
}


void codigoIRFuncao(LLVMContextRef context, LLVMModuleRef module, LLVMBuilderRef builder, NoFuncao *nofuncao, ListaVariaveis* variaveisLocais, ListaVariaveis *parametros, ListaInicializacao* inicializacaoLocais){
    if(compareString(nofuncao -> tipo, "inteiro") == 0){
        LLVMValueRef Zero64 = LLVMConstInt(LLVMInt64Type(), 0, false);
        LLVMTypeRef functionReturnType = LLVMInt64TypeInContext(context);
        LLVMValueRef function = LLVMAddFunction(module, nofuncao -> nome, LLVMFunctionType(functionReturnType, NULL, 0, 0));
        
        LLVMBasicBlockRef entryBlock = LLVMAppendBasicBlockInContext(context, function, "entry");
        LLVMBasicBlockRef endBasicBlock = LLVMAppendBasicBlock(function, "end");
        LLVMPositionBuilderAtEnd(builder, entryBlock);

        codigoIRVariaveis(context, module, builder, variaveisLocais, inicializacaoLocais);
        LLVMValueRef returnVal = LLVMBuildAlloca(builder, LLVMInt64Type(), "retorno");
        LLVMBuildStore(builder, Zero64, returnVal);

        LLVMBuildBr(builder, endBasicBlock);
        LLVMPositionBuilderAtEnd(builder, endBasicBlock);
        LLVMBuildRet(builder, LLVMBuildLoad(builder, returnVal, ""));




    } else if(compareString(nofuncao -> tipo, "flutuante") == 0){
        //LLVMTypeRef mainFnReturnType = LLVMFloatTypeInContext(context);
        
        LLVMValueRef Zero64 = LLVMConstInt(LLVMFloatType(), 0, false);
        LLVMTypeRef functionReturnType = LLVMFloatTypeInContext(context);
        LLVMValueRef function = LLVMAddFunction(module, nofuncao -> nome, LLVMFunctionType(functionReturnType, NULL, 0, 0));
        
        LLVMBasicBlockRef entryBlock = LLVMAppendBasicBlockInContext(context, function, "entry");
        LLVMBasicBlockRef endBasicBlock = LLVMAppendBasicBlock(function, "end");
        LLVMPositionBuilderAtEnd(builder, entryBlock);

        codigoIRVariaveis(context, module, builder, variaveisLocais, inicializacaoLocais);
        LLVMValueRef returnVal = LLVMBuildAlloca(builder, LLVMFloatType(), "retorno");
        LLVMBuildStore(builder, Zero64, returnVal);

        LLVMBuildBr(builder, endBasicBlock);
        LLVMPositionBuilderAtEnd(builder, endBasicBlock);
        LLVMBuildRet(builder, LLVMBuildLoad(builder, returnVal, ""));

    } 
}


void codigoIRGlobais(LLVMContextRef context, LLVMModuleRef module, LLVMBuilderRef  builder, ListaVariaveis *globais, ListaInicializacao *inicializacao){
    char nomeVariavel[MAX];
    int valor1, valor2;
    NoVariaveis *auxiliar = globais -> primeiro;
    while(auxiliar != NULL){
        memset(nomeVariavel, 0, sizeof(nomeVariavel));
        if(compareString(auxiliar -> tipo, "inteiro") == 0){
            strcpy(nomeVariavel, auxiliar -> nome);
            if(auxiliar -> ehUnidimensional){
                valor1 = atoi(auxiliar -> valor1);
                LLVMTypeRef type = LLVMArrayType(LLVMInt64Type(), valor1);
                LLVMValueRef array = LLVMAddGlobal(module, type, nomeVariavel);
                LLVMSetInitializer(array, LLVMConstInt(LLVMInt64Type(), 0, false));
                LLVMSetLinkage(array, LLVMCommonLinkage);
                LLVMSetAlignment(array, 16);
            } else if(auxiliar -> ehBidimensional){
                valor1 = atoi(auxiliar -> valor1);
                valor2 = atoi(auxiliar -> valor2);
                LLVMTypeRef type_0 = LLVMArrayType(LLVMInt64Type(), valor1);
                LLVMTypeRef type = LLVMArrayType(type_0, valor2);
                LLVMValueRef array = LLVMAddGlobal(module, type, nomeVariavel);
                LLVMSetInitializer(array, LLVMConstInt(LLVMInt64Type(), 0, false));
                LLVMSetLinkage(array, LLVMCommonLinkage);
                LLVMSetAlignment(array, 16);
            } else if((auxiliar -> ehUnidimensional == false) && (auxiliar -> ehBidimensional == false)){
                LLVMValueRef array = LLVMAddGlobal (module, LLVMInt64Type(), nomeVariavel);
                LLVMSetInitializer(array, LLVMConstInt(LLVMInt64Type(), existeAtribuicaoInteiro(auxiliar -> nome, inicializacao), false));
                LLVMSetLinkage(array, LLVMCommonLinkage);
                LLVMSetAlignment(array, 16);            }
        } else if(compareString(auxiliar -> tipo, "flutuante") == 0){
            strcpy(nomeVariavel, auxiliar -> nome);
            if(auxiliar -> ehUnidimensional){
                valor1 = atoi(auxiliar -> valor1);
                LLVMTypeRef type = LLVMArrayType(LLVMFloatType(), valor1);
                LLVMValueRef array = LLVMAddGlobal(module, type, nomeVariavel);
                LLVMSetInitializer(array, LLVMConstInt(LLVMFloatType(), 0, false));
                LLVMSetLinkage(array, LLVMCommonLinkage);
                LLVMSetAlignment(array, 16);
            } else if(auxiliar -> ehBidimensional){
                valor1 = atoi(auxiliar -> valor1);
                valor2 = atoi(auxiliar -> valor2);
                LLVMTypeRef type_0 = LLVMArrayType(LLVMFloatType(), valor1);
                LLVMTypeRef type = LLVMArrayType(type_0, valor2);
                LLVMValueRef array = LLVMAddGlobal(module, type, nomeVariavel);
                LLVMSetInitializer(array, LLVMConstInt(LLVMFloatType(), 0, false));
                LLVMSetLinkage(array, LLVMCommonLinkage);
                LLVMSetAlignment(array, 16);
            } else if((auxiliar -> ehUnidimensional == false) && (auxiliar -> ehBidimensional == false)){
                LLVMValueRef array = LLVMAddGlobal (module, LLVMFloatType(), nomeVariavel);
                LLVMSetInitializer(array, LLVMConstInt(LLVMFloatType(), existeAtribuicaoFlutuante(auxiliar -> nome, inicializacao), false));
                LLVMSetLinkage(array, LLVMCommonLinkage);
                LLVMSetAlignment(array, 16);
            }
        } 
        auxiliar = auxiliar -> proximo;
    }
}
