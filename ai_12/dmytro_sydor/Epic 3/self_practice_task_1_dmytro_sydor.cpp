#include <iostream>
#include <vector>
using namespace std;

vector<string> menu(vector<string> library1);
void quantity(vector<string> library2);
vector<string> take1(vector<string> library3);
vector<string> return1(vector<string> library4);
void endFunc();

int main()
{

    string word;
    vector<string> library = {
        "Fallout",
        "God of war",
        "Metro 2035",
        "Metro 2033",
    };
pos1:
    cout << endl;
    cout << "If you want to check which books are available type: \"Menu\"" << endl;
    cout << "To check how many books are available type: \"Quantity\"" << endl;
    cout << "To take a book, or return it go to the menu" << endl;
    cout << "Type \"End\" to leave" << endl;
    cout << endl;
    cin >> word;

    if (word == "menu" || word == "Menu")
    {
        menu(library);
    }
    else if (word == "quantity" || word == "Quantity")
    {
        quantity(library);
    }
    else if (word == "end" || word == "End")
    {
        endFunc();
    }
    else
    {
        cout << "You write wring wird! Try again" << endl;
        goto pos1;
    }
pos2:
    return 0;
}

vector<string> menu(vector<string> library1)
{
    for (int i = 0; i < library1.size(); i++)
    {
        cout << endl;
        cout << library1[i] << endl;
    }
pos2:
    string word1;
    cout << endl;
    cout << "If you want to take a book type: \"Take\"" << endl;
    cout << endl;
    cout << "If you want to return a book type: \"Return\"" << endl;
    cout << "Type \"End\" to leave" << endl;

    cin >> word1;
    if (word1 == "Take" || word1 == "take")
    {
        take1(library1);
        library1 = take1(library1);
    }
    else if (word1 == "Return" || word1 == "return")
    {
        return1(library1);
    }
    else if (word1 == "End" || word1 == "end")
    {
        endFunc();
    }
    else
    {
        goto pos2;
    }

    return library1;
}

void quantity(vector<string> library2)
{
    cout << endl;
    cout << "Quantity of books are: " << library2.size() << endl;
}

vector<string> take1(vector<string> library3)
{
    do
    {
        string bookToRemove;

        cout << endl;
        cout << "Type name of book you would like to take: " << endl;

        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

        getline(cin, bookToRemove);

        auto it = find(library3.begin(), library3.end(), bookToRemove);

        if (it != library3.end())
        {
            library3.erase(remove(library3.begin(), library3.end(), bookToRemove), library3.end());

            cout << "Congratulations! You took a book." << endl;
            cout << "Type Menu/Quantity if you want to check." << endl;
            break;
        }
        else
        {
            cout << endl;
            cout << "You wrote wrong book!" << endl;
        }
    } while (true);
    string word3;
    cin >> word3;

    if (word3 == "Menu" || word3 == "menu")
    {
        menu(library3);
    }
    else if (word3 == "Quantity" || word3 == "quantity")
    {
        quantity(library3);
    }

    return library3;
}

vector<string> return1(vector<string> library4)
{

    string bookToAdd;
    string word4;
    cout << endl;
    cout << "Type name of book you would like to give: " << endl;

    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    getline(cin, bookToAdd);

    library4.push_back(bookToAdd);

    cout << endl;
    cout << "Congratulations your book have been added!" << endl;
    cout << "If you want to check type menu" << endl;
    do
    {
        cin >> word4;
        if (word4 == "menu" || word4 == "Menu")
        {
            menu(library4);
            break;
        }
        else
        {
            cout << "Write a word menu!";
        }
    } while (true);
    return library4;
}
void endFunc()
{
    exit(0);
}
