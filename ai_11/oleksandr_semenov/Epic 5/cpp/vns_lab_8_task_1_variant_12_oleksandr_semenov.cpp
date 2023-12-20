#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <filesystem>

using namespace std;

// Структура для представлення музичного диска
struct MusicDisc {
    string title;
    string author;
    int duration;  // тривалість
    float price;
};

// Функція для друкованого виведення елементів музичного диска
void printMusicDisc(const MusicDisc& disc) {
    cout << "Назва: " << disc.title << endl;
    cout << "Автор: " << disc.author << endl;
    cout << "Тривалість: " << disc.duration << " хвилин" << endl;
    cout << "Ціна: $" << disc.price << endl << endl;
}

// Функція для додавання елементів після заданого номера
void addElementsAfter(vector<MusicDisc>& discs, int afterIndex) {
    // Створення нових елементів
    MusicDisc newDisc1 = {"Новий Диск 1", "Новий Автор 1", 5, 10.99};
    MusicDisc newDisc2 = {"Новий Диск 2", "Новий Автор 2", 4, 12.99};

    // Вставка нових елементів після заданого номера
    discs.insert(discs.begin() + afterIndex + 1, {newDisc1, newDisc2});
}

// Функція для знищення елемента з заданою тривалістю
void deleteElementByDuration(vector<MusicDisc>& discs, int targetDuration) {
    // Пошук індексу елемента з заданою тривалістю
    auto it = find_if(discs.begin(), discs.end(),
                           [targetDuration](const MusicDisc& disc) {
                               return disc.duration == targetDuration;
                           });

    // Знищення першого знайденого елемента (якщо такий існує)
    if (it != discs.end()) {
        discs.erase(it);
    }
}

int main() {
    filesystem::path newDirectory = "D:\\LAB 8"; // Замініть це на власний шлях
    // Перевірка існування та створення нової директорії
    if (!filesystem::exists(newDirectory))
        filesystem::create_directory(newDirectory);

    // Зміна поточної директорії на нову
    filesystem::current_path(newDirectory);
    filesystem::path currentPath = filesystem::current_path();
    cout << "Поточна директорія: " << currentPath << endl;
    vector<MusicDisc> musicCollection;

    // Додавання декількох елементів у колекцію (можна використати власні дані)
    musicCollection.push_back({"AM", "Arctic Monkeys", 30, 9.99});
    musicCollection.push_back({"Encore ", "Eminem", 40, 14.99});
    musicCollection.push_back({"After Hours", "The Weeknd", 55, 12.49});

    // Відкриття файлу для запису у бінарному режимі
    ofstream outFile("music_collection.bin", ios::binary);

    // Перевірка на успішність відкриття файлу
    if (!outFile.is_open()) {
        cerr << "Помилка відкриття файлу для запису." << endl;
        return 1;  // Повернення коду помилки
    }

    // Запис елементів у файл
    outFile.write(reinterpret_cast<const char*>(musicCollection.data()),
                  musicCollection.size() * sizeof(MusicDisc));

    // Закриття файлу
    outFile.close();

    // Друк вмісту файлу
    ifstream inFile("music_collection.bin", ios::binary);

    // Перевірка на успішність відкриття файлу
    if (!inFile.is_open()) {
        cerr << "Помилка відкриття файлу для читання." << endl;
        return 1;  // Повернення коду помилки
    }

    // Зчитування елементів з файлу
    musicCollection.clear();
    musicCollection.resize(3);  // Резервування місця для зчитування трьох елементів
    inFile.read(reinterpret_cast<char*>(musicCollection.data()),
                musicCollection.size() * sizeof(MusicDisc));

    // Друк вмісту зчитаного файла
    cout << "Вміст файлу після запису:" << endl;
    for (const auto& disc : musicCollection) {
        printMusicDisc(disc);
    }

    // Закриття файлу
    inFile.close();

    // Виклик функцій для знищення та додавання елементів
    deleteElementByDuration(musicCollection, 5);
    addElementsAfter(musicCollection, 1);

    // Відкриття файлу для запису знову
    outFile.open("music_collection.bin", ios::binary | ios::trunc);

    // Перевірка на успішність відкриття файлу
    if (!outFile.is_open()) {
        cerr << "Помилка відкриття файлу для запису." << endl;
        return 1;  // Повернення коду помилки
    }

    // Запис елементів після змін до файлу
    outFile.write(reinterpret_cast<const char*>(musicCollection.data()),
                  musicCollection.size() * sizeof(MusicDisc));

    // Закриття файлу
    outFile.close();

    // Друк вмісту зміненого файлу
    inFile.open("music_collection.bin", ios::binary);

return 0;

}