#ifndef GENERATE_H
#define	GENERATE_H

#include <llvm-c/Core.h>
#include <llvm-c/BitWriter.h>
#include "lista.h"

//void codigoIRInicializacaoGlobais(LLVMContextRef, LLVMModuleRef, LLVMBuilderRef, ListaInicializacao*);
void codigoIRFuncao(LLVMContextRef, LLVMModuleRef, LLVMBuilderRef, NoFuncao*, ListaVariaveis*, ListaVariaveis*, ListaInicializacao*);
void codigoIRGlobais(LLVMContextRef, LLVMModuleRef, LLVMBuilderRef, ListaVariaveis*, ListaInicializacao*);

#endif/* GENERATE_H */