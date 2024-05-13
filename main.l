%option noyywrap yylineno case-insensitive
/* nodefault */
%{
#include <stdio.h>
#include "main.tab.h"

%}
%%

  /* keyword */
SELECT { return SELECT; }
FROM   { return FROM; }
INTO   { return INTO; }
INJECT { return INJECT; }
WITH   { return WITH; }
ONTO   { return ONTO; }

  /* strings */
[_.a-zA-Z0-9]+ { yylval.strval = str(yytext); return STRING; }


%%
