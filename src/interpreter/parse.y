%{
#include <stdio.h>
#include <stdlib.h>

// Include your VM or interpreter headers here if needed
extern int yylex();
extern void yyerror(const char *s);
%}
%union {
    int num;
	int NONE: 1;
}
%start input
%token <num> NUMBER
%token <NONE> EXIT

%type <num> expression

%%

input:
    | input line
	| line
;

line:
    '\n'                { printf("\e[1;36m>>\e[0m "); }
    | expression '\n'   { /* apply shunting yard */
		printf("\e[1;36m>>\e[0m ");	}
	| EXIT '\n'			{ printf("bye!\n\t:)\n\e[0m"); return 0;}
;

expression:
	  NUMBER              { $$ = $1; }
    | expression '+' expression { $$ = $1 + $3; }
    | expression '-' expression { $$ = $1 - $3; }
    | expression '*' expression { $$ = $1 * $3; }
    | expression '/' expression { if ($3 == 0) yyerror("Division by zero"); else $$ = $1 / $3; }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
