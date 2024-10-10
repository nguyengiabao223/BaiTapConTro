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

    cout << "Nhập điểm đánh giá hiệu suất: ";
    cin >> computer->performanceScore;

    cout << "Nhập giá của máy tính: ";
    cin >> computer->price;
}

void displayComputerConfig(ComputerConfig* computer) {
    cout << "\nThông tin cấu hình máy tính:\n";
    cout << "Tốc độ xung nhịp CPU: " << computer->clockSpeed << " GHz" << endl;
    cout << "Số lõi CPU: " << computer->cpuCores << endl;
    cout << "Dung lượng RAM: " << computer->ramSize << " GB" << endl;
    cout << "Dung lượng ổ cứng: " << computer->hddSize << " GB" << endl;
    cout << "Điểm đánh giá hiệu suất: " << computer->performanceScore << endl;
    cout << "Giá của máy tính: $" << computer->price << endl;
}

int main() {
    int numberOfComputers;

    cout << "Nhập số lượng máy tính cần lưu trữ thông tin: ";
    cin >> numberOfComputers;

    ComputerConfig* computers = new ComputerConfig[numberOfComputers];

    for (int i = 0; i < numberOfComputers; ++i) {
        cout << "\nNhập thông tin cho máy tính thứ " << i + 1 << ":" << endl;
        inputComputerConfig(&computers[i]);
    }

    for (int i = 0; i < numberOfComputers; ++i) {
        displayComputerConfig(&computers[i]);
    }

    delete[] computers;

    return 0;
}
