#include <iostream>
#include <fstream>

using namespace std;

class Node{
public:
    char* element;
    Node* next;
    Node* prev;
    Node(char* data) : element(data) , prev(NULL) , next(NULL){} 
};

class doubly_linked_list{
private:
    Node* Head;
public:
    doubly_linked_list(): Head(NULL){}

    void adding_to_the_end(char* inf){
        Node* newpointer = new Node(inf);
        if (Head == NULL)
            Head = newpointer;
        else{
            Node* actual_pointer = Head;
            while(actual_pointer->next){
                actual_pointer = actual_pointer->next;
            }
            actual_pointer->next = newpointer;
            newpointer->prev = actual_pointer;
        }
    }

    void printing_of_the_list(){
        if(Head == NULL)
            cout<<"список порожній:(";
        else{
            Node* actual_pointer = Head;
            while(actual_pointer){
                cout<<actual_pointer->element<<" ";
                actual_pointer = actual_pointer->next;
            }
        }
    }

    void deleting(int k){
        Node* actual_pointer = Head;
        while (actual_pointer && actual_pointer->next){
            actual_pointer = actual_pointer->next;
        }
        for (int i = 0; i < k; i++){
            if (actual_pointer) 
            {
                if (actual_pointer->prev) 
                {
                    actual_pointer = actual_pointer->prev;
                    actual_pointer->next = nullptr;
                }else{
                    Head = nullptr;
                    break;
                }
            }else{
                cout<<"список порожній:(";
                break; 
            }
        }
    }
    void add_k_element(int k,char* element){
        if(Head == NULL)
            cout<<"список порожній:(";
        else{
            Node* actual_pointer = Head;
            int actualindex = 0;
            while (actual_pointer && actualindex < k){
                actual_pointer = actual_pointer->next;
                actualindex++;
            }
            Node* pointerk = new Node(element);
            pointerk->prev = actual_pointer;
            pointerk->next = actual_pointer->next;
            actual_pointer->next = pointerk;
        }
    }
    void write(string& name_of_the_file){
        ofstream file_stream1(name_of_the_file, ios::out);
        if (file_stream1.is_open()) 
        {   
            Node* actual_pointer = Head;
            while(actual_pointer)
            {
                file_stream1 << actual_pointer->element << "\n";
                actual_pointer = actual_pointer->next;
            }
            file_stream1.close();
        }else
            cout << "Error while opening" << endl;
    }

    void read(const std::string& name_of_the_file){
        ifstream file_stream2(name_of_the_file);
        if(file_stream2.is_open()){
            string line;
            while (getline(file_stream2, line)){
                char* element = new char[line.size() + 1];
                strcpy(element, line.c_str());
                adding_to_the_end(element); 
            }
            file_stream2.close();
        }else{ 
            cout << "Error while opening" << endl;
        }
    }   

    void deleting_of_list(){
        while (Head) {
            Node* buffer = Head;
            Head = Head->next;
            delete buffer;
        }
    }

};
int main(){
    doubly_linked_list list;

    list.adding_to_the_end((char*)"Hello");
    list.adding_to_the_end((char*)"dear");
    list.adding_to_the_end((char*)"World");
    list.adding_to_the_end((char*)"World");
    list.adding_to_the_end((char*)"World");
    int k = 3;
    list.printing_of_the_list();
    cout<<'\n';
    list.deleting(k);
    k=1;
    list.printing_of_the_list();
    cout<<'\n';
    list.add_k_element(k , (char*)"World");
    list.printing_of_the_list();
    cout<<'\n';
    string filename = "lab_10.txt";
    list.write(filename);
    list.deleting_of_list();
    list.read(filename);
    list.printing_of_the_list();
    cout<<'\n';
    list.deleting_of_list();
    list.printing_of_the_list();
    return 0;
}