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

    cout << "Nhập số lượt thích: ";
    cin >> quote->likes;
}

void displayQuoteData(QuoteData* quote) {
    cout << "\nThông tin câu trích dẫn:\n";
    cout << "Tác giả: " << quote->author << endl;
    cout << "Nội dung: \"" << quote->content << "\"" << endl;
    cout << "Số lượt thích: " << quote->likes << endl;
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

    for (int i = 0; i < numberOfQuotes; ++i) {
        displayQuoteData(&quotes[i]);
    }

    delete[] quotes;

    return 0;
}
