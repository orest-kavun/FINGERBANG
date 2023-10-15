%{
    #include <stdlib.h>
    #include <stdio.h>
    #include "Node.h"

    Node *make_node(int operation, Node *previous, Node *next);
    void *destroy_node(Node *node);
    int run(Node *node);
    int yylex(void);
    void yyerror(char const *string);
%}

%union{
    Node *node;
}
%token FORWARD REWIND INCREMENT DECREMENT OUTPUT MEMDMP LOOP IN
%type <node> command commands

%%

program:
    commands { run($1); destroy_node($1); putchar('\n'); exit(0); };
commands: 
    command {$$ = $1;}
    | commands command {$$ = make_node(IN, $1, $2);}
command:
      FORWARD {$$ = make_node(FORWARD, NULL, NULL);}
    | REWIND {$$ = make_node(REWIND, NULL, NULL);}
    | INCREMENT {$$ = make_node(INCREMENT, NULL, NULL);}
    | DECREMENT {$$ = make_node(DECREMENT, NULL, NULL);}
    | OUTPUT {$$ = make_node(OUTPUT, NULL, NULL);}
    | MEMDMP {$$ = make_node(MEMDMP, NULL, NULL);}
    | LOOP commands IN {$$ = make_node(LOOP, $2, NULL);}

%%

void yyerror(char const *string) {
    fprintf(stderr, "%s\n", string);
}

#include "cry.c"