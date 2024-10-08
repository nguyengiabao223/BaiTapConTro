#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
void sapXep(char **ten, int *diem, int n) {
    for (int i = 1; i < n; i++) {
        char *keyTen = *(ten + i);
        int keyDiem = *(diem + i);
        int j = i - 1;
        while (j >= 0 && *(diem + j) > keyDiem) {
            *(ten + j + 1) = *(ten + j);
            *(diem + j + 1) = *(diem + j);
            j--;
        }
        *(ten + j + 1) = keyTen;
        *(diem + j + 1) = keyDiem;
    }
}

int main() {
    int n;
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;

    char **ten = new char*[n];
    int *diem = new int[n];

    for (int i = 0; i < n; i++) {
        ten[i] = new char[50];
        cout << "Nhap ten hoc sinh thu " << i + 1 << ": " ;
        cin.getline(ten[i], 50);
        cout << "Nhap diem: ";
        cin >> diem[i];
        cin.ignore();
    }

    sapXep(ten, diem, n);

    cout << "\nDanh sach diem da sap xep:\n";
    for (int i = 0; i < n; i++) {
        cout << *(ten + i) << ": " << *(diem + i) << endl;
    }
    for (int i = 0; i < n; i++) {
        delete[] ten[i];
    }
    delete[] ten;
    delete[] diem;

    return 0;
}