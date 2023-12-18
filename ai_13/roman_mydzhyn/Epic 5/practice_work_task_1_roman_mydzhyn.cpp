#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// оголошення перелічення для результату операції з файлом
enum FileOpResult
{
	Success,
	Failure
};

// функція для запису вмісту в файл
FileOpResult write_to_file(const string &name, const string &content)
{
	// відкриття файлу для запису (або створення, якщо він не існує)
	ofstream file(name);
	if (!file)
	{
		return Failure; // повертання Failure при невдалому відкритті
	}

	// запис вмісту в файл
	file << content;
	if (!file)
	{
		return Failure; // повертання Failure при помилці запису
	}

	// файл автоматично закриється при знищенні об'єкта file

	return Success; // повертання Success при успішному відкриті та записі
}

int main()
{
	string filename = "test.txt";
	string content = "Це приклад вмісту файлу.";

	FileOpResult result = write_to_file(filename, content);
	if (result == Success)
	{
		cout << "Файл успішно записано.\n";
	}
	else
	{
		cout << "Виникла помилка під час запису файлу.\n";
	}

	return 0;
}