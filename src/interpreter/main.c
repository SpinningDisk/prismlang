#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include "../include/functions.h"
#include "../include/VM.h"

extern int yyparse();

int main(){
	printf("\n>> ");
	yyparse();
	return 0;
}
