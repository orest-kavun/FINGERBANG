#include <stdlib.h>
#include "Node.h"

void yyerror(char const*);

Node *make_node(int operation, Node *previous, Node *next) {
    Node *node = malloc(sizeof(Node));
    if (!node) { yyerror("🔥🔥🔥 Failed to allocate node! 🔥🔥🔥\n");}
    node->operation = operation;
    node->previous = previous;
    node->next = next;
    return node;
}

void destroy_node(Node *node) {
    if (!node) { return; }
    destroy_node(node->previous);
    destroy_node(node->next);
    free(node);
}