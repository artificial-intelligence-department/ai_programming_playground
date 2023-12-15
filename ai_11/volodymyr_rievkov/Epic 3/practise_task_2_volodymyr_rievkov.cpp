#include<iostream>
#include<vector>
#include<functional>
using namespace std;
int sideSize;
bool lever = true;
int action;
void GetSideSize()
{
    cout << "Enter size: ";
    cin >> sideSize;
}
void ChoosePattern()
{
    do
    {
        cout << " 1 - Square\n 2 - Rectangle\n 3 - Triangle\n 4 - Pyramid\n 5 - Exit\nEnter number: ";
        cin >> action;
    } while (action != 1 && action != 2 && action != 3 && action != 4 && action != 5 && action != 6);
}
bool IsFilled()
{
    char choice;
    bool isFilled;
    do
    {
        cout << "Do you want to fill pattern(y/n): ";
        cin >> choice;
    } while (choice != 'y' && choice != 'n');
    if(choice == 'y')
    {
        isFilled = true;
    }
    else
    {
        isFilled = false;
    }
    cout << endl;
    return isFilled;
}
void PrintSquare()
{
    GetSideSize();
    if(IsFilled())
    {
        for(int i = 0; i < sideSize; i++)
        {
            for(int y = 0; y < sideSize; y++)
            {
                cout << "* ";
            }
            cout << endl;
        }
    }
    else
    {
        for(int i = 0; i < sideSize; i++)
        {
            for(int y = 0; y < sideSize; y++)
            {
                if(y == 0 || i == 0 || y == sideSize - 1 || i == sideSize - 1)
                {
                    cout << "* ";
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }  
    cout << endl;
}
void PrintRectangle()
{
    GetSideSize();
    int doubleSidesize = sideSize * 2;
    if(IsFilled())
    {
        for(int i = 0; i < sideSize; i++)
        {
            for(int y = 0; y < doubleSidesize; y++)
            {
                cout << "* ";
            }
            cout << endl;
        }
    }
    else
    {
        for(int i = 0; i < sideSize; i++)
        {
            for(int y = 0; y < doubleSidesize; y++)
            {
                if(y == 0 || i == 0 || y == doubleSidesize - 1 || i == sideSize - 1)
                {
                    cout << "* ";
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }  
    cout << endl;

}
void PrintTriangle()
{
    GetSideSize();
    if(IsFilled())
    {
        for(int i = 0; i < sideSize; i++)
        {
            for(int y = 0; y <= i; y++)
            {
                cout << "* ";
            }
            cout << endl;
        }
    }
    else
    {
        for(int i = 0; i < sideSize; i++)
        {
            for(int y = 0; y <= i; y++)
            {
                if (y == i || i == sideSize - 1 || y == 0)
                {
                    cout << "* ";
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }  
    cout << endl;
}
void PrintPyramid()
{
    GetSideSize();
    int doubleSidesize = sideSize * 2;
    if(IsFilled())
    {
        for(int i = 0; i < sideSize; i++)
        {
            int spaces = (sideSize - (i + 1));
            for(int y = 0; y < doubleSidesize - 1; y++)
            {
                if(spaces > 0 || y >= sideSize + i)
                {
                    cout << "  ";
                    spaces--;
                }
                else
                {
                    cout << "* ";
                }               
            }
            cout << endl;
        }
    }
    else
    {
        for(int i = 0; i < sideSize; i++)
        {
            for(int y = 0; y < doubleSidesize - 1; y++)
            {
                if(y == sideSize - i - 1 || y == sideSize + i - 1 || i == sideSize - 1)
                {
                    cout << "* ";
                    
                }
                else
                {
                    cout << "  ";
                }               
            }
            cout << endl;
        }
    }  
    cout << endl;
}
void Exit()
{
    lever = false;
}
vector<function<void()>>patterns {PrintSquare, PrintRectangle, PrintTriangle, PrintPyramid, Exit};
int main()
{
    while(lever)
    {
        ChoosePattern();
        for(int i = 0; i < patterns.size(); i++)
        {
            if(action - 1 == i)
            {
                patterns[i]();
            }
        }
    }
}