#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Employee
{
	string pib;
	string post;
	int yearofbirth;
	int salary;
};

// функція для створення нового працівника
Employee createEmployee()
{
	Employee newEmployee; // створення нового об'єкта структури
	cout << "Enter Last name First name Patronymic: ";
	getline(cin, newEmployee.pib); // отримання ПІБ від юзера
	cout << "Position: ";
	getline(cin, newEmployee.post);
	cout << "Yearofbirth: ";
	cin >> newEmployee.yearofbirth;
	cout << "Salary: ";
	cin >> newEmployee.salary;
	cin.ignore();		  // очущуємо буфера вводу, щоб уникнути проблем зі зчитуванням рядків
	return newEmployee; // повернення нового створеного працівника
}

// функція для виведення інформації про працівника
void printEmployee(const Employee &employee)
{
	cout << "Last name First name Patronymic: " << employee.pib << endl;
	cout << "Position: " << employee.post << endl;
	cout << "Yearofbirth: " << employee.yearofbirth << endl;
	cout << "Salary: " << employee.salary << endl;
	cout << "------" << endl; // Розділюва
}

// функція для збереження працівників у файл
bool saveEmployees(const vector<Employee> &employees, const string &filename)
{
	ofstream file(filename, ios::binary); // відкриття файлу для запису у бінарному режимі
	if (!file)
	{
		cout << "Error opening the file" << endl;
		return false;
	}
	file.write(reinterpret_cast<const char *>(employees.data()), sizeof(Employee) * employees.size()); // запис даних про працівників у файл
	return true;
}

// функція для завантаження працівників з файлу
vector<Employee> loadEmployees(const string &filename)
{
	ifstream file(filename, ios::binary);
	vector<Employee> employees; // створення пустого вектору працівників
	if (!file)
	{
		cout << "Error opening the file" << endl;
		return employees; // повернення пустого вектору
	}

	file.seekg(0, ios::end);			  // перехід в кінець файлу
	const int fileSize = file.tellg(); // отримання розміру файлу
	file.seekg(0, ios::beg);			  // перехід на початок файлу

	if (fileSize % sizeof(Employee) != 0)
	{
		cout << "File is corrupted" << endl; // перевірка на цілісність файлу
		return employees;							 // повернення пустого вектору, якщо файл пошкоджений
	}

	employees.resize(fileSize / sizeof(Employee));						  // зміна розміру вектору для працівників
	file.read(reinterpret_cast<char *>(employees.data()), fileSize); // зчитування даних про працівників із файлу

	return employees; // повернення вектору, що містить завантажених працівників
}

int main()
{
	vector<Employee> employees;	// створення вектору для зберігання працівників
	string filename = "file.bin"; // назва файлу, в якому буде зберігатися інформація про працівників
	bool running = true;

	while (running)
	{
		cout << endl;
		cout << "1 - Add employee" << endl;
		cout << "2 - Save" << endl;
		cout << "3 - Delete structure" << endl;
		cout << "4 - Add structure" << endl;
		cout << "5 - Output" << endl;
		cout << "6 - Read from file" << endl;
		cout << "7 - Exit" << endl;
		cout << "Select action: ";

		int choice;
		cin >> choice; //
		cin.ignore();

		switch (choice)
		{
		case 1:
			employees.push_back(createEmployee()); // додавання нового працівника у вектор
			break;
		case 2:
			if (saveEmployees(employees, filename))
			{
				cout << "Data saved to " << filename << endl;
			}
			break;
		case 3:

			break;
		case 4:

			break;
		case 5:
			for (const Employee &employee : employees)
			{
				printEmployee(employee);
			}
			break;
		case 6:
			employees = loadEmployees(filename);
			break;
		case 7:
			running = false;
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
	}

	return 0;
}
