%{
#include "../../build/include/plang.h"

%}

%%
exit\(\)				{return EXIT;}
[0-9]+    { yylval.num = atoi(yytext); return NUMBER; }
\n        { return '\n'; }
[ \t]     { /* ignore whitespace */ }
.         { return yytext[0]; }
%%

int yywrap() {
    return 1;
}

