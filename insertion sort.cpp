#include <iostream>
using namespace std;

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int array[n];
    cout<<"Enter the elements to the array : ";
    for(int i=0; i<n; i++){
        cin>>array[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }

    insertionSort(array, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }

    return 0;
}
