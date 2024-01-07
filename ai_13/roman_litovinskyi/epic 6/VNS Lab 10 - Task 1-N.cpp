#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Функція для запису списку у файл
void zapis_do_failu(const vector<int>& lista, const string& nazva_failu) {
    ofstream file(nazva_failu);

    if (file.is_open()) {
        for (const auto& elem : lista) {
            file << elem << " ";
        }
        file.close();
        cout << "list successfully saved to file " << nazva_failu << endl;
    } else {
        cout << "Error opening file for writing!" << endl;
    }
}

// Функція для виведення списку
void druk_spysku(const vector<int>& lista) {
    if (lista.empty()) {
        cout << "the list is empty" << endl;
    } else {
        cout << "List: ";
        for (const auto& elem : lista) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> lista = {1, 2, 3, 4, 5}; // Приклад списку

    // Записуємо список у файл
    zapis_do_failu(lista, "spysok.txt");

    // Очищуємо список
    lista.clear();

    // Виводимо список
    druk_spysku(lista);

    return 0;
}
