%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "Module/utils.h"
#include "grammer.h"


void yyerror(const char *s, ...);

extern int yylineno;

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
%token IF
%token DO
%token ELSE

%%

stmt_list: stmt ';'
    | stmt_list stmt ';'
    ;

 /* inject */
stmt:
     | INJECT STRING
       ONTO STRING
       USEKEY STRING
       IF NUMBER '[' NUMBER ']'
       DO NUMBER '[' NUMBER ']' 
       ELSE NUMBER '[' NUMBER ']'
       OUT STRING
       { inject_file( $2, $23 , $4, $6, $8, $10, $13, $15, $18, $20); } 
       ;

 /* else protocol[offset] */

 /* default out file */
     
%%

void yyerror(const char *s, ...){
    va_list ap;
    va_start(ap, s);

    fprintf(stderr, "%d: error: ", yylineno);
    vfprintf(stderr, s, ap);
    fprintf(stderr, "\n");

    va_end(ap);
}

int main(){
    return yyparse();
    
}
