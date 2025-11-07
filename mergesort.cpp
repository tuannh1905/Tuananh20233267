#include <iostream>
using namespace std;
void mergeArray(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int arr1[n1], arr2[n2];
    //divide
    for(int i = 0; i < n1; i++){
        arr1[i] = arr[left + i];
    }
    for(int j = 0; j < n2; j++){
        arr2[j] = arr[mid + 1 + j];
    }
    //merge
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]) arr[k++] = arr1[i++];
        else arr[k++] = arr2[j++];
    }
    while(i < n1) arr[k++] = arr1[i++];
    while(j < n2) arr[k++] = arr2[j++];
}
void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        mergeArray(arr, left, mid, right);
    }
}
int main(){
    int arr[] = {8,9,5,6,1,2,4,3,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr,0,n - 1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}

