#include <iostream>
#include <string>
using namespace std;

struct QuoteData {
    string author;         
    string content;        
    int likes;             
};

void inputQuoteData(QuoteData* quote) {
    cout << "Nhập tên tác giả của câu trích dẫn: ";
    cin.ignore();
    getline(cin, quote->author);

    cout << "Nhập nội dung câu trích dẫn: ";
    getline(cin, quote->content);

    do {
        cout << "Nhập số lượt thích (không chấp nhận giá trị âm): ";
        cin >> quote->likes;
        if (quote->likes < 0) {
            cout << "Lượt thích không thể âm. Vui lòng nhập lại." << endl;
        }
    } while (quote->likes < 0);
}

int calculateTotalLikes(QuoteData* quotes, int size) {
    int totalLikes = 0;
    for (int i = 0; i < size; ++i) {
        totalLikes += (quotes + i)->likes;
    }
    return totalLikes;
}

void displayPopularQuotes(QuoteData* quotes, int size, double averageLikes) {
    cout << "\nCác câu trích dẫn phổ biến hơn mức trung bình:\n";
    for (int i = 0; i < size; ++i) {
        if ((quotes + i)->likes > averageLikes) {
            double percentage = ((quotes + i)->likes / averageLikes) * 100;
            cout << "\"" << (quotes + i)->content << "\" - " << (quotes + i)->author;
            cout << " (Lượt thích: " << (quotes + i)->likes << ", chiếm " << percentage << "% so với trung bình)\n";
        }
    }
}

int main() {
    int numberOfQuotes;

    cout << "Nhập số lượng câu trích dẫn: ";
    cin >> numberOfQuotes;

    QuoteData* quotes = new QuoteData[numberOfQuotes];

    for (int i = 0; i < numberOfQuotes; ++i) {
        cout << "\nNhập thông tin cho câu trích dẫn thứ " << i + 1 << ":" << endl;
        inputQuoteData(&quotes[i]);
    }

    int totalLikes = calculateTotalLikes(quotes, numberOfQuotes);
    double averageLikes = static_cast<double>(totalLikes) / numberOfQuotes;

    displayPopularQuotes(quotes, numberOfQuotes, averageLikes);

    delete[] quotes;

    return 0;
}
