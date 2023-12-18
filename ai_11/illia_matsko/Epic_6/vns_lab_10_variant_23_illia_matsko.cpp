#include <iostream>
#include <fstream>
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
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;

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
            NodeToInsertBefore->prev->next = newNode;
            NodeToInsertBefore->prev = newNode;
        }

        size++;
    }

    void erase(int index) {
        Node<T>* NodeToErase = head;

        if(NodeToErase == tail) {
            tail = nullptr;
        } else {
            NodeToErase->prev->next = NodeToErase->next;
            NodeToErase->next->prev = NodeToErase->prev;
        }
        size--;
    }

    void print() {
        if(size == 0)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node<T>* current = head;
        for(int i = 0; i < size; i++) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void writeToFile(string filename) {
        ofstream file(filename, ios::binary | ios::trunc);
        if (!file.is_open()) {
            cerr << "Error opening" << endl;
            return;
        }

        Node<T>* current = head;
        for (int i = 0; i < size; i++) {
            file.write(reinterpret_cast<char*>(&current->data), sizeof(T));
            current = current->next;
        }

        file.close();
    }

    void readFromFile(string filename) {
        ifstream file(filename, ios::binary);
        if (!file.is_open()) {
            cerr << "Error opening" << endl;
            return;
        }

        while (!file.eof()) {
            T value;
            file.read(reinterpret_cast<char*>(&value), sizeof(T));
            if (!file.fail()) {
                insert(size, value);
            }
        }

        file.close();
    }
};

int main()
{
    DoubleLinkedList<char*> list;

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
                char* value = new char[10];
                cin >> value;

                list.insert(index, value);
                index++;
            }
        } else if(input == "print") {
            list.print();
        }
    }

    /*====================================================================================================*/
    /*====================================================================================================*/

    list.writeToFile("list.bin");

    int size = list.size;
    for(int i = 0; i < size; i++)
    {
        list.erase(0);
    }

    cout << "List after erasing:" << endl;
    list.print();

    list.readFromFile("list.bin");
    cout << "List after reading from file:" << endl;
    list.print();

    return 0;
}