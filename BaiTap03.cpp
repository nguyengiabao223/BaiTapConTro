#include <iostream>
#include <cstdlib>

using namespace std;

// Hàm tìm vị trí của phần tử nhỏ nhất trong mảng
int timViTriMin(int *arr, int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (*(arr + i) < *(arr + minIndex)) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Hàm sắp xếp mảng theo thứ tự tăng dần (sử dụng thuật toán sắp xếp chèn)
// (Giữ nguyên hàm này)

// Hàm tính điểm trung bình, loại bỏ điểm nhỏ nhất
float tinhDiemTrungBinh(int *arr, int n) {
    int minIndex = timViTriMin(arr, n);
    int tong = 0;
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (i != minIndex) {
            tong += *(arr + i);
            dem++;
        }
    }
    return (float)tong / dem;
}
int main() {
    int n;

    cout << "Nhap so luong diem kiem tra : ";
    cin >> n;

    int *diem = new int[n];

    cout << "Nhap cac diem kiem tra:\n";
    for (int i = 0; i < n; i++) {
                cout << "Diem mon 1 " << i + 1 ;
        cin >> *(diem + i);
    }

    sapXepTangDan(diem, n);

    float diemTrungBinh = tinhDiemTrungBinh(diem, n);

    cout << "\nDanh sach diem da sap xep:\n";
    for (int i = 0; i < n; i++) {
        cout << *(diem + i) << " ";
    }

    cout << "\nDiem trung binh: " << diemTrungBinh << endl;

    delete[] diem;

    return 0;
}
