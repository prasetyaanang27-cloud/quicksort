// QUICK SORT DENGAN PIVOT BERWARNA
// Pivot akan tampil merah di terminal

#include <iostream>
using namespace std;

// Warna ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"

// Menampilkan array dan pivot berwarna
void tampilPivot(int arr[], int n, int pivotIndex)
{
    for (int i = 0; i < n; i++)
    {
        if (i == pivotIndex)
            cout << RED << arr[i] << RESET << " ";
        else
            cout << arr[i] << " ";
    }
    cout << endl;
}

// Quick Sort
void quickSort(int arr[], int low, int high, int n)
{
    int i = low;
    int j = high;

    int pivotIndex = (low + high) / 2;
    int pivot = arr[pivotIndex];

    cout << "\nPivot dipilih: ";
    tampilPivot(arr, n, pivotIndex);

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    cout << "Setelah diproses: ";
    tampilPivot(arr, n, pivotIndex);

    if (low < j)
        quickSort(arr, low, j, n);

    if (i < high)
        quickSort(arr, i, high, n);
}

int main()
{
    int n;

    cout << "Jumlah data: ";
    cin >> n;

    int arr[100];

    for (int i = 0; i < n; i++)
    {
        cout << "Masukkan harga ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\nData awal: ";
    tampilPivot(arr, n, -1);

    quickSort(arr, 0, n - 1, n);

    cout << "\nHasil akhir sorting: ";
    tampilPivot(arr, n, -1);

    return 0;
}