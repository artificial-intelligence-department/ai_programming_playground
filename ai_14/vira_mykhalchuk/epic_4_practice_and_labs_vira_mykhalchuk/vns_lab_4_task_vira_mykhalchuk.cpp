#include <iostream>
using namespace std;

const int n = 100;
int arr[n];
int top = -1;
int amountOfElements;

void destroy() 
{
    cout << "\n";
    if(top >= 0)
    {
        cout << arr[top--] << " is now successfully deleted!\n";
    }
    else
    {
        cout << "You can't delete any element! Stack is empty.\n";
    }
}

void output()
{
    cout << "Current stack: ";
    for(int i = 0; i <= top; i++)
    {
        cout << arr[i] << " " << "\n";
    }
    cout << "\n";
}

void add(int element) 
{
    cout << "\n";
    if(top < amountOfElements-1)
    {
        arr[++top] = element;
        cout << element << " is successfully added to the stack!\n";
    }
    else
    {
        cout << "The element " << element << " can't be added! Stack is full.\n";
    }
}


int main()
{
    int userInputSizeOfStack;
    string userInputAction;

    cout << "\nHi! Welcome to the stack! Enter the amount of elements of the stack (1;100): ";
    cin >> userInputSizeOfStack;

    while(userInputSizeOfStack > 100 or userInputSizeOfStack <=0)
    {
        cout << "The amount of elements is wrong! It must be greater than 0 and less than 100.\n";
        cout << "Try again: ";
        cin >> userInputSizeOfStack;
    }
    amountOfElements = userInputSizeOfStack;


    do
    {
        cout << "You can:\n";
        cout << "1. Add an element (type add)\n";
        cout << "2. Delete an element (type delete)\n";
        cout << "3. Exit the program (type exit)\n";
        cout << "Enter your action here: ";
        cin >> userInputAction;

        switch(userInputAction[0])
        {
            case 'a':
                int elementToAdd;
                cout << "Enter the element you want to add: ";
                cin >> elementToAdd;
                add(elementToAdd);
                output();
                break;

            case 'd':
                destroy();
                output();
                break;

            case 'e':
                cout << "Goodbye! See you soon!" << "\n";
                break;

            default:
                cout << "ERROR" << "\n";
                break;
        }
    }
    while(userInputAction != "exit");

    return 0;
}