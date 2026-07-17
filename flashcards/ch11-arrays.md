# Ch 11 — Arrays

## Q&A

Q: What does an array name evaluate to in most expressions?
A: A pointer to its first element. `arr` is equivalent to `&arr[0]`.

Q: What is array decay?
A: The automatic conversion of an array to a pointer to its first element when used in an expression. The array "decays" — you lose size information.

Q: What does `arr[i]` mean in terms of pointer arithmetic?
A: It is exactly equivalent to `*(arr + i)`.

Q: Can you use pointer arithmetic to walk an array?
A: Yes. `ptr++` advances the pointer by `sizeof(*ptr)` bytes, moving to the next element.

Q: What happens if you access `arr[i]` where `i` is out of bounds?
A: Undefined behavior. C does not bounds-check arrays.

Q: How do you pass an array to a function?
A: As a pointer to its first element. The function receives `int *arr` or `int arr[]` — they are identical. Size must be passed separately.

Q: What is the difference between `sizeof(arr)` inside vs outside the function that declared it?
A: Inside the declaring scope, `sizeof(arr)` gives the full array size in bytes. Once passed to a function (decayed to pointer), `sizeof` gives the pointer size, not the array size.

## Cheat-sheet

- `int arr[5]` — array of 5 ints on the stack; size fixed at compile time
- `arr` decays to `int *` pointing to `arr[0]` in most contexts
- `arr[i]` ≡ `*(arr + i)` — indexing is pointer arithmetic
- `ptr + 1` advances by `sizeof(*ptr)` bytes, not 1 byte
- no bounds checking — out-of-bounds access is UB
- pass arrays as `int *arr, int len` — size is never carried with the pointer
- `sizeof(arr)` is only reliable in the scope where arr is declared

## Beej's Notes

- Beej emphasizes that arrays and pointers are not the same thing, but arrays decay to pointers so freely that they behave similarly in most code.
- Beej warns that losing the array size on decay is a common source of bugs — always pass the length explicitly.
- Beej notes that `arr[i]` and `*(arr + i)` are interchangeable by definition in the C spec; some programmers use the pointer form deliberately to make arithmetic intent explicit.
