# Chapter 7: Strings

## Q&A

**Q: What is a C string?**
A: A null-terminated array of characters. The `\0` (null terminator) marks the end of the string.

**Q: How many bytes does the string "hello" occupy?**
A: 6 bytes: 'h', 'e', 'l', 'l', 'o', '\0'. The null terminator is always included.

**Q: What's the difference between `char *s = "hello"` and `char s[] = "hello"`?**
A: First is a pointer to a string literal (read-only, in static memory). Second is an array on the stack (mutable, can be modified).

**Q: Why is `gets()` dangerous?**
A: It has no bounds checking. It will write past the end of your buffer if the input is too long, causing buffer overflow (security vulnerability).

**Q: What does `strlen()` return?**
A: The number of characters BEFORE the null terminator. For "hello", it returns 5, not 6.

**Q: What's the difference between `strcpy` and `strcat`?**
A: `strcpy(dest, src)` copies src to dest, overwriting dest. `strcat(dest, src)` appends src to the end of dest (after finding dest's null terminator).

**Q: How much memory do you need to concatenate two strings?**
A: `strlen(str1) + strlen(str2) + 1` bytes (the +1 is for the null terminator).

### Session Insights

**Q: Can you use array syntax when declaring a malloc'd string (e.g., `char str[] = malloc(...)`)?**
A: No. `char str[]` declares an array type, but malloc returns a pointer. You must use `char *str = malloc(...)`.

**Q: What happens if you forget to add spaces between strings when concatenating manually?**
A: Each `strcpy` adds a `\0`, but if you advance the pointer to that `\0` and call `strcpy` again, it overwrites the `\0` with the next string. Result: strings concatenate with no separator. The final `strcpy` adds a `\0`, so it won't crash, but you lose the spaces.

**Q: Why is using pointer arithmetic more efficient than repeated `strcat` calls?**
A: `strcat` must scan from the beginning of the destination string to find the `\0` each time (O(n) per call, O(n²) total). Pointer arithmetic maintains the position, making it O(n) total.

## Cheat-sheet

- `char str[] = "hello"` - mutable array on stack, 6 bytes including `\0`
- `char *str = "hello"` - pointer to read-only string literal in static memory
- `strlen(str)` - returns length WITHOUT null terminator
- `strcpy(dest, src)` - copies src to dest (including `\0`), overwrites dest
- `strcat(dest, src)` - appends src to dest (finds dest's `\0` first)
- `strcmp(s1, s2)` - returns 0 if equal, <0 if s1<s2, >0 if s1>s2
- `strncpy(dest, src, n)` - copies at most n chars, may NOT null-terminate
- `strncat(dest, src, n)` - appends at most n chars, always null-terminates
- Always allocate `strlen(s1) + strlen(s2) + 1` for concatenation
- String literals are immutable - modifying them is undefined behavior
- `printf("%s", str)` - prints string until `\0`
- `scanf("%s", str)` - dangerous without size limit, use `scanf("%99s", str)` instead

## Beej's Notes

**Beej's rule on string literals:** "String literals are stored in read-only memory. If you try to modify one, you might get a segfault, or it might appear to work but cause weird bugs later. Always use `char[]` if you need to modify a string."

**Beej's warning on gets():** "Never use `gets()`. It's been removed from C11 because it's impossible to use safely. Use `fgets()` instead, which lets you specify a maximum length."

**Beej's tip on strlen:** "Remember that `strlen()` has to scan the entire string to count characters. If you're calling it repeatedly in a loop, save the result in a variable instead."

**Beej's caution on strcpy:** "`strcpy()` doesn't check if the destination buffer is large enough. It's your responsibility to ensure you've allocated enough space. Use `strncpy()` if you want bounds checking, but be aware it might not null-terminate."

**Beej's advice on string comparison:** "Never use `==` to compare strings. That compares pointer addresses, not contents. Use `strcmp()` instead."

**Beej's note on null terminator:** "The null terminator is what makes a string a string in C. Without it, functions like `printf` and `strlen` will keep reading memory until they find a `\0`, which could be anywhere (or nowhere, causing a crash)."

**Beej's memory allocation rule:** "When allocating space for a string, always remember the +1 for the null terminator. `malloc(strlen(s))` is a bug - you need `malloc(strlen(s) + 1)`."
