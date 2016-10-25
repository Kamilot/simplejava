all: main.cpp lex.yy.cpp classes.cpp rules.tab.cpp
	g++ -std=gnu++11 main.cpp lex.yy.cpp classes.cpp rules.tab.cpp