#include<iostream>
using namespace std;
int main (){
    int Array[10];
    for (int i = 0; i < 10 ; i++) {
        cout << "Nhap phan tu thu  " << i + 1  << " = ";
        cin >> Array[i]; 
    }
    int sizeofArray = sizeof(Array);
    cout << "Kich thuoc mang " << sizeofArray << " byte " <<  endl;
    for (int i = 0; i < 10 ; i++ ) {
        cout << "Dia chi cua phan tu " << "Array[" << i << "] " << &Array[i] << endl;

    }

    return 0;
}