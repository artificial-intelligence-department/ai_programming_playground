#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;
    Node *end;

public:
    LinkedList()
    {
        head = NULL;
        end = NULL;
    }

    void insertStart(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;

        if (head == NULL)
        {
            newNode->next = newNode;
            head = newNode;
            end = newNode;
        }
        else
        {
            newNode->next = head;
            end->next = newNode;
            head = newNode;
        }
    }
void insertLast(int data)
{
    Node *newNode = new Node();
    newNode->data = data;

    if (head == NULL)
    {
        // If the list is empty, make the new node point to itself
        newNode->next = newNode;
        head = newNode;
        end = newNode;
    }
    else
    {
        end->next = newNode; // Update the reference in the current end node
        end = newNode;       // Update the end to the new node
        end->next = head;     // Update the reference in the new end node
    }
}

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty \n";
            return;
        }

        Node *node = head;//ноде стає вказівником на голову

        do //тепер видруковуємо від першої ноди і поки знов не буде нодою
        {
            cout << node->data << " ";
            node = node->next;
        } while (node != head);

        cout <<"\n";
    }

    void displayFromK(int k)
    {
        if (head == NULL)
        {
            cout << "List is empty \n";
            return;
        }

        Node *firstNode = head;

        for (int i = 0; i < k; ++i) //переміщуємось в к вузол
        {
            firstNode = firstNode->next;
            if (firstNode == head)
            {
                display();
                return;
            }
        }

        Node *node = firstNode; // фірстнод це к вузол
        do
        {
            cout << node->data << " ";
            node = node->next;
        } while (node != head);

        node = head; // перехід до початку списау
        while (node != firstNode) // цикл завершується коли нод дійде до вузла на який вказує фірстнод
        {
            cout << node->data << " ";
            node = node->next;
        }

        cout << "\n";
    }

    void deleteNode(Node *del) // метод видаляє вказаний вузол del
    {
        if (del == head) // перевіряєм чи видаляється голова
        {
            if (head->next == head) //перевірка чи олова єдиний вузол
            {
                delete del; //звільнення памяті під цей вузол
                head = NULL; //порожній, тому встановлюємо в нуль
                end = NULL;
                return;
            }

            head = head->next; //зміна голови на наступний вузол
            end->next = head; //бо список порожній
        }
        else
        {
            Node *temp = head;
            while (temp->next != head && temp->next != del) // шукає вузол перед тим шо видаляється або поки не кінець
            {
                temp = temp->next;
            }

            if (temp->next == head) //перевірка чи дійшли до кінця списку
            {
                return;
            }

            temp->next = del->next; //кажем шоб некст (вказує на те саме шо видалений)однаковий був

            if (del == end){
                end = temp;}
        }

        delete del;
    }

    void deleteEvenNodes(){
        Node *ptr = head;
        while (ptr != NULL){
            Node *next = ptr->next;
            if (ptr->data % 2 == 0) {
                deleteNode(ptr); }
            ptr = next;
            if (ptr == head){
                break;}
        }
    }
};

int main()
{
    LinkedList *list = new LinkedList();
    list->insertStart(5);
    list->insertStart(10);
    list->insertStart(15);
    list->insertStart(20);
    list->insertStart(25);
    list->insertStart(30);
    list->insertStart(35);
    cout << "Original List: ";
    list->display();
    cout << "Original List from K to (K-1): ";
    list->displayFromK(3);
    cout << "List after deleting even nodes: ";
    list->deleteEvenNodes();
    list->displayFromK(2);
    list->insertLast(40);
    list->insertLast(45);
    list->insertStart(6);
    cout << "List after appending elements to the end: ";
    list->display();
    return 0;
}
