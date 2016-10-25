#ifndef LEXER_H_INCLUDED
#define LEXER_H_INCLUDED

#include <string>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>

struct State;
struct Field;
struct Method;
struct StatementList;

enum statement_type
{
    ASSIGN,
    IFSTAT,
    WHILESTAT,
    INVOKE,
    RETURNSTAT
};

enum data_type
{
    INTEGER,
    BOOLEAN,
    NONE
};

struct Expression
{
    data_type type;
    int value;
    virtual void eval(std::map<std::string, Field*> &locals, std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods) { }
};

struct ExpressionList
{
    std::vector<Expression*> list;

    void addExpression(Expression* expression)
    {
        list.push_back(expression);
    }
};

struct InvokeExpression: public Expression
{
    std::string name;
    std::string classname;
    ExpressionList *arguments;

    InvokeExpression(char *name, ExpressionList *arguments, char *classname)
    {
        this -> name = name;
        this -> classname = classname;
        this -> arguments = arguments;
    }

    virtual void eval(std::map<std::string, Field*> &locals, std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods);
};

struct LiteralExpression: public Expression
{

    LiteralExpression(data_type type, int value)
    {
        this -> type = type;
        this -> value = value;
    }

    virtual void eval(std::map<std::string, Field*> &locals, std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods);
};

struct VariableExpression: public Expression
{
    std::string name;

    VariableExpression(char *name)
    {
        this -> name = name;
    }

    virtual void eval(std::map<std::string, Field*> &locals, std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods);
};

enum operation_type
{
    IDLE,
    OPPOSITE,
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    MODULE,
    OPAND,
    OPOR,
    NOT,
    EQUAL,
    NOT_EQUAL,
    LESS_EQUAL,
    LESS,
    GREATER,
    GREATER_EQUAL
};

struct OperatorExpression: Expression
{
    operation_type action;
    Expression *left, *right;

    OperatorExpression(operation_type action, Expression *left, Expression *right):
        action(action), left(left), right(right) {};

    virtual void eval(std::map<std::string, Field*> &locals, std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods);
};

struct Statement
{
    statement_type type;

    virtual void execute(State &state, std::map<std::string, Field*> &locals, std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods) {}
};

struct AssignStatement: public Statement
{
    std::string variable;
    Expression *expr;

    AssignStatement(char* name, Expression *expr)
    {
        type = statement_type::ASSIGN;
        variable = name;
        this -> expr = expr;
    }

    virtual void execute(State &state, std::map<std::string, Field*> &locals, std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods);
};

struct IfStatement: public Statement
{
    Expression *condition;
    StatementList *body;
    StatementList *elseBlock;

    IfStatement(Expression *condition, StatementList *body, StatementList *elseBlock):
        condition(condition), body(body), elseBlock(elseBlock)
    {
        type = statement_type::IFSTAT;
    }

    virtual void execute(State &state, std::map<std::string, Field*> &locals, std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods);
};

struct WhileStatement: public Statement
{
    Expression *condition;
    StatementList *body;

    WhileStatement(Expression *condition, StatementList *body):
        condition(condition), body(body)
    {
        type = statement_type::WHILESTAT;
    }

    virtual void execute(State &state, std::map<std::string, Field*> &locals, std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods);
};

struct InvokeStatement: public Statement
{
    Expression *invokation;

    InvokeStatement(Expression *invokation):
        invokation(invokation)
    {
        type = statement_type::INVOKE;
    }

    virtual void execute(State &state, std::map<std::string, Field*> &locals, std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods);
};

struct ReturnStatement: public Statement
{
    Expression *result;

    ReturnStatement(Expression *result):
        result(result)
    {
        type = statement_type::RETURNSTAT;
    }

    virtual void execute(State &state, std::map<std::string, Field*> &locals, std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods);
};

struct StatementList
{
    std::vector<Statement*> statements;

    void addStatement(Statement* statement)
    {
        statements.push_back(statement);
    }
};

struct Field
{
    std::string name;
    data_type type;
    int value;

    Field(data_type type, char* name)
    {
        if (type == data_type::NONE)
        {
            fprintf(stderr, "Field of void type");
            exit(-1);
        }
        this -> type = type;
        this -> name = name;
        value = 0;
    }

    Field(Field* other)
    {
        this -> type = other -> type;
        this -> name = other -> name;
        this -> value = other -> value;
    }
};

struct Variables
{
    std::vector<Field*> vars;

    Variables() {};
    void addField(Field *field)
    {
        vars.push_back(field);
    }
};

struct MethodBody
{
    Variables* vars;
    StatementList *statements;

    MethodBody(Variables* vars, StatementList *statements)
    {
        this -> vars = vars;
        this -> statements = statements;
    }
};

struct Method
{
    std::string name;
    Variables* arguments;
    Variables* localdeclaration;
    StatementList *commands;
    data_type returntype;

    Method() {}
    Method(char* name, Variables *arguments, MethodBody *body, data_type returntype);
    virtual int invoke(std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods, Variables *input);
};

struct readIntMethod: Method
{
    readIntMethod()
    {
        name = "readInt";
        returntype = data_type::INTEGER;
    }

    virtual int invoke(std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods, Variables *input);
};

struct readBoolMethod: Method
{
    readBoolMethod()
    {
        name = "readBool";
        returntype = data_type::BOOLEAN;
    }

    virtual int invoke(std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods, Variables *input);
};

struct writeMethod: Method
{
    writeMethod()
    {
        name = "write";
        returntype = data_type::NONE;
    }

    virtual int invoke(std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods, Variables *input);
};

struct FieldMethodList
{
    std::map<std::string, Method*> methods;
    std::map<std::string, Field*> fields;

    void addMethod(Method* method);
    void addField(Field* field);
};

struct Executable
{
    FieldMethodList* list;
    std::string name;

    Executable(FieldMethodList* list, char* name):
        list(list)
    {
        this -> name = name;
    };

    void run();
};

struct State
{
    Method* currentMethod;
    int returnvalue;
    bool returnflag;

    State(Method *currentMethod, int returnvalue, bool returnflag):
        currentMethod(currentMethod), returnvalue(returnvalue), returnflag(returnflag) {}
};

extern Executable *executable;

#include "rules.tab.h"

int yylex();
int yyparse();
void yyerror(std::string s);

#endif // LEXER_H_INCLUDED
