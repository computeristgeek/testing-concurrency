%{
#include <stdio.h>
%}
%%
[a-zA-Z0-9 ]{4}: { printf("Found a type name:%s",yytext);} 
[0-9]+\.[0-9]+  { printf("Found a floating-point number:%s",yytext); }
[0-9]+          { printf("Found an integer:%s",yytext); }
[a-zA-Z0-9]+    { printf("Found a string: %s",yytext); }
%%
int main(int argc, char** argv) {
	yylex();
}
