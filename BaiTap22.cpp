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

void displaySpeaker(Speaker* speaker, int index) {
    cout << "\nThông tin diễn giả thứ " << index + 1 << ":\n";
    cout << "Tên: " << speaker->name << endl;
    cout << "Số điện thoại: " << speaker->phoneNumber << endl;
    cout << "Chủ đề bài phát biểu: " << speaker->topic << endl;
    cout << "Phí diễn thuyết: $" << speaker->speakingFee << endl;
}

void updateSpeakingFee(Speaker* speaker) {
    do {
        cout << "Nhập phí diễn thuyết mới (>= 0): ";
        cin >> speaker->speakingFee;
        if (speaker->speakingFee < 0) {
            cout << "Phí diễn thuyết không thể âm. Vui lòng nhập lại." << endl;
        }
    } while (speaker->speakingFee < 0);

    cout << "Phí diễn thuyết đã được cập nhật thành công!" << endl;
}

int main() {
    int numberOfSpeakers = 0;
    int choice;

    Speaker* speakers = nullptr;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Thêm diễn giả mới\n";
        cout << "2. Cập nhật phí diễn thuyết của diễn giả\n";
        cout << "3. Hiển thị danh sách diễn giả\n";
        cout << "4. Thoát\n";
        cout << "Nhập lựa chọn của bạn: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int newCount = numberOfSpeakers + 1;
                Speaker* newSpeakers = new Speaker[newCount];

                for (int i = 0; i < numberOfSpeakers; ++i) {
                    newSpeakers[i] = speakers[i];  
                }

                cout << "\nNhập thông tin cho diễn giả thứ " << newCount << ":" << endl;
                inputSpeaker(&newSpeakers[numberOfSpeakers]);

                delete[] speakers;  
                speakers = newSpeakers; 
                numberOfSpeakers = newCount;

                cout << "Diễn giả mới đã được thêm thành công!" << endl;
                break;
            }
            case 2: {
                if (numberOfSpeakers == 0) {
                    cout << "Không có diễn giả nào để cập nhật.\n";
                } else {
                    int index;
                    do {
                        cout << "Nhập số thứ tự của diễn giả (1 - " << numberOfSpeakers << "): ";
                        cin >> index;
                        if (index < 1 || index > numberOfSpeakers) {
                            cout << "Số thứ tự không hợp lệ. Vui lòng nhập lại.\n";
                        }
                    } while (index < 1 || index > numberOfSpeakers);

                    updateSpeakingFee(&speakers[index - 1]);
                }
                break;
            }
            case 3: {
                if (numberOfSpeakers == 0) {
                    cout << "Không có diễn giả nào để hiển thị.\n";
                } else {
                    for (int i = 0; i < numberOfSpeakers; ++i) {
                        displaySpeaker(&speakers[i], i);
                    }
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
