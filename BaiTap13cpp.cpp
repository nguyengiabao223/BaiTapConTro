#include <iostream>
#include <string>
using namespace std;

struct MovieData {
    string title;        
    string director;     
    int releaseYear;     
    int duration;       
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
}

void displayMovieData(MovieData* movie) {
    cout << "\nThông tin phim:\n";
    cout << "Tên phim: " << movie->title << endl;
    cout << "Đạo diễn: " << movie->director << endl;
    cout << "Năm phát hành: " << movie->releaseYear << endl;
    cout << "Thời gian: " << movie->duration << " phút" << endl;
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
