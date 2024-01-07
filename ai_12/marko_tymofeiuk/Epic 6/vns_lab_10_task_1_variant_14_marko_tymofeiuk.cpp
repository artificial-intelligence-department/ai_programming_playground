#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

class Node {
    public:
        const char* data;
    Node *next;
    Node *prev;
};

void printLinkedList(Node *n){
    while (n != nullptr){
        std::cout << n->data << std::endl;
        n = n->next;
    }
}

void insertAfter(Node * prev_node, const char* new_data){
    if (prev_node == nullptr){
        std::cerr << "Wrong input, please try again." << std::endl;
        return;
    }
    Node * new_node = new Node;
    new_node->data = new_data;
    new_node->next = prev_node->next;
    new_node->prev = prev_node;
    prev_node->next = new_node;
}

Node * findIndex(Node*&head, int pos){
    Node * current = head;

    for (short i = 1; current && i < pos; i++){
        current = current->next;
    }

    return current;
}

void addMultipleElements(Node * prev_node, size_t k){
    std::vector<const char*> basics = {"blueberry", "raspberry", "watermelon", "strawberry"};

    if (k <= 0){
        std::cerr << "Wrong input, please try again" << std::endl;
        return;

    }
    if (k > 4){
        std::cout << "Sorry, but we don't have that many srings. 4 is our maximum at the moment" << std::endl;
        k = 4;
    }

    for (short i = 0; i < k; i++){
        insertAfter(prev_node, basics[i]);
    }
}
void deleteNode(Node*&head, int numb){
    for (short i = 0; i < numb; i++){
        std::cout << "Enter the index of the element you want to delete: ";
        size_t temp;
        std::cin >> temp;
        Node * findreturn = findIndex(head, temp);
        
        if (findreturn) {
            if (findreturn->prev) {
                findreturn->prev->next = findreturn->next;
            } else {
                head = findreturn->next;
            }

            if (findreturn->next) {
                findreturn->next->prev = findreturn->prev;
            }

            delete findreturn;

            printLinkedList(head);
            std::cout << std::endl;
        }
    }
}

void writeListToFile(Node* head, const std::string& filename) {
    std::ofstream outFile(filename);

    if (!outFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    while (head != nullptr) {
        outFile << head->data << std::endl;
        head = head->next;
    }

    outFile.close();
}

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void restoreListFromFile(Node*& head, const std::string& filename) {
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    Node* current = nullptr;
    std::string line;

    while (std::getline(inFile, line)) {
        Node* newNode = new Node;

        newNode->data = strdup(line.c_str());

        newNode->next = nullptr;

        if (current) {
            current->next = newNode;
            newNode->prev = current;
        } else {
            head = newNode;
            newNode->prev = nullptr;
        }

        current = newNode;
    }

    inFile.close();
}

int main(){
    Node *head = nullptr;
    Node *second = nullptr;
    Node *third = nullptr;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = "apple";
    head->next = second;
    head->prev = nullptr;

    second->data = "orange";
    second->next = third;
    second->prev = head;

    third->data = "banana";
    third->next = nullptr;
    third->prev = second;

    printLinkedList(head);
    std::cout << std::endl;

    std::cout << "Enter the number of elements you want to add and after which element you want to add them: ";
    size_t addnum, addindex;
    std::cin >> addnum >> addindex;
    Node * findreturn = findIndex(head, addindex);
    addMultipleElements(findreturn, addnum);
    printLinkedList(head);
    std::cout << std::endl;

     std::cout << "Enter the number of elements you want to delete: ";
     size_t delnum;
     std::cin >> delnum;
    
    deleteNode(head, delnum);

    writeListToFile(head, "linkedlist.txt");

    deleteList(head);

    restoreListFromFile(head, "linkedlist.txt");

    printLinkedList(head);

    deleteList(head);

    return 0;
}