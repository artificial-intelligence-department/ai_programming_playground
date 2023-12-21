#include <iostream>

// Вузол списку
struct Node 
{
    int data;      // Дані, які вузол містить 
    Node* next;    // Вказівник на наступний вузол у списку

    // Конструктор для створення вузла з заданим значенням даних
    Node(int val) : data(val), next(nullptr) {}
};

// Метод для реверсу списку
Node* reverse(Node* head) 
{
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) 
    {
        next = current->next; //  Зберігаємо посилання на наступний вузол у змінній next щоб не втратити його при зміні посилань в наступних кроках
        current->next = prev; // змінюємо вказівник next поточного вузла,вказуючи його на попередній вузол
        prev = current; // Переміщуємо prev на поточний вузол тепер це стає попереднім вузлом для наступного кроку
        current = next; // Переміщуємо current на наступний вузол у списку
    }

    return prev;  // новий початок списку
}

// метод для виведення списку
void printList(Node* head) 
{
    while (head != nullptr) 
    {
        std::cout << head->data <<" ";
        head = head->next;
    }

    std::cout << std::endl;
}

int main() 
{
    // Створюємо вхідний список 1 - 2 - 3 - 4 - 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Виводимо вхідний список
    std::cout << "список";
    printList(head);

    // Реверсуємо список
    head = reverse(head);

    // Виводимо обернений список
    std::cout << "Реверс списку(обернений)";
    printList(head);

    // Звільняємо пам'ять від списку
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
