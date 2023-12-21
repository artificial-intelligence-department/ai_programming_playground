#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ofstream first_file("F1.txt");

	if (!first_file.is_open())
	{
        cout << "Failure" << endl;
        return 1;
	}

	int rows;

	cout << "Enter number of rows you want to fill: ";
	cin >> rows;

	cin.ignore();

	for (int i = 0; i < rows; ++i) 
	{
		cout << "Enter information of row number " << i + 1 << " in file F1.txt: ";
        string string;
        getline(cin, string);
        first_file << string << endl;
	}

	first_file.close();

	ifstream first_file_read("F1.txt");
	ofstream second_file("F2.txt");

	if (!first_file_read.is_open() || !second_file.is_open())
	{
        cout << "Failure" << endl;
        return 1;
	}

	string line;
	int line_number = 0;

	while (getline(first_file_read, line))
	{
        ++line_number;
        if (line_number >= 4)
        {
            second_file << line << endl;
        }
	}

	first_file_read.close();
	second_file.close();

	ifstream second_file_read("F2.txt");

	if (!second_file_read.is_open())
	{
        cout << "Failure" << endl;
        return 1;
	}

	string last_word;

	while (!second_file_read.eof())
    {
        second_file_read >> last_word;
    }

	second_file_read.close();

	cout << "Last word in F2: " << last_word << endl;
	cout << "Number of charackters in the word: " << last_word.length() << endl;

	return 0;
}