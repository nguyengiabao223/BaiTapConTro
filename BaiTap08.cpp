#include <iostream>
#include <algorithm> 
using namespace std;

float timMedian(int* arr, int soLuong) {
    sort(arr, arr + soLuong); 

    if (soLuong % 2 != 0) {
        return *(arr + soLuong / 2); 
    } 

    else {
        int mid1 = *(arr + (soLuong / 2) - 1); 
        int mid2 = *(arr + (soLuong / 2)); 
        return (mid1 + mid2) / 2.0; 
    }
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

    float median = timMedian(arr, soLuong);
    cout << "Median của mảng là: " << median << endl;

    delete[] arr;

    return 0;
}
