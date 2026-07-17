# Ch 13 — Scope

## Q&A

Q: What are the four storage durations in C?
A: Automatic (stack, local variables), static (program lifetime), allocated (heap, malloc/free), and thread (thread lifetime).

Q: What is the scope of a variable declared inside a block `{}`?
A: It exists only within that block. It is destroyed when execution leaves the block.

Q: What does the `static` keyword do on a local variable?
A: Changes its storage duration to program lifetime — it persists across function calls. Scope remains local (only visible inside the function).

Q: What does `static` mean on a file-level variable or function?
A: Limits its linkage to the current translation unit — it is not visible to other .c files.

Q: What is shadowing?
A: Declaring a variable in an inner scope with the same name as one in an outer scope. The inner one hides the outer one within its scope.

Q: Where does a variable with file scope (global) live for its entire lifetime?
A: In the data segment (initialized) or BSS segment (zero-initialized). Not on the stack.

Q: What is the default value of a static or global variable?
A: Zero (for numeric types) or NULL (for pointers). Guaranteed by the C spec.

## Cheat-sheet

- block scope: variable lives and dies within its `{}`
- function scope: only labels (`goto` targets) have function scope
- file scope: declared outside any function; visible throughout the translation unit
- `static` on local var → persists across calls, still only visible locally
- `static` on file-level symbol → internal linkage, hidden from other .c files
- `extern` → declares a symbol defined in another translation unit
- globals and statics are zero-initialized; automatic (local) variables are not
- shadowing is legal but dangerous — compiler may warn with `-Wshadow`

## Beej's Notes

- Beej's rule of thumb: prefer the smallest possible scope for every variable — declare it as close to its use as possible.
- Beej warns against over-using globals; they make code hard to reason about because any function can modify them.
- Beej notes that `static` local variables are useful for things like "count how many times this function has been called" but should be used sparingly.
