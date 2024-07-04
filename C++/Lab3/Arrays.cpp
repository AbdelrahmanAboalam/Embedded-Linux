#include <stdio.h>
#include <stdlib.h>

typedef void (*Callback)(int);

int* Array_2D(int** array, int size, int* sizers, Callback callback);
void print_callback(int value);

int main() {
    int r1[] = { 1, 2, 3 };
    int r2[] = { 4, 5 };
    int* array[] = { r1, r2 };
    int sizers[] = { 3, 2 };
    int size = 2;

    Callback callback = &print_callback;

    int* result = Array_2D(array, size, sizers, callback);

    printf("Result array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);

    return 0;
}

int* Array_2D(int** array, int size, int* sizers, Callback callback) {
    int* result = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; ++i) {
        int sum = 0;
        for (int j = 0; j < sizers[i]; ++j) {
            sum += array[i][j];
        }
        callback(sum);
        result[i] = sum;
    }

    return result;
}

void print_callback(int value) {
    printf("Sum: %d\n", value);
}
