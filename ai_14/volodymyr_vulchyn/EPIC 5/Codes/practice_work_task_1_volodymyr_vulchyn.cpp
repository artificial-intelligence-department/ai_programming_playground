#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char* name, const char* content) {
    // Відкриваємо файл для запису 
    ofstream file(name);

    // Перевіряємо, чи вдалося записати файл
    if (!file.is_open()) {
        return Failure;
    }

    // Записуємо введене у файл
    file << content;

    // Перевіряємо, чи файл нормально закрився
    if (file.fail()) {
        return Failure;
    }

    // Повертаємо саксес, якщо файл було створено та все записано
    return Success;
}

int main() {
    // Вводимо ім'я файлу та самої стрічки для запису
    char filename[15];
    char content[150];

    cout << "Вкажіть ім'я файлу: ";
    cin >> filename;

    cout << "Введіть, те, чим хочете заповнити файл: ";
    cin.ignore();  
    cin.getline(content, sizeof(content));

    // Викликаємо фанкшен, для запису у файл
    FileOpResult result = write_to_file(filename, content);

    // Виводимо відповідний результат
    if (result == Success) {
        cout << "Файл УСПІШНО створений, та у ньому записані ваші введеня! <3" << endl;
    } else {
        cout << "ПОМИЛКА створення файлу, або ж ПОМИЛКА запису. :( " << endl;
    }

    return 0;
}
