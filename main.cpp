#include "lexer.h"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

extern FILE* yyin;

Executable *executable;

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        cerr << "Specify source file" << endl;
        return -1;
    }
    FILE *file;
    if ((file = fopen(argv[1], "r")) == NULL) {
        perror("");
		cerr << "Error: cannot open file\n";
		return -1;
	}
	yyin = file;
	yyparse();
	executable -> run();
    return 0;
}

void yyerror(string s)
{
	cerr << "Parser error: " << s << "\n";
	exit(1);
}
