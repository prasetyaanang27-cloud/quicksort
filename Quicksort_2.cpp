// QUICK SORT HARGA BARANG SEDERHANA

#include <iostream>
using namespace std;

// Menampilkan array
void tampil(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Quick Sort Ascending
void quickSortAsc(int arr[], int low, int high) {
    int i = low, j = high;
    int pivot = arr[(low + high) / 2];

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (low < j)
        quickSortAsc(arr, low, j);
    if (i < high)
        quickSortAsc(arr, i, high);
}

// Quick Sort Descending
void quickSortDesc(int arr[], int low, int high) {
    int i = low, j = high;
    int pivot = arr[(low + high) / 2];

    while (i <= j) {
        while (arr[i] > pivot) i++;
        while (arr[j] < pivot) j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (low < j)
        quickSortDesc(arr, low, j);
    if (i < high)
        quickSortDesc(arr, i, high);
}

int main() {
    int n;

    cout << "Jumlah barang: ";
    cin >> n;

    int arr[100]; // maksimal 100 data

    for (int i = 0; i < n; i++) {
        cout << "Harga barang ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    int pilih;
    cout << "\n1. Ascending\n2. Descending\n";
    cout << "Pilih: ";
    cin >> pilih;

    if (pilih == 1) {
        quickSortAsc(arr, 0, n - 1);
        cout << "\nHasil Ascending:\n";
        tampil(arr, n);
    }
    else if (pilih == 2) {
        quickSortDesc(arr, 0, n - 1);
        cout << "\nHasil Descending:\n";
        tampil(arr, n);
    }
    else {
        cout << "Pilihan salah!";
    }

    return 0;
}