#include <iostream>
#include <fstream>
#include <string>
using namespace std;
enum FileOpResult { Success, Failure };

FileOpResult create_and_write_to_file(const char* file_name) {
    // Відкриття файлу для запису
    ofstream file(file_name);

    if (!file.is_open()) {
        cerr << "Error: Не вдається створити або відкрити файл '" << file_name << "'.\n";
        return FileOpResult::Failure;
    }

    // Читання даних з консолі та запис у файл
    string data;
    cout << "Напиши дані в файл(завершити Enter):\n";

    while (true) {
        getline(cin, data);

        if (data.empty()) {
            break;
        }

        file << data << endl;
    }

    // Закриття файлу
    file.close();

    cout << "Дані записані у файл '" << file_name << "'.\n";
    return FileOpResult::Success;
}

FileOpResult copy_file(const char* source_file, const char* destination_file) {
    // Відкриття файлу для читання
    ifstream source(source_file);

    if (!source.is_open()) {
        cerr << "Error: Неможливо відкрити вихідний файл '" << source_file << "'.\n";
        return FileOpResult::Failure;
    }

    // Відкриття файлу для запису
    ofstream destination(destination_file);

    if (!destination.is_open()) {
        cerr << "Error: Не вдається створити або відкрити цільовий файл '" << destination_file << "'.\n";
        source.close();
        return FileOpResult::Failure;
    }

    // Копіювання даних з одного файлу в інший
    string line;
    while (getline(source, line)) {
        destination << line << endl;
    }

    // Закриття файлів
    source.close();
    destination.close();

    cout << "Копіювання файлу успішне.\n";
    return FileOpResult::Success;
}

int main() {
    const char* input_file_name = "input.txt";
    const char* output_file_name = "output.txt";

    // Створення та запис даних у файл
    FileOpResult create_result = create_and_write_to_file(input_file_name);

    if (create_result == FileOpResult::Success) {
        // Копіювання даних у новий файл
        FileOpResult copy_result = copy_file(input_file_name, output_file_name);

        if (copy_result == FileOpResult::Success) {
            cout << "Копіювання файлу успішно завершено.\n";
        } else {
            cerr << "Помилка копіювання файлу.\n";
        }
    } else {
        cerr << "Помилка створення та запису файлу.\n";
    }

    return 0;
}