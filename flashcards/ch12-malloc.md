# Chapter 12: Manual Memory Management (malloc/free)

## Q&A

**Q: What is the C equivalent of Java's `new` keyword?**
A: `malloc()` - but unlike Java, you must manually call `free()` to deallocate memory. There is no garbage collector.

**Q: What does malloc return if memory allocation fails?**
A: `NULL`. You must always check for NULL before using the pointer.

**Q: What happens if you forget to call free()?**
A: Memory leak. The memory remains allocated until the program exits. Unlike Java's GC, C will not reclaim it automatically.

**Q: Can you free only part of a malloc'd block?**
A: No. You must free the entire block using the original pointer returned by malloc. Freeing a pointer to the middle of a block is undefined behavior.

**Q: What is a double-free and why is it dangerous?**
A: Calling free() twice on the same pointer. It corrupts malloc's internal data structures and can cause crashes or security vulnerabilities.

**Q: What is a dangling pointer?**
A: A pointer that still points to memory after it has been freed. Dereferencing it is undefined behavior.

### Session Insights

**Q: Can you use array syntax when allocating with malloc (e.g., `int nums[] = malloc(...)`)?**
A: No. `int nums[]` declares an array type, but malloc returns a pointer. You must use `int *nums = malloc(sizeof(int) * n)`.

**Q: Can you use array syntax to access malloc'd memory (e.g., `ptr[i]`)?**
A: Yes. After `int *ptr = malloc(...)`, you can use `ptr[0]`, `ptr[1]`, etc. Array indexing is just syntactic sugar for pointer arithmetic: `ptr[i]` equals `*(ptr + i)`.

**Q: How does free() know how much memory to deallocate when you only pass a pointer?**
A: malloc stores metadata (allocation size) in a hidden header just before the memory block it returns. free() backs up from your pointer to read this header and determine how many bytes to free.

## Cheat-sheet

- `void *malloc(size_t size)` - allocate `size` bytes on the heap, returns pointer or NULL
- `void free(void *ptr)` - deallocate memory previously allocated by malloc
- `void *calloc(size_t count, size_t size)` - allocate and zero-initialize array
- `void *realloc(void *ptr, size_t size)` - resize previously allocated memory
- Always check malloc return value: `if (ptr == NULL) { /* handle error */ }`
- Always free what you malloc: `free(ptr);`
- Set pointer to NULL after freeing: `ptr = NULL;` (prevents double-free)
- `sizeof(type)` gives size in bytes: `malloc(sizeof(int) * 10)` for 10 ints
- malloc returns `void*` - automatically converts to any pointer type in C
- Memory allocated by malloc persists until freed or program exits

## Beej's Notes

**Beej's rule on malloc sizing:** Always use `sizeof(type) * count` rather than hardcoding byte sizes. If `int` changes size on different platforms, your code still works.

**Beej's warning on NULL checks:** "Always check if malloc returns NULL. On modern systems with virtual memory you might not hit this often, but embedded systems or constrained environments will fail, and your program should handle it gracefully."

**Beej's tip on free:** "Calling free(NULL) is explicitly safe and does nothing. You don't need to check `if (ptr != NULL)` before freeing."

**Beej's caution on realloc:** "realloc might move your data to a new location. Never do `ptr = realloc(ptr, new_size)` - if realloc fails and returns NULL, you've lost your original pointer. Use a temporary variable."

**Beej's memory leak advice:** "In small programs that run and exit quickly, memory leaks aren't catastrophic - the OS reclaims everything on exit. But in long-running programs (servers, daemons), leaks accumulate and will eventually exhaust memory."

**Beej's undefined behavior warning:** "Using memory after free (use-after-free) is undefined behavior. The memory might appear to work, might crash immediately, or might corrupt data elsewhere. Never rely on freed memory containing anything meaningful."
