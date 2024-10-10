#include <iostream>
using namespace std;

int* noiMang(int* arr1, int kichThuoc1, int* arr2, int kichThuoc2) {
    int kichThuocMoi = kichThuoc1 + kichThuoc2;

    int* arrMoi = new int[kichThuocMoi];

    for (int i = 0; i < kichThuoc1; ++i) {
        *(arrMoi + i) = *(arr1 + i);
    }

    for (int i = 0; i < kichThuoc2; ++i) {
        *(arrMoi + kichThuoc1 + i) = *(arr2 + i);
    }

    return arrMoi;
}

int main() {
    int kichThuoc1, kichThuoc2;

    cout << "Nhập kích thước mảng đầu tiên: ";
    cin >> kichThuoc1;

    int* arr1 = new int[kichThuoc1];

    for (int i = 0; i < kichThuoc1; ++i) {
        cout << "Nhập phần tử thứ " << i << " của mảng đầu tiên: ";
        cin >> *(arr1 + i);
    }

    cout << "Nhập kích thước mảng thứ hai: ";
    cin >> kichThuoc2;

    int* arr2 = new int[kichThuoc2];

    for (int i = 0; i < kichThuoc2; ++i) {
        cout << "Nhập phần tử thứ " << i << " của mảng thứ hai: ";
        cin >> *(arr2 + i);
    }

    int* arrMoi = noiMang(arr1, kichThuoc1, arr2, kichThuoc2);

    cout << "\nMảng sau khi nối hai mảng là:\n";
    for (int i = 0; i < kichThuoc1 + kichThuoc2; ++i) {
        cout << *(arrMoi + i) << " ";
    }
    cout << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] arrMoi;

    return 0;
}

