%{
    #include "lexer.h"
    #include <string>
%}

%union {
	Expression *expression;
    Statement *statement;
    StatementList *statementList;
    Method *method;
    Field *field;
    FieldMethodList *methodList;
    MethodBody *methodBody;
    Variables *variables;
    ExpressionList *passedArguments;

	int value;
	char* name;
	data_type type;
};

%left AND OR
%nonassoc '!'
%left LE GE '<' '>' EQ NE
%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS UPLUS

%token <value> NUMERAL
%token <value> BOOL
%token <name> NAME
%token STRING PUBLIC CLASS STATIC VOID INTTYPE BOOLTYPE IF ELSE WHILE RETURN READINT READBOOL WRITE AND OR LE GE EQ NE MAIN

%type <methodList> field_method_list_init
%type <method> main_method
%type <methodList> field_method_list
%type <methodBody> method_body
%type <method> method_declaration
%type <field> field_declaration
%type <type> typename
%type <variables> arguments_or_empty
%type <variables> arguments
%type <field> argument
%type <variables> localvars
%type <statementList> statement_list
%type <field> localvar
%type <statement> statement
%type <statement> assign_statement
%type <statement> if_statement
%type <statement> while_statement
%type <statement> invoke_statement
%type <statement> return_statement
%type <statementList> else_block
%type <expression> expression
%type <expression> invoke_expression
%type <passedArguments> passed_arguments
%type <passedArguments> passed_arguments_or_empty
%type <expression> literal_expression
%type <expression> variable_expression
%type <expression> unary_expression
%type <expression> binary_expression

%%
class
	: PUBLIC CLASS NAME '{' field_method_list_init '}' {executable = new Executable($5, $3);}
	;
field_method_list_init
    : main_method field_method_list {$2->addMethod($1); $$ = $2; }
    ;
main_method
    : PUBLIC STATIC VOID MAIN '(' STRING '[' ']' NAME ')' '{' method_body '}' {$$ = new Method("main", new Variables(), $12, data_type::NONE);}
    ;
field_method_list
    : field_declaration field_method_list {$2->addField($1); $$ = $2;}
    | method_declaration field_method_list {$2->addMethod($1); $$ = $2;}
    | /* epsilon */ {$$ = new FieldMethodList();}
    ;
field_declaration
    : STATIC typename NAME ';' { $$ = new Field($2, $3);}
    ;
typename
    : BOOLTYPE {$$ = data_type::BOOLEAN;}
    | INTTYPE {$$ = data_type::INTEGER;}
    | VOID {$$ = data_type::NONE;}
    ;
method_declaration
    : STATIC typename NAME '(' arguments_or_empty ')' '{' method_body '}' {$$ = new Method($3, $5, $8, $2);}
    ;
arguments_or_empty
    : arguments { $$ = $1;}
    | /*epsilon*/ { $$ = new Variables(); }
    ;
arguments
    : argument ',' arguments { $3->addField($1); $$ = $3; }
    | argument { $$ = new Variables(); $$ -> addField($1); }
    ;
argument
	: typename NAME {$$ = new Field($1, $2);}
	;
method_body
    : localvars statement_list { $$ = new MethodBody($1, $2); }
    ;
localvars
	: localvar localvars {$2 -> addField($1); $$ = $2;}
	| /* epsilon */ {$$ = new Variables();}
	;
localvar
    : typename NAME ';' {$$ = new Field($1, $2);}
    ;
statement_list
	: statement statement_list {$2 -> addStatement($1); $$ = $2;}
	| /* epsilon */ {$$ = new StatementList();}
	;
statement
    : assign_statement {$$ = $1;}
    | if_statement {$$ = $1;}
    | while_statement {$$ = $1;}
    | invoke_statement {$$ = $1;}
    | return_statement {$$ = $1;}
    ;
assign_statement
    : NAME '=' expression ';' {$$ = new AssignStatement($1, $3);}
    ;
if_statement
    : IF '(' expression ')' '{' statement_list '}' else_block {$$ = new IfStatement($3, $6, $8);}
    ;
else_block
    : ELSE '{' statement_list '}' {$$ = $3;}
    | /* epsilon */ {$$ = new StatementList();}
    ;
while_statement
    : WHILE '(' expression ')' '{' statement_list '}' {$$ = new WhileStatement($3, $6);}
    ;
invoke_statement
    : invoke_expression ';' {$$ = new InvokeStatement($1);}
    ;
return_statement
    : RETURN expression ';' {$$ = new ReturnStatement($2);}
    ;
invoke_expression
    : NAME '.' NAME '(' passed_arguments_or_empty ')' {$$ = new InvokeExpression($3, $5, $1);}
    | NAME '(' passed_arguments_or_empty ')' {$$ = new InvokeExpression($1, $3, "");}
    | WRITE '(' passed_arguments_or_empty ')' {$$ = new InvokeExpression("write", $3, "");}
    | READINT '(' passed_arguments_or_empty ')' {$$ = new InvokeExpression("readInt", $3, "");}
    | READBOOL '(' passed_arguments_or_empty ')' {$$ = new InvokeExpression("readBool", $3, "");}
    ;
passed_arguments_or_empty
    : passed_arguments {$$ = $1;}
    | /*epsilon*/ {$$ = new ExpressionList();}
    ;
passed_arguments
    : expression ',' passed_arguments {$3 -> addExpression($1); $$ = $3;}
    | expression {$$ = new ExpressionList(); $$ -> addExpression($1);}
    ;
expression
    : invoke_expression {$$ = $1;}
    | literal_expression {$$ = $1;}
    | variable_expression {$$ = $1;}
    | '(' expression ')' {$$ = $2;}
    | unary_expression {$$ = $1;}
    | binary_expression {$$ = $1;}
    ;
literal_expression
    : BOOL {$$ = new LiteralExpression(data_type::BOOLEAN, $1);}
    | NUMERAL {$$ = new LiteralExpression(data_type::INTEGER, $1);}
    ;
variable_expression
    : NAME {$$ = new VariableExpression($1);}
    ;
unary_expression
    : '-' expression %prec UMINUS {$$ = new OperatorExpression(operation_type::OPPOSITE, $2, NULL);}
    | '+' expression %prec UPLUS {$$ = new OperatorExpression(operation_type::IDLE, $2, NULL);}
    | '!' expression {$$ = new OperatorExpression(operation_type::NOT, $2, NULL);}
    ;
binary_expression
    : expression '+' expression {$$ = new OperatorExpression(operation_type::ADD, $1, $3);}
    | expression '-' expression {$$ = new OperatorExpression(operation_type::SUBTRACT, $1, $3);}
    | expression '/' expression {$$ = new OperatorExpression(operation_type::DIVIDE, $1, $3);}
    | expression '*' expression {$$ = new OperatorExpression(operation_type::MULTIPLY, $1, $3);}
    | expression '%' expression {$$ = new OperatorExpression(operation_type::MODULE, $1, $3);}
    | expression AND expression {$$ = new OperatorExpression(operation_type::OPAND, $1, $3);}
    | expression OR expression {$$ = new OperatorExpression(operation_type::OPOR, $1, $3);}
    | expression EQ expression {$$ = new OperatorExpression(operation_type::EQUAL, $1, $3);}
    | expression NE expression {$$ = new OperatorExpression(operation_type::NOT_EQUAL, $1, $3);}
    | expression LE expression {$$ = new OperatorExpression(operation_type::LESS_EQUAL, $1, $3);}
    | expression '<' expression {$$ = new OperatorExpression(operation_type::LESS, $1, $3);}
    | expression GE expression {$$ = new OperatorExpression(operation_type::GREATER_EQUAL, $1, $3);}
    | expression '>' expression {$$ = new OperatorExpression(operation_type::GREATER, $1, $3);}
%%
