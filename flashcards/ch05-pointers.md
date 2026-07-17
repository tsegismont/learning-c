# Ch 5 — Pointers

## Q&A

Q: How do you declare a pointer to int?
A: `int *p;`

Q: What does the `&` operator do?
A: Returns the memory address of a variable. `&x` gives the address of x.

Q: What does the `*` operator do when applied to a pointer?
A: Dereferences it — reads or writes the value at the address the pointer holds.

Q: What is an uninitialized pointer?
A: A pointer that has been declared but not assigned an address. Dereferencing it is UB.

Q: What is a dangling pointer?
A: A pointer that holds an address that is no longer valid (e.g. the variable went out of scope or the memory was freed).

Q: What is the safe way to initialize a pointer you're not ready to use yet?
A: Set it to `NULL`. Dereferencing NULL causes a crash (segfault), which is detectable — unlike UB from a garbage address.

Q: What does `*p = 5` do?
A: Writes the value 5 to the memory location that p points to.

Q: What does `int **pp` declare?
A: A pointer to a pointer to int.

## Cheat-sheet

- `int *p` — pointer to int; `*` is part of the type, not a dereference here
- `&x` — address-of x; type is `int *` if x is `int`
- `*p` — dereference p; reads or writes the value at that address
- `p = NULL` — safe "no address" sentinel; always initialize if not assigning immediately
- dereferencing an uninitialized or dangling pointer → UB (no crash guaranteed, silent corruption possible)
- `void *` — pointer with no type; can hold any address; must cast before dereferencing

## Beej's Notes

- Beej's rule of thumb on NULL: always initialize pointers to NULL if you don't have a real address yet — it makes bugs visible instead of silent.
- Beej warns that pointers are one of the hardest parts of C for newcomers; the concept of "address of a thing" vs "the thing itself" must become second nature.
- Beej notes that `*` means different things depending on context: in a declaration it signals the type is a pointer; in an expression it dereferences.
