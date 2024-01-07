#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class LinkedList // Клас LinkedList
{
	vector<int> listElements; // вектор для зберігання елементів списку

public:
	void addElement(int data) // функція для додавання елемента
	{
		listElements.push_back(data); // додавання елемента в кінець вектора
	}

	void deleteElement(int key)
	{
		listElements.erase(remove(listElements.begin(), listElements.end(), key), listElements.end()); // видалення елемента з вектора
	}

	void addBeforeElement(int key, int data)
	{
		vector<int>::iterator it = find(listElements.begin(), listElements.end(), key); // знаходження елемента у векторі
		if (it != listElements.end())
		{
			listElements.insert(it, data);
		}
		else
		{
			cout << "Error: Element " << key << " not found in the list." << endl;
		}
	}

	void printList()
	{
		if (listElements.empty())
		{
			cout << "The list is empty" << endl;
			return;
		}

		for (int data : listElements)
		{
			cout << data << " ";
		}
		cout << endl;
	}

	void saveToFile(string filename) // функція для збереження списку в файл
	{
		ofstream file(filename); // відкривання файла для запису
		for (int data : listElements)
		{
			file << data << " "; // Записування елементс в файл
		}
		file.close();
	}

	void loadFromFile(string filename)
	{
		ifstream file(filename);
		int data;
		while (file >> data) // поки є дані для читання
		{
			listElements.push_back(data); // додавання елемента в список
		}
		file.close();
	}

	void destroyList()
	{
		listElements.clear();
	}
};

int main()
{
	LinkedList list;

	// додавання елементів у список
	list.addElement(1);
	list.addElement(2);
	list.addElement(3);

	// вивід списку
	cout << "Original List: ";
	list.printList();

	// видалення елемента
	list.deleteElement(2);

	// вивід зміненого списку
	cout << "Modified List: ";
	list.printList();

	// додавання елемента перед конкретним елементом
	list.addBeforeElement(3, 10);

	// вивід фінального списку
	cout << "Final List: ";
	list.printList();

	// збереження та завантаження з файлу
	list.saveToFile("myList.txt");
	list.loadFromFile("myList.txt");

	// знищення  списку
	list.destroyList();

	return 0;
}
