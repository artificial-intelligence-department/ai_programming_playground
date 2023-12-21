#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeToFile(const string& filename, const string& content) {
    ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
        cout << "Записано в файл: " << filename << endl;
    } else {
        cerr << "Помилка відкриття файлу: " << filename << endl;
    }
}

void appendToFile(const string& filename, const string& content) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << content;
        file.close();
        cout << "Дописано в файл: " << filename << endl;
    } else {
        cerr << "Помилка відкриття файлу: " << filename << endl;
    }
}

void copyFile(const string& source, const string& destination, bool appendToEnd = false) {
    ifstream sourceFile(source);
    ofstream destFile(destination, (appendToEnd ? ios::app : ios::trunc));

    if (sourceFile.is_open() && destFile.is_open()) {
        destFile << sourceFile.rdbuf();
        sourceFile.close();
        destFile.close();
        cout << "Файл скопійовано: " << source << " -> " << destination << endl;
    } else {
        cerr << "Помилка відкриття файлу: " << source << " або " << destination << endl;
    }
}

void deleteFile(const string& filename) {
    cout << "Ви впевнені, що хочете видалити файл " << filename << "? (yes/no): ";
    string confirmation;
    cin >> confirmation;

    if (confirmation == "yes") {
        if (remove(filename.c_str()) == 0) {
            cout << "Файл видалено: " << filename << endl;
        } else {
            cerr << "Помилка видалення файлу: " << filename << endl;
        }
    } else {
        cout << "Видалення відмінено." << endl;
    }
}

void printHelp() {
    cout << endl;
    cout << "Доступні команди:" << endl;
    cout << "write <filename> <content>: записати вміст у файл до символу '\\'" << endl;
    cout << "toAdd <filename> <content>: дописати вміст у кінець файлу до символу '\\'" << endl;
    cout << "copy <source> <destination> [appendToEnd/end]: скопіювати вміст файлу" << endl;
    cout << "dell <filename>: видалити файл" << endl;
    cout << "help: вивести це повідомлення" << endl;
    cout << "end: завершити програму" << endl;
}

int main() {
    string command;

    while (true) {
        cout << endl << "Введіть команду: ";
        cin >> command;

        if (command == "write") {
            string filename, content;
            cin >> filename;
            cin.ignore();
            getline(cin, content, '\\');
            writeToFile(filename, content);
        } else if (command == "toAdd") {
            string filename, content;
            cin >> filename;
            cin.ignore();
            getline(cin, content, '\\');
            appendToFile(filename, content);
        } else if (command == "copy") {
            string source, destination, option;
            cin >> source >> destination >> option;
            bool appendToEnd = (option == "appendToEnd" || option == "end");
            copyFile(source, destination, appendToEnd);
        } else if (command == "dell") {
            string filename;
            cin >> filename;
            deleteFile(filename);
        } else if (command == "help") {
            printHelp();
        } else if (command == "end") {
            cout << "Завершення програми." << endl;
            break;
        } else {
            cout << "Невідома команда. Введіть 'help' для виведення списку команд." << endl;
        }
    }

    return 0;
}
