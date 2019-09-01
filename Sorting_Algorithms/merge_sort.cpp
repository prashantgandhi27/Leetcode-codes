#include <iostream>

using namespace std;

void _merge(int *arr, int left,int mid, int right){
    int i=0,j=0,k=0;
    int left_size = mid - left +1;
    int right_size = right - mid;

    int left_array[left_size];
    int right_array[right_size];

    for(i=0; i<left_size; i++)
        left_array[i] = arr[left+i];
    for(i=0; i<right_size; i++)
        right_array[i] = arr[mid+1+i];

    i=0; k = left;

    while(i<left_size && j<right_size){
        if(left_array[i] <= right_array[j])
           {
               arr[k] = left_array[i];
                i++;
                k++;
           }else{
               arr[k] = right_array[j];
                j++;
                k++;
           }
    }

    while(i<left_size){
        arr[k] = left_array[i];
        k++;
        i++;
    }
    while(j<right_size){
        arr[k] = right_array[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int left, int right){
    int mid = 0;
    if(left < right){
        mid = left + (right - left)/2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        _merge(arr, left, mid, right);
    }
}
int main(void){
    int merge_sort_array[] = {3,2,8,5,7,1};
    int n = sizeof(merge_sort_array)/sizeof(merge_sort_array[0]);

    cout << "Unsorted array : ";
    for(int i = 0; i < n; i++)
        cout << merge_sort_array[i] << " ";

    mergeSort(merge_sort_array, 0, n-1);

    cout << endl;
    cout << "Sorted array : ";
    for(int i = 0; i < n; i++)
        cout << merge_sort_array[i] << " ";


    return 0;
}
