#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream F1("First_file.txt");
    ofstream F2("Second_file.txt");

    if (!F1.is_open() || !F2.is_open())
    {
        cout << "Failure" << endl;
        return 1;
    }

    int n;

    cout << "How many lines do you want to enter? ";
    cin >> n;

    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        cout << "Enter content for First_file.txt: ";
        string str;
        getline(cin, str);
        F1 << str << endl;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Enter content for Second_file.txt: ";
        string str;
        getline(cin, str);
        F2 << str << endl;
    }

    F1.close();
    F2.close();

    ifstream F1_("First_file.txt");
    ifstream F2_("Second_file.txt");

    if (!F1_.is_open() || !F2_.is_open())
    {
        cout << "Failure" << endl;

        return 1;
    }

    string first_file_line, second_file_line;
    int counter = 0;

    while (getline(F1_, first_file_line) && getline(F2_, second_file_line))
    {
        counter++;

        if (first_file_line.length() != second_file_line.length())
        {
            std::cout << "Files have lines with different length" << endl;
            return 0;
        }
    }

    std::cout << "All lines in files have the same length" << endl;

    F1_.close();
    F2_.close();

    return 0;
}