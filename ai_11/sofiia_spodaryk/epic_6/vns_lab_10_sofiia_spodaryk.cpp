#include <iostream>
#include <fstream>
using namespace std;

// Визначення вузла в подвійному зв'язаному списку
struct Node {
    char* key;   // Дані, що зберігаються в вузлі
    Node* next;  // Вказівник на наступний вузол у списку
    Node* prev;  // Вказівник на попередній вузол у списку

    // Конструктор для ініціалізації вузла заданим ключем
    Node(const char* k) : next(nullptr), prev(nullptr) {
        key = new char[strlen(k) + 1];  // Виділення пам'яті під ключ
        strcpy(key, k);  // Копіювання ключа у виділену пам'ять
    }

    // Деструктор для звільнення виділеної пам'яті для ключа
    ~Node() {
        delete[] key;
    }
};

// Визначення подвійного зв'язаного списку
class DoublyLinkedList {
private:
    Node* head;  // Вказівник на перший вузол у списку
    Node* tail;  // Вказівник на останній вузол у списку

public:
    // Конструктор для ініціалізації порожнього списку
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Функція для додавання елемента на початок списку
    void addElementToFront(const char* k) {
        Node* newNode = new Node(k);

        // Якщо список порожній, встановлюємо як голову і хвіст новий вузол
        if (!head) {
            head = tail = newNode;
        } else {
            // Інакше оновлюємо вказівники, щоб вставити на початок
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Функція для додавання елемента в кінець списку
    void addElementToBack(const char* k) {
        Node* newNode = new Node(k);

        // Якщо список порожній, встановлюємо як голову і хвіст новий вузол
        if (!tail) {
            head = tail = newNode;
        } else {
            // Інакше оновлюємо вказівники, щоб вставити в кінець
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Функція для виведення елементів списку
    void printList() const {
        if (!head) {
            cout << "Список порожній" <<endl;
            return;
        }

        // Проходження списку і виведення кожного елемента
        Node* current = head;
        while (current) {
            cout << current->key << " ";
            current = current->next;
        }
        cout <<endl;
    }

    // Функція для видалення елемента з заданим ключем
    void deleteElement(const char* k) {
        Node* current = head;

        // Проходження списку для знаходження вузла з заданим ключем
        while (current) {
            if (strcmp(current->key, k) == 0) {
                // Оновлення вказівників, щоб пропустити вузол, який слід видалити
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }

                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }

                // Видалення вузла та повернення
                delete current;
                return;
            }

            // Перехід до наступного вузла
            current = current->next;
        }

        // Якщо ключ не знайдено, вивести повідомлення
        cout << "Елемент з ключем " << k << " не знайдений." <<endl;
    }

    // Функція для видалення всього списку
    void deleteList() {
        Node* current = head;

        // Проходження списку та видалення кожного вузла
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }

        // Встановлення голови і хвоста в nullptr, щоб позначити порожній список
        head = tail = nullptr;
    }

    // Функція для збереження списку у файл
    void saveToFile(const char* filename) const {
        ofstream outFile(filename);

        // Перевірка, чи файл успішно відкрито
        if (!outFile.is_open()) {
            cerr << "Не вдалося відкрити файл для запису." <<endl;
            return;
        }

        // Проходження списку і запис кожного елемента у файл
        Node* current = head;
        while (current) {
            outFile << current->key <<endl;
            current = current->next;
        }

        // Закриття файлу
        outFile.close();
    }

    // Функція для відновлення списку з файлу
    void restoreFromFile(const char* filename) {
        ifstream inFile(filename);

        // Перевірка, чи файл успішно відкрито
        if (!inFile.is_open()) {
            cerr << "Не вдалося відкрити файл для читання." <<endl;
            return;
        }

        // Видалення поточного списку перед відновленням
        deleteList();

        char buffer[100];
        // Читання кожного рядка з файлу і додавання його до списку
        while (inFile.getline(buffer, sizeof(buffer))) {
            addElementToBack(buffer);
        }

        // Закриття файлу
        inFile.close();
    }
};

int main() {
    DoublyLinkedList myList;

    // Додавання елементів на початок і в кінець списку
    myList.addElementToFront("One");
    myList.addElementToFront("Two");
    myList.addElementToBack("Three");
    myList.addElementToBack("Four");

    // Виведення початкового списку
    cout << "Початковий список:" <<endl;
    myList.printList();

    // Збереження списку у файл
    myList.saveToFile("myList.txt");

    // Видалення елементу з ключем "Two"
    myList.deleteElement("Two");

    // Виведення оновленого списку
    cout << "Список після видалення елементу з ключем \"Two\":" <<endl;
    myList.printList();

    // Додавання ще декількох елементів на початок і в кінець
    myList.addElementToFront("Five");
    myList.addElementToBack("Six");

    // Виведення оновленого списку
    cout << "Список після додавання \"Five\" на початок і \"Six\" в кінець:" <<endl;
    myList.printList();

    // Збереження оновленого списку у файл
    myList.saveToFile("myList_updated.txt");

    // Видалення всього списку
    myList.deleteList();

    // Виведення списку після видалення
    cout << "Список після повного видалення:" <<endl;
    myList.printList();

    // Відновлення списку з файлу
    myList.restoreFromFile("myList_updated.txt");

    // Виведення відновленого списку
    cout << "Відновлений список:" <<endl;
    myList.printList();

    return 0;
}