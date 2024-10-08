#include <iostream>
#include <unordered_map>
using namespace std;

int timMode(int* arr, int soLuong) {
    if (soLuong <= 0) return -1; 

    unordered_map<int, int> dem; 

    for (int* ptr = arr; ptr < arr + soLuong; ++ptr) {
        dem[*ptr]++;
    }

    int mode = -1; 
    int maxCount = 0;

    for (auto& pair : dem) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mode = pair.first;
        }
    }

    return (maxCount > 1) ? mode : -1;
}

int main() {
    int soLuong;

    cout << "Nhập số lượng phần tử trong mảng: ";
    cin >> soLuong;

    int* arr = new int[soLuong];

    for (int i = 0; i < soLuong; ++i) {
        cout << "Nhập giá trị phần tử thứ " << i + 1 << ": ";
        cin >> *(arr + i); 
    }

    int mode = timMode(arr, soLuong);
    if (mode != -1) {
        cout << "Mode của mảng là: " << mode << endl;
    } else {
        cout << "Không có mode trong mảng." << endl;
    }

    delete[] arr;

    return 0;
}



