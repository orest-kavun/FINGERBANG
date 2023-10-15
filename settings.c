/* Initial memory size.
Intentionally left small to demonstrate how the memory expands. */
#define INIT_MEMSIZE 1 

/* Memory size is multiplied by this number 
every time the memory is increased. */
#define MEM_GROW_RATE 2

/* Prints debug information every time the values in the memory are modified or the memory is expanded. */
#define DEBUG 