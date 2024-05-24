%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "Module/utils.h"
#include "grammer.h"


void yyerror(const char *s, ...);

extern int yylineno;

FILE *yyset_in(FILE *);
%}

%union {
    char *strval;
    int  intval;
}

%token <strval> STRING
%token <intval> NUMBER
%token <intval> ENUM_PROTO

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


%type <strval> outfile
%%

stmt_list: stmt ';'
    | stmt_list stmt ';'
    ;

 /* inject */
stmt:
     | INJECT STRING
       ONTO STRING
       USEKEY STRING
       // IF ENUM_PROTO '[' NUMBER ']'
       // DO ENUM_PROTO '[' NUMBER ']' 
       IF ENUM_PROTO '[' NUMBER ']'
       DO ENUM_PROTO '[' NUMBER ']' 
       ELSE ENUM_PROTO '[' NUMBER ']'
       outfile
 	{ inject_file( $2, $22, $4, $6, $8, $10, $13, $15, $18, $20); } 
       ;

 /* else protocol[offset] */

 /* stega function name*/
 /* default out file */
 outfile: { $$ = "covert.pcap" ;} 
    | OUT STRING { $$ = $2 ;}
    ;

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
    /*
    char* buffer = NULL;
    while( ( buffer = readline("> ")) ){
	add_history(buffer);
	strcat(buffer, "\n");
	yyset_in(fmemopen(buffer, strlen(buffer), "r"));
	yyparse();
        free(buffer);
    }*/
   yyparse();
  
   return 0;
}
