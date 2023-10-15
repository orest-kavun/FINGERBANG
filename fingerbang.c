#include <string.h>
#include "settings.c"

int memory_pointer;
int curr_memsize;
char *memory;

void expand_memory() {
    int prev_memsize = curr_memsize;
    curr_memsize *= MEM_GROW_RATE;
    memory = realloc(memory, curr_memsize);
    if (!memory) {
        printf("🔥🔥🔥🔥🔥🔥 Failed to reallocate 🧠 🔥🔥🔥🔥🔥🔥.\n");
        abort();
    }
    // Fill new memory with zeros
    size_t difference = curr_memsize - prev_memsize;
    char *new_start = memory + prev_memsize;
    memset(new_start, 0, difference);

    #ifdef DEBUG
        printf("New 🧠 size is %d, was %d\n", curr_memsize, prev_memsize);
    #endif
}

void forward() {
    memory_pointer++;
    if (memory_pointer >= curr_memsize) { expand_memory(); }
}

void rew() {
    memory_pointer--;
    if (memory_pointer < 0) {
        yyerror("🤦🤦🤦🤦🤦🤦🤦🤦🤦🤦🤦🤦🤦🤦🤦🤦🤦\nYou decremented past the beginning of memory.\n");
        abort();
    }
}

void increment() {
    #ifdef DEBUG
        printf("\nMemory at %d had value %c, ", memory_pointer, memory[memory_pointer]);
    #endif

    memory[memory_pointer]++;

    #ifdef DEBUG
        printf("now it's %c.\n", memory[memory_pointer]);
    #endif
}

void decrement() {
    #ifdef DEBUG
        printf("\nMemory at %d had value %c, ", memory_pointer, memory[memory_pointer]);
    #endif

    memory[memory_pointer]--;

    #ifdef DEBUG
        printf("now it's %c.\n", memory[memory_pointer]);
    #endif
}

void output() {
    putchar(memory[memory_pointer]);
}

void begin_loop(Node *node) {
    while(memory[memory_pointer]) {
        run(node->previous);
    }
    run(node->next);
}

void end_loop(Node *node) {
    run(node->previous);
    run(node->next);
}

void print_memory() {
    printf("\nBEGIN 🧠 DUMP:\n");
    int i;
    for (i = 0; i < curr_memsize; i++) {
        putchar(memory[i]); // printf("%s"...) requires a null-terminated string 
    }
    printf("\nEND 🧠 DUMP.\n");
}

int run(Node *node) {
    if (!node) { return 0;}
    switch(node->operation) {
    case FORWARD:
        forward();
        return 0;
    case REWIND:
        rew();
        return 0;
    case INCREMENT:
        increment();
        return 0;
    case DECREMENT:
        decrement();
        return 0;
    case OUTPUT:
        output();
        return 0;
    case LOOP: 
        begin_loop(node);
        return 0;
    case IN: 
        end_loop(node);
        return 0;
    case MEMDMP: 
        print_memory();
        return 0;
    }
    return -1;
}

int main() {
    memory_pointer = 0;
    curr_memsize = INIT_MEMSIZE;
    memory = calloc(curr_memsize, sizeof(char));
    if (!memory) {
        fprintf(stderr, "🔥🔥🔥 Failed to allocate 🧠! 🔥🔥🔥\n");
        return 1;
    }
    yyparse();
}