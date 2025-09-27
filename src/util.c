#include <stdlib.h>
#include "util.h"

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
};


void shuffle(int arr[], int low, int high)
{
    for (int i = low; i < high; i++) {
        int j = low + (rand() % (high - low));
        swap(&arr[i], &arr[j]);
    }
}


void random_swap(int arr[], int size, int n)
{
    for (int k = 0; k < n; k++) {
        int i = rand() % size;
        int j = rand() % size;
        swap(&arr[i], &arr[j]);
    }
}


int* generate_array(int size)
{
    int* arr = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        arr[i] = i;
    return arr;
}


int* generate_random_array(int size)
{
    int* arr = generate_array(size);
    shuffle(arr, 0, size);
    return arr;
}


int* generate_partial_random_array1(int size, double ratio)
{
    int* arr = generate_array(size);
    int n = (int)(size * (1.0 - ratio));
    shuffle(arr, n, size);
    return arr;
}


int* generate_partial_random_array2(int size, double ratio)
{
    int* arr = generate_array(size);
    int n = (int)(size * ratio);
    random_swap(arr, size, n);
    return arr;
}


int is_sorted(int arr[], int size)
{
    int flag = 1;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            flag = 0;
            break;
        }
    }
    return flag;
}
