typedef struct Node Node;
struct Node {
    int operation;
    Node *previous;
    Node *next;
};