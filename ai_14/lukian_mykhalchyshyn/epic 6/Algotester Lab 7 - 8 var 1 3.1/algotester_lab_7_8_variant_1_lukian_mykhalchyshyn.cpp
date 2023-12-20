#include <iostream>
#include <list>

using namespace std;

int main() 
{
    list <int> myList;

    int Q;
    cin >> Q;

    while (Q--) 
    {
        string command;
        cin >> command;

        if (command == "insert") 
        {
            int index, N;
            cin >> index;
            cin >> N;

            for (int i = 0; i < N; ++i) 
            {
                int value;
                cin >> value;

                auto it = myList.begin();
                advance(it, index + i);
                myList.insert(it, value);
            }
        } 
        else if (command == "erase") 
        {
            int index, n;
            cin >> index >> n;

            auto start = myList.begin();
            advance(start, index);
            auto end = start;
            advance(end, n);

            myList.erase(start, end);
        } 
        else if (command == "size") 
        {
            cout << myList.size() << endl;
        } 
        else if (command == "get") 
        {
            int index;
            cin >> index;

            auto it = myList.begin();
            advance(it, index);

            cout << *it << endl;
        } 
        else if (command == "set") 
        {
            int index, value;
            cin >> index;
            cin >> value;

            auto it = myList.begin();
            advance(it, index);

            *it = value;
        } 
        else if (command == "print") 
        {
            for (const auto& element : myList) 
            {
                cout << element << " ";
            }
            cout << endl;
        }
    }

    return 0;
}