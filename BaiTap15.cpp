#include <iostream>
#include <string>
using namespace std;

struct MovieData {
    string title;        
    string director;    
    int releaseYear;    
    int duration;        
    float productionCost; 
    float revenue;        
};

void inputMovieData(MovieData* movie) {
    cout << "Nhập tên phim: ";
    cin.ignore(); 
    getline(cin, movie->title);
    
    cout << "Nhập đạo diễn: ";
    getline(cin, movie->director);

    cout << "Nhập năm phát hành: ";
    cin >> movie->releaseYear;

    cout << "Nhập thời gian (phút): ";
    cin >> movie->duration;

    cout << "Nhập chi phí sản xuất: ";
    cin >> movie->productionCost;

    cout << "Nhập doanh thu trong năm đầu tiên: ";
    cin >> movie->revenue;
}

void displayMovieData(MovieData* movie) {
    cout << "\nThông tin phim:\n";
    cout << "Tên phim: " << movie->title << endl;
    cout << "Đạo diễn: " << movie->director << endl;
    cout << "Năm phát hành: " << movie->releaseYear << endl;
    cout << "Thời gian: " << movie->duration << " phút" << endl;
    cout << "Chi phí sản xuất: " << movie->productionCost << " triệu đồng" << endl;
    cout << "Doanh thu trong năm đầu tiên: " << movie->revenue << " triệu đồng" << endl;

    float profitOrLoss = movie->revenue - movie->productionCost;
    if (profitOrLoss > 0) {
        cout << "Lợi nhuận: " << profitOrLoss << " triệu đồng" << endl;
    } else if (profitOrLoss < 0) {
        cout << "Thua lỗ: " << -profitOrLoss << " triệu đồng" << endl;
    } else {
        cout << "Không có lợi nhuận hoặc thua lỗ." << endl;
    }
}

int main() {
    int numberOfMovies;

    cout << "Nhập số lượng phim: ";
    cin >> numberOfMovies;

    MovieData* movies = new MovieData[numberOfMovies];

    for (int i = 0; i < numberOfMovies; ++i) {
        cout << "\nNhập thông tin cho phim thứ " << i + 1 << ":" << endl;
        inputMovieData(&movies[i]);
    }

    for (int i = 0; i < numberOfMovies; ++i) {
        displayMovieData(&movies[i]);
    }

    delete[] movies;

    return 0;
}
