#include <iostream>
#include <string>
using namespace std;

struct ComputerConfig {
    float clockSpeed;     
    int cpuCores;          
    int ramSize;          
    int hddSize;           
    float performanceScore; 
    float price;          
};

void inputComputerConfig(ComputerConfig* computer) {
    cout << "Nhập tốc độ xung nhịp của bộ xử lý (GHz): ";
    cin >> computer->clockSpeed;

    cout << "Nhập số lõi của CPU: ";
    cin >> computer->cpuCores;

    cout << "Nhập dung lượng RAM (GB): ";
    cin >> computer->ramSize;

    cout << "Nhập dung lượng ổ cứng (GB): ";
    cin >> computer->hddSize;

    do {
        cout << "Nhập điểm đánh giá hiệu suất (>= 0): ";
        cin >> computer->performanceScore;
        if (computer->performanceScore < 0) {
            cout << "Điểm hiệu suất không thể âm. Vui lòng nhập lại." << endl;
        }
    } while (computer->performanceScore < 0);

    do {
        cout << "Nhập giá của máy tính (>= 0): ";
        cin >> computer->price;
        if (computer->price < 0) {
            cout << "Giá không thể âm. Vui lòng nhập lại." << endl;
        }
    } while (computer->price < 0);
}

void displayComputerConfig(ComputerConfig* computer, int index) {
    cout << "\nCấu hình máy tính thứ " << index + 1 << ":\n";
    cout << "Tốc độ xung nhịp CPU: " << computer->clockSpeed << " GHz" << endl;
    cout << "Số lõi CPU: " << computer->cpuCores << endl;
    cout << "Dung lượng RAM: " << computer->ramSize << " GB" << endl;
    cout << "Dung lượng ổ cứng: " << computer->hddSize << " GB" << endl;
    cout << "Điểm đánh giá hiệu suất: " << computer->performanceScore << endl;
    cout << "Giá của máy tính: $" << computer->price << endl;
}

void updatePrice(ComputerConfig* computer) {
    do {
        cout << "Nhập giá mới của máy tính (>= 0): ";
        cin >> computer->price;
        if (computer->price < 0) {
            cout << "Giá không thể âm. Vui lòng nhập lại." << endl;
        }
    } while (computer->price < 0);

    cout << "Giá đã được cập nhật thành công!" << endl;
}

int main() {
    int numberOfComputers = 0;
    int choice;

    ComputerConfig* computers = nullptr;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Thêm cấu hình máy mới\n";
        cout << "2. Thay đổi giá của cấu hình hiện có\n";
        cout << "3. Hiển thị toàn bộ dữ liệu máy tính\n";
        cout << "4. Thoát\n";
        cout << "Nhập lựa chọn của bạn: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int newCount = numberOfComputers + 1;
                ComputerConfig* newComputers = new ComputerConfig[newCount];

                for (int i = 0; i < numberOfComputers; ++i) {
                    newComputers[i] = computers[i]; 
                }

                cout << "\nNhập thông tin cho máy tính thứ " << newCount << ":" << endl;
                inputComputerConfig(&newComputers[numberOfComputers]);

                delete[] computers;
                computers = newComputers;
                numberOfComputers = newCount;

                cout << "Cấu hình mới đã được thêm thành công!" << endl;
                break;
            }
            case 2: {
                if (numberOfComputers == 0) {
                    cout << "Không có cấu hình máy tính nào để cập nhật.\n";
                } else {
                    int index;
                    do {
                        cout << "Nhập số thứ tự của máy tính (1 - " << numberOfComputers << "): ";
                        cin >> index;
                        if (index < 1 || index > numberOfComputers) {
                            cout << "Số thứ tự không hợp lệ. Vui lòng nhập lại.\n";
                        }
                    } while (index < 1 || index > numberOfComputers);

                    updatePrice(&computers[index - 1]);
                }
                break;
            }
            case 3: {
                if (numberOfComputers == 0) {
                    cout << "Không có cấu hình máy tính nào để hiển thị.\n";
                } else {
                    for (int i = 0; i < numberOfComputers; ++i) {
                        displayComputerConfig(&computers[i], i);
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

    delete[] computers; 

    return 0;
}
