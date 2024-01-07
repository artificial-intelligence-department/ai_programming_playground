#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct Video { //Структура
    string title;
    string director;
    int duration;
    float price;
};


void createFile(const char* filename, Video* data, int size) { //створюємо файл 
    ofstream file(filename, ios::binary);//створюємо

    if (!file) { //якщо нема змоги відкрити файл помилка
        cerr << "Помилка: не вдалося відкрити файл для запису." << endl; //вивід помилки
        return;
    }

    file.write(reinterpret_cast<char*>(data), size * sizeof(Video));//записуємо файл та переводити масив структ у чар
    file.close();//закриваємо файл задля збереження файлів
}


void printFile(const char* filename, int size) {// друк вмісту файлу
    ifstream file(filename, ios::binary);// записуємо в файл

    if (!file) {
        cerr << "Помилка: не вдалося відкрити файл для читання." << endl;
        return;
    }

    Video* data = new Video[size];
    file.read(reinterpret_cast<char*>(data), size * sizeof(Video));
    file.close();

    for (int i = 0; i < size; ++i) {
        cout << "Element " << i + 1 << ":\n";
        cout << "Name of Movie: " << data[i].title << endl;
        cout << "Producer: " << data[i].director << endl;
        cout << "Lenght: " << data[i].duration << " minuts\n";
        cout << "Price: " << data[i].price << " grn\n\n";
    }

    delete[] data;
}

//додавання елементів в кінець файлу
void addElements(const char* filename, Video* newData, int newSize) {
    ofstream file(filename, ios::binary | ios::app);

    if (!file) {
        cerr << "Помилка: не вдалося відкрити файл для запису." << endl;
        return;
    }

    file.write(reinterpret_cast<char*>(newData), newSize * sizeof(Video));
    file.close();
}

//знищення елементів з ціною вищою заданої
void deleteElements(const char* filename, float maxPrice) {
    ifstream file(filename, ios::binary);

    if (!file) {
        cerr << "Помилка: не вдалося відкрити файл для читання." << endl;
        return;
    }

    ofstream tempFile("temp.txt", ios::binary);

    if (!tempFile) {
        cerr << "Помилка: не вдалося відкрити тимчасовий файл для запису." << endl;
        file.close();
        return;
    }

    Video temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(Video))) { 
        if (temp.price <= maxPrice) { // перевіряє чи ціна не перевищує вказану
            tempFile.write(reinterpret_cast<char*>(&temp), sizeof(Video)); //додає до тимчасового файлу
        }
    }

    file.close();
    tempFile.close();

    remove(filename);//видаляє орігінальний файл 
    rename("temp.txt", filename); //перейменовує тимчасовий
}

int main() {
    const char* filename = "casetta.txt";
    const int initialSize = 3; // Початковий розмір файлу
    const float maxprice = 50.0; // Максимальна ціна для знищення елементів

    Video initialData[initialSize] = {
        {"Movie 1", "Producer 1", 120, 40.0},
        {"Movie 2", "Producer 2", 90, 35.0},
        {"Movie 3", "Producer 3", 110, 55.0}
    };

    createFile(filename, initialData, initialSize);//формування файлу з даними

    
    cout << "Початковий вміст файлу:\n";//друк вмісту файл
    printFile(filename, initialSize);

    
    deleteElements(filename, maxprice);// видалення з ціною вищою 

    
    cout << "\nВміст файлу після знищення елементів з ціною вищою за " << maxprice << ":\n";//  вміст файлу після видалення
    printFile(filename, initialSize);

    // Додавання 3 елементів в кінець файлу
    const int newSize = 3;
    Video newElements[newSize] = {
        {"Movie 4", "Producer 4", 100, 45.0},
        {"Movie 5", "Producer 5", 80, 30.0},
        {"Movie 6", "Producer 6", 95, 50.0}
    };

    addElements(filename, newElements, newSize);

    
    cout << "\nВміст файлу після додавання 3 елементів:\n";  //  вміст файлу після додавання
    printFile(filename, initialSize + newSize);

    return 0;
}
