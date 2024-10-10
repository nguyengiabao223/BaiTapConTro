#include <iostream>
using namespace std;

int* boiSo(int* arr, int kichThuoc, int boi, int &kichThuocMoi) {
    kichThuocMoi = 0;
    for (int i = 0; i < kichThuoc; ++i) {
        if (*(arr + i) % boi == 0) {
            ++kichThuocMoi;
        }
    }

    int* mangMoi = new int[kichThuocMoi];
    int chiSo = 0;

    for (int i = 0; i < kichThuoc; ++i) {
        if (*(arr + i) % boi == 0) {
            *(mangMoi + chiSo) = *(arr + i);
            ++chiSo;
        }
    }

    return mangMoi;
}

int main() {
    int kichThuoc, boi, kichThuocMoi;

    cout << "Nhập kích thước của mảng: ";
    cin >> kichThuoc;

    int* arr = new int[kichThuoc];

    for (int i = 0; i < kichThuoc; ++i) {
        cout << "Nhập phần tử thứ " << i << ": ";
        cin >> *(arr + i);
    }

    cout << "Nhập giá trị để lọc bội số: ";
    cin >> boi;

    int* mangMoi = boiSo(arr, kichThuoc, boi, kichThuocMoi);

    cout << "\nMảng chỉ chứa các giá trị là bội số của " << boi << " là:\n";
    for (int i = 0; i < kichThuocMoi; ++i) {
        cout << *(mangMoi + i) << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] mangMoi;

    return 0;
}
