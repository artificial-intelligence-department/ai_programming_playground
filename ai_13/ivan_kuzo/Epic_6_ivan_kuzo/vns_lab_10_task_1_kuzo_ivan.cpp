#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;\
struct Node{
    char* data;
    Node* prev;
    Node* next;
};
Node* create_list(){
    return nullptr;
}
void print_list(Node* head){
    if(!head){
        cout<<"The list is epmty"<<endl;    
        return;
    }
    Node* current=head;
    while(current){
        cout<<current->data<<" ";
        current=current->next;  
    }
    cout<<endl;
}
void add_element_to_list(Node*& head, const char* newData, int position){
    Node* newNode = new Node{strdup(newData), nullptr, nullptr};

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        int currentPosition = 0;

        while (current != nullptr && currentPosition < position) {
            current = current->next;
            currentPosition++;
        }

        if (current != nullptr) {
            newNode->prev = current;
            newNode->next = current->next;
            if (current->next != nullptr) {
                current->next->prev = newNode;
            }
            current->next = newNode;
        } else {
            Node* tail = head;
            while (tail->next != nullptr) {
                tail = tail->next;
            }
            tail->next = newNode;
            newNode->prev = tail;
        }
    }
}
void delete_element_from_list(Node*& head,const char* key){
    Node* current = head;
    while (current != nullptr) {
        if (strcmp(current->data, key) == 0) {
            if (current->prev != nullptr)
                current->prev->next = current->next;
            else
                head = current->next;
            if (current->next != nullptr)
                current->next->prev = current->prev;
            free(current->data);
            free(current);
            return;
        }
        else
            current = current->next;
    }
}

void from_list_to_file(Node* head, const char* filename)
{
    ofstream file(filename);
     if (!file.is_open()) {
        cerr << "Trouble with opening";
        return;
    }
    Node* current =head;
    while(current!=nullptr){
        file<<current->data<<endl;
        current=current->next;
    }
    cout<<endl;
}
void delete_list(Node* head){
    while(head != nullptr){
        Node* temp =head;
        head=head->next;
        free(temp->data);
        free(temp);   
    }
}
void from_file_to_list(Node*& head, const char* filename)
{
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Trouble with opening" << endl;
        return;
    }
    Node* tail = nullptr;
    string line;
    while (getline(file, line)) {
        Node* newNode = new Node{strdup(line.c_str()), nullptr, nullptr};
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } 
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    file.close();
}
int main()
{
    Node* list = create_list();
    cout<<"List 1"<<endl;
    print_list(list);
    add_element_to_list(list,"Element_1",0);
    cout<<"List 2"<<endl;
    print_list(list);
    add_element_to_list(list,"Element_2",1);
    cout<<"List 3"<<endl;
    print_list(list);
    delete_element_from_list(list,"Element_2");
    cout<<"List 4"<<endl;
    print_list(list);
    int k;
    cin>>k;
    for (int i=0;i<k;i++){
        string a;
        cin >> a;
        add_element_to_list(list, a.c_str(), i + 1);
    }
    cout<<"List 5"<<endl;
    print_list(list);
    const char* filename = "file_1.txt";
    ofstream file(filename);
    from_list_to_file(list,filename);
    file.close();
    delete_list(list);
    list = nullptr;
    cout<<"List 6"<<endl;
    print_list(list);
    ifstream file2(filename);
    from_file_to_list(list,filename);
    file2.close();
    cout<<"List 7"<<endl;
    print_list(list);
    delete_list(list);
    list =nullptr;
    cout<<"List 8"<<endl;
    print_list(list);
    return 0;
}