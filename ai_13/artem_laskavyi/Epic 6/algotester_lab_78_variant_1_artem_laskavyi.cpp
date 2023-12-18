#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

};

class DoublyLinkedList {
private:
public:
    Node* head;
DoublyLinkedList() : head(nullptr) {}


// Function to create a new node with given data
Node* createNode(int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;
    new_node->prev = nullptr;
    return new_node;
}

// Function to find a node at a specific index
Node* getNode(Node* head, int index){
    int count = 0;
    Node* current = head;

    while (current != nullptr && count < index)
    {
        current = current->next;
        count++;
    }

    return current;
}

void insertAfter(Node* prev_node, int new_data)
{
    if (prev_node == nullptr){
        
        Node* new_node = createNode(new_data);
        new_node->next = head;
        new_node->prev = nullptr;

        if (head != nullptr)
            head->prev = new_node;

        head = new_node;
    }else{
        Node* new_node = createNode(new_data);
        new_node->next = prev_node->next;
        prev_node->next = new_node;
        new_node->prev = prev_node;

        if (new_node->next != nullptr)
            new_node->next->prev = new_node;
    }
}

void deleteNode(Node** head_ref, Node* del)
{
    if (*head_ref == nullptr || del == nullptr)
        return;

    if (del->prev != nullptr)
        del->prev->next = del->next;
    else
        *head_ref = del->next;

    if (del->next != nullptr)
        del->next->prev = del->prev;
        
    delete del;
}

void setNode(Node* head, int index, int new_data)
{
    Node* node = getNode(head, index);
        node->data = new_data;

}

int getSize(Node* head)
{
    int count = 0;
    Node* current = head;

    while (current != nullptr)
    {
        count++;
        current = current->next;
    }

    return count;
}

int getData(Node* head, int index){
    Node* node = getNode(head, index);

	return node->data;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


};

int main()
{
    int q;
    cin >> q;
    DoublyLinkedList list;
    
    for (int i = 1; i <= q; i++)
    {
        string input;
        cin >> input;
        cin.ignore();

        if (input == "insert")
        {
            int index, length, element;
            cin >> index >> length;
            for (int j = 0; j < length; j++)
            {
                cin >> element;
                Node* prev_node = list.getNode(list.head, index - 1);
                list.insertAfter(prev_node, element);
                index++;
            }
        }
        else if (input == "erase")
            {
            int eraseIndex, eraseLength;
            cin >> eraseIndex >> eraseLength;
            Node* startNode = list.getNode(list.head, eraseIndex);

            Node* endNode = list.getNode(list.head, eraseIndex + eraseLength);
            
            while (startNode != nullptr && startNode != endNode)
            {
            Node* temp = startNode->next;
            list.deleteNode(&list.head, startNode);
            startNode = temp;
            }
        }

        else if (input == "size")
        {
            cout << list.getSize(list.head) << endl;
        }
        else if (input == "get")
        {
            int getIndex;
            cin >> getIndex;
            cout << list.getData(list.head, getIndex) << endl;
        }
        else if (input == "set")
        {
            int setIndex, setData;
            cin >> setIndex >> setData;
            list.setNode(list.head, setIndex, setData);
        }
        else if (input == "print")
        {
            list.printList(list.head);
        }

    }


    return 0;
}

