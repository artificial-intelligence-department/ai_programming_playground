#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct Node{
    char key[10];
    Node* next;
    Node* prev;
    //Node(char* data): key(data), next(nullptr), prev(nullptr){}
};

struct dblLinkedList{
    Node* head;
    Node* tail;
    int size;
};

dblLinkedList* createList(){
    dblLinkedList* List = new dblLinkedList;
    List->head=nullptr;
    List->tail=nullptr;
    List->size=0;
    return List;
}

void destroyList(dblLinkedList* List){
    Node* data = List->head;
    while(data!=nullptr){
        Node* next_data = data->next;
        delete data;
        data=next_data;
        List->size--;
    }
    List->head=nullptr;
    List->tail=nullptr;
}

void printList(dblLinkedList* List){
    Node* data = List->head;
    if(data==nullptr){
        cout << "List is empty" << endl;
        return;
    } else{
        while(data!=nullptr){
            cout << data->key << "  ";
            data=data->next;
        }
    }
}

void addEl(dblLinkedList* List, int index, const char* str){
    index--;
    if(index > List->size || index<0){
        cout << "wrong index:(" << endl;
        return;
    }
    Node* newNode = new Node;
    strcpy(newNode->key, str);
    if(List->head==nullptr){
        List->head=newNode;
        newNode->next=nullptr;
        newNode->prev=nullptr;
        List->tail=newNode;
        List->size++;
    } else{
        Node* current = List->head;
        int i = 0;
        while(current!=nullptr && i<index){
            current=current->next;
            i++;
        }
        if(current==List->head){
            newNode->next=List->head;
            List->head->prev=newNode;
            List->head=newNode;
            newNode->prev=nullptr;
        } else if(current==nullptr){
            newNode->next=nullptr;
            newNode->prev=List->tail;
            List->tail->next=newNode;
            List->tail=newNode;
        } else{
            newNode->next=current;
            newNode->prev=current->prev;
            current->prev->next=newNode;
            current->prev=newNode;
        }
        List->size++;
    }
}

void deleteEl(dblLinkedList* List, int index){
    index--;
    if(List->size==0){
        cout << "it is nothing to delete" << endl;
        return;
    }
    if(index >= List->size || index < 0){
        cout << "wrong index" << endl;
        return;
    }
    Node* current = List->head;
    int i = 0;
    while(current!=nullptr && i<index){
        current=current->next;
        i++;
    }
    if(current->prev!=nullptr){
        current->prev->next=current->next;
    }
    if(current->next!=nullptr){
        current->next->prev=current->prev;
    }
    if(current->prev==nullptr){
        List->head=current->next;
    }
    if(current->next==nullptr){
        List->tail=current->prev;
    }
    List->size--;
    delete current;
}

void write_to_file(dblLinkedList* List, const char* filename){
    ofstream oFile(filename);
    if(oFile.is_open()){
        Node* data = List->head;
        while(data!=nullptr){
            oFile << data->key << endl;
            data=data->next;
        }
        oFile.close();
    } else{
        cout << "error opening file" << endl;
    }
}

dblLinkedList* restore(dblLinkedList* List, const char* filename){
    ifstream iFile(filename);
    if(iFile.is_open()){
        char str[20];
        while(!iFile.eof()){
            Node* elem = new Node;
            iFile.getline(str, sizeof(str));
            //elem->key=new char [strlen(str)];
            strcpy(elem->key, str);
            if(List->head==nullptr){
                List->head=elem;
                List->tail=elem;
                elem->next=nullptr;
                elem->prev=nullptr;
                List->size++;
            } else{
                elem->prev=List->tail;
                elem->next=nullptr;
                elem->prev->next=elem;
                List->tail=elem;
                List->size++;
            }
        }
        iFile.close();
    } else{
        cout << "error opening files" << endl;
    }
    return List;
}

int main(){
    dblLinkedList* list = createList();
    printList(list);

    addEl(list, 1, "a");
    addEl(list, 2, "b");
    addEl(list, 3, "c");
    addEl(list, 4, "d");
    addEl(list, 5, "e");
    cout << "formed list: ";
    printList(list);

    int K;
    cout << endl << "enter the number of elements: " << endl;
    cin >> K;
    for(int i = 0; i < K; i++){
        char word[10];
        int index;
        cout << "enter the short word: ";
        cin >> word;
        cout << "enter the index of new element: ";
        cin >> index;
        addEl(list, index, word);
    }

    cout << "updated list: ";
    printList(list);

    cout << endl << "enter the number of elements to delete: ";
    cin >> K;
    if(K>list->size){
        cout << "there are not many elements in the list" << endl;
    } else{
        for(int i = 0; i < K; i++){
            int index;
            cout << endl << "enter the index of element to delete: ";
            cin >> index;
            deleteEl(list, index);
            cout << "after deleting: ";
            printList(list);
        }
    }

    write_to_file(list, "dbllinkedlist.txt");

    destroyList(list);
    cout << endl << "after destroying: ";
    printList(list);

    list = restore(list, "dbllinkedlist.txt");
    cout << "after restoring: ";
    printList(list);

    return 0;
}