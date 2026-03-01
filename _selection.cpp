#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    
    for (int i = 0; i < n - 1; i++) {
        int semi_index = i; 

        for (int j = i + 1; j < n; j++) {      
            if (arr[j] < arr[semi_index]) {     
                semi_index = j;               
            }
        }

    
        if (semi_index != i) {                 
            swap(arr[i], arr[semi_index]);      
        }
    }
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    
    selectionSort(arr, n);

   
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }


    return 0;
}

