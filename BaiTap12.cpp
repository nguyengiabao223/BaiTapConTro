#include <iostream>
#include <algorithm>
using namespace std;

int mode(int* arr, int kichThuoc) {
    int maxCount = 0, modeValue = -1;

    for (int i = 0; i < kichThuoc; ++i) {
        int count = 1;
        for (int j = i + 1; j < kichThuoc; ++j) {
            if (*(arr + i) == *(arr + j)) {
                ++count;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            modeValue = *(arr + i);
        }
    }

    if (maxCount == 1) return -1; 
    return modeValue;
}

double median(int* arr, int kichThuoc) {
    sort(arr, arr + kichThuoc);
    if (kichThuoc % 2 == 0) {
        return (*(arr + kichThuoc / 2 - 1) + *(arr + kichThuoc / 2)) / 2.0;
    } else {
        return *(arr + kichThuoc / 2);
    }
}

double tinhTrungBinh(int* arr, int kichThuoc) {
    int tong = 0;
    for (int i = 0; i < kichThuoc; ++i) {
        tong += *(arr + i);
    }
    return static_cast<double>(tong) / kichThuoc;
}

int main() {
    int soSinhVien;

    do {
        cout << "Nhập số lượng sinh viên đã được khảo sát: ";
        cin >> soSinhVien;
        if (soSinhVien <= 0) {
            cout << "Số lượng sinh viên phải lớn hơn 0. Vui lòng nhập lại." << endl;
        }
    } while (soSinhVien <= 0);

    int* phim = new int[soSinhVien];

    for (int i = 0; i < soSinhVien; ++i) {
        do {
            cout << "Nhập số phim mà sinh viên thứ " << i + 1 << " đã xem: ";
            cin >> *(phim + i);
            if (*(phim + i) < 0) {
                cout << "Số phim không được âm. Vui lòng nhập lại." << endl;
            }
        } while (*(phim + i) < 0);
    }

    double trungBinh = tinhTrungBinh(phim, soSinhVien);
    double giaTriMedian = median(phim, soSinhVien);
    int giaTriMode = mode(phim, soSinhVien);

    cout << "\nTrung bình số phim mà sinh viên xem: " << trungBinh << endl;
    cout << "Median số phim: " << giaTriMedian << endl;

    if (giaTriMode == -1) {
        cout << "Không có mode (không có giá trị nào xuất hiện nhiều hơn một lần)." << endl;
    } else {
        cout << "Mode (giá trị xuất hiện nhiều nhất): " << giaTriMode << endl;
    }

    delete[] phim;

    return 0;
}
