/* Selection sort:
*
*/

#include <iostream>

using namespace std;

int main(void){
    int arr[] = {3,2,8,5,7,1};
    unsigned int n = sizeof(arr)/sizeof(arr[0]);
    unsigned int i=0,j=0,small=0;
    int temp=0;

    for(i=0; i<(n-1) ;i++){
        small = i;
        for(j=i+1; j<n; j++){
            if(arr[j] < arr[small]){
                small = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[small];
        arr[small] = temp;
    }

    for(int p=0; p<n; p++)
        cout << arr[p] << endl;


    return 0;
}
