#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    char board[8][8];
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            cin >> board[i][j];
        }
    }

    int k, x, y;
    cin >> k;
    string result;

    for(int i=0; i<k; i++)
    {
        cin >> x >> y;
        x--;
        y--;

        if(board[x][y] != 'O')
        {
            result.push_back('X');
            result.push_back('\n');
            continue;
        }
        string output;

        //column
        for(int j=0; j<=7; j++)
        {
            if(board[j][y] == 'R' || board[j][y] == 'Q')
            {
                output.push_back(board[j][y]);
            }
        }

        //row
        for(int j=0; j<=7; j++)
        {
            if(board[x][j] == 'R' || board[x][j] == 'Q')
            {
                output.push_back(board[x][j]);
            }
        }

        int count = 0;

        //main diagonal left
        while(x>=0 && y>=0)
        {
            if(board[x][y] == 'Q' || board[x][y] == 'B')
            {
                output.push_back(board[x][y]);
            }
            y--;
            x--;
            count++;
        }
        x+=count;
        y+=count;
        count=0;

        //main diagonal right
        while(x<=7 && y<=7)
        {
            if(board[x][y] == 'Q' || board[x][y] == 'B')
            {
                output.push_back(board[x][y]);
            }
            y++;
            x++;
            count++;
        }
        x-=count;
        y-=count;
        count=0;


        //second diagonal left
        while(x<=7 && y>=0)
        {
            if(board[x][y] == 'Q' || board[x][y] == 'B')
            {
                output.push_back(board[x][y]);
            }
            y--;
            x++;
            count++;
        }
        x-=count;
        y+=count;
        count=0;

        //second diagonal right
        while(x>=0 && y<=7)
        {
            if(board[x][y] == 'Q' || board[x][y] == 'B')
            {
                output.push_back(board[x][y]);
            }
            y++;
            x--;
            count++;
        }
        x+=count;
        y-=count;

        //pawn
        if((x-1>=0 && y-1>=0 && board[x-1][y-1] == 'P') || (x-1>=0 && y+1<=7 && board[x-1][y+1] == 'P'))
        {
            output.push_back('P');
        }

        //king
        for(int m=-1; m<=1; m++)
        {
            for(int p=-1; p<=1; p++)
            {
                if(x+m>=0 && x+m<=7 && y+p>=0 && y+p<=7 && board[x+m][y+p] == 'K')
                {
                    output.push_back('K');
                }
            }
        }

        //knight
        for(int m=-2; m<=2; m+=4)
        {
            for(int p=-1; p<=1; p+=2)
            {
                if((x+m>=0 && x+m<=7 && y+p>=0 && y+p<=7 && board[x+m][y+p] == 'N') || (x+p>=0 && x+p<=7 && y+m>=0 && y+m<=7 && board[x+p][y+m] == 'N'))
                {
                    output.push_back('N');
                }
            }
        }

        if(output.empty())
        {
            result.push_back('O');
            result.push_back('\n');
            continue;
        }

        sort(begin(output), end(output));
        for(int j=0; j<output.size(); j++)
        {
            result.push_back(output[j]);
            while(output[j] == output[j+1])
            {
                j++;
            }
        }
        result.push_back('\n');
    }

    cout << result;
    return 0;
}