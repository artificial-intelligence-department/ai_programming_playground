#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

const int Size_of_desk = 3;

bool win(char board[Size_of_desk][Size_of_desk], char playerMove)
{

    for (int i = 0; i < Size_of_desk; ++i)
    {
        if ((board[i][0] == playerMove && board[i][1] == playerMove && board[i][2] == playerMove) ||
            (board[0][i] == playerMove && board[1][i] == playerMove && board[2][i] == playerMove))
        {
            return true;
        }
    }

    if ((board[0][0] == playerMove && board[1][1] == playerMove && board[2][2] == playerMove) ||
        (board[0][2] == playerMove && board[1][1] == playerMove && board[2][0] == playerMove))
    {
        return true;
    }

    return false;
}

bool Draw(char board[Size_of_desk][Size_of_desk])
{
    for (int i = 0; i < Size_of_desk; ++i)
    {
        for (int j = 0; j < Size_of_desk; ++j)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

bool move(char board[Size_of_desk][Size_of_desk], int row, int column, char playerMove)
{
    if (row >= 0 && row < Size_of_desk && column >= 0 && column < Size_of_desk && board[row][column] == ' ')
    {
        board[row][column] = playerMove;
        return true;
    }
    else
    {
        std::cout << "Invalid move. Try again." << std::endl;
        return false;
    }
}

void outputDesk(char desk[Size_of_desk][Size_of_desk])
{
    for (int i = 0; i < Size_of_desk; i++)
    {
        for (int j = 0; j < Size_of_desk; j++)
        {
            std::cout << desk[i][j];
            if (j < Size_of_desk - 1)
                std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < Size_of_desk - 1)
        {
            std::cout << "---------" << std::endl;
        }
    }
    std::cout << std::endl;
}

int main()
{
    char desk[Size_of_desk][Size_of_desk];
    for (int i = 0; i < Size_of_desk; i++)
    {
        for (int j = 0; j < Size_of_desk; j++)
        {
            desk[i][j] = ' ';
        }
    }

    char playerMove = 'X';

    int row, column;
    int moves = 0;

    while (true)
    {
        outputDesk(desk);
        std::cout << "Player " << playerMove << " enter row and column : ";
        std::cin >> row >> column;
        row -= 1;
        column -= 1;

        if (move(desk, row, column, playerMove))
        {

            if (win(desk, playerMove))
            {
                outputDesk(desk);
                std::cout << "Player " << playerMove << " wins!" << std::endl;
                break;
            }
            else if (Draw(desk))
            {
                outputDesk(desk);
                std::cout << "It's a draw!" << std::endl;
                break;
            }

            if (playerMove == 'X')
            {
                playerMove = 'O';
            }
            else
            {
                playerMove = 'X';
            }
        }
    }

    return 0;
}
