#include <stdio.h>
#include <stdlib.h>

int *generate_range(int min, int max, int step, size_t *sz) {
    int* result = (int*) malloc(*sz * sizeof (int));

    for (int i = 0; i < *sz; ++i) {
        result[i] = min;
        min += step;
    }

    return result;
}

int main(void) {
    size_t sz = 4;

    int* res = generate_range(1, 10, 3, &sz);

    for (int i = 0; i < sz; ++i) {
        printf("%d\n", res[i]);
    }

    return 0;
}
