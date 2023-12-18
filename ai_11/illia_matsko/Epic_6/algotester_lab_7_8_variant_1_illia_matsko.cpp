#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;

    Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

template <class T>
class DoubleLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    int size = 0;

    void insert(int index, T value) {
        Node<T>* newNode = new Node<T>(value);
        if (size == 0) {
            head = tail = newNode;
            tail->next = head;
            head->prev = tail;
        } else if (index == 0) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            tail->next = head;
            head->prev = tail;
        } else if(index == size) {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
            head->prev = tail;
        } else {
            Node<T>* NodeToInsertBefore = head;
            while (index > 0) {
                NodeToInsertBefore = NodeToInsertBefore->next;
                index--;
            }

            newNode->next = NodeToInsertBefore;
            newNode->prev = NodeToInsertBefore->prev;
            NodeToInsertBefore->prev->next = newNode; // Оновити посилання на наступний вузол для попереднього вузла
            NodeToInsertBefore->prev = newNode; // Оновити посилання на попередній вузол для вставленого вузла
        }

        size++;
    }

    void erase(int index, int n) {
        Node<T>* NodeToErase = head;
        while (index > 0) {
            NodeToErase = NodeToErase->next;
            index--;
        }

        if(NodeToErase == head) {
            head = NodeToErase->next;
            tail->next = head;
            head->prev = tail;
        } else if(NodeToErase == tail) {
            tail = NodeToErase->prev;
            tail->next = head;
            head->prev = tail;
        } else {
            NodeToErase->prev->next = NodeToErase->next;
            NodeToErase->next->prev = NodeToErase->prev;
        }
        size--;
    }

    void get(int index) {
        Node<T>* NodeToGet = head;
        while (index > 0) {
            NodeToGet = NodeToGet->next;
            index--;
        }
        cout << NodeToGet->data << endl;
    }

    void set(int index, T value) {
        Node<T>* NodeToSet = head;
        while (index > 0) {
            NodeToSet = NodeToSet->next;
            index--;
        }
        NodeToSet->data = value;
    }

    void print() {
        Node<T>* current = head;
        for(int i = 0; i < size; i++) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << std::endl;
    }
};

int main()
{
    DoubleLinkedList<int> list;

    int k, index;
    cin >> k;

    for(int i = 0; i < k; i++)
    {
        string input;
        cin >> input;

        if(input == "insert") {
            int n;
            cin >> index >> n;

            for(int j = 0; j < n; j++)
            {
                int value;
                cin >> value;

                list.insert(index, value);
                index++;
            }
        } else if(input == "erase") {
            int n;
            cin >> index >> n;

            for(int j = 0; j < n; j++)
            {
                list.erase(index, n);
            }
        } else if(input == "size") {
            cout << list.size << endl;
        } else if(input == "get") {
            cin >> index;

            list.get(index);
        } else if(input == "set") {
            int value;
            cin >> index >> value;

            list.set(index, value);
        } else if(input == "print") {
            list.print();
        }
    }

    return 0;
}