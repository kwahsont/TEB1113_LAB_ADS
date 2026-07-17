#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++){                // iterate through the unsorted part of the array. index 0 is considered sorted, so we start from index 1
        int key = arr[i];                       // the value to be inserted into the sorted part of the array         
        int j = i - 1;                          // the index of the last element in the sorted part of the array     

        while (j >= 0 && arr[j] > key){         // shift elements of the sorted part of the array to the right to make space for the key. 
            arr[j + 1] = arr[j];                // shift the element to the right
            j--;
        }
        arr[j + 1] = key;                       // insert the key into the correct position in the sorted part of the array
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    printArray(arr, n);
    insertionSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;   
}