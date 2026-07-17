#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;                       // size of the left subarray
    int n2 = right - mid;                          // size of the right subarray

    int* L = new int[n1];                          // create left subarray
    int* R = new int[n2];                          // create right subarray

    for (int i = 0; i < n1; i++)                   // copy data to left subarray
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)                   // copy data to right subarray
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;                    // initial indexes of subarrays and merged array

    while (i < n1 && j < n2) {                     // merge the subarrays back into arr
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {                               // copy remaining elements of L[], if any
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {                               // copy remaining elements of R[], if any
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;                                    // free memory allocated for subarrays
    delete[] R;
}

void mergeSort(int arr[], int left, int right){
    if (left < right) {
        int mid = left + (right - left) / 2;       // find the middle point
        mergeSort(arr, left, mid);                 // sort first half
        mergeSort(arr, mid + 1, right);            // sort second half
        merge(arr, left, mid, right);              // merge the sorted halves
    }
}

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);   // calculate the number of elements in the array

    cout << "Original array: ";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);               // sort the array using merge sort

    cout << "Sorted array: ";
    printArray(arr, arr_size);

    return 0;
}