#include <stdio.h>

/*
 * Apply transform to every element of arr (length n), modifying it in place.
 * transform is a function pointer: takes an int, returns an int.
 */
void apply(int *arr, int n, int (*transform)(int)) {
    for (int i = 0; i < n; i++) {
        arr[i] = transform(arr[i]);
    }
}

/* Print every element of arr (length n). */
void print_array(const int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int double_it(int x) { return x * 2; }
int square(int x)    { return x * x; }

int main(void) {
    int data[] = {1, 2, 3, 4, 5};
    int n = 5;

    apply(data, n, double_it);
    print_array(data, n);  /* expected: 2 4 6 8 10 */

    apply(data, n, square);
    print_array(data, n);  /* expected: 4 16 36 64 100 */

    return 0;
}
