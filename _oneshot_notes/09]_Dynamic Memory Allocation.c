// Using  `malloc` , `calloc` , `realloc` , and `free` :-

// 1) malloc (Memory Allocation):

// - Stands for “memory allocation.”
// - Allocates a specified amount of memory on the heap (runtime memory).
// - Syntax: void *malloc(size_t size);
// - Returns a pointer to the allocated memory block or NULL if allocation fails.
// - e.g -->  int *p = (int *)malloc(5 * sizeof(int));      // Allocate memory for 5 integers

//---------------------------------------------------------------------------------------------------------------------------------------

// 2) calloc (Contiguous Allocation)

// - Stands for “contiguous allocation.”
// - Allocates memory for an array of elements, initializing them to zero.
// - Syntax: void *calloc(size_t num_elements, size_t element_size);
// - e.g -->  int *arr = (int *)calloc(10, sizeof(int));         // Allocate memory for 10 integers (initialized to 0)

//---------------------------------------------------------------------------------------------------------------------------------------

// 3) realloc (Reallocate Memory)

// Adjusts the size of an existing memory block.
// Syntax: void *realloc(void *ptr, size_t new_size);
// Returns a pointer to the reallocated memory block
// e.g -->  p = (int *)realloc(p, 10 * sizeof(int));        // Resize the memory block to hold 10 integers

//---------------------------------------------------------------------------------------------------------------------------------------

// 4) free (Deallocate Memory)

// - Releases memory previously allocated using malloc, calloc, or realloc.
// - Syntax: void free(void *ptr);
// e.g -->  free(p);         // Free the allocated memory
