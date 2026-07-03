#include <stdio.h>
#include <string.h>  // for memcpy

// TODO: implement a generic swap function using void pointers
// It should swap 'size' bytes between the two memory locations
// Hint: you'll need a temporary buffer and memcpy
void generic_swap(void *a, void *b, size_t size) {
    unsigned char tmp[size];
    memcpy(tmp, b, size);
    memcpy(b, a, size);
    memcpy(a, tmp, size);
}

int main(void) {
    // Test 1: swap integers
    int x = 42;
    int y = 99;
    printf("Before int swap: x = %d, y = %d\n", x, y);
    generic_swap(&x, &y, sizeof(int));
    printf("After int swap: x = %d, y = %d\n", x, y);

    // Test 2: swap doubles
    double pi = 3.14159;
    double e = 2.71828;
    printf("\nBefore double swap: pi = %.5f, e = %.5f\n", pi, e);
    generic_swap(&pi, &e, sizeof(double));
    printf("After double swap: pi = %.5f, e = %.5f\n", pi, e);

    // Test 3: swap character arrays
    char str1[20] = "Hello";
    char str2[20] = "World";
    printf("\nBefore string swap: str1 = %s, str2 = %s\n", str1, str2);
    generic_swap(str1, str2, 20); // swap the entire buffers
    printf("After string swap: str1 = %s, str2 = %s\n", str1, str2);

    return 0;
}
