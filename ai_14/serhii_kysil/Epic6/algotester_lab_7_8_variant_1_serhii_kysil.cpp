#include <iostream> 
#include <deque> 
using namespace std; 
int main() { 
    int Q; 
    cin >> Q; 
    deque<int> myList; 
    for (int i = 0; i < Q; i++) { 
        string operation; 
        cin >> operation; 
        if (operation == "insert") { 
            int index, N; 
            cin >> index >> N; 
            for (int j = 0; j < N; j++) { 
                int value; 
                cin >> value; 
                myList.insert(myList.begin() + index + j, value); 
            } 
        } else if (operation == "erase") { 
            int index, N; 
            cin >> index >> N; 
            myList.erase(myList.begin() + index, myList.begin() + index + N); 
        } else if (operation == "size") { 
            cout << myList.size() << endl; 
        } else if (operation == "get") { 
            int index; 
            cin >> index; 
            if (index >= 0 && index < myList.size()) { 
                cout << myList[index] << endl; 
            } else { 
                cout << "Invalid index" << endl; 
            } 
        } else if (operation == "set") { 
            int index, value; 
            cin >> index >> value; 
            if (index >= 0 && index < myList.size()) { 
                myList[index] = value; 
            } 
        } else if (operation == "print") { 
            for (const int& val : myList) { 
                cout << val << " "; 
            } 
            cout << endl; 
        } 
    } 
    return 0; 
}
