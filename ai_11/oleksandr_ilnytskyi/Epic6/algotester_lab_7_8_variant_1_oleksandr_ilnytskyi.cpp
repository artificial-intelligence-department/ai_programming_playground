#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct node {
    int value;
    node* prev;
    node* next;
    explicit node(int num) {
        value = num;
        prev = nullptr;
        next = nullptr;
    }
};

class DoubleLinkedList {
private:
    node* head;
    node* tail;
    int size;
public:
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void insert(int index, int numsLength, const int* nums) {
        if (index == 0) {
            for (int i = numsLength-1; i >= 0; i--) {
                if (head != nullptr) {
                    node* newNode = new node(nums[i]);
                    tail->prev = newNode;
                    newNode->next = tail;
                    tail = newNode;
                    size += 1;
                }
                else {
                    node* newNode = new node(nums[i]);
                    head = newNode;
                    tail = head;
                    size += 1;
                }
            }
        }
        else if (index == size-1) {
            for (int i = 0; i < numsLength; i++) {
                node* newNode = new node(nums[i]);
                head->next = newNode;
                newNode->prev = head;
                head = newNode;
                size += 1;
            }
        }
        else {
            node* current = tail;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            for (int i = numsLength-1; i >= 0; i--) {
                node* newNode = new node(nums[i]);
                newNode->prev = current->prev;
                current->prev->next = newNode;
                newNode->next = current;
                current->prev = newNode;
                current = newNode;
                size += 1;
            }
        }
    }

    void erase(int index, int deleteNum) {
        if (index == 0) {
            for (int i = 0; i < deleteNum; i++) {
                tail = tail->next;
                tail->prev->next = nullptr;
                tail->prev = nullptr;
                size -= 1;
            }
        }
        else if (index == size-1) {
            for (int i = 0; i < deleteNum; i++) {
                head = head->prev;
                head->next->prev = nullptr;
                head->next = nullptr;
                size -= 1;
            }
        }
        else {
            node* current = tail;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            for (int i = 0; i < deleteNum; i++) {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                current = current->next;
                size -= 1;
            }
        }
    }

    void print() {
        node* toOut = tail;
        for (int i = 0; i < size; i++) {
            cout << toOut->value << " ";
            toOut = toOut->next;
        }
        cout << endl;
    }

    void printSize() const {
        cout << size << endl;
    }

    node* get(int index) {
        node* current = tail;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    }

    void set(int index, int num) {
        get(index)->value = num;
    }
};

int main() {
    DoubleLinkedList nums;
    int inputsNum;
    cin >> inputsNum;
    for (int i = 0; i < inputsNum; i++) {
        string command;
        cin >> command;
        if (command == "insert") {
            int index;
            cin >> index;
            int length;
            cin >> length;
            int* values = new int[length] {};
            for (int v = 0; v < length; v++) {
                cin >> values[v];
            }
            nums.insert(index, length, values);
        }
        else if (command == "print") {
            nums.print();
        }
        else if (command == "erase") {
            int index;
            cin >> index;
            int deepness;
            cin >> deepness;
            nums.erase(index, deepness);
        }
        else if (command == "size") {
            nums.printSize();
        }
        else if (command == "get") {
            int index;
            cin >> index;
            int value = nums.get(index)->value;
            cout << value << endl;
        }
        else {
            int index;
            cin >> index;
            int value;
            cin >> value;
            nums.set(index, value);
        }
    }

    return 0;
}