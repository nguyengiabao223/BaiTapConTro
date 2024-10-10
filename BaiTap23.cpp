#include <iostream>
#include <string>
using namespace std;

struct Speaker {
    string name;           
    string phoneNumber;    
    string topic;      
    float speakingFee;     
};

void inputSpeaker(Speaker* speaker) {
    cout << "Nhập tên diễn giả: ";
    cin.ignore(); 
    getline(cin, speaker->name);

    cout << "Nhập số điện thoại: ";
    getline(cin, speaker->phoneNumber);

    cout << "Nhập chủ đề bài phát biểu: ";
    getline(cin, speaker->topic);

    do {
        cout << "Nhập phí diễn thuyết (>= 0): ";
        cin >> speaker->speakingFee;
        if (speaker->speakingFee < 0) {
            cout << "Phí diễn thuyết không thể âm. Vui lòng nhập lại." << endl;
        }
    } while (speaker->speakingFee < 0);
}

void displaySpeaker(Speaker* speaker) {
    cout << "Tên: " << speaker->name << endl;
    cout << "Số điện thoại: " << speaker->phoneNumber << endl;
    cout << "Chủ đề bài phát biểu: " << speaker->topic << endl;
    cout << "Phí diễn thuyết: $" << speaker->speakingFee << endl;
}

void updateSpeaker(Speaker* speaker) {
    cout << "Cập nhật thông tin cho diễn giả:\n";
    inputSpeaker(speaker);
}

int main() {
    const int SIZE = 10;  
    Speaker* speakers = new Speaker[SIZE];  
    int choice = 0;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Nhập thông tin cho diễn giả\n";
        cout << "2. Cập nhật thông tin cho diễn giả\n";
        cout << "3. Hiển thị danh sách diễn giả\n";
        cout << "4. Thoát\n";
        cout << "Nhập lựa chọn của bạn: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                for (int i = 0; i < SIZE; ++i) {
                    cout << "\nNhập thông tin cho diễn giả thứ " << i + 1 << ":\n";
                    inputSpeaker(&speakers[i]);
                }
                break;
            }
            case 2: {
                int index;
                cout << "Nhập số thứ tự của diễn giả để cập nhật (1 - " << SIZE << "): ";
                cin >> index;
                if (index >= 1 && index <= SIZE) {
                    updateSpeaker(&speakers[index - 1]);
                } else {
                    cout << "Số thứ tự không hợp lệ." << endl;
                }
                break;
            }
            case 3: {
                cout << "\nDanh sách diễn giả:\n";
                for (int i = 0; i < SIZE; ++i) {
                    cout << "\nDiễn giả thứ " << i + 1 << ":\n";
                    displaySpeaker(&speakers[i]);
                }
                break;
            }
            case 4:
                cout << "Thoát chương trình...\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại.\n";
        }
    } while (choice != 4);

    delete[] speakers;  

    return 0;
}
