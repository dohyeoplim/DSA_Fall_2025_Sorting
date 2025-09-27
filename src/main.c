#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util.h"
#include "sort.h"

const int MAX_ITER = 20;
const int SIZE = 10000;
const double RATIO = 0.25;


int main(void)
{
    double random_time = 0.0;
    double partial_random1_time = 0.0;
    double partial_random2_time = 0.0;

    for (int i = 0; i < MAX_ITER; i++) {
        // Generate random array
        int *random_array = generate_random_array(SIZE);
        int *partial_random_array1 = generate_partial_random_array1(SIZE, RATIO);
        int *partial_random_array2 = generate_partial_random_array2(SIZE, RATIO);

        // Sort random array
        clock_t random_t0 = clock();
        insertion_sort(random_array, 0, SIZE);
        clock_t random_t1 = clock();
        random_time += (double)(random_t1 - random_t0) / CLOCKS_PER_SEC;

        if (is_sorted(random_array, SIZE) == 0)
            printf("    ---- Fail to sort random array (%d / %d)\n", i + 1, MAX_ITER);

        // Sort partial random array 1
        clock_t partial_random1_t0 = clock();
        insertion_sort(partial_random_array1, 0, SIZE);
        clock_t partial_random1_t1 = clock();
        partial_random1_time += (double)(partial_random1_t1 - partial_random1_t0) / CLOCKS_PER_SEC;

        if (is_sorted(partial_random_array1, SIZE) == 0)
            printf("    ---- Fail to sort random array (%d / %d)\n", i + 1, MAX_ITER);

        // Sort partial random array 2
        clock_t partial_random2_t0 = clock();
        insertion_sort(partial_random_array2, 0, SIZE);
        clock_t partial_random2_t1 = clock();
        partial_random2_time += (double)(partial_random2_t1 - partial_random2_t0) / CLOCKS_PER_SEC;

        if (is_sorted(partial_random_array2, SIZE) == 0)
            printf("    ---- Fail to sort random array (%d / %d)\n", i + 1, MAX_ITER);

        // Delete random array
        free(random_array);
        free(partial_random_array1);
        free(partial_random_array2);
    }
    random_time /= MAX_ITER;
    partial_random1_time /= MAX_ITER;
    partial_random2_time /= MAX_ITER;

    printf("Insertion Sort:\n");
    printf("    Maximum iteration: %d\n", MAX_ITER);
    printf("    Array size: %d\n", SIZE);
    printf("    Random ratio: %.4f\n", RATIO);
    printf("    Average execution time on random array: %.8f sec \n", random_time);
    printf("    Average execution time on partial random array1: %.8f sec \n", partial_random1_time);
    printf("    Average execution time on partial random array2: %.8f sec \n\n", partial_random2_time);

    return 0;
}
