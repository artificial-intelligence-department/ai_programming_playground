#include <iostream>

// Структура для представлення вузла двозв'язного списку
struct Node 
{
    int data;      // Дані, які зберігаються в вузлі
    Node* next;    // Вказівник на наступний вузол
    Node* prev;    // Вказівник на попередній вузол

    // Конструктор ініціалізації вузла з вказаним значенням даних
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Клас для реалізації двозв'язного списку
class DoublyLinkedList 
{
private:
    Node* head;    // Вказівник на початковий вузол
    Node* tail;    // Вказівник на кінцевий вузол
    int size;      // Кількість елементів у списку

public:
    // Конструктор за замовчуванням ініціалізує вказівники як nullptr і розмір як 0
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Функція вставки елементів у вказану позицію
    void insert(int index, int N, int* values) 
    {
        Node* newNode;
        Node* current;

        for (int i = 0; i < N; ++i) 
        {
            newNode = new Node(values[i]);

            if (size == 0) 
            {
                head = tail = newNode;
            } 
            else if (index == 0) 
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            } 
            else if (index == size) 
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            } 
            else 
            {
                current = head;
                for (int j = 0; j < index; ++j) 
                {
                    current = current->next;
                }

                newNode->prev = current->prev;
                newNode->next = current;
                current->prev->next = newNode;
                current->prev = newNode;
            }

            ++size;
            ++index;
        }
    }

    // Функція видалення елементів з вказаної позиції
    void erase(int index, int n) 
    {
        while (n > 0 && index < size) 
        {
            Node* current = head;
            for (int i = 0; i < index; ++i) 
            {
                current = current->next;
            }

            Node* nextNode = current->next;

            if (current->prev) 
            {
                current->prev->next = nextNode;
            } 
            else 
            {
                head = nextNode;
            }

            if (nextNode) 
            {
                nextNode->prev = current->prev;
            } 
            else 
            {
                tail = current->prev;
            }

            delete current;
            --size;
            --n;
        }
    }

    // Функція отримання розміру списку
    void getSize() const 
    {
        std::cout << size << std::endl;
    }

    // Функція отримання значення елементу за індексом
    void get(int index) const 
    {
        if (index >= 0 && index < size) 
        {
            Node* current = head;

            for (int i = 0; i < index; i++) 
            {
                current = current->next;
            }

            std::cout << current->data << std::endl;
        } 
    }

    // Функція зміни значення елементу за індексом
    void set(int index, int value) 
    {
        if (index >= 0 && index < size) 
        {
            Node* current = head;

            for (int i = 0; i < index; i++) 
            {
                current = current->next;
            }

            current->data = value;
        } 
    }

    // Перегрузка оператора виводу для виведення списку
    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList& list) 
    {
        Node* current = list.head;

        while (current) {
            os << current->data << " ";
            current = current->next;
        }

        os << std::endl;
        return os;
    }

    // Деструктор для вивільнення пам'яті відведеної під вузли
    ~DoublyLinkedList() 
    {
        Node* current = head;
        while (current) 
        {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        size = 0;
    }
};

int main() 
{
    int Q;
    std::cin >> Q;

    DoublyLinkedList list;

    for (int i = 0; i < Q; i++) 
    {
        std::string userprint;
        std::cin >> userprint;

        if (userprint == "insert") 
        {
            int index, N;
            std::cin >> index >> N;

            int* values = new int[N];
            for (int j = 0; j < N; ++j) 
            {
                std::cin >> values[j];
            }

            list.insert(index, N, values);
            delete[] values;
        } 
        else if (userprint == "erase") 
        {
            int index, n;
            std::cin >> index >> n;
            list.erase(index, n);
        } 
        else if (userprint == "print") 
        {
            std::cout << list;
        } 
        else if (userprint == "size") 
        {
            list.getSize();
        } 
        else if (userprint == "get") 
        {
            int index;
            std::cin >> index;
            list.get(index);
        } 
        else if (userprint == "set") 
        {
            int index, value;
            std::cin >> index >> value;
            list.set(index, value);
        }
    }

    return 0;
}
