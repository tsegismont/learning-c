#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Print every element of arr (length n) using a format string. */
void print_array(const int *arr, int n) {
    printf("The array contains {");
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(",");
        printf("%d", arr[i]);
    }
    printf("}\n");
}


/* Comparator for ascending order */
int cmp_asc(const void *a, const void *b) {
    const int *i = a;
    const int *j = b;
    return (*i < *j) ? -1 : ((*i > *j) ? 1 : 0);
}

/* Comparator for descending order */
int cmp_desc(const void *a, const void *b) {
    const int *i = a;
    const int *j = b;
    return (*i < *j) ? 1 : ((*i > *j) ? -1 : 0);
}

void verify(int data[], int n, int (*comp)(const void *, const void *)) {
    int failed = 0;
    for (int i = 0; i < n - 1; i++) {
        if (comp(&data[i], &data[i + 1]) > 0) {
            failed = 1;
            printf("Wrong order at index %d\n", i);
        }
    }
    if (!failed) {
        printf("Order is correct\n");
    }
}

int main(void) {
    int data[] = {5, 2, 8, 1, 9, 8};
    int n = 6;

    qsort(data, n, sizeof(int), cmp_asc);
    print_array(data, n);
    verify(data, n, cmp_asc);
    int tmp[] = {10, 7, 4, 1, 9, 1};
    memcpy(data, tmp, sizeof(data));

    qsort(data, n, sizeof(int), cmp_desc);
    print_array(data, n);
    verify(data, n, cmp_desc);

    return 0;
}
