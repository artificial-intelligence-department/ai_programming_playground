#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult copy_file(const char* file_from, const char* file_to) {
    // Відкриття вхідного файлу для читання
    ifstream input_file(file_from, ios::binary);
    if (!input_file.is_open()) {
        cerr << "Error opening input file: " << file_from << endl;
        return FileOpResult::Failure;
    }

    // Відкриття вихідного файлу для запису
    ofstream output_file(file_to, ios::binary);
    if (!output_file.is_open()) {
        cerr << "Error opening output file: " << file_to << endl;
        return FileOpResult::Failure;
    }

    // Копіювання вмісту з вхідного файлу в вихідний
    output_file << input_file.rdbuf();

    // Перевірка на помилки читання або запису
    if (!output_file.good() || !input_file.eof()) {
        cerr << "Error copying content from " << file_from << " to " << file_to << endl;
        return FileOpResult::Failure;
    }

    // Закриття файлів
    input_file.close();
    output_file.close();

    return FileOpResult::Success;
}

int main() {
    const char* file_from = "input.txt";  // Шлях до вхідного файлу
    const char* file_to = "output.txt";   // Шлях до вихідного файлу

    FileOpResult result = copy_file(file_from, file_to);

    if (result == FileOpResult::Success) {
        cout << "File copy successful!" << endl;
    } else {
        cerr << "File copy failed." << endl;
    }

    return 0;
}
