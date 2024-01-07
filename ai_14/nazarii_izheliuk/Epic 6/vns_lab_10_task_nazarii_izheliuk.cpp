#include<iostream>
#include<string>

using namespace std;

struct Node {
    int data;
    Node* previous;
    Node* next;
};

class Double_list {
public:
    Node* head;
    Node* tail;
    int size;

    Double_list() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void addElements(int N) {
        for (int i = 0; i < N; ++i) {
            int value;
            cin >> value;

            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = nullptr;

            if (head == nullptr) {
                newNode->previous = nullptr;
                head = newNode;
                tail = newNode;
            } else {
                newNode->previous = tail;
                tail->next = newNode;
                tail = newNode;
            }

            size++;
        }
    }

    void print() {
        Node* current = head;
        cout << "Double list: " ;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void deleteK(int K) {
        Node* current = head;
        for (int i = 1; i < K; ++i) {
            current = current->next;
        }

        current->previous->next = current->next;
        current->next->previous = current->previous;

        delete current;
        size--;
    }
};

int main() {
    int N, K;
    cout << "Enter the number of elements: ";
    cin >> N;

    Double_list list1;
    
    cout << "Enter elements: ";
    list1.addElements(N);
                        
    cout << "Enter which element to delete: ";
    cin >> K;
    list1.deleteK(K);

    list1.print();

    return 0;
}
