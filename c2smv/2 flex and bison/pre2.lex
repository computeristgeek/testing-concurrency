%{
#include <iostream>
using namespace std;
#define YY_DECL extern "C" {int yylex(void);}
%}
%%
[a-zA-Z0-9 ]{4}: { cout<<"Found a type name:"<<yytext<<endl;} 
[0-9]+\.[0-9]+  { cout<<"Found a floating-point number:"<<yytext<<endl; }
[0-9]+          { cout<<"Found an integer:"<<yytext<<endl; }
[a-zA-Z0-9]+    { cout<<"Found a string: "<<yytext<<endl; }
%%
int main(int argc, char** argv) {
	yylex();
}
