#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int count;

    printf("How many integers? ");
    scanf("%d", &count);

    if (count <= 0) return 0;

    int *arr = malloc(count * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        printf("int at pos #%d? ", i);
        scanf("%d", arr + i);
    }

    for (int i = 0; i < count; i++) {
        printf("int at pos #%d is %d\n", i, arr[i]);
    }

    free(arr);

    return 0;
}
