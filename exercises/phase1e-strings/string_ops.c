#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        return 0;
    }

    if (argc == 2) {
        printf("%s\n", argv[1]);
        return 0;
    }

    int count = argc - 1;
    size_t target_size = count; // all words followed by a space, last one by NULL terminator
    for (int i = 0; i < count; i++) {
        target_size += strlen(argv[i + 1]);
    }

    char *res = malloc(target_size);
    if (res == NULL) {
        fprintf(stderr, "Could not allocate res\n");
        return 1;
    }

    char *dest = res;
    for (int i = 0; i < count; i++) {
        strcpy(dest, argv[i + 1]);
        dest += strlen(argv[i + 1]);
        if (i < count - 1) {
            *dest = ' ';
            dest++;
        }
    }

    printf("%s\n", res);

    free(res);

    return 0;
}
