#include <iostream>

// Вузол списку
struct Node 
{
    int data;      // Дані, які вузол містить 
    Node* next;    // Вказівник на наступний вузол у списку
    // Конструктор для створення вузла з заданим значенням даних
    Node(int val) : data(val), next(nullptr) {}
};

Node* add(Node* n1, Node* n2) 
{
    Node* head = nullptr;
    Node* tail = nullptr;
    int suma = 0;

    while (n1 != nullptr || n2 != nullptr || suma != 0) 
    {
        int value0 = (n1 != nullptr) ? n1->data : 0;
        int value1 = (n2 != nullptr) ? n2->data : 0;

        int sum = value0 + value1 + suma;
        suma = sum / 10;  // Визначаємо перенос
        int digit = sum % 10;  // Отримуємо значення розряду

        // Створюємо новий вузол з отриманим значенням розряду
        Node* newNode = new Node(digit);

        // Додаємо новий вузол до кінця результативного списку
        if (head == nullptr) 
        {
            head = newNode;
            tail = newNode;
        } 
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }

        // Переходимо до наступного розряду у обох вхідних списках (якщо вони не закінчилися)
        if (n1 != nullptr) n1 = n1->next;
        if (n2 != nullptr) n2 = n2->next;
    }

    return head;
}

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
    Node* num1 = new Node(3);
    num1->next = new Node(7);
    num1->next->next = new Node(9);

    Node* num2 = new Node(9);
    num2->next = new Node(2);
    num2->next->next = new Node(5);

    Node* result = add(num1, num2);

    // Вивід результату
    std::cout << "Список " << std::endl;
    printList(num1);
    std::cout << "Список " << std::endl;
    printList(num2);
    std::cout << "Сума " << std::endl;
    printList(result);

    // Звільняємо пам'ять від списків
    while (num1 != nullptr) 
    {
        Node* temp = num1;
        num1 = num1->next;
        delete temp;
    }

    while (num2 != nullptr) 
    {
        Node* temp = num2;
        num2 = num2->next;
        delete temp;
    }

    while (result != nullptr) 
    {
        Node* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
