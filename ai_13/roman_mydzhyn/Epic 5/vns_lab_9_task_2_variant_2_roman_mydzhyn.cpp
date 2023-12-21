#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void createfile()
{
	ofstream filename_3("f1.txt", ios::trunc);
	if (filename_3.is_open())
	{
		filename_3 << "The sun shines brightly in the clear blue sky. \n";
		filename_3 << "A cat naps peacefully on the windowsill. \n";
		filename_3 << "Children play happily in the park. \n";
		filename_3 << "Coffee brews, filling the kitchen with its aroma. \n";
		filename_3 << "The rain patters softly against the windowpane. \n";
		filename_3 << "A gentle breeze rustles the leaves on the trees. \n";
		filename_3 << "Birds sing their melodious songs at dawn. \n";
		filename_3 << "The old book smells of history and adventure. \n";
		filename_3 << "Laughter echoes through the bustling cafe. \n";
		filename_3 << "Stars twinkle in the vast, night sky. \n";
		filename_3.close();
	}
}

int main(int argc, char *argv[])
{
	createfile();
	ifstream filename("f1.txt");
	ofstream filename_2("f2.txt");
	if (!filename.is_open() || !filename_2.is_open())
		return 1; // перевірка, чи вдалося відкрити файли
	string str;
	int count = 0;						 // лічильник символів
	while (getline(filename, str)) // читання рядків з файлу f1.txt
	{
		if (*str.begin() == *(str.end() - 1)) // перевірка на збіжність першого та останнього рядка
		{
			filename_2 << str << endl; // запис рядка у файл f2.txt
			count += str.size();			// додавання кількості символів рядка до лічильника
		}
	}
	cout << "Number of characters in f2.txt: " << count << endl;
	return 0;
}
