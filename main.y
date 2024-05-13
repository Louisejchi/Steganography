%{
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

%}

%union {
	char *strval;
}

%token <strval> PROTO
%token <strval> IP
%token <strval> STRING

%token SELECT
%token FROM
%token INTO
%token INJECT
%token WITH
%token ONTO

%%

expr: IP
    | expr SELECT PROTO { }
    | expr FROM PROTO { }
    | expr INTO PROTO { }
    | expr INJECT PROTO { }
    | expr STRING PROTO { }
    | expr WITH PROTO { }
    | expr ONTO IP { }

%%
