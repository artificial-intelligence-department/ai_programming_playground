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

    void print(Node* node , std::string symbol)
    {
        if (node != nullptr)
        {
            Node* current = node;
            std::cout<< current->value <<symbol;
            print(current->next, symbol);
        }

    }

    void reversed(Node* node )
    {
        Node* current = node;
        while(current != nullptr)
        {
            Node* buff = current->next;
            current->next = current->previous;
            current->previous = buff;
            current = buff;
        }
        Node* buff = head;
        head = tail;
        tail = buff;

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
    void reverse()
    {
        reversed(head);
    }

    bool compare(Node* node1, Node* node2)
    {
        Node* current1 = node1;
        Node* current2 = node2;
        while(current1 != nullptr && current2 != nullptr)
        {
            if(current1->value != current2 -> value)
            {
                return false;
            }
            current1 = current1->next;
            current2 = current2-> next;
        }
        return true;
    }

    void insertion(T value, int index)
    {

        insert(new Node(value) ,index);
    }

    void insertion(Node* value, int index)
    {

        insert(value ,index);
    }

    void sum(Node* node1, Node* node2, TwoLinkedList<int>& buff)
    {

        int index = 0;
        int carry = 0;
        Node* current1 = node1;
        Node* current2 = node2;
        while(current1 != nullptr && current2 != nullptr)
        {
            if((current2->value + current1->value + carry) < 10)
            {
                buff.insertion(current2->value + current1->value + carry, index);
                carry = 0;
            }
            else
            {
                buff.insertion((current2->value + current1->value + carry) - 10, index);
                carry = 1;
            }
            current1 = current1->next;
            current2 = current2->next;
            index++;
        }
        if (carry)
        {
            buff.insertion(carry, index);
        }

    }

    void printing(std::string symbol)
    {
        print(head, symbol);
        std::cout<<std::endl;
    }

    Node* operator[](int index)
    {
        return get_node(index);
    }
};


int main() {
    using namespace std;
    TwoLinkedList<int> list1, list2, list3, list4, list5;

    srand(time(0));
    for (int i = 0 ; i < 10; i++)
    {
        list1.insertion(rand() % 100, i);
    }
    for (int j = 0 ; j < 10; j++)
    {
        list2.insertion(rand() % 100, j);
    }
    for (int i = 0 ; i < 6; i++)
    {
        list3.insertion(rand() % 10, i);
    }
    for (int j = 0 ; j < 6; j++)
    {
        list4.insertion(rand() % 10, j);
    }


    cout<< "Initialized list 1:" ;
    list1.printing(" ");
    cout<< "\nInitialized list 2:" ;
    list2.printing(" ");
    list1.reverse();
    cout<< "Reversed list:" ;
    list1.printing(" ");
    string check = (list1.compare(list1[0],list2[0]))?("are equal"):("aren't equal");
    cout<<"\nCompared lists: "<< check<<endl;
    string check1 = (list1.compare(list1[0],list1[0]))?("are equal"):("aren't equal");
    cout<<"\nCompared lists: "<< check1<<endl;
    cout<< "\nNumber reversed 1: " ;
    list3.printing("");
    cout<< "\nNumber reversed 2: " ;
    list4.printing("");
    list5.sum(list3[0], list4[0], list5);
    cout<< "\nSum: ";
    list5.reverse();
    list5.printing("");
    return 0;

}