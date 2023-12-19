#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
struct Element_of_list{
    T data;
    Element_of_list<T>* next;
    Element_of_list<T>* prev;
};

template <typename T>
class LinkedList{
    private:
        Element_of_list<T>* head;
        Element_of_list<T>* tail;
        int list_size;
    public:
        LinkedList(int _size = 0){
            head = NULL;
            tail = NULL;
            list_size = _size;
        }

        ~LinkedList(){
            clear();
        }

        Element_of_list<T>* get_head(){ 
            return head;
        }

        int size(){
            return list_size;
        }

        void push_back(T _data){
            Element_of_list<T>* newElement = new Element_of_list<T>;
            newElement -> next = NULL;
            newElement -> prev = tail;
            newElement -> data = _data;

        if(tail != NULL){
            tail -> next = newElement;
        }

        if(list_size == 0){
            head = tail = newElement;
        }

        else{
            tail = newElement;
        }

        list_size++;
        }

        void Del_First_Element(){
            Element_of_list<T> *temp = new Element_of_list<T>;
            temp = head;
            head = head -> next;
            delete temp;
        }

        void clear(){
            int n = list_size;
            for(int i = 0; i < n; i++){
                Del_First_Element();
            }
            list_size = 0;
        }

        void Print(string list){

            if(list_size == 0){
                cout << "List is empty" << endl;
                return;
            }
            
            else{
                Element_of_list<T>* temp = head;
                for(int i = 0; i < list_size; i++){
                    cout << temp -> data << " ";
                    temp = temp -> next;
                }
            }
            cout << endl;
        }

};

    void write_to_file(const char *file_name , LinkedList<int>& list){
        ofstream file(file_name);
        if(!file.is_open()){
            cout << "File is not open" << endl;
        }
        else{
            Element_of_list<int>* temp = list.get_head();
            for(int i = 0; i < list.size(); i++){
                file << temp -> data << " ";
                temp = temp -> next;
            }
            file.close();
        }
    }

    void recover_from_file(const char *file_name, LinkedList<int>& list){
        ifstream file(file_name);
        if(!file.is_open()){
            cout << "File is not open" << endl;
        }
        else{
            int data;
            while(file >> data){
                list.push_back(data);
            }
            file.close();
        }
    }

int main(){

    int size;
    cin >> size;

    LinkedList<int> list;
    for(int i = 0; i < size; i++){
        int data;
        cin >> data;
        list.push_back(data);
    }

    cout << "List => ";
    list.Print("List");

    write_to_file("list.txt" , list);

    list.clear();

    cout << "List => ";
    list.Print("List");

    recover_from_file("list.txt" , list);

    cout << "Recovered list => ";
    list.Print("List");





    return 0;
}