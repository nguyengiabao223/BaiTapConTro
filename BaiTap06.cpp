#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void sapXepDiemVaTenGiamDan(float* diem, string* ten, int soLuongDiem) {
    for (int i = 0; i < soLuongDiem - 1; ++i) {
        for (int j = i + 1; j < soLuongDiem; ++j) {
            if (*(diem + i) < *(diem + j)) {

                swap(*(diem + i), *(diem + j));
                swap(*(ten + i), *(ten + j));
            }
        }
    }
}

float tinhDiemTrungBinh(float* diem, int soLuongDiem) {
    float tong = 0.0;
    for (float* ptr = diem; ptr < diem + soLuongDiem; ++ptr) {
        tong += *ptr;
    }
    return tong / soLuongDiem;
}

int main() {
    int soLuongDiem;

    do {
        cout << "Nhập số lượng học sinh kiểm tra: ";
        cin >> soLuongDiem;
        if (soLuongDiem <= 0) {
            cout << "Số lượng học sinh phải lớn hơn 0. Vui lòng nhập lại." << endl;
        }
    } while (soLuongDiem <= 0);

    float* diem = new float[soLuongDiem];
    string* ten = new string[soLuongDiem];

    for (int i = 0; i < soLuongDiem; ++i) {
        cout << "Nhập tên học sinh thứ " << i + 1 << ": ";
        cin >> *(ten + i);  

        do {
            cout << "Nhập điểm kiểm tra của " << *(ten + i) << ": ";
            cin >> *(diem + i);  
            if (*(diem + i) < 0) {
                cout << "Điểm không được âm. Vui lòng nhập lại." << endl;
            }
        } while (*(diem + i) < 0); 
    }

    sapXepDiemVaTenGiamDan(diem, ten, soLuongDiem);

    float diemTrungBinh = tinhDiemTrungBinh(diem, soLuongDiem);

    cout << "\nDanh sách học sinh và điểm đã sắp xếp theo thứ tự giảm dần:\n";
    for (int i = 0; i < soLuongDiem; ++i) {
        cout << *(ten + i) << ": " << *(diem + i) << endl;
    }

    cout << "\nĐiểm trung bình: " << diemTrungBinh << endl;

    delete[] diem;
    delete[] ten;

    return 0;
}
