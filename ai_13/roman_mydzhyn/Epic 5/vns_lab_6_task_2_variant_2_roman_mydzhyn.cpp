#include <iostream>
#include <string>

using namespace std;

bool hasVowel(const string &word)
{
	for (char ch : word)
	{ // перебір кожного символа у слові
		// якщо символ є голосною літерою, повертаємо true
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
			 ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
		{
			return true;
		}
	}
	// якщо не вивелось true, то виводиться false
	return false;
}

int main()
{
	cout << "Enter a text string (finish with a dot): ";

	string input;
	getline(cin, input); // читання введеного рядка

	string::const_iterator start = input.begin(); // ітератор до початку рядка
	string::const_iterator end = input.end();		 // ітератор до кінця рядка

	while (start != end)
	{ // поки не досягнемо кінця рядка
		// пропуск пробілів на початку слова
		while (start != end && (*start == ' ' || *start == '\t' || *start == '\n' || *start == '\r'))
		{
			++start;
		}

		// знаходження кінець слова
		string::const_iterator wordEnd = start;
		while (wordEnd != end && (*wordEnd != ' ' && *wordEnd != '\t' && *wordEnd != '\n' && *wordEnd != '\r'))
		{
			++wordEnd;
		}

		// витягуємо слово та перевіряємо його на голосні літери
		string word(start, wordEnd);
		if (!hasVowel(word))
		{								// якщо слово не містить голосних
			cout << word << " "; // його вивід
		}

		start = wordEnd; // переміщення до наступного слова
	}

	cout << endl; // вивід новий рядок

	return 0;
}
