%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

void yyerror(char *s, ...);

%}

%union {
	char *strval;
    int  intval;
}

%token <strval> STRING
%token <intval> NUMBER

%token SELECT
%token FROM
%token INTO

%token INJECT
%token ONTO
%token USEKEY
%token PROTO
%token WITH
%token OUT
%token EOL

%%

expr:
    | expr SELECT PROTO { }
    | expr FROM PROTO { }
    | expr INTO PROTO { }
    | expr INJECT PROTO { }
    | expr STRING PROTO { }
    | expr WITH PROTO { }

%%

/*void
yyerror(char *s, ...){
    extern yylineno;

    va_list ap;
    va_start(ap, s);

    fprintf(stderr, "%d: error: ", yylineno);
    vfprintf(stderr, s, ap);
    fprintf(stderr, "\n");
}*/

int main(){
    yyparse();
}
