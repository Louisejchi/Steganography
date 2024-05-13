%{
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

%}

%union {
	char *strval;
}

%token <strval> RPOTO
%token <strval> IP

%token SELECT
%token FROM
%token INTO
%token INJECT
%token WITH
%token ONTO


