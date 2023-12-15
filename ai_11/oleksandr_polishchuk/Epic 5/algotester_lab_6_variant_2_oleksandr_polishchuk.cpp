    #include <iostream>
    #include <string>
    #include <algorithm>

    using namespace std;

string removeDuplicatesAndSort(const string& input)
 {
    string result = "";

    for (int i = 0; i < input.size(); i++)
    {
        bool isPresent = false;
        for (int j = 0; j < result.size(); j++)
         {
            if (input[i] == result[j]) 
            {
                isPresent = true;
                break;
            }
        }
        if (!isPresent) {
            result.push_back(input[i]);
        }
    }
    sort(result.begin(), result.end());

    return result;
}

    int main()
    {
        string finalResult = "";
        char board[8][8];
        int n, x, y;

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cin >> board[i][j];
            }
        }

        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string result = "";
            cin >> x >> y;
            x -= 1;
            y -= 1;

            if (board[x][y] != 'O')
            {
                result.push_back('X');
            }
            else
            {
                if (x > 0 && y > 0 && (board[x - 1][y-1] == 'P'))
                    result.push_back('P');
                if (x > 0 && y < 8 && board[x - 1][y + 1] == 'P')
                    result.push_back('P');

                int a, b;
                for (int j = 0; j < 8; j++)
            {
                if(board[j][y] == 'Q')
                {
                    result.push_back('Q');
                }
                if(board[j][y] == 'R')
                {
                    result.push_back('R');
                }
                        
            }
            
           for (int j = 0; j < 8; j++)
            {
                if(board[x][j] == 'Q')
                {
                    result.push_back('Q');
                }
                if(board[x][j] == 'R')
                {
                    result.push_back('R');
                }
                        
            }
                
                a = x + 1;
                b = y + 1;
                while (a < 8 && b < 8)
                {
                    if (board[a][b] == 'Q')
                        result.push_back('Q');
                    if (board[a][b] == 'B')
                        result.push_back('B');
                    a++;
                    b++;
                }

                
                a = x - 1;
                b = y - 1;
                while (a >= 0 && b >= 0)
                {
                    if (board[a][b] == 'Q')
                        result.push_back('Q');
                    if (board[a][b] == 'B')
                        result.push_back('B');
                    a--;
                    b--;
                }

                a = x - 1;
                b = y + 1;
                while (a >= 0 && b < 8)
                {
                    if (board[a][b] == 'Q')
                        result.push_back('Q');
                    if (board[a][b] == 'B')
                        result.push_back('B');
                    a--;
                    b++;
                }

                a = x + 1;
                b = y - 1;
                while (a < 8 && b >= 0)
                {
                    if (board[a][b] == 'Q')
                        result.push_back('Q');
                    if (board[a][b] == 'B')
                        result.push_back('B');
                    a++;
                    b--;
                }

                int knightX[] = {1, -1, 2, -2, -2, 2, -1, 1};
                int knightY[] = {2, -2, -1, -1, 1, 1, 2, -2};
                for (int j = 0; j < 8; j++)
                {
                    int checkX = x + knightX[j];
                    int checkY = y + knightY[j];
                    if (checkX >= 0 && checkX < 8 && checkY >= 0 && checkY < 8)
                    {
                        if (board[checkX][checkY] == 'N')
                            result.push_back('N');
                    }
                }

                int kingX[] = {1, -1, -1, 1, 0, 0, -1, 1};
                int kingY[] = {1, -1, 1, -1, 1, -1, 0, 0};
                for (int j = 0; j < 8; j++)
                {
                    int checkX = x + kingX[j];
                    int checkY = y + kingY[j];
                    if (checkX >= 0 && checkX < 8 && checkY >= 0 && checkY < 8)
                    {
                        if (board[checkX][checkY] == 'K')
                            result.push_back('K');
                    }
                }
            }
            if (result.empty())
            {
                result.push_back('O');
            }
            result = removeDuplicatesAndSort(result);
            finalResult += result + "\n";
        }
        
        cout << finalResult;
        return 0;
    }

