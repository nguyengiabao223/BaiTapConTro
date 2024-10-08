#include<iostream>
using namespace std;

void sapXepTangDan(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = *(arr + i);
        int j = i - 1;
        while (j >= 0 && *(arr + j) > key) {
            *(arr + j + 1) = *(arr + j);
            j--;
        }
        *(arr + j + 1) = key;
    }
}

float tinhDiemTrungBinh(int *arr, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += *(arr + i);
    }
    return (float)tong / n;
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