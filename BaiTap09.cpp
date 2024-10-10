#include <iostream>
using namespace std;

int* layGiaTriChan(int* arr, int kichThuoc, int& kichThuocMoi) {
    kichThuocMoi = (kichThuoc + 1) / 2;

    int* arrChan = new int[kichThuocMoi];

    for (int i = 0, j = 0; i < kichThuoc; i += 2, ++j) {
        *(arrChan + j) = *(arr + i); 
    }

    return arrChan;
}

int main() {
    int kichThuoc;

    cout << "Nhập kích thước của mảng: ";
    cin >> kichThuoc;

    int* arr = new int[kichThuoc];

    for (int i = 0; i < kichThuoc; ++i) {
        cout << "Nhập phần tử thứ " << i << ": ";
        cin >> *(arr + i);
    }

    int kichThuocMoi;

    int* arrChan = layGiaTriChan(arr, kichThuoc, kichThuocMoi);

    cout << "Các giá trị tại vị trí chẵn trong mảng gốc là:\n";
    for (int i = 0; i < kichThuocMoi; ++i) {
        cout << *(arrChan + i) << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] arrChan;

    return 0;
}
