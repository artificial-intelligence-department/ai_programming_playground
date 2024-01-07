#include <iostream>
#include <algorithm>
using namespace std;

bool pawn (int xf, int yf, int x0, int y0)
{
    return abs(xf-x0) == 1 && yf+1 == y0;
}

bool tour(int xf, int yf, int x0, int y0)
{
    return xf==x0 || yf==y0;
}

bool bishop(int xf, int yf, int x0, int y0)
{
    return abs(x0-xf) == abs(y0-yf);
}

bool queen(int xf, int yf, int x0, int y0)
{
    return tour(xf, yf, x0, y0) || bishop(xf, yf, x0, y0);
}

bool horse(int xf, int yf, int x0, int y0)
{
    return (abs(x0-xf) == 2 && abs(y0-yf) == 1) || (abs(x0-xf) == 1 && abs(y0-yf) == 2);
}

bool king(int xf, int yf, int x0, int y0)
{
    //return (abs(x0-xf) == 1 && abs(y0-yf) == 1;
    return (abs(x0-xf) == 1 && abs(y0-yf) == 1 || abs(x0-xf) == 1 &&  abs(y0-yf) == 0) || abs(x0-xf) == 0 &&  abs(y0-yf) == 1;
}

bool procesing_piece(char piece, int x, int y, int x0, int y0) 
{
    switch(piece)
    {
        case 'K':
        return king(x,y,x0,y0);
        case 'N':
        return horse(x,y,x0,y0);
        case 'R':
        return tour(x,y,x0,y0);
        case 'P':
        return pawn(x,y,x0,y0);
        case 'B':
        return bishop(x,y,x0,y0);
        case 'Q':
        return queen(x,y,x0,y0);
    }
    return false;
}
void print_results(string results[], int results_count) 
{
    for(int i=0; i<results_count; i++) 
    {
        if(results[i] == "") 
        {
            cout<<"O"<<endl;
        }
        else
        {
            sort(results[i].begin(), results[i].end());
            cout<<results[i]<<endl;
        }
    }
}

int main()
{
    string board[8];
    for(int row = 0; row <8; row++)
    {
        cin>>board[row];  
    }
    int request_count; 
    cin>> request_count;
    int requests[request_count][2];  
    for(int i = 0; i<request_count; i++)
    {
        cin>>requests[i][1];
        cin>>requests[i][0];
    }
    string results[request_count]; 
    for(int row = 0; row <8; row++)
    {
        for(int column = 0; column<8; column++)
        {
            char piece = board[row][column]; 
            if(piece!= 'O')
            {
               for(int i=0; i<request_count; i++)
               {
                    int x = requests[i][0]-1;
                    int y = requests[i][1]-1; 
                    if(board[y][x] != 'O') 
                    {
                        results[i] = "X";
                    }
                    else if(procesing_piece(piece, column, row,  x, y)) 
                    {
                        if (count(results[i].begin(), results[i].end(), piece) == 0) {
                        results[i] += piece;
                        }
                    }
               }
            }
        }
    }
    print_results(results, request_count);
}