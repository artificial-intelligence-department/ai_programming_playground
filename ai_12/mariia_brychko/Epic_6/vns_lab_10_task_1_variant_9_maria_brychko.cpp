#include <iostream>
#include <fstream>
using namespace std;

// Структура вузла списку
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

//клас для двонаправленого списку
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

     // Функція для створення списку
    void createList() {
        int n;
        cout << "Enter the number of elements: ";
        cin >> n;

        for (int i = 0; i < n; ++i) {
            int key;
            cout << "Enter the key value for the element " << i + 1 << ": ";
            cin >> key;

            Node* newNode = new Node(key);

            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }
    }

// Функція для додавання К елементів в кінець списку
void addElementsToEnd(int K) {
    for (int i = 0; i < K; ++i) {
        int value;
        cout << "Enter value for element " << i + 1 << ": ";
        cin >> value;

        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
}

// Функція для видалення K елементів перед елементом з номером index
void deleteKBeforeElement(int K, int index) {
    Node* current = head;

    // Перехід до вузла з номером index
    for (int i = 0; i < index && current != nullptr; ++i) {
        current = current->next;
    }

    if (current == nullptr || current == head) {
        // Вузол з номером index не знайдено або видалення не можливе
        return;
    }

    Node* prevNode = current->prev; // Вказівник на елемент перед видаляємими

    // Перехід до елемента, який потрібно видалити
    for (int i = 0; i < K && prevNode != nullptr; ++i) {
        Node* temp = prevNode;
        prevNode = prevNode->prev;
        
        if (temp == head) {
            head = current;
        }

        if (temp->prev != nullptr) {
            temp->prev->next = current;
        }

        current->prev = temp->prev;
        delete temp;
    }
}

    // Функція для друку списку
void printList() {
    Node* current = head;

    if (current == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    cout << "Elements in the list: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Функція для запису списку у файл
void writeToFile(const string& filename) {
    ofstream file(filename);

    if (!file) {
        cerr << "Unable to open the file" << endl;
        return;
    }

    Node* temp = head;

    while (temp != nullptr) {
        file << temp->data << " ";
        temp = temp->next;
    }

    file.close();
    cout << "List has been written to the file" << endl;
}

    // Функція для знищення списку
 void deleteList() {
    Node* current = head;
    Node* next;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
    tail = nullptr;

    cout << "List has been deleted" << endl;
}

 // Функція для відновлення списку з файлу
void restoreFromFile(const string& filename) {
    ifstream file(filename);

    if (!file) {
        cerr << "Unable to open the file" << endl;
        return;
    }

    int value;
    while (file >> value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    file.close();
    cout << "List has been restored from the file" << endl;
    }
};

int main() {
    DoublyLinkedList list;

    // Створення списку
    list.createList();

    // Виведення списку після створення
    cout << "List after creation:" << endl;
    list.printList();

   // Додавання K елементів в кінець списку
    int K;
    cout << "Enter the number of elements to add at the end: ";
    cin >> K;
    list.addElementsToEnd(K);

    // Знищення K елементів перед елементом із заданим номером index
    int index;
    cout << "Enter the index of the element before which to delete " << K << " elements: ";
    cin >> index;
    index = index-1;
    list.deleteKBeforeElement(K, index);

    // Виведення списку після додавання та видалення елементів
    cout << "List after adding and deleting elements:" << endl;
    list.printList();

    // Запис списку у файл
    string filename = "list.txt";
    list.writeToFile(filename);

    // Знищення списку
    list.deleteList();

    // Відновлення списку з файлу
    list.restoreFromFile(filename);

    // Виведення списку після відновлення
    cout << "List after restoration:" << endl;
    list.printList();

    return 0;
}