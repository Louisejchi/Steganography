%option noyywrap nodefault yylineno case-insensitive
/* nodefault */
%{
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "main.tab.h"
%}

%%

  /* keyword */
SELECT  { return SELECT; }
FROM    { return FROM; }
INTO    { return INTO; }

INJECT  { return INJECT; }
ONTO    { return ONTO; }
USEKEY  { return USEKEY; }
PROTO   { return PROTO; }
WITH    { return WITH; }
OUT     { return OUT; }

\n      { return EOL; }

  /* strings */
[_.A-Z0-9]+ { yylval.strval = strdup(yytext); return STRING; }

%%
