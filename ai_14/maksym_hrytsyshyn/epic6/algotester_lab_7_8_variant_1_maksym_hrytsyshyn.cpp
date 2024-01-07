#include  <iostream>
using namespace std;

class Node {    
public: 
     int value;
     Node* prev, * next;
};


class LinkedList {
private:
    struct Node{
        int value;
        Node* next;
        Node* prev;
        Node(int val, Node *node = nullptr ) {
            value = val;
            next = node;
        }
    };

    Node* head, * tail;
    int size;


public: 
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

     Node* getNode(int index) {
        Node* traverser = head;
        int counter = 0;
        while (counter != index) {
            if (traverser == nullptr) return traverser;
            counter++;
            traverser = traverser->next;
        }
        return traverser;
    } 
    
    int getNodes(int index) {
        Node* traverser = head;
        int counter = 0;
        while (counter != index) {
            if (traverser == nullptr) return traverser->value;
            counter++;
            traverser = traverser->next;
        }
        return traverser->value;
    }

    int listsize() {
        int size = 0;
        Node* traverser = head;
        while (traverser != nullptr) {
            size++;
            traverser = traverser->next;
        }
        return size;
    }
   

    void insert(int index, int N, int arr[]) {
        if (index > listsize()) {
            return;
        }

        for (int i = N - 1; i >= 0; i--) {
            Node* traverser = new Node(arr[i]);
            traverser->value = arr[i];
            traverser->prev = nullptr;
            traverser->next = nullptr;

            if (index == 0) {
                traverser->next = head;
                if (head != nullptr) {
                    head->prev = traverser;
                }
                head = traverser;
                if (tail == nullptr) {
                    tail = traverser;
                }
            } else if (index == listsize()) {
                traverser->prev = tail;
                if (tail != nullptr) {
                    tail->next = traverser;
                }
                tail = traverser;
                if (head == nullptr) {
                    head = traverser;
                }
            } else {
                Node* ptr = head;
                for (int j = 0; j < index - 1; j++) {
                    ptr = ptr->next;
                }
                traverser->next = ptr->next;
                traverser->prev = ptr;
                if (ptr->next != nullptr) {
                    ptr->next->prev = traverser;
                }
                ptr->next = traverser;
                }
            size = listsize() + 1;
            }
        } 


    void eraseNode(int index, int N) {
        if (index < 0 || N < 0) return;
        Node* traverser = getNode(index);
        
        for (int i = 0; i < N && traverser != nullptr; i++) {
        Node* nextNode = traverser->next;
        Node* prevNode = traverser->prev;

        if (prevNode)
            prevNode->next = nextNode;
        else
            head = nextNode;

        if (nextNode)
            nextNode->prev = prevNode;
        else
            tail = prevNode;
        delete traverser;
        traverser = nextNode;
    }
    }
    
    void setNode(int index, int content) {
        Node* traverser = getNode(index);
    
        if (traverser != nullptr)
        traverser->value = content;
    }

    friend ostream& operator<<(ostream& os, const LinkedList& list) {
    Node *ptr = list.head;
    while (ptr != nullptr) {
      os << ptr->value << " ";
      ptr = ptr->next;
    }
    return os;
  }
};

int main() {
    int Q;
    cin >> Q;
    LinkedList list;
    while (Q--) {
        string request;
        cin >> request;

        if(request == "insert") {
            int index;
            cin >> index;   
            int N;
            cin >> N;
            int nums[N];
            for (int i = 0; i < N; i++) {
                cin >> nums[i];
            }
            list.insert(index, N, nums);
        }
        else if(request == "erase") {
            int index;
            int n;
            cin >> index >> n;
            cout << endl;
            list.eraseNode(index, n);
        }
        else if(request == "size") {
            int size = list.listsize();
            cout << size << endl;
        }
        else if(request == "set") {
            int index;
            int content;
            cin >> index >> content;
            list.setNode(index, content);
        }
        else if(request == "get") {
            int index;
            cin >> index;
         
             cout << list.getNodes(index) << endl;
        }
        else if(request == "print") {
            cout << list << endl;
            cout << endl;
        }
    
    }
    return 0;
}

