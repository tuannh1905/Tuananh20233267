#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (true) {
        // Tăng i cho đến khi tìm thấy phần tử lớn hơn pivot
        while (i <= high && arr[i] <= pivot) i++;
        // Giảm j cho đến khi tìm thấy phần tử nhỏ hơn pivot
        while (j >= low && arr[j] > pivot) j--;

        // Nếu hai con trỏ đã vượt nhau thì dừng
        if (i >= j) break;

        swap(arr[i], arr[j]);
    }

    // Đưa pivot về đúng vị trí
    swap(arr[low], arr[j]);
    return j; // trả về chỉ số pivot mới
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int new_pivot = partition(arr, low, high);
        quickSort(arr, low, new_pivot - 1);
        quickSort(arr, new_pivot + 1, high);
    }
}

int main() {
    int arr[] = {9, 5, 2, 7, 6, 1, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
