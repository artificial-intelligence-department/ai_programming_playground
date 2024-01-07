#include <iostream>

using  namespace std;

struct Node {

    int data;
    Node* next;

    Node(int value, Node* node)
    {
        data = value;
        next = node;
    }
};

void showNode(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!!" << endl;
        return;
    }

    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

void pushFront(Node*& head, int value) {
    if (head == nullptr) {
        head = new Node{ value, nullptr };
    }
    else {
        Node* newNode = new Node{ value, head };
        head = newNode;
    }
}

Node* reverse(Node* head) {
    Node* current = head;
    Node* last = nullptr;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = last;
        last = current;
        current = next;
    }
    return last;
}

bool compare(Node* h1, Node* h2) {
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->data != h2->data) {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    if (h1 != nullptr || h2 != nullptr) {
        return false;
    }

    return true;
}


int main() {
    Node* list1 = nullptr;
    pushFront(list1, 1);
    pushFront(list1, 3);
    pushFront(list1, 5);
    pushFront(list1, 7);


    cout << "| List: ";
    showNode(list1);
    cout << endl;
    cout << "-------------------------" << endl;
    list1 = reverse(list1);
    cout << "| Reversed list: ";
    cout << endl;
    cout << endl;
    showNode(list1);
    cout << endl;
    cout << "-------------------------" << endl;
    cout << endl;


    Node* list2 = nullptr;
    pushFront(list2, 5);
    pushFront(list2, 2);
    pushFront(list2, 3);
    pushFront(list2, 1);

    cout << "| List -> 1: ";
    showNode(list1);

    Node* list3 = nullptr;
    pushFront(list3, 5);
    pushFront(list3, 0);
    pushFront(list3, 1);
    pushFront(list3, 9);

    cout << "| List -> 2: ";
    showNode(list3);

    bool result = compare(list2, list3);

    if (result)
        cout << "| List equal!" << endl;
    else
        cout << "| List not equal!" << endl;

    Node* list4 = nullptr;
    pushFront(list4, 1);
    pushFront(list4, 2);
    pushFront(list4, 3);

    cout << "| List -> 3: ";
    showNode(list4);

    Node* list5 = nullptr;
    pushFront(list5, 9);
    pushFront(list5, 8);
    pushFront(list5, 7);


    return 0;
}

//#include <iostream> 
//#include <queue>
//using  namespace std;
//
//struct Tree {
//    int data;
//    Tree* left;
//    Tree* right;
//
//    Tree(int value) {
//        data = value;
//        left = nullptr;
//        right = nullptr;
//    }
//};
//
//Tree* insert(Tree* root, int data) {
//
//    if (root == nullptr) {
//        return new Tree(data);
//    }
//
//    if (data > root->data) {
//        root->right = insert(root->right, data);
//    }
//    else if (data < root->data) {
//        root->left = insert(root->left, data);
//    }
//
//    return root;
//}
//
//void show(Tree* root) {
//
//    if (root == nullptr) {
//        return;
//    }
//
//    show(root->left);
//    cout << root->data << " ";
//    show(root->right);
//}
//
//Tree* create_mirror_flip(Tree* root) {
//    if (root == nullptr) {
//        return nullptr;
//    }
//
//    Tree* new_root = new Tree(root->data);
//    new_root->left = create_mirror_flip(root->right);
//    new_root->right = create_mirror_flip(root->left);
//
//    return new_root;
//}
//
//void tree_sum(Tree* root) {
//    if (root == nullptr) {
//        return;
//    }
//
//    queue<Tree*> queue;
//    queue.push(root);
//
//    while (!queue.empty()) {
//        Tree* current = queue.front();
//        queue.pop();
//
//        if (current->left != nullptr) {
//            queue.push(current->left);
//            current->data += current->left->data;
//        }
//
//        if (current->right != nullptr) {
//            queue.push(current->right);
//            current->data += current->right->data;
//        }
//    }
//}
//
//int main() {
//    Tree* root = nullptr;
//    root = insert(root, 5);
//    insert(root, 8);
//    insert(root, 1);
//    insert(root, 0);
//    insert(root, 5);
//
//
//    cout << "| Tree: ";
//    show(root);
//    cout << endl;
//
//    Tree* mirror_tree = create_mirror_flip(root);
//    cout << "| New Mirror Tree: ";
//    show(mirror_tree);
//    cout << endl;
//
//    tree_sum(root);
//
//    cout << "| Tree sum: ";
//    show(root);
//
//    return 0;
//}
