#include <iostream>
using namespace std;

int linearSearch(const int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
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
    int k;
    cout<<"Enter the target element : ";
    cin>>k;

    int result = linearSearch(array, n, k);

    if (result != -1) {
        cout << "Element " << k << " found at index " << result << "." << endl;
    } else {
        cout << "Element " << k << " not found in the array." << endl;
    }

    return 0;
}
