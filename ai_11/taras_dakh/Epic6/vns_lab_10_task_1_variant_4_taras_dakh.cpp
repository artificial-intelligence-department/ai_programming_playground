#include <iostream>
#include <fstream>

using namespace std;

// Структура елемента списку
struct Node {
    int key;
    Node* next;
};

// Функція для створення порожнього списку
Node* createList() {
    return nullptr;
}

// Функція для додавання елемента в список
void addElement(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Функція для друку списку
void printList(Node* head) {
    if (!head) {
        cout << "Список порожній" << endl;
    } else {
        Node* current = head;
        while (current) {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }
}

// Функція для знищення елемента списку за заданим номером
void deleteElement(Node*& head, int position) {
    if (!head) {
        cout << "Список порожній" << endl;
        return;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        Node* current = head;
        for (int i = 1; i < position - 1 && current; ++i) {
            current = current->next;
        }

        if (!current || !current->next) {
            cout << "Помилка: елемента з номером " << position << " не існує" << endl;
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}

// Функція для запису списку у файл
void writeToFile(Node* head, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Помилка відкриття файлу для запису" << endl;
        return;
    }

    Node* current = head;
    while (current) {
        file << current->key << " ";
        current = current->next;
    }

    file.close();
}

// Функція для знищення списку
void destroyList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Функція для відновлення списку з файлу
Node* restoreList(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Помилка відкриття файлу для читання" << endl;
        return nullptr;
    }

    Node* head = nullptr;
    int value;
    while (file >> value) {
        addElement(head, value);
    }

    file.close();
    return head;
}

// Функція для додавання K елементів, починаючи із заданого номера
void addKElements(Node*& head, int position, int K) {
    Node* current = head;
    for (int i = 1; i < position && current; ++i) {
        current = current->next;
    }

    if (!current) {
        cout << "Помилка: елемента з номером " << position << " не існує" << endl;
        return;
    }

    for (int i = 0; i < K; ++i) {
        int newValue;
        cout << "Введіть значення для нового елемента: ";
        cin >> newValue;
        addElement(current, newValue);
        current = current->next;
    }
}

int main() {
    Node* myList = createList();

    // Додавання елементів у список
    addElement(myList, 23);
    addElement(myList, 20);
    addElement(myList, 30);
    addElement(myList, 45);
    addElement(myList, 56);

    // Друк списку
    cout << "Список після додавання елементів: ";
    printList(myList);

    // Запит користувача про номер елемента для видалення
    int deletePosition;
    cout << "Введіть номер елемента для видалення: ";
    cin >> deletePosition;

    // Знищення елемента за заданим номером
    deleteElement(myList, deletePosition);
    cout << "Список після видалення елемента за номером " << deletePosition << ": ";
    printList(myList);

    // Додавання K елементів, починаючи із заданого номера
    int K;
    cout << "Введіть кількість елементів для додавання: ";
    cin >> K;
    addKElements(myList, deletePosition, K);
    cout << "Список після додавання " << K << " елементів за номером " << deletePosition << ": ";
    printList(myList);

    // Запис списку у файл
    writeToFile(myList, "mylist.txt");

    // Знищення списку
    destroyList(myList);
    cout << "Список після знищення: ";
    printList(myList);

    // Відновлення списку з файлу
    myList = restoreList("mylist.txt");
    cout << "Відновлений список: ";
    printList(myList);

    // Знищення відновленого списку
    destroyList(myList);
    cout << "Список після знищення відновленого: ";
    printList(myList);

    return 0;
}
