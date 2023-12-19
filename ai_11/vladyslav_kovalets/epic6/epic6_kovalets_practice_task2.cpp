#include <iostream>

// Вузол списку
struct Node 
{
    int data;      // Дані, які вузол містить 
    Node* next;    // Вказівник на наступний вузол у списку

    // Конструктор для створення вузла з заданим значенням даних
    Node(int val) : data(val), next(nullptr) {}
};

bool compare(Node* h1, Node* h2) 
{
    if (h1->data != h2->data) 
    {
        // Якщо дані в вузлах не збігаються
        return false;
    }
    while (h1 != nullptr && h2 != nullptr) 
    {
        // Переходимо до наступних вузлів у обох списках
        h1 = h1->next;
        h2 = h2->next;
    }
    // Одна з умов: або обидва списки закінчилися одночасно, або один з них не закінчився, а інший закінчився раніше
    // У обох випадках список однаковий до цього моменту
    return (h1 == nullptr && h2 == nullptr);
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
    // Створюємо перший список 1 - 2 - 3 - 4 - 5
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);

    // Створюємо другий список 6 - 7 - 8 - 9 -10
    Node* head2 = new Node(6);
    head2->next = new Node(7);
    head2->next->next = new Node(8);
    head2->next->next->next = new Node(9);
    head2->next->next->next->next = new Node(10);

    // Виводимо обидва списки
    std::cout << "Список №1";
    printList(head1);
    std::cout << "Список №2";
    printList(head2);

    // Порівнюємо списки і виводимо результат
    if (compare(head1, head2)) 
    {
        std::cout << "Списки однакові" << std::endl;
    }

    else 
    {
        std::cout << "Списки різні" << std::endl;
    }

    // Звільняємо пам'ять від обох списків
    while (head1 != nullptr) 
    {
        Node* temp = head1;
        head1 = head1->next;
        delete temp;
    }

    while (head2 != nullptr) 
    {
        Node* temp = head2;
        head2 = head2->next;
        delete temp;
    }

    return 0;
}
