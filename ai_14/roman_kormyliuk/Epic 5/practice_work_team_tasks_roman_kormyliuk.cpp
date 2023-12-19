#include <iostream>
#include <fstream>
using namespace std;
enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name, const char *content) {
    // Перевірка на нульові вказівники
    if (name == nullptr || content == nullptr) {
        return Failure;
    }

    // Відкриття файлу для запису
    ofstream file(name);
    
    // Перевірка на успішне відкриття файла
    if (!file.is_open()) {
        return Failure;
    }

    // Запис вмісту у файл
    file << content << endl;

    // Перевірка на успішний запис
    if (file.fail()) {
        file.close();
        return Failure;
    }

    // Закриття файла
    file.close();

    // Успішне виконання
    return Success;
}

int main() {
    const char *filename = "example.txt";
    
    // Зчитування стрічки для запису в файл
    cout << "Введіть текст для запису в файл: ";
    string content;
    getline(cin, content);

    // Виклик функції для запису в файл
    FileOpResult result = write_to_file(filename, content.c_str());

    // Вивід результату
    if (result == Success) {
        cout << "Файл успішно створено та дані записано." << endl;
    } else {
        cout << "Помилка при створенні або запису в файл." << endl;
    }
    return 0;
}
