# Ch 23 — Pointers II

## Q&A

Q: What does `void *` mean, and what can you do with it?
A: A pointer to memory with no declared type. You can store any pointer in it and pass it around, but you must cast it to a typed pointer before dereferencing.

Q: What is pointer arithmetic, and what unit does it operate in?
A: Adding or subtracting an integer from a pointer moves it by multiples of `sizeof` the pointed-to type, not by bytes.

Q: If `int *p` points to `arr[0]`, what does `p + 3` point to?
A: `arr[3]`. The compiler scales by `sizeof(int)` automatically.

Q: What is the relationship between `arr[i]` and pointer arithmetic?
A: `arr[i]` is exactly equivalent to `*(arr + i)`. The compiler rewrites subscript notation into pointer arithmetic.

Q: What does subtracting two pointers of the same type give you?
A: The number of elements between them (type `ptrdiff_t`). Only valid when both pointers point into the same array (or one past the end).

Q: What is "one past the end" and why is it legal?
A: A pointer to the address just after the last element of an array. It is legal to form (not dereference) and is used as a sentinel in loops.

Q: What does `const int *p` mean vs `int * const p`?
A: `const int *p` — the value pointed to is read-only (pointer itself can change). `int * const p` — the pointer is fixed (value it points to can change).

Q: What does `const int * const p` mean?
A: Both the pointer and the value it points to are read-only.

Q: Can you pass a `T *` where a `const T *` is expected?
A: Yes. Adding `const` is always safe; removing it requires an explicit cast and may be UB if you write through the result.

Q: What is a function pointer, and how do you declare one?
A: A pointer that holds the address of a function. `int (*fp)(int, int)` declares a pointer to a function taking two ints and returning int.

Q: How do you call a function through a pointer?
A: Either `fp(a, b)` or `(*fp)(a, b)` — both are valid.

Q: What is the danger of comparing pointers from different arrays?
A: The result is undefined behavior. Only pointers into the same array (or one past the end) can be compared or subtracted.

## Cheat-sheet

- `void *` holds any pointer; cast before use: `int *p = (int *)vp;`
- pointer arithmetic scales by `sizeof` the pointed-to type automatically
- `arr[i]` ≡ `*(arr + i)` — subscript is syntactic sugar
- `p - q` → `ptrdiff_t` (element count); only valid within the same array
- one-past-the-end pointer: legal to form, illegal to dereference
- `const T *p` — read-only target; `T * const p` — read-only pointer
- `const T * const p` — both read-only
- function pointer declaration: `return_type (*name)(param_types);`
- calling through a function pointer: `fp(args)` or `(*fp)(args)`
- comparing/subtracting pointers across different arrays → UB

## Beej's Notes

- Beej's rule of thumb on `const`: put it in function signatures wherever you don't intend to modify the data — it documents intent and lets the compiler catch mistakes.
- Beej notes that pointer arithmetic is one of C's most powerful features and one of its most dangerous; going out of bounds is UB with no runtime check.
- Beej warns that `void *` is useful for generic code (like `qsort`, `memcpy`) but gives up all type safety — the cast is on you.
- Beej highlights that function pointers enable callbacks and polymorphism in C — the pattern behind `qsort`'s comparator argument.
