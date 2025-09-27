#ifndef UTIL_H
#define UTIL_H

void swap(int *x, int *y);
void shuffle(int arr[], int low, int high);
void random_swap(int arr[], int low, int high);
int* generate_array(int size);
int* generate_random_array(int size);
int* generate_partial_random_array1(int size, double ratio);
int* generate_partial_random_array2(int size, double ratio);
int is_sorted(int arr[], int size);


#endif //UTIL_H
