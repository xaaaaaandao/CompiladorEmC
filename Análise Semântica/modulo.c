#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <llvm-c/Core.h>
#include <llvm-c/BitWriter.h>

int main(int argc, char *argv[]) {
 	LLVMContextRef context = LLVMGetGlobalContext();
	LLVMModuleRef module = LLVMModuleCreateWithNameInContext("simples.bc", context);
	LLVMBuilderRef builder = LLVMCreateBuilderInContext(context);

	LLVMTypeRef typea = LLVMArrayType(LLVMFloatType(), 30);
	LLVMValueRef arraya = LLVMAddGlobal (module, typea, "a");
	LLVMSetInitializer(arraya, LLVMConstInt(LLVMInt64Type(), 0, false));
	LLVMSetLinkage(arraya, LLVMCommonLinkage);
	LLVMSetAlignment(arraya, 16);
	LLVMDumpModule(module);
	if (LLVMWriteBitcodeToFile(module, "simples.bc") != 0) {
 		fprintf(stderr, "error writing bitcode to file, skipping");
 	}
}