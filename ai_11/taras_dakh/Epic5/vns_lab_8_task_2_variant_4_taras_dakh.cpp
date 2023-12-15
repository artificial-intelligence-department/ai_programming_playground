#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Структура для представлення інформації про людину
struct Person {
    char lastName[50];
    char firstName[50];
    char patronymic[50];
    char address[100];
    char phoneNumber[15];
    int age;
};

// Функція для виведення вмісту бінарного файлу
void printBinaryFileContents(const char* filename) {
    ifstream inFile(filename, ios::binary);

    if (!inFile.is_open()) {
        cerr << "Неможливо відкрити файл: " << filename << endl;
        return;
    }

    Person person;
    while (inFile.read(reinterpret_cast<char*>(&person), sizeof(person))) {
        cout << "Прізвище: " << person.lastName << "\n";
        cout << "Ім'я: " << person.firstName << "\n";
        cout << "По батькові: " << person.patronymic << "\n";
        cout << "Адреса: " << person.address << "\n";
        cout << "Номер телефону: " << person.phoneNumber << "\n";
        cout << "Вік: " << person.age << "\n\n";
    }

    inFile.close();
}

// Функція для видалення записів за вказаним віком
void deleteByAge(const char* filename, int ageToDelete) {
    ifstream inFile(filename, ios::binary);  //Створює об'єкт для читання з файлу (ios::binary вказує, що файл є бінарним).
    ofstream outFile("temp.bin", ios::binary);   //Створює об'єкт для запису у новий тимчасовий файл temp.bin

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Неможливо відкрити файл для видалення." << endl;
        return;
    }

    Person person;  //Створюється об'єкт person типу Person, який використовується для зчитування даних з вхідного файлу.
    while (inFile.read(reinterpret_cast<char*>(&person), sizeof(person))) {   //зчитуються блоки даних розміром sizeof(person) з вхідного файлу
        if (person.age != ageToDelete) {
            outFile.write(reinterpret_cast<char*>(&person), sizeof(person)); //Кожний зчитаний запис порівнюється за віком з ageToDelete, і якщо вік не збігається, запис додається до тимчасового файлу.
        }
    }

    inFile.close();
    outFile.close();

    remove(filename);
    rename("temp.bin", filename);

    cout << "Особи з віком " << ageToDelete << " успішно видалено.\n";
}

// Функція для додавання запису після конкретного індексу
void addAfterIndex(const char* filename, int index, const Person& newPerson) {
    ifstream inFile(filename, ios::binary);
    ofstream outFile("temp.bin", ios::binary);

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Неможливо відкрити файл для додавання." << endl;
        return;
    }

    Person person;
    int currentIndex = 0;

    while (inFile.read(reinterpret_cast<char*>(&person), sizeof(person))) {  //зчитуються блоки даних розміром sizeof(person) з вхідного файлу
        outFile.write(reinterpret_cast<char*>(&person), sizeof(person));

        if (currentIndex == index) {
            outFile.write(reinterpret_cast<const char*>(&newPerson), sizeof(newPerson));
        }

        currentIndex++;   //Кожний зчитаний запис записується у тимчасовий файл. Якщо досягнутий індекс, на якому ми хочемо вставити новий запис, цей новий запис також додається у тимчасовий файл.
    }

    inFile.close();
    outFile.close();

    remove(filename);
    rename("temp.bin", filename);

    cout << "Особу додано після індексу " << index << " успішно.\n";
}

// Функція для заповнення файлу інформацією про людей
void fillFile(const char* filename, int count) {
    Person person;
    ofstream file(filename, ios::binary);

    if (!file.is_open()) {
        cerr << "Помилка відкриття файлу для запису: " << filename << endl;
        return;
    }

    for (int i = 0; i < count; ++i) {
        cout << "\nВведіть дані для особи " << i + 1 << ":\n";
        cout << "Прізвище: ";
        cin.getline(person.lastName, sizeof(person.lastName));

        cout << "Ім'я: ";
        cin.getline(person.firstName, sizeof(person.firstName));

        cout << "По батькові: ";
        cin.getline(person.patronymic, sizeof(person.patronymic));

        cout << "Адреса: ";
        cin.getline(person.address, sizeof(person.address));

        cout << "Номер телефону: ";
        cin.getline(person.phoneNumber, sizeof(person.phoneNumber));

        cout << "Вік: ";
        cin >> person.age;

        cin.ignore(); // Очищення символу нового рядка з буфера

        file.write(reinterpret_cast<const char*>(&person), sizeof(person)); //Викликається file.write, який записує об'єкт person у бінарний файл;перетворення типу об'єкта на покажчик на const char, щоб його можна було записати у бінарний файл.
    }

    file.close();
}

int main() {
    const char* filename = "people_data.bin";
    int count = 3; 

    fillFile(filename, count);

    cout << "\nПочатковий вміст файлу:\n";
    printBinaryFileContents(filename);

    int ageToDelete;
    cout << "\nВведіть вік для видалення: ";
    cin >> ageToDelete;
    deleteByAge(filename, ageToDelete);

    cout << "\nВміст файлу після видалення:\n";
    printBinaryFileContents(filename);

    int insertIndex;
    cout << "\nВведіть індекс для вставки після: ";
    cin >> insertIndex;
    cin.ignore(); // Очищення символу нового рядка з буфера

    Person newPerson;
    cout << "\nВведіть дані для нової особи:\n";
    cout << "Прізвище: ";
    cin.getline(newPerson.lastName, sizeof(newPerson.lastName));

    cout << "Ім'я: ";
    cin.getline(newPerson.firstName, sizeof(newPerson.firstName));

    cout << "По батькові: ";
    cin.getline(newPerson.patronymic, sizeof(newPerson.patronymic));

    cout << "Адреса: ";
    cin.getline(newPerson.address, sizeof(newPerson.address));

    cout << "Номер телефону: ";
    cin.getline(newPerson.phoneNumber, sizeof(newPerson.phoneNumber));

    cout << "Вік: ";
    cin >> newPerson.age;

    addAfterIndex(filename, insertIndex, newPerson);

    cout << "\nВміст файлу після додавання:\n";
    printBinaryFileContents(filename);

    return 0;
}
