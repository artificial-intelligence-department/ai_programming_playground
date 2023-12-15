#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    const int size = 8;
    string chessBoard[size];
    vector<string> vector = {};

    for (int i = 0; i < size; ++i) {
        getline(cin, chessBoard[i]);
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {

        int x, y, counter = 0;
        cin >> x >> y;

        x -= 1;
        y -= 1;
        string attackFigures = "";

        if (chessBoard[x][y] != 'O') {
            vector.push_back("X");
        }
        else {
            //pawn
            if ((y > 0 && x > 0 && chessBoard[x - 1][y - 1] == 'P') || (x > 0 && y < size - 1 && (chessBoard[x - 1][y + 1] == 'P')))
            {
                attackFigures += 'P';
                counter++;
            }


            //tura
            for (int i = 0; i < size; i++) {
                if (chessBoard[x][i] == 'R' || chessBoard[i][y] == 'R')
                {
                    attackFigures += 'R';
                    counter++;
                }
            }

            //horse
            if ((x < size - 2 && y > 0 && chessBoard[x + 2][y - 1] == 'N') ||
                (x < size - 2 && y < size - 1 && chessBoard[x + 2][y + 1] == 'N') ||
                (x > 1 && y > 0 && chessBoard[x - 2][y - 1] == 'N') ||
                (x > 1 && y < size - 1 && chessBoard[x - 2][y + 1] == 'N') ||
                (x < size - 1 && y > 1 && chessBoard[x + 1][y - 2] == 'N') ||
                (x < size - 1 && y < size - 2 && chessBoard[x + 1][y + 2] == 'N') ||
                (x > 0 && y > 1 && chessBoard[x - 1][y - 2] == 'N') ||
                (x > 0 && y < size - 2 && chessBoard[x - 1][y + 2] == 'N'))
            {
                attackFigures += 'N';
                counter++;
            }

            //officer-elephant
            for (int i = 0; i < size; i++) {
                if (x + i < size && y + i < size && chessBoard[x + i][y + i] == 'B' ||
                    y >= i && x + i < size && chessBoard[x + i][y - i] == 'B' ||
                    x >= i && y + i < size && chessBoard[x - i][y + i] == 'B' ||
                    x >= i && y >= i && chessBoard[x - i][y - i] == 'B')
                {
                    attackFigures += 'B';
                    counter++;
                }
            }

            //king
            if (y > 0 && chessBoard[x][y - 1] == 'K' ||
                y < size - 1 && chessBoard[x][y + 1] == 'K' ||
                x > 0 && y > 0 && chessBoard[x - 1][y - 1] == 'K' ||
                x > 0 && chessBoard[x - 1][y] == 'K' ||
                x > 0 && y < size - 1 && chessBoard[x - 1][y + 1] == 'K' ||
                x < size - 1 && chessBoard[x + 1][y] == 'K' ||
                x < size - 1 && y < size - 1 && chessBoard[x + 1][y + 1] == 'K' ||
                x < size - 1 && y > 0 && chessBoard[x + 1][y - 1] == 'K')
            {
                attackFigures += 'K';
                counter++;
            }


            //queen
            for (int i = 0; i < size; i++) {
                if (x + i < size && y + i < size && chessBoard[x + i][y + i] == 'Q' ||
                    y >= i && x + i < size && chessBoard[x + i][y - i] == 'Q' ||
                    x >= i && y + i < size && chessBoard[x - i][y + i] == 'Q' ||
                    x >= i && y >= i && chessBoard[x - i][y - i] == 'Q' ||
                    chessBoard[x][i] == 'Q' ||
                    chessBoard[i][y] == 'Q')
                {
                    attackFigures += 'Q';
                    counter++;
                }
            }

            if (counter == 0 && chessBoard[x][y] == 'O')
            {
                vector.push_back("O");
            }
            else
            {
                sort(attackFigures.begin(), attackFigures.end());
                auto newEnd = unique(attackFigures.begin(), attackFigures.end());
                attackFigures.resize(distance(attackFigures.begin(), newEnd));
                vector.push_back(attackFigures);
            }

        }
    }
    for (int i = 0; i < Q; i++)
    {
        cout << vector[i] << endl;
    }
    return 0;
}
