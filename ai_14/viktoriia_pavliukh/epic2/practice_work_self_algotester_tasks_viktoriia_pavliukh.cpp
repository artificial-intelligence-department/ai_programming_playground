#include <iostream>
#include <string>

using namespace std;

int main() {
    string book[5] = {"Harry Potter", "Octopus", "Math", "Ten little niggers", "Little women"};
    bool access[5] = {0, 1, 1, 0, 1};
    int num, action;
    tryAgain:
    num = 0;
    action = 0;
    cout << "took book-1" << endl;
    cout << "view books-2" << endl;
    cout << "return-3" << endl;
    cout << "exit-4" << endl;
    cout << "choose and enter the action:" << endl;
    cin >> action;
        if (action == 1) {
            cout << "enter number of book: " << endl;
            cin >> num;
            while (num <= 4) {
                if (access[num] == 1) {
                    cout << "available" << endl;
                    access[num] = 0;
                } else {
                    cout << "not available" << endl;
                }
                cout << "enter new number of book or if you want to exit enter 5:  " << endl;
                cin >> num;
            }
        } else if (action == 2) {
            for (int i = 0; i < 5; i++) {
                cout << book[i] << "-" << i << ", ";
            }
        } else if (action == 3) {
            cout << "enter number of book: " << endl;
            cin >> num;
            while (num <= 4) {
                if (access[num] == 1) {
                    cout << "already available" << endl;
                } else {
                    cout<<"thank you!"<<endl;
                    access[num] = 1;
                }
                cout << "enter new number of book or if you want to exit enter 5:  " << endl;
                cin >> num;
            }
        }else{
           return 0;
        }
        goto tryAgain;
}


