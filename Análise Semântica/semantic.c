#include <stdio.h>
#include <stdlib.h>
#include "semantic.h"

void imprimeErro(){
	if(erroSemantico == true)
		system("cat semantico.txt");
	system("rm semantico.txt");
}