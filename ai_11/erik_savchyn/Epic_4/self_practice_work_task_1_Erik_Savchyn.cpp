#include <iostream>

using namespace std;

void displayBoard(char board[3][3]) {
    cout << "Ігрове поле:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (j > 0) {
                cout << "|";
            }
            cout << " " << board[i][j] << " ";
        }
        cout << endl;

        if (i < 2) {
            cout << "---+---+---" << endl;
        }
    }
}

bool checkWinner(char board[3][3], char symbol) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) return true;
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) return true;
    }

    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) return true;
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) return true;

    return false;
}

bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

void WinPlayer(char board[3][3], char playerSymbol, char computerSymbol) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == computerSymbol && board[i][1] == ' ' && board[i][2] == ' ') {
            board[i][2] = computerSymbol;
            return;
        }
        if (board[i][1] == computerSymbol && board[i][2] == ' ' && board[i][0] == ' ') {
            board[i][0] = computerSymbol;
            return;
        }
        if (board[i][2] == computerSymbol && board[i][0] == ' ' && board[i][1] == ' ') {
            board[i][1] = computerSymbol;
            return;
        }
        if (board[0][i] == computerSymbol && board[1][i] == ' ' && board[2][i] == ' ') {
            board[2][i] = computerSymbol;
            return;
        }
        if (board[1][i] == computerSymbol && board[2][i] == ' ' && board[0][i] == ' ') {
            board[0][i] = computerSymbol;
            return;
        }
        if (board[2][i] == computerSymbol && board[0][i] == ' ' && board[1][i] == ' ') {
            board[1][i] = computerSymbol;
            return;
        }
    }
    if (board[1][1] == computerSymbol && board[2][2] == ' ' && board[0][0] == ' ') {
        board[0][0] = computerSymbol;
        return;
    }
    if (board[1][1] == computerSymbol && board[2][0] == ' ' && board[0][2] == ' ') {
        board[0][2] = computerSymbol;
        return;
    }
    if (board[1][1] == ' ') {
        board[1][1] = computerSymbol;
        return;
    }
    if (board[0][0] == ' ') {
        board[0][0] = computerSymbol;
        return;
    }
    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            if (board[k][l] == ' ') {
                board[k][l] = computerSymbol;
            }
        }
    }
}

void blockPlayerWin(char board[3][3], char playerSymbol, char computerSymbol) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == playerSymbol && board[i][0] == board[i][1] && board[i][2] == ' ') {
            board[i][2] = computerSymbol;
            return;
        }
        if (board[i][1] == playerSymbol && board[i][1] == board[i][2] && board[i][0] == ' ') {
            board[i][0] = computerSymbol;
            return;
        }
        if (board[i][0] == playerSymbol && board[i][0] == board[i][2] && board[i][1] == ' ') {
            board[i][1] = computerSymbol;
            return;
        }
        if (board[0][i] == playerSymbol && board[0][i] == board[1][i] && board[2][i] == ' ') {
            board[2][i] = computerSymbol;
            return;
        }
        if (board[1][i] == playerSymbol && board[1][i] == board[2][i] && board[0][i] == ' ') {
            board[0][i] = computerSymbol;
            return;
        }
        if (board[0][i] == playerSymbol && board[0][i] == board[2][i] && board[1][i] == ' ') {
            board[1][i] = computerSymbol;
            return;
        }
    }
    if (board[0][0] == playerSymbol && board[0][0] == board[1][1] && board[2][2] == ' ') {
        board[2][2] = computerSymbol;
        return;
    }
    if (board[1][1] == playerSymbol && board[1][1] == board[2][2] && board[0][0] == ' ') {
        board[0][0] = computerSymbol;
        return;
    }
    if (board[0][0] == playerSymbol && board[0][0] == board[2][2] && board[1][1] == ' ') {
        board[1][1] = computerSymbol;
        return;
    }
    if (board[0][2] == playerSymbol && board[0][2] == board[1][1] && board[2][0] == ' ') {
        board[2][0] = computerSymbol;
        return;
    }
    if (board[1][1] == playerSymbol && board[1][1] == board[2][0] && board[0][2] == ' ') {
        board[0][2] = computerSymbol;
        return;
    }
    if (board[0][2] == playerSymbol && board[0][2] == board[2][0] && board[1][1] == ' ') {
        board[1][1] = computerSymbol;
        return;
    }
    WinPlayer(board, 'X', 'O');
}

