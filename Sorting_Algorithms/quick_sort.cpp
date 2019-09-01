#include <iostream>

using namespace std;

swap_elements(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition_quick_sort(int *arr, int low, int high){
    int pivot = arr[high];

    int j = (low-1);

    for(unsigned int i = low; i<=high-1; i++){
        if(arr[i]<pivot){
            j++;
            swap_elements(&arr[j], &arr[i]);
        }
    }
    swap_elements(&arr[j+1], &arr[high]);

    return (j+1);
}

void quickSort(int *arr, int low, int high){
    if(low < high){
        int pivot_index = partition_quick_sort(arr, low, high);

        quickSort(arr, low, pivot_index-1);
        quickSort(arr, pivot_index+1, high);
    }
}

int main(void){

    int arr[] = {3,2,8,5,7,1};
    unsigned int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Unsorted array: ";
    for(unsigned int i =0; i<n; i++ )
        cout << arr[i] << " ";

    quickSort(arr, 0, n-1);

    cout << endl;
    cout << "Sorted array: ";
    for(unsigned int i =0; i<n; i++ )
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
