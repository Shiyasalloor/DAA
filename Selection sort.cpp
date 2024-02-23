#include <iostream>
using namespace std;

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int array[n];
    cout<<"Enter the elements to array : ";
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    cout << "Original array: ";
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }

    selectionSort(array, n);

    std::cout << "\nSorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }

    return 0;
}
