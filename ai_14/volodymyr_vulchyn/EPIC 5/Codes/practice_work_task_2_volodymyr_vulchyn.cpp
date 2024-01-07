#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char* name, const char* content) {
    // Відкриття файлу для запису
    ofstream file(name);

    // Перевірка, чи файл вдалося відкрити
    if (!file.is_open()) {
        return Failure;
    }

    // Запис стрічки у файл
    file << content;

    // Перевірка, чи відбулося правильне закриття файлу
    if (file.fail()) {
        return Failure;
    }

    // Файл успішно створено та дані записано
    return Success;
}

FileOpResult copy_file(char* file_from, char* file_to) {
    // Відкриття вхідного файлу для читання
    ifstream initialFile(file_from, ios::binary);

    // Перевірка, чи вхідний файл вдалося відкрити
    if (!initialFile.is_open()) {
        return Failure;
    }

    // Відкриття цільового файлу для запису
    ofstream lastFile(file_to, ios::binary);

    // Перевірка, чи цільовий файл вдалося відкрити
    if (!lastFile.is_open()) {
        return Failure;
    }

    // Копіювання вмісту файла
    lastFile << initialFile.rdbuf();

    // Перевірка, чи відбулося правильне закриття обох файлів
    if (initialFile.fail() || lastFile.fail()) {
        return Failure;
    }

    // Файл успішно скопійовано
    return Success;
}

int main() {
    // Введення імені вихідного та цільового файлів
    char initialFileName[100];
    char lastFileName[100];

    cout << "Вкажіть файл, з якого хочете скопіювати інофрмацію: ";
    cin >> initialFileName;

    cout << "Вкажіть назву файлу, в який хочете вставити інформацію: ";
    cin >> lastFileName;

    // Виклик функції для копіювання файлу
    FileOpResult result = copy_file(initialFileName, lastFileName);

    // Виведення результату
    if (result == Success) {
        cout << "Елементи файлy: " << "(" << initialFileName << ")" <<  " успішно скопійовані в файл " << "(" << lastFileName << ")"<< endl;
    } else {
        cout << "Помилка при копіюванні даних." << endl;
    }

    return 0;
}