#include <iostream>
using namespace std;

int main() {
    int n;
    bool a,b = true;
    cout << "Enter length of array: " << endl;
    cin >> n;
    int n1=n;
    if (n > 100 || n<=0) {
        cout << "Wrong input!" << endl;
        return 0;
    }

    int array[n];
    for (int i = 0; i < n; i++) {
        cout << "Element " << i << " is ";
        cin >> array[i];
    }

    menu:
    cout<<endl;
    cout << "Action menu" << endl << endl;
    cout << "1. Delete element from array" << endl;
    cout << "2. Add element to array" << endl;
    cout << "3. Exit" << endl;

    int action;
    cin >> action; 

    switch (action) {
        case 1: {
            if (n > 0) {
                    cout<<"element deleted!"<<endl;
                    n--; 
            } 
            else 
            {
                cout << "Array is empty!" << endl;
                b=false;
            }
            break;
        }
        case 2: {
           if (n<=n1-1) {
                cout << "Enter the element to add: ";
                cin >> array[n];
                n++;
                b=true;
            } else {
                cout << "Array is full" << endl;
            }
            break;
        }
        case 3:
            cout<<"Bye!"<<endl;
            return 0;
        default:
            cout << "Wrong input!!!" << endl;
            return 0;
    }
    if(b!=false){
    cout << "Array elements:" << endl;
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    }
    cout << endl;

    char choice2;
    do
    {
        cout<<"Do you want to continue?(Y/N): "<<endl;
        cin>>choice2;
        if(choice2=='Y')
        {
            a = true;
            goto menu;
        }
        else if (choice2 == 'N')
        {
            a = true;
            cout<<"Bye!"<<endl;
        }
    } while(a != true);

    return 0;
}