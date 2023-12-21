#include <iostream>
#include <fstream>
using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult copy_file(const char *file_from, const char *file_to) {
    ofstream file1(file_from); // Створення вихідного файлу

    if (!file1.is_open()) {
        cerr << "Failed to create source file." << endl;
        return Failure;
    }

    cout << "Enter text to copy to file '" << file_from << "':" << endl;

    string input_text;
    getline(cin, input_text); // Отримання введеного користувачем тексту

    file1 << input_text; // Запис введеного тексту у вихідний файл
    file1.close(); // Закриття вихідного файлу

    ifstream source(file_from, ios::binary); // Відкриття вихідного файлу для читання в бінарному режимі
    ofstream destination(file_to, ios::binary); // Відкриття цільового файлу для запису в бінарному режимі

    if (!source.is_open()) {
        cerr << "Failed to open source file." << endl;
        return Failure;
    }

    if (!destination.is_open()) {
        cerr << "Failed to open destination file." << endl;
        source.close();
        return Failure;
    }

    destination << source.rdbuf(); // Копіювання вмісту з вихідного файлу в цільовий файл

    source.close(); // Закриття вихідного файлу
    destination.close(); // Закриття цільового файлу

    return Success;
}

int main() {
    const char* file_from = "file_1.txt"; // Ім'я вихідного файлу
    const char* file_to = "file_2.txt"; // Ім'я цільового файлу

    FileOpResult result = copy_file(file_from, file_to);

    if (result == Success) {
        cout << "File copying completed successfully." << endl;
    } else {
        cout << "Failed to copy file." << endl;
    }

    return 0;
}
