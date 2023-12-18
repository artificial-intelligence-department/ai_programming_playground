#include <iostream> 
using  namespace std;

struct Node{
    int data;
    Node *next;

    Node(int val, Node *node = nullptr ) {
        data = val;
        next = node;
    }
    // Node(int val, Node* next){
    //     data = val;
    //     this->next = next;
    // }
};

void pushFront(Node *&head, int value){
    if(head == nullptr){
        head = new Node{value, nullptr};
    }else{
        Node *newNode = new Node{value, head};
        head = newNode;
    }
}

void Show(Node *head){
    if(head == nullptr){
        cout << "List is empty" << endl;;
        return;
    }

    while (head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *reverse(Node *head){
    Node *current = head;
    Node *prev = nullptr;
    Node *next = nullptr;

    while (current != nullptr){
        next = current->next;
        current->next = prev;
        prev =current;
        current = next;
    }
    return prev;  
}

bool compare(Node *h1, Node *h2){
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->data != h2->data) {
            // Знайдено невідповідність даних
            return false; 
        }
        h1 = h1->next;
        h2 = h2->next;
    }

    // Якщо один список закінчується раніше іншого, повертаємо false
    if (h1 != nullptr || h2 != nullptr) {
        return false;
    }

    return true; // Списки однакові
}

Node* add(Node *num1, Node *num2){
    Node *result = nullptr;
    Node *current = nullptr;
    int carry = 0;

    while (num1 || num2 || carry){
        int val1 = (num1) ? num1->data : 0; 
        int val2 = (num2) ? num2->data : 0; 
        
        int sum = val1 + val2 + carry;
        
        int s = sum % 10;
        carry = sum / 10;

        if(result == nullptr){
            result = new Node(s);
            current = result;
        }else{
            current->next = new Node(s);
            current = current->next;
        }
        
        // Переходимо до наступних вузлів
        if (num1 != nullptr) {
            num1 = num1->next;
        }
        if (num2 != nullptr) {
            num2 = num2->next;
        }
    }

    return result;
}


int main(){
    Node *list = nullptr;
    pushFront(list, 7);
    pushFront(list, 1);
    pushFront(list, 10);
    pushFront(list, 3);
    pushFront(list, 5);
    pushFront(list, 2);

    cout << "List: ";
    Show(list);

    list = reverse(list);

    cout << "Reversed list: ";
    Show(list);

    Node *list1 = nullptr;
    pushFront(list1, 5);
    pushFront(list1, 3);
    pushFront(list1, 10);
    pushFront(list1, 9);

    cout << "List 1: ";
    Show(list1);

    Node *list2 = nullptr;
    pushFront(list2, 5);
    pushFront(list2, 0);
    pushFront(list2, 1);
    pushFront(list2, 9);

    cout << "List 2: ";
    Show(list2);

    bool result1 = compare(list1, list2);
    if(result1){
        cout << "List equal!" << endl;
    }else{
        cout << "List not equal!" << endl;
    }

    Node *list3 = nullptr;
    pushFront(list3, 1);
    pushFront(list3, 2);
    pushFront(list3, 3);

    cout << "List 3: ";
    Show(list3);

    Node *list4 = nullptr;
    pushFront(list4, 9);
    pushFront(list4, 8);
    pushFront(list4, 7);

    cout << "List 4: ";
    Show(list4);

    Node *result2 = add(list3, list4);
    result2 = reverse(result2);

    cout << "Sum: ";
    Show(result2);

    return 0;
}