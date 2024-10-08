#include<iostream>
using namespace std;
int timViTriMin(int *arr, int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (*(arr + i) < *(arr + minIndex)) {
            minIndex = i;
        }
    }
    return minIndex;
}

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
