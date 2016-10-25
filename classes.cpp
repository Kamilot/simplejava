#include "lexer.h"

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <set>
#include <map>

using namespace std;

void FieldMethodList::addField(Field *field)
{
    if (fields.find(field->name) != fields.end() || methods.find(field->name) != methods.end())
    {
        fprintf(stderr, "Field name is already in use\n");
        exit(-1);
    }
    fields.insert(make_pair(field->name, field));
}

void FieldMethodList::addMethod(Method *method)
{
    if (fields.find(method->name) != fields.end() || methods.find(method->name) != methods.end())
    {
        fprintf(stderr, "Method name is already in use\n");
        exit(-1);
    }
    methods.insert(make_pair(method->name, method));
}

Method::Method(char* name, Variables* arguments, MethodBody *body, data_type returntype)
{
    this -> name = name;
    this -> returntype = returntype;
    set<string> fieldNames;
    for (Field* arg : arguments -> vars)
    {
        if (fieldNames.find(arg -> name) != fieldNames.end())
        {
            fprintf(stderr, "Redeclared variable %s\n", arg -> name.c_str());
            exit(-1);
        }
        fieldNames.insert(arg -> name);
    }
    for (Field* var : body -> vars -> vars)
    {
        if (fieldNames.find(var -> name) != fieldNames.end())
        {
            fprintf(stderr, "Redeclared variable %s\n", var -> name.c_str());
            exit(-1);
        }
        fieldNames.insert(var -> name);
    }
    this -> arguments = arguments;
    this -> localdeclaration = body -> vars;
    this -> commands = body -> statements;
}

void Executable::run()
{
    map<string, Field*> &globals = list -> fields;
    map<string, Method*> &methods = list -> methods;
    methods.insert(make_pair("write", new writeMethod()));
    methods.insert(make_pair("readInt", new readIntMethod()));
    methods.insert(make_pair("readBool", new readBoolMethod()));
    auto it = methods.find("main");
    if (it == methods.end())
    {
        fprintf(stderr, "Error: main method not found\n");
        exit(-1);
    }
    Variables* vars = new Variables();
    (*it).second -> invoke(globals, methods, vars);
    delete vars;
}

int Method::invoke(std::map<std::string, Field*> &globals, map<std::string, Method*> &methods, Variables *input)
{
    map<string, Field*> locals;
    if ((input -> vars).size() > (arguments -> vars).size())
    {
        fprintf(stderr, "Too many arguments\n");
        exit(-1);
    }
    if ((input -> vars).size() < (arguments -> vars).size())
    {
        fprintf(stderr, "Too few arguments\n");
        exit(-1);
    }
    for (int i = 0; i < (arguments -> vars).size(); i++)
    {
        Field *current = (input -> vars)[i];
        if (current -> type != (arguments -> vars)[i] -> type)
        {
            fprintf(stderr, "Type mismatch\n");
            exit(-1);
        }
        Field *newLocal = new Field(current);
        newLocal -> name = (arguments -> vars)[i] -> name;
        locals.insert(make_pair(newLocal -> name, newLocal));
    }
    for (Field *field : localdeclaration -> vars)
    {
        Field *newLocal = new Field(field);
        locals.insert(make_pair(field -> name, newLocal));
    }
    State state(this, 0, false);

    for (int i = (int)(commands -> statements.size()) - 1; i >= 0; i--)
    {
        Statement* statement = commands -> statements[i];
        statement -> execute(state, locals, globals, methods);
        if (state.returnflag)
        {
            break;
        }
    }

    for (auto it = locals.begin(); it != locals.end(); it++)
    {
        delete (*it).second;
    }
    locals.clear();
    return state.returnvalue;
}

int readIntMethod::invoke(std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods, Variables *input)
{
    if ((input -> vars).size() > 0)
    {
        fprintf(stderr, "Too many arguments\n");
        exit(-1);
    }
    int value;
    cin >> value;
    return value;
}

int readBoolMethod::invoke(std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods, Variables *input)
{
    if ((input -> vars).size() > 0)
    {
        fprintf(stderr, "Too many arguments\n");
        exit(-1);
    }
    string s;
    cin >> s;
    if (s == "true")
        return 1;
    else if (s == "false")
        return 0;
    else
    {
        fprintf(stderr, "bool should be 'true' or 'false'");
        exit(-1);
    }
}

int writeMethod::invoke(std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods, Variables *input)
{
    if ((input -> vars).size() > 1)
    {
        fprintf(stderr, "Too many arguments\n");
        exit(-1);
    }
    if ((input -> vars).size() < 1)
    {
        fprintf(stderr, "Too few arguments\n");
        exit(-1);
    }
    Field* output = (input -> vars)[0];
    if (output -> type == data_type::INTEGER)
        printf("%d\n", output -> value);
    else
        if (output -> value)
            printf("true\n");
        else
            printf("false\n");
}

void AssignStatement::execute(State &state, std::map<std::string, Field*> &locals, std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods)
{
    Field* current = NULL;
    auto local_it = locals.find(variable);
    if (local_it == locals.end())
    {
        auto global_it = globals.find(variable);
        if (global_it == globals.end())
        {
            fprintf(stderr, "Undefined variable %s\n", variable.c_str());
            exit(-1);
        }
        current = (*global_it).second;
    }
    else
    {
        current = (*local_it).second;
    }

    expr -> eval(locals, globals, methods);
    if (expr -> type != current -> type)
    {
        fprintf(stderr, "Type mismatch\n");
        exit(-1);
    }
    current -> value = expr -> value;
}

void IfStatement::execute(State &state, std::map<std::string, Field*> &locals, std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods)
{
    condition -> eval(locals, globals, methods);
    if (condition -> type != data_type::BOOLEAN)
    {
        fprintf(stderr, "if condition should be bool\n");
        exit(-1);
    }
    StatementList *commands;
    if (condition -> value)
        commands = body;
    else
        commands = elseBlock;

    for (int i = (int)(commands -> statements.size()) - 1; i >= 0; i--)
    {
        Statement* statement = commands -> statements[i];
        statement -> execute(state, locals, globals, methods);
        if (state.returnflag)
            break;
    }
}

void WhileStatement::execute(State &state, std::map<std::string, Field*> &locals, std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods)
{
    condition -> eval(locals, globals, methods);
    if (condition -> type != data_type::BOOLEAN)
    {
        fprintf(stderr, "while condition should be bool\n");
        exit(-1);
    }
    while (condition -> value)
    {
        for (int i = (int)(body -> statements.size()) - 1; i >= 0; i--)
        {
            Statement* statement = body -> statements[i];
            statement -> execute(state, locals, globals, methods);
            if (state.returnflag)
                break;
        }
        if (state.returnflag)
            break;
        condition -> eval(locals, globals, methods);
    }
}

void InvokeStatement::execute(State &state, std::map<std::string, Field*> &locals, std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods)
{
    invokation -> eval(locals, globals, methods);
}

void ReturnStatement::execute(State &state, std::map<std::string, Field*> &locals, std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods)
{
    result -> eval(locals, globals, methods);
    if (result -> type != state.currentMethod -> returntype)
    {
        fprintf(stderr, "return type mismatch\n");
        exit(-1);
    }
    state.returnflag = true;
    state.returnvalue = result -> value;
}

void InvokeExpression::eval(std::map<std::string, Field*> &locals, std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods)
{
    Variables *variables = new Variables();
    for (Expression *expression : arguments -> list)
    {
        expression -> eval(locals, globals, methods);
        Field *field = new Field(expression -> type, "");
        field -> value = expression -> value;
        variables -> addField(field);
    }
    if (classname != "" && classname != executable -> name)
    {
        fprintf(stderr, "Method wasn't found\n");
        exit(-1);
    }
    auto it = methods.find(name);
    if (it == methods.end())
    {
        fprintf(stderr, "Method wasn't found\n");
        exit(-1);
    }
    Method *method = (*it).second;
    value = method -> invoke(globals, methods, variables);
    type = method -> returntype;
    for (Field *field : variables -> vars)
    {
        delete field;
    }
    delete variables;
}

void LiteralExpression::eval(std::map<std::string, Field*> &locals, std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods)
{
    //NOTHING TO DO
}

void VariableExpression::eval(std::map<std::string, Field*> &locals, std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods)
{
    Field* current = NULL;
    auto local_it = locals.find(name);
    if (local_it == locals.end())
    {
        auto global_it = globals.find(name);
        if (global_it == globals.end())
        {
            fprintf(stderr, "Undefined variable %s\n", name.c_str());
            exit(-1);
        }
        current = (*global_it).second;
    }
    else
    {
        current = (*local_it).second;
    }

    value = current -> value;
    type = current -> type;
}

void OperatorExpression::eval(std::map<std::string, Field*> &locals, std::map<std::string, Field*> &globals, std::map<std::string, Method*> &methods)
{
    if (action == operation_type::IDLE)
    {
        left -> eval(locals, globals, methods);
        if (left -> type != data_type::INTEGER)
        {
            fprintf(stderr, "+ can only be applied to INTEGER\n");
            exit(-1);
        }
        value = left -> value;
        type = left -> type;
    }
    else if (action == operation_type::OPPOSITE)
    {
        left -> eval(locals, globals, methods);
        if (left -> type != data_type::INTEGER)
        {
            fprintf(stderr, "- can only be applied to INTEGER\n");
            exit(-1);
        }
        value = -(left -> value);
        type = left -> type;
    }
    else if (action == operation_type::NOT)
    {
        left -> eval(locals, globals, methods);
        if (left -> type != data_type::BOOLEAN)
        {
            fprintf(stderr, "! can only be applied to BOOLEAN\n");
            exit(-1);
        }
        value = 1 - (left -> value);
        type = left -> type;
    }
    else if (action == operation_type::ADD)
    {
        left -> eval(locals, globals, methods);
        right -> eval(locals, globals, methods);
        if (left -> type != data_type::INTEGER)
        {
            fprintf(stderr, "+ can only be applied to INTEGER\n");
            exit(-1);
        }
        if (right -> type != data_type::INTEGER)
        {
            fprintf(stderr, "+ can only be applied to INTEGER\n");
            exit(-1);
        }
        value = (left -> value) + (right -> value);
        type = left -> type;
    }
    else if (action == operation_type::SUBTRACT)
    {
        left -> eval(locals, globals, methods);
        right -> eval(locals, globals, methods);
        if (left -> type != data_type::INTEGER)
        {
            fprintf(stderr, "- can only be applied to INTEGER\n");
            exit(-1);
        }
        if (right -> type != data_type::INTEGER)
        {
            fprintf(stderr, "- can only be applied to INTEGER\n");
            exit(-1);
        }
        value = (left -> value) - (right -> value);
        type = left -> type;
    }
    else if (action == operation_type::MULTIPLY)
    {
        left -> eval(locals, globals, methods);
        right -> eval(locals, globals, methods);
        if (left -> type != data_type::INTEGER)
        {
            fprintf(stderr, "* can only be applied to INTEGER\n");
            exit(-1);
        }
        if (right -> type != data_type::INTEGER)
        {
            fprintf(stderr, "* can only be applied to INTEGER\n");
            exit(-1);
        }
        value = (left -> value) * (right -> value);
        type = left -> type;
    }
    else if (action == operation_type::DIVIDE)
    {
        left -> eval(locals, globals, methods);
        right -> eval(locals, globals, methods);
        if (left -> type != data_type::INTEGER)
        {
            fprintf(stderr, "/ can only be applied to INTEGER\n");
            exit(-1);
        }
        if (right -> type != data_type::INTEGER)
        {
            fprintf(stderr, "/ can only be applied to INTEGER\n");
            exit(-1);
        }
        if (right -> value == 0)
        {
            fprintf(stderr, "division by zero\n");
            exit(-1);
        }
        value = (left -> value) / (right -> value);
        type = left -> type;
    }
    else if (action == operation_type::MODULE)
    {
        left -> eval(locals, globals, methods);
        right -> eval(locals, globals, methods);
        if (left -> type != data_type::INTEGER)
        {
            fprintf(stderr, "%% can only be applied to INTEGER\n");
            exit(-1);
        }
        if (right -> type != data_type::INTEGER)
        {
            fprintf(stderr, "%% can only be applied to INTEGER\n");
            exit(-1);
        }
        if (right -> value == 0)
        {
            fprintf(stderr, "division by zero\n");
            exit(-1);
        }
        value = (left -> value) % (right -> value);
        type = left -> type;
    }
    else if (action == operation_type::OPAND)
    {
        left -> eval(locals, globals, methods);
        if (left -> type != data_type::BOOLEAN)
        {
            fprintf(stderr, "&& can only be applied to BOOLEAN\n");
            exit(-1);
        }
        if (left -> value == 0)
            value = 0;
        else
        {
            right -> eval(locals, globals, methods);
            if (right -> type != data_type::BOOLEAN)
            {
                fprintf(stderr, "&& can only be applied to BOOLEAN\n");
                exit(-1);
            }
            value = (left -> value) && (right -> value);
        }
        type = left -> type;
    }
    else if (action == operation_type::OPOR)
    {
        left -> eval(locals, globals, methods);
        if (left -> type != data_type::BOOLEAN)
        {
            fprintf(stderr, "|| can only be applied to BOOLEAN\n");
            exit(-1);
        }
        if (left -> value == 1)
            value = 1;
        else
        {
            right -> eval(locals, globals, methods);
            if (right -> type != data_type::BOOLEAN)
            {
                fprintf(stderr, "|| can only be applied to BOOLEAN\n");
                exit(-1);
            }
            value = (left -> value) || (right -> value);
        }
        type = left -> type;
    }
    else if (action == operation_type::EQUAL)
    {
        left -> eval(locals, globals, methods);
        right -> eval(locals, globals, methods);
        if (left -> type == data_type::NONE || right -> type == data_type::NONE)
        {
            fprintf(stderr, "Can't compare VOID\n");
            exit(-1);
        }
        if (left -> type != right -> type)
        {
            fprintf(stderr, "sides have different type\n");
            exit(-1);
        }
        value = (left -> value) == (right -> value);
        type = data_type::BOOLEAN;
    }
    else if (action == operation_type::NOT_EQUAL)
    {
        left -> eval(locals, globals, methods);
        right -> eval(locals, globals, methods);
        if (left -> type == data_type::NONE || right -> type == data_type::NONE)
        {
            fprintf(stderr, "Can't compare VOID\n");
            exit(-1);
        }
        if (left -> type != right -> type)
        {
            fprintf(stderr, "sides have different type\n");
            exit(-1);
        }
        value = (left -> value) != (right -> value);
        type = data_type::BOOLEAN;
    }
    else if (action == operation_type::LESS_EQUAL)
    {
        left -> eval(locals, globals, methods);
        right -> eval(locals, globals, methods);
        if (left -> type != data_type::INTEGER || right -> type != data_type::INTEGER)
        {
            fprintf(stderr, "<= only for INTEGER\n");
            exit(-1);
        }
        value = (left -> value) <= (right -> value);
        type = data_type::BOOLEAN;
    }
    else if (action == operation_type::LESS)
    {
        left -> eval(locals, globals, methods);
        right -> eval(locals, globals, methods);
        if (left -> type != data_type::INTEGER || right -> type != data_type::INTEGER)
        {
            fprintf(stderr, "< only for INTEGER\n");
            exit(-1);
        }
        value = (left -> value) < (right -> value);
        type = data_type::BOOLEAN;
    }
    else if (action == operation_type::GREATER_EQUAL)
    {
        left -> eval(locals, globals, methods);
        right -> eval(locals, globals, methods);
        if (left -> type != data_type::INTEGER || right -> type != data_type::INTEGER)
        {
            fprintf(stderr, ">= only for INTEGER\n");
            exit(-1);
        }
        value = (left -> value) >= (right -> value);
        type = data_type::BOOLEAN;
    }
    else if (action == operation_type::GREATER)
    {
        left -> eval(locals, globals, methods);
        right -> eval(locals, globals, methods);
        if (left -> type != data_type::INTEGER || right -> type != data_type::INTEGER)
        {
            fprintf(stderr, "> only for INTEGER\n");
            exit(-1);
        }
        value = (left -> value) > (right -> value);
        type = data_type::BOOLEAN;
    }
}




