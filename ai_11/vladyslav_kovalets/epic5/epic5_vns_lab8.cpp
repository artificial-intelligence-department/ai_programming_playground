#include <iostream>
#include <vector>
#include <algorithm>

// Структура для представлення інформації про співробітника
struct Employee 
{
    std::string lastName;
    std::string firstName;
    std::string middleName;
    std::string position;
    int birthYear;
    double salary;
};

// Функція для видалення співробітника за прізвищем
void removeEmployeeByLastName(std::vector<Employee> &employees, const std::string &lastName) 
{ // Використовуємо алгоритм erase-remove_if для видалення співробітника за прізвищем
    employees.erase
        (std::remove_if//переміщує в кінець потрібне прізвище
            (employees.begin(), 
                employees.end(),
                    [lastName](const Employee &e) { return e.lastName == lastName;}
            ),
            employees.end()//видаляє його
        );
}

// Функція для додавання нового співробітника після вказаного індексу
void addEmployeeAfterIndex(std::vector<Employee> &employees, const Employee &newEmployee, size_t index) 
{
    if (index < employees.size()) // Перевірка чи індекс в межах розміру вектора
    {
        employees.insert(employees.begin() + index + 1, newEmployee);// Вставка нового співробітника після вказаного індексу
    } 
    else 
    {
        // Якщо індекс за межами додаємо нового співробітника в кінці
        employees.push_back(newEmployee);
    }
}

int main() 
{
     // Створення вектора для збереження співробітників
    std::vector<Employee> employees;
    std::cout << employees.empty() << std::endl;

    // Додавання прикладових співробітників
    employees.push_back({"Biden", "Joe", "Simson", "President", 1950,70000.0});
    employees.push_back({"Simson", "Alice", "Marie", "Engineer", 1990, 60000.0});
    employees.push_back({"Smit", "Bob", "James", "Analyst", 1986, 60000.0});

     // Виведення початкового списку співробітників
    std::cout << "Початковий список співробітників:" << std::endl;
        std::cout << employees.empty() << std::endl;
    for (const auto &employee : employees) 
    {
        std::cout << employee.lastName << ", " << employee.firstName << " - " << employee.position << std::endl;
    }

    // Видалення співробітника за прізвищем
    removeEmployeeByLastName(employees, "Biden");

     // Виведення списку співробітників після видалення
    std::cout << "Список співробітників після видалення Biden:" << std::endl;
    for (const auto &employee : employees) 
    {
        std::cout << employee.lastName << ", " << employee.firstName << " - " << employee.position << std::endl;
    }

    // Додавання нового співробітника після вказаного індексу
    Employee newEmployee{"Taylor", "Derden", "Grace", "Runner", 1985, 65000.0};
    addEmployeeAfterIndex(employees, newEmployee, 2);

    // Виведення остаточного списку співробітників
    std::cout << "Остаточний список співробітників:" << std::endl;
    for (const auto &employee : employees) 
    {
        std::cout << employee.lastName << ", " << employee.firstName << " - " << employee.position << std::endl;
    }

    return 0;
}
