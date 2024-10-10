#include <iostream>
#include <string>
using namespace std;

struct EarthquakeData {
    string name;          
    string location;       
    int year;              
    float magnitude;       
    int casualties;      
};

void inputEarthquakeData(EarthquakeData* earthquake) {
    cout << "Nhập tên trận động đất: ";
    cin.ignore(); 
    getline(cin, earthquake->name);
    
    cout << "Nhập vị trí trận động đất: ";
    getline(cin, earthquake->location);

    cout << "Nhập năm xảy ra: ";
    cin >> earthquake->year;

    cout << "Nhập độ lớn (theo thang Richter): ";
    cin >> earthquake->magnitude;

    cout << "Nhập số người thiệt mạng: ";
    cin >> earthquake->casualties;
}

void displayEarthquakeData(EarthquakeData* earthquake) {
    cout << "\nThông tin trận động đất:\n";
    cout << "Tên: " << earthquake->name << endl;
    cout << "Vị trí: " << earthquake->location << endl;
    cout << "Năm xảy ra: " << earthquake->year << endl;
    cout << "Độ lớn: " << earthquake->magnitude << endl;
    cout << "Số người thiệt mạng: " << earthquake->casualties << endl;
}

int main() {
    const int numberOfEarthquakes = 3; 
    EarthquakeData* earthquakes = new EarthquakeData[numberOfEarthquakes];

    for (int i = 0; i < numberOfEarthquakes; ++i) {
        cout << "\nNhập thông tin cho trận động đất thứ " << i + 1 << ":" << endl;
        inputEarthquakeData(&earthquakes[i]);
    }

    for (int i = 0; i < numberOfEarthquakes; ++i) {
        displayEarthquakeData(&earthquakes[i]);
    }

    delete[] earthquakes;

    return 0;
}
