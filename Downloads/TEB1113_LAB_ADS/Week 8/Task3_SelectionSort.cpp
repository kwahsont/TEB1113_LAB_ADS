#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;                           // assume the minimum is the first element of the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {           // find the index of the minimum element in the unsorted part
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);                // swap the found minimum element with the first element of the unsorted part
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {64, 25, 12, 54, 11};
    int n = sizeof(arr) / sizeof(arr[0]);           // calculate the number of elements in the array
    cout << "Original array: ";
    printArray(arr, n);
    selectionSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);
    
    return 0;
}