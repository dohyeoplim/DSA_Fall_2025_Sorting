#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "util.h"
#include "sort.h"

const int MAX_ITER = 20;
// const int SIZE = 10000;
const double RATIO = 0.25;

double benchmark(void (*sort_fn)(int*, int, int), int *arr, int size) {
    clock_t t0 = clock();
    sort_fn(arr, 0, size);
    clock_t t1 = clock();

    if (!is_sorted(arr, size)) {
        printf("    ---- Fail to sort!\n");
    }
    return (double)(t1 - t0) / CLOCKS_PER_SEC;
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: %s <algorithm> <array_size>\n", argv[0]);
        printf("Algorithms: insertion | merge | quick\n");
        return 1;
    }

    char *algo = argv[1];
    int SIZE = atoi(argv[2]);

    void (*sort_fn)(int*, int, int) = NULL;

    if (strcmp(algo, "insertion") == 0) {
        sort_fn = insertion_sort;
    } else if (strcmp(algo, "merge") == 0) {
        sort_fn = merge_sort;
    } else if (strcmp(algo, "quick") == 0) {
        sort_fn = quick_sort;
    } else {
        printf("Unknown algorithm: %s\n", algo);
        return 1;
    }

    double random_time = 0.0;
    double partial_random1_time = 0.0;
    double partial_random2_time = 0.0;

    for (int i = 0; i < MAX_ITER; i++) {
        // Generate arrays
        int *random_array = generate_random_array(SIZE);
        int *partial_random_array1 = generate_partial_random_array1(SIZE, RATIO);
        int *partial_random_array2 = generate_partial_random_array2(SIZE, RATIO);

        // Benchmark each type
        random_time += benchmark(sort_fn, random_array, SIZE);
        partial_random1_time += benchmark(sort_fn, partial_random_array1, SIZE);
        partial_random2_time += benchmark(sort_fn, partial_random_array2, SIZE);

        // Free memory
        free(random_array);
        free(partial_random_array1);
        free(partial_random_array2);
    }

    random_time /= MAX_ITER;
    partial_random1_time /= MAX_ITER;
    partial_random2_time /= MAX_ITER;

    printf("%s Sort:\n", algo);
    printf("    Maximum iteration: %d\n", MAX_ITER);
    printf("    Array size: %d\n", SIZE);
    printf("    Random ratio: %.4f\n", RATIO);
    printf("    Average execution time on random array: %.8f sec\n", random_time);
    printf("    Average execution time on partial random array1: %.8f sec\n", partial_random1_time);
    printf("    Average execution time on partial random array2: %.8f sec\n\n", partial_random2_time);

    return 0;
}
