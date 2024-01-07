#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int SIZE = 8;

char Capture(int a, int b, int c, int d);
char pawn(int a, int b, int c, int d);
char rook(int a, int b, int c, int d);
char bishop(int a, int b, int c, int d);
char knight(int a, int b, int c, int d);
char queen(int a, int b, int c, int d);
char king(int a, int b, int c, int d);
bool BoardEmpty(const std::string& str);

int limit();
int LimitOfRequest();
void SortAndShow(string result);

int main() {
    char board_figures[SIZE][SIZE];
    vector<char> row;
    vector<int> position_x;
    vector<int> position_y;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> board_figures[i][j];
            if (board_figures[i][j] != 'O') {
                row.push_back(board_figures[i][j]);
                position_x.push_back(i + 1);
                position_y.push_back(j + 1);
            }
        }
    }
    int Q, x, y; 
    Q = LimitOfRequest();

    for (int i = 0; i < Q; i++) {
        string result;
        x = limit();
        y = limit();

        for (int i = 0; i < row.size(); i++) {
            char result_symbol = 0;

            switch (row[i]) {
                case 'P':
                    result_symbol = pawn(position_x[i], position_y[i], x, y);
                    break;
                case 'R':
                    result_symbol = rook(position_x[i], position_y[i], x, y);
                    break;
                case 'B':
                    result_symbol = bishop(position_x[i], position_y[i], x, y);
                    break;
                case 'N':
                    result_symbol = knight(position_x[i], position_y[i], x, y);
                    break;
                case 'Q':
                    result_symbol = queen(position_x[i], position_y[i], x, y);
                    break;
                case 'K':
                    result_symbol = king(position_x[i], position_y[i], x, y);
                    break;
            }
            if(result_symbol) {
                result += result_symbol;
            }
        }
        SortAndShow(result);
    }

    return 0;
}

int limit(){
    int a;
    cin >> a;
    while(true){
        if(a >= 1 && a <= 8) break;
        else cin >> a;
    }
    return a;
}

int LimitOfRequest(){
    int a;
    cin >> a;
    while(true){
        if(a >= 1 && a <= 64) break;
        else cin >> a;
    }
    return a;
}

void SortAndShow(string result){
    if (BoardEmpty(result)) {
        cout << 'O' << endl;
    } else if (result.find('X') != string::npos) { // string::npos - означає не знайдено або нема позиції
        cout << "X" << endl;
    } else {
        sort(result.begin(), result.end());
        auto unique_values = unique(result.begin(), result.end());
        result.erase(unique_values, result.end());
        cout << result << endl;
    }
}

char Review(int x_pos, int y_pos, int x, int y) {
    return (x_pos == x && y_pos == y) ? 'X' : 0;
}

char pawn(int x_pos, int y_pos, int x, int y) {
    return Review(x_pos, y_pos, x, y) ? 'X' : (x - x_pos == 1 && abs(y - y_pos) == 1) ? 'P' : 0;
}

char rook(int x_pos, int y_pos, int x, int y) {
    return Review(x_pos, y_pos, x, y) ? 'X' : (x_pos == x || y_pos == y) ? 'R' : 0;
}

char bishop(int x_pos, int y_pos, int x, int y) {
    return Review(x_pos, y_pos, x, y) ? 'X' : (abs(x_pos - x) == abs(y_pos - y)) ? 'B' : 0;
}

char knight(int x_pos, int y_pos, int x, int y) {
    return Review(x_pos, y_pos, x, y) ? 'X' : (abs(x_pos - x) == 2 && abs(y - y_pos) == 1) || (abs(x_pos - x) == 1 && abs(y - y_pos) == 2) ? 'N' : 0;
}

char queen(int x_pos, int y_pos, int x, int y) {
    return Review(x_pos, y_pos, x, y) ? 'X' : (x_pos == x || y_pos == y || abs(x_pos - x) == abs(y_pos - y)) ? 'Q' : 0;
}

char king(int x_pos, int y_pos, int x, int y) {
    return Review(x_pos, y_pos, x, y) ? 'X' : (abs(x_pos - x) <= 1 && abs(y_pos - y) <= 1) ? 'K' : 0;
}

bool BoardEmpty(const string& str) {
    // Ця функція перевіряє, чи є дошка, представлена у вигляді рядка символів, повністю порожньою.
    // Умова для порожньої дошки полягає в тому, щоб всі символи в рядку були крапками
    // Лямбда-вираз [ ](char c) { return c == '.'; } перевіряє, чи кожний символ у рядку є крапкою
    // all_of повертає true, якщо умова вказана в лямбда-виразі виконується для всіх елементів діапазону
    return all_of(str.begin(), str.end(), [](char c) { return c == '.'; }); 
}