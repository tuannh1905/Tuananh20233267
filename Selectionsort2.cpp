#include <iostream>
using namespace std;
void SelectionSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i+1;j < n;j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
int main(){
    int arr[] = {9,5,7,4,3,2,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    SelectionSort(arr,n);
    for(int i = 0; i < n;i++){
        cout<< arr[i] <<" ";
    }
    return 0;
}