#include <stdlib.h>

#include "sort.h"
#include "util.h"

#define THRESHOLD 32

void insertion_sort(int arr[], int low, int high)
{
    /*
    Move elements of arr[0..i-1], that are greater than key,
    to one position ahead of their current position
    */
    for (int i = low + 1; i < high; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


void merge_sort(int arr[], int low, int high)
{
    if (high - low <= 1) return;
    int mid = low + (high - low) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid, high);
    merge(arr, low, mid, high);
}

void merge_sort_2(int arr[], int low, int high)
{
    if (high - low <= THRESHOLD) {
        insertion_sort(arr, low, high);
        return;
    }

    int mid = low + (high - low) / 2;
    merge_sort_2(arr, low, mid);
    merge_sort_2(arr, mid, high);
    merge(arr, low, mid, high);
}

void merge_sort_3(int arr[], int low, int high)
{
    if (high - low <= THRESHOLD) {
        insertion_sort(arr, low, high);
        return;
    }

    int mid = low + (high - low) / 2;
    merge_sort_3(arr, low, mid);
    merge_sort_3(arr, mid, high);

    if (arr[mid - 1] > arr[mid]) {
        merge(arr, low, mid, high);
    }
}

void merge(int arr[], int low, int mid, int high)
{
    /*
    Merges two subarrays of arr[].
    1st: arr[l..m]
    2nd: arr[m+1..r]
    */
    int n1 = mid - low;
    int n2 = high - mid;

    int* left = (int*)malloc(sizeof(int) * n1);
    int* right = (int*)malloc(sizeof(int) * n2);

    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + j];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    free(left);
    free(right);
}



void quick_sort(int arr[], int low, int high)
{
    if (low < high - 1) {
        int p = partition(arr, low, high);
        quick_sort(arr, low, p);
        quick_sort(arr, p + 1, high);
    }
}


int partition(int arr[], int low, int high)
{
    int pivot_index = low + rand() % (high - low);
    swap(&arr[pivot_index], &arr[high - 1]); // fixing segfault...
    int pivot = arr[high - 1];
    int i = low - 1;
    for (int j = low; j < high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high - 1]);
    return i + 1;
}
