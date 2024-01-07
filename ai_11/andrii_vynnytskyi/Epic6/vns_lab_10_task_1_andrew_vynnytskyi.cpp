#include <iostream>
#include <ctime>
#include <fstream>


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
    void print(Node* node)
    {
        if (node != nullptr)
        {
            Node* current = node;
            std::cout<< current->value <<' ';
            print(current->next);
        }

    }

    void write(std::string path,  Node* data)
    {
        std::ofstream file;
        if(data != nullptr)
        {

            file.open(path,std::ios_base::app);
            if (!file){

                std::cout<< "Failure" ;
                return;

            }
            file << data->value<<"\n";
            write(path , data->previous);
        }
        file.close();

    }
    void read(std::string path)
    {

        std::string line;
        std::ifstream file;
        file.open(path, std::ios_base::app);
        if (!file){

            std::cout<< "Failure" ;

        }

        int index = 0;
        while(getline(file , line))
        {
            T buff = stoi(line);
            insert(new Node(buff),index);
            index++;
        }
        file.close();
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
    void printing()
    {
        print(head);
        std::cout<<std::endl;
    }
    int size_f()
    {
        return size;
    }
    void write_to_file(std::string path  )
    {
        write(path, tail);
    }void recreation(std::string path  )
    {
        read(path);
    }
    T& operator[](int index){
        return get_node(index)->value;
    }
};


int main() {
    using namespace std;
    TwoLinkedList<int> list;
    srand(time(0));
    for (int i = 0 ; i < 10; i++)
    {
       list.insertion(rand() % 100, i);
    }

    cout<< "Initialized list:" ;
    list.printing();
    int index, count;
    cout<< "\nEnter a number of elements to delete: ";
    cin >> count;
    cout<< "\nEnter a index of elements before which you want delete: ";
    cin >> index;
    for (int j = index ; j > index - count; --j)
        list.erase_element(index - count - 1);
    cout<< "\nEdited list:" ;
    list.printing();
    int count1;
    cout<< "\nEnter a number of elements to add: ";
    cin >> count1;
    int buff = list.size_f();
    for (int k = list.size_f(); k < buff + count1 ; k++)
    {
                list.insertion(rand() % 100, k);
    }
    cout<< "\nEdited list:" ;
    list.printing();
    list.write_to_file("C:/Users/Nout_1/CLionProjects/untitled4/output.txt");
    list.~TwoLinkedList();
    cout<< "\nDeleted list:" ;
    list.printing();
    list.recreation("C:/Users/Nout_1/CLionProjects/untitled4/output.txt");
    cout<< "\nRecreated list:" ;
    list.printing();






    return 0;
}