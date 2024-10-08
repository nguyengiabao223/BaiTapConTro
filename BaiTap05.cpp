#include <iostream>

using namespace std;

void arrSelectSort(int *[], int);
void showArrPtr(int *[], int);

int main() {
    int numDonations;

    cout << "Nhap so luong dong gop: ";
    cin >> numDonations;

    // Phan bo dong mang
    int *donations = new int[numDonations];
    int *arrPtr[numDonations];

    // Nhap cac gia tri
    cout << "Nhap cac gia tri dong gop:\n";
    for (int i = 0; i < numDonations; i++) {
        cin >> donations[i];
        arrPtr[i] = &donations[i];
    }

    // Sap xep
    arrSelectSort(arrPtr, numDonations);
    cout << "Danh sach dong gop da sap xep:\n";
    showArrPtr(arrPtr, numDonations);

    delete[] donations;

    return 0;
}