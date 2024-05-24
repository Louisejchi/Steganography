%option noyywrap yylineno case-insensitive
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
IF	{ return IF; }
DO	{ return DO; }
ELSE	{ return ELSE; }


 /* numbers */
[0-9]+  { yylval.intval = atoi(yytext); return NUMBER; }

 /* strings */
[_.A-Z]+ { yylval.strval = strdup(yytext); return STRING; }

 /* skip whitespace */
[ \t\n]   

.       { return yytext[0]; } /* return any other character as itself */

%%
