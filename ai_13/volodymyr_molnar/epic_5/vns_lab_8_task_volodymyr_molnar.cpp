#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
// Структура, яка представляє студента
struct Student {
    string surname;
    string name;
    string patronymic;
    string schoolClass;
    string phoneNumber;
    int mathGrade;
    int physicsGrade;
    int ukrainianGrade;
    int literatureGrade;
};

// Функція для перевірки чи є дві оцінки з одного предмету
bool is2markInOneSubject(const Student& student) {
    vector<string> subjects;

    // Заповнення вектора предметами, з яких є оцінки
    if (student.mathGrade > 0)
        subjects.push_back("math");
    if (student.physicsGrade > 0)
        subjects.push_back("physics");
    if (student.ukrainianGrade > 0)
        subjects.push_back("ukrainian");
    if (student.literatureGrade > 0)
        subjects.push_back("literature");

    vector<string> uniqueSubjects;

    // Перевірка наявності дублікатів предметів
    for (const auto& subject : subjects) {
        if (find(uniqueSubjects.begin(), uniqueSubjects.end(), subject) != uniqueSubjects.end()) {
            return true; // Якщо дублікат знайдено
        }
        uniqueSubjects.push_back(subject);
    }

    return false; // Якщо дублікатів не знайдено
}

int main() {
    // Відкриття файлів для читання та запису
    ifstream inputFile("student.txt");
    ofstream outputFile("new_student.txt");

    // Перевірка наявності файлів
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "can`t open file." << endl;
        return 1;
    }

    string line;
    bool addnew = false;

    // Додавання нового елемента на початок файлу
    outputFile << "New Student;New Class;New Phone;1:10;2:11;3:12\n";

    // Обробка кожного рядка у файлі
    while (getline(inputFile, line)) {
        istringstream iss(line);
        Student student;

        // Читання та розбір рядка на поля студента
        getline(iss, student.surname, ';');
        getline(iss, student.name, ';');
        // ... Продовження зчитування та розбору інших полів

        // Перевірка наявності двох оцінок з одного предмету
        if (!is2markInOneSubject(student)) {
            // Якщо дублікатів немає, запис студента у вихідний файл
            outputFile << line << endl;
        }
        else {
            addnew = true;
        }
    }

    // Закриття файлів
    inputFile.close();
    outputFile.close();

    // Опціонально: видалення оригінального файлу та перейменування нового
    if (addnew) {
        remove("student.txt");
        rename("new_student.txt", "student.txt");
    }

    return 0;
}