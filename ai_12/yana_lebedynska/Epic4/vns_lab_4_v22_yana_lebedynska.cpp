#include <iostream>
using namespace std;

const int n = 100;
int arr[n];
int top = -1;
int amountOfELEMENTS;

void add(int element) 
{
    cout << endl;
    if(top < amountOfELEMENTS-1)
    {
        arr[++top] = element;
        cout << element << " is successfully added!" << endl;
    }
    else
    {
        cout << "The element " << element << " can't be added! Stack is overwhelmed." << endl;
    }
}

void deleteElement() 
{
    cout << endl;
    if(top >= 0)
    {
        cout << arr[top--] << " is now succssesfully deleted!" << endl;
    }
    else
    {
        cout << "You can't delete the element! Stack is empty." << endl;
    }
}

void print()
{
    cout << "Current stack: ";
    for(int i = 0; i <= top; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;
}

int main()
{
    int amountOfElements;
    string option;

    cout << "Enter the amount of elements of the stack: ";
    cin >> amountOfElements;

    while(amountOfElements > 100 || amountOfElements <=0)
    {
        cout << "The amount of elements is wrong! It must be greater than 0 and less than 100." << endl;
        cout << "Try again: ";
        cin >> amountOfElements;
    }
    amountOfELEMENTS = amountOfElements;
    
    
    do
    {
        cout << "You can:" << endl;
        cout << "1. Add an element (type add)" << endl;
        cout << "2. Delete an element (type delete)" << endl;
        cout << "3. Exit the program (type exit)" << endl;
        cout << "Enter the option here: ";
        cin >> option;

        switch(option[0])
        {
            case 'a':
                int elementToAdd;
                cout << "Enter the element you want to add: ";
                cin >> elementToAdd;
                add(elementToAdd);
                print();
                break;

            case 'd':
                deleteElement();
                print();
                break;

            case 'e':
                cout << "The end of the program." << endl;
                break;

            default:
                cout << "The option isn't found! Try again." << endl;
                break;
        }
    }
    while(option != "exit");

    return 0;
}
