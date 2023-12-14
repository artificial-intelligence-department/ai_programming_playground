#include <iostream>
template<class T>
class TwoLinkedList
{
private:
    class Node
    {public:
        T value;
        Node* next;
        Node* previous;


        explicit Node(T value) {
            this -> value = value;
            next = nullptr;
            previous = nullptr;
        }
    };
    Node* head;
    Node* tail;
    int size;

    Node* get_node(int index)
    {
        if (index < 0 || index >= size) {
            return nullptr;
        }
        Node* current;
        int middle = size / 2;
        if (index < middle)
        {
            current = head;
            for(int j = 0; j < index;++j)
            {
                current = current->next;
            }
        }
        else
        {
            current = tail;
            for(int j = size - 1; j > index;--j)
            {
                current = current->previous;
            }
        }
        return current;
    }


    void insert(Node* new_node, int index)
    {

        if (new_node == nullptr || index < 0 || index > size ) {
            return;
        }

        if (size == 0)
        {
            tail = head = new_node;
        }
        else if(index == 0)
        {
            new_node->next = head;
            head->previous = new_node;
            head = new_node;
        }
        else if(index == size)
        {
            new_node->previous = tail;
            tail->next = new_node;
            tail = new_node;
        }
        else
        {
            Node* current = get_node(index - 1);
            new_node->previous = current;
            new_node->next = current->next;
            current->next->previous = new_node;
            current->next = new_node;
        }

        ++size;
    }

    void erase(int index)
    {
        if (index < 0 || index >= size) {
            return; // Invalid index
        }


        Node* current = get_node(index);

        if (index == 0) {
            head = head->next;
            if (head != nullptr) {
                head->previous = nullptr;
            }
        } else if (index == size - 1) {
            tail = tail->previous;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
        } else {
            current->previous->next = current->next;
            current->next->previous = current->previous;
        }

        delete current;
        --size;


    }

    void set( int index , T value)
    {
        Node* modify_node = get_node(index);
        modify_node->value = value;
   }
    void print(Node* node)
    {
        if (node != nullptr)
        {
            Node* current = node;
            std::cout<< current->value <<' ';
            print(current->next);
        }

    }
public:
    TwoLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~TwoLinkedList() {
        while (head != nullptr) {
            Node* next = head->next;
            delete head;
            head = next;
        }
        size = 0;
    }

    void insertion(T value, int index)
    {

        insert(new Node(value) ,index);
    }
    void erase_element(int index)
    {
        erase(index);
    }
    void setter(int index, T value)
    {
        set(index, value);
    }
    void printing()
    {
        print(head);
        std::cout<<std::endl;
    }
    int size_f()
    {
        return size;
    }
    T& operator[](int index){
        return get_node(index)->value;
    }
};


int main() {
    using namespace std;
    TwoLinkedList<int> list;

    int count_of_questions;
    string question;
    cin >> count_of_questions;

    for (int i = 0; i < count_of_questions; ++i) {
        cin >> question;


            if (question == "insert") {
                int index, count;
                cin >> index >> count;
                for (int j = count - 1; j >= 0; --j)
                {
                    int number;
                    cin >> number;
                    list.insertion(number, index);
                    index++;
                }

            } else if (question == "erase") {
                int index, count;
                cin >> index >> count;
                for (int j = 0; j < count; ++j)
                    list.erase_element(index);
            } else if (question == "size") {
                cout << list.size_f() << endl;
            } else if (question == "get") {
                int index;
                cin >> index;
                cout<< list[index]<<endl;
            } else if (question == "set") {
                int index, value;
                cin >> index >> value;
                list.setter(index, value);
            } else if (question == "print") {
                list.printing();
            }
        }


    return 0;
}