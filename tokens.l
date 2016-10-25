%{
    #include <cstdlib>
    #include <string>
    #include "lexer.h"

    using namespace std;
%}

NAME ([a-zA-Z]+[0-9]*)+
NUMERAL ([1-9][0-9]*)|"0"
BOOLEAN "true"|"false"

%option noyywrap

%%
"{"             return '{'; //printf("opening bracket\n");
"}"             return '}'; //printf("closing bracket\n");
{BOOLEAN}       {
                    yylval.value = (strcmp(yytext, "true") == 0);
                    return BOOL;
                }//printf("bool value\n");
"["             return '['; //printf("[\n");
"]"             return ']'; //printf("]\n");
"String"        return STRING; //printf("string\n");
"public"        return PUBLIC; //printf("public\n");
"class"         return CLASS; //printf("class\n");
"static"        return STATIC; //printf("static\n");
"void"          return VOID; //printf("void\n");
"int"           return INTTYPE; //printf("integer\n");
"boolean"       return BOOLTYPE; //printf("boolean\n");
"("             return '('; //printf("opening bracket\n");
")"             return ')'; //printf("closing bracket\n");
"if"            return IF; //printf("if statement\n");
"else"          return ELSE; //printf("else\n");
"while"         return WHILE; //printf("while\n");
"return"        return RETURN; //printf("return\n");
"readInt"       return READINT; //printf("readInt\n");
"readBool"      return READBOOL; //printf("readBool\n");
"write"         return WRITE; //printf("write\n");
"main"          return MAIN; //printf("main\n");
{NUMERAL}       {
                    yylval.value = atoi(yytext);
                    return NUMERAL;
                } //printf("numeral found\n");
{NAME}          {
                    yylval.name = new char[strlen(yytext) + 1];
                    strcpy(yylval.name, yytext);
                    return NAME;
                } //printf("variable name\n");
"."             return '.'; //printf("dot\n");
","             return ','; //printf("comma\n");
";"             return ';'; //printf("semicolon\n");
"+"             return '+'; //printf("add\n");
"*"             return '*'; //printf("multiply\n");
"&&"            return AND; //printf("and\n");
"||"            return OR; //printf("or\n");
"-"             return '-'; //printf("minus\n");
"/"             return '/'; //printf("devide\n");
"%"             return '%'; //printf("mod\n");
">"             return '>'; //printf("greater\n");
"<"             return '<'; //printf("less\n");
"<="            return LE; //printf("less equal\n");
">="            return GE; //printf("greater equal\n");
"=="            return EQ; //printf("equal\n");
"="             return '='; //printf("assign\n");
"!="            return NE; //printf("not equal\n");
\n              ;/*Nothing*/
" "|"\t"|"\r"   ;/*Nothing*/
.               printf("Unparsed symbol %s\n", yytext); exit(-1);/*Nothing*/
%%
