//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int main() {
//    const int size = 8;
//    string chessBoard[size];
//    vector<string> result;
//
//    for (int i = 0; i < size; ++i) {
//        getline(cin, chessBoard[i]);
//    }
//
//    int Q;
//    cin >> Q;
//
//    for (int q = 0; q < Q; q++) {
//        int x, y, counter = 0;
//        cin >> x >> y;
//
//        x -= 1;
//        y -= 1;
//        string attackFigures = "";
//
//        if (chessBoard[x][y] != 'O') {
//            result.push_back("X");
//        }
//        else {
//            // Пішак
//            if (x > 0 && y > 0 && chessBoard[x - 1][y - 1] == 'P') {
//                attackFigures += 'P';
//                counter++;
//            }
//            if (x > 0 && y < size - 1 && chessBoard[x - 1][y + 1] == 'P') {
//                attackFigures += 'P';
//                counter++;
//            }
//
//            // Тура
//            for (int i = 0; i < size; i++) {
//                if (chessBoard[x][i] == 'R' || chessBoard[i][y] == 'R') {
//                    attackFigures += 'R';
//                    counter++;
//                }
//            }
//
//            //horse
//            if ((x < size - 2 && y > 0 && chessBoard[x + 2][y - 1] == 'N') ||
//                (x < size - 2 && y < size - 1 && chessBoard[x + 2][y + 1] == 'N') ||
//                (x > 1 && y > 0 && chessBoard[x - 2][y - 1] == 'N') ||
//                (x > 1 && y < size - 1 && chessBoard[x - 2][y + 1] == 'N') ||
//                (x < size - 1 && y > 1 && chessBoard[x + 1][y - 2] == 'N') ||
//                (x < size - 1 && y < size - 2 && chessBoard[x + 1][y + 2] == 'N') ||
//                (x > 0 && y > 1 && chessBoard[x - 1][y - 2] == 'N') ||
//                (x > 0 && y < size - 2 && chessBoard[x - 1][y + 2] == 'N'))
//            {
//                attackFigures += 'N';
//                counter++;
//            }
//
//
//            //officer-elephant
//            for (int i = 0; i < size; i++) {
//                if (x + i < size && y + i < size && chessBoard[x + i][y + i] == 'B' ||
//                    y >= i && x + i < size && chessBoard[x + i][y - i] == 'B' ||
//                    x >= i && y + i < size && chessBoard[x - i][y + i] == 'B' ||
//                    x >= i && y >= i && chessBoard[x - i][y - i] == 'B')
//                {
//                    attackFigures += 'B';
//                    counter++;
//                }
//            }
//
//            //king
//            if (y > 0 && chessBoard[x][y - 1] == 'K' ||
//                y < size - 1 && chessBoard[x][y + 1] == 'K' ||
//                x > 0 && y > 0 && chessBoard[x - 1][y - 1] == 'K' ||
//                x > 0 && chessBoard[x - 1][y] == 'K' ||
//                x > 0 && y < size - 1 && chessBoard[x - 1][y + 1] == 'K' ||
//                x < size - 1 && chessBoard[x + 1][y] == 'K' ||
//                x < size - 1 && y < size - 1 && chessBoard[x + 1][y + 1] == 'K' ||
//                x < size - 1 && y > 0 && chessBoard[x + 1][y - 1] == 'K')
//            {
//                attackFigures += 'K';
//                counter++;
//            }
//
//
//            //queen
//            for (int i = 0; i < size; i++) {
//                if (x + i < size && y + i < size && chessBoard[x + i][y + i] == 'Q' ||
//                    y >= i && x + i < size && chessBoard[x + i][y - i] == 'Q' ||
//                    x >= i && y + i < size && chessBoard[x - i][y + i] == 'Q' ||
//                    x >= i && y >= i && chessBoard[x - i][y - i] == 'Q' ||
//                    chessBoard[x][i] == 'Q' ||
//                    chessBoard[i][y] == 'Q')
//                {
//                    attackFigures += 'Q';
//                    counter++;
//                }
//            }
//
//            if (counter == 0 && chessBoard[x][y] == 'O') {
//                result.push_back("O");
//            }
//            else {
//                sort(attackFigures.begin(), attackFigures.end());
//                result.push_back(attackFigures);
//            }
//        }
//    }
//
//    for (int i = 0; i < Q; i++) {
//        cout << result[i] << endl;
//    }
//
//    return 0;
//}

//13.Записи в лінійному списку містять ключове поле типу * char(рядок
//    символів).Сформувати двонаправлений список.Знищити з нього К перших
//    елементів.Додати елемент після елемента, що починається із зазначеного
//    символу.

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring> 
#include "List.h"
using namespace std;

int main() {

    List list;
    list.Show();

    const char* text1 = "c++";
    const char* text2 = "hello";
    const char* text3 = "julia";
    const char* text4 = "qwerty";
    const char* text5 = "world";
    
    list.PushBack(text1);
    list.PushBack(text2);
    list.PushBack(text3);
    list.PushBack(text4);
    list.PushBack(text5);

    list.Show();
    int user_num;
    cout << "Enter count delete word: ";
    cin >> user_num;
    for (int i = 0; i < user_num; i++)
    {
        list.PopFront();
    }
    list.Show();

    char user_symbol;
    cout << "Enter count delete word: ";
    cin >> user_symbol;
    //cout << list.SearchFirstSymbol(user_symbol) << endl;

    const char* text6 = "NewWord";
    list.Add(text6, list.SearchFirstSymbol(user_symbol));

    list.Show();

    return 0;
}
