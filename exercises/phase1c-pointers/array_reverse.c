#include <stdio.h>

// TODO: implement this function using ONLY pointer arithmetic
// Do NOT use array indexing (arr[i]) anywhere in this function
// Reverse the array in-place
void reverse_array(int *arr, int length) {
    // Your code here
    if (length <= 1) return;
    for (int *a = arr, *b = arr + length - 1, tmp; a < b; a++, b--) {
        tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

int main(void) {
    int nums[] = {10, 20, 30, 40, 50};
    int length = 5;

    printf("Before reverse: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    reverse_array(nums, length);

    printf("After reverse: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
