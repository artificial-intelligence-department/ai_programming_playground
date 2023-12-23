#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node
{
    char data;
    Node* prev;
    Node* next;
};


class dll
{
private:
    Node head;
    Node tail;
public:
        //1. Написати функцію для створення списку.
    dll(){ // функція, яка нічого не повертає, але створює елемент класу
        head.prev = nullptr;
        head.next = &tail;

        tail.prev = &head;
        tail.next = nullptr;
    }

    Node* start() {
        return head.next; //Node0
    }
    //head = Node
    //head.next = Node*

    Node* end() {
        return tail.prev;
    }

    //вставка елементів
    
    void push(char data) {
        insert_after(head, data);
    }

    void push_back(char data) {
        insert_after(*tail.prev, data);
    }

    void insert_after(Node &after, char value){
        Node* newNode = new Node(); //"чиста" нода
        newNode->data = value; //а тут вже щось записуємо
        // cout << "ins: " << newNode->data << endl;

        newNode->next = after.next;
        newNode->prev = &after;
        
        after.next->prev = newNode;
        after.next = newNode;
    }

        // 2. Написати функцію для друку списку.
    void print(){
        Node* node = start(); //ми створюємо, який буде посиланням на початок списку
        
        if(node->next == nullptr)
        {
            cout << "list is empty...\n";
            return;
        }

        while(node->next != nullptr)
        {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }


        //3. видалення згідно зі своїм варіантом
    void deleteBeforeAndAfter(int key){ // key >= 2
        if(key < 2)
        {
            cout << "wrong key\n";
            return;
        }
        key--;
        deleteElement(key-1);
        deleteElement(key);
    }

        //3. Написати функції для знищення й додавання елементів списку
    void deleteElement(int key){ 
        Node* node = start();
        for(int i = 1; i < key; i++) // проходимось до потрібного вузла в dll
            node = node->next;

        node->next = node->next->next;
        delete node->next->prev;
        node->next->prev = node;
    }

        //5. Написати функцію для запису списку у файл
    void writeToFile(string fileName)
    {
        ofstream fout(fileName);

        Node* node = start();
        while(node->next != nullptr)
        {
            fout << node->data << endl;
            node = node->next;
        }   
    }

        //8. Написати функцію для відновлення списку з файлу
    void restoreFromFile(string fileName)
    {
        Node* node = start();
        ifstream fin ("newFileWithData.dat");
        
        if (!fin.is_open())
            return;

        string str;
        while(getline(fin, str))
            push_back(*str.c_str());

        fin.close();
    }
    
        //7. знищення списку
    void destroyList()
    {
        Node* current = start()->next;

            //видалення кожного вузла
        while (current->next != nullptr) 
        {
            delete current->prev;
            current = current->next;
        }
        delete current->prev;

            //обнуляємо список
        head.next = &tail;
        tail.prev = &head;
        head.prev = nullptr;
        tail.next = nullptr;
    }

};


int main()
{
        
    dll list = dll(); //запускаємо функцію в класі dll для ініціалізації об'єкту класу

    // char chars[20];
        // 4. Виконати зміни в списку
        cout << "origin list: \n";
        list.push_back('8');
    
        //4.й друк після зміни

    list.print();

    //Додати по К елементів у початок й у кінець списку.
    int k = 4;
    for (int i = 0; i < k; i++)
    {
        list.push(97 + i); //97 -> ASCII код літери a
        list.push_back(48 + i); //48 -> 0
    }

    cout << "list after adding k elements to start and end: \n";
    list.print();
    
        //Знищити елементи перед і після елемента із заданим ключем.
    int key = 3;
    list.deleteBeforeAndAfter(key);
    cout << "list after deleting elements behind and after key: \n";
    list.print();

        //запис та зчитування з файлу
    list.writeToFile("newFileWithData.dat");

    dll list2 = dll();

    list2.restoreFromFile("newFileWithData.dat");
    // list2.deleteElement(2);
    // cout << list2.end()->data;
    cout << "restored list: \n";
    list2.print();
    list2.destroyList();
    cout << "there we delete list...\n"; 
    list2.print();


    return 0;
}
