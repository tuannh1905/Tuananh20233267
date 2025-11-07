#include <iostream>
using namespace std;
void BubbleSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        bool swapped = false;
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        while(!swapped) break;
    }
}
int main(){
    int arr[] = {9,5,7,2,4,6,1,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    BubbleSort(arr,n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}
