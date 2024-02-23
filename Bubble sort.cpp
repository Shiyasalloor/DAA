#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int array[n];
    cout<<"Enter the elements to the array : ";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }

    bubbleSort(array, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }

    return 0;
}
