#include <iostream>

using namespace std;

swap_elements(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, int _size){

    for(unsigned int k = 1; k<_size; k++){
        for(unsigned int i = 0; i<_size-k; i++){
            if(arr[i]>arr[i+1])
                swap_elements(&arr[i],&arr[i+1]);
        }
    }
}

int main(void){
     int arr[] = {100,95,101,200,1,50};
     unsigned int n = sizeof(arr)/sizeof(arr[0]);

     cout << "Unsorted array : ";
     for (unsigned int i=0; i<n; i++)
        cout << arr[i] << " ";

     bubbleSort(arr, n);

     cout << endl;
     cout << "Sorted array : ";
     for (unsigned int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}