void tryWin(char board[3][3], char playerSymbol, char computerSymbol) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == computerSymbol && board[i][0] == board[i][1] && board[i][2] == ' ') {
            board[i][2] = computerSymbol;
            return;
        }
        if (board[i][1] == computerSymbol && board[i][1] == board[i][2] && board[i][0] == ' ') {
            board[i][0] = computerSymbol;
            return;
        }
        if (board[i][0] == computerSymbol && board[i][0] == board[i][2] && board[i][1] == ' ') {
            board[i][1] = computerSymbol;
            return;
        }
        if (board[0][i] == computerSymbol && board[0][i] == board[1][i] && board[2][i] == ' ') {
            board[2][i] = computerSymbol;
            return;
        }
        if (board[1][i] == computerSymbol && board[1][i] == board[2][i] && board[0][i] == ' ') {
            board[0][i] = computerSymbol;
            return;
        }
        if (board[0][i] == computerSymbol && board[0][i] == board[2][i] && board[1][i] == ' ') {
            board[1][i] = computerSymbol;
            return;
        }
    }
    if (board[0][0] == computerSymbol && board[0][0] == board[1][1] && board[2][2] == ' ') {
        board[2][2] = computerSymbol;
        return;
    }
    if (board[1][1] == computerSymbol && board[1][1] == board[2][2] && board[0][0] == ' ') {
        board[0][0] = computerSymbol;
        return;
    }
    if (board[0][0] == computerSymbol && board[0][0] == board[2][2] && board[1][1] == ' ') {
        board[1][1] = computerSymbol;
        return;
    }
    if (board[0][2] == computerSymbol && board[0][2] == board[1][1] && board[2][0] == ' ') {
        board[2][0] = computerSymbol;
        return;
    }
    if (board[1][1] == computerSymbol && board[1][1] == board[2][0] && board[0][2] == ' ') {
        board[0][2] = computerSymbol;
        return;
    }
    if (board[0][2] == computerSymbol && board[0][2] == board[2][0] && board[1][1] == ' ') {
        board[1][1] = computerSymbol;
        return;
    }
    blockPlayerWin(board, 'X', 'O'); 
}

int main() {
    start:
    char board[3][3];

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }

    int players;
    int whoFirst = 1;

    char currentPlayer = 'X';
    char symbol;

    cout << "Введіть кількість гравців (1 або 2): ";
    cin >> players;

    if (players == 1) {
        cout << "хто ходить першим X (ви) чи O? (1 чи 2): ";
        cin >> whoFirst;
    } 

    do {

        if (whoFirst != 1 && board[1][1] == ' ') {
            board[1][1] = 'O';
        }

        displayBoard(board);

        symbol = (currentPlayer == 'X') ? 'X' : 'O';

        int row, col;
        int again = 1;

        if (currentPlayer == 'X' || (currentPlayer == 'O' && players == 2)) {
            cout << "Гравець " << currentPlayer << ", введіть рядок та стовпець (від 1 до 3): ";
            cin >> row >> col;

            row--;
            col--;

            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
                board[row][col] = symbol;
            } else {
                cout << "Некоректні координати. Спробуйте ще раз." << endl;
                continue;
            }
        }

        if (currentPlayer == 'O' && players == 1) {
            cout << "Хід комп'ютера:" << endl;
            tryWin(board, 'X', 'O');
        }

        if (checkWinner(board, symbol)) {
            displayBoard(board);
            cout << "Гравець " << currentPlayer << " переміг!" << endl;
            cout << "бажаєте зіграти ще раз? (1 якщо так): ";
            cin >> again;
            if (again == 1) {
                goto start;
            }
            break;
        }
        
        if (isBoardFull(board)) {
            displayBoard(board);
            cout << "Гра закінчилася в нічию." << endl;
            cout << "бажаєте зіграти ще раз? (1 якщо так): ";
            cin >> again;
            if (again == 1) {
                goto start;
            }
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

    } while (true);

    return 0;
}
