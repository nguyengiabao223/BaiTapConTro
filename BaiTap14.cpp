#include <iostream>
#include <string>
using namespace std;

struct MovieData {
    string title;       
    string director;     
    int releaseYear;    
    int duration;        
};

void displayMovieData(MovieData* movie) {
    cout << "\n--- Thông tin phim ---\n";
    cout << "Tên phim: " << movie->title << endl;
    cout << "Đạo diễn: " << movie->director << endl;
    cout << "Năm phát hành: " << movie->releaseYear << endl;
    cout << "Thời gian: " << movie->duration << " phút" << endl;
}

int main() {
    MovieData* movie1 = new MovieData;
    MovieData* movie2 = new MovieData;

    movie1->title = "Inception";
    movie1->director = "Christopher Nolan";
    movie1->releaseYear = 2010;
    movie1->duration = 148;

    movie2->title = "The Matrix";
    movie2->director = "Lana Wachowski, Lilly Wachowski";
    movie2->releaseYear = 1999;
    movie2->duration = 136;

    displayMovieData(movie1);
    displayMovieData(movie2);

    delete movie1;
    delete movie2;

    return 0;
}
