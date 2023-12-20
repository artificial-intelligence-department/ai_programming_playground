#include <iostream>

using namespace std;

struct node {
    int value;
    node* left;
    node* right;
    explicit node(int num) {
        value = num;
        left = nullptr;
        right = nullptr;
    }
};

node* mirror(node* Node) {
    if (Node == nullptr) {
        return nullptr;
    }
    node* resultTree = new node(Node->value);
    resultTree->left = mirror(Node->right);
    resultTree->right = mirror(Node->left);
    return resultTree;
}

void doSum(node* Node) {
    if (Node != nullptr) {
        if (Node->left || Node->right) Node->value = (Node->left ? Node->left->value : 0) + (Node->right ? Node->right->value : 0);
        doSum(Node->left);
        doSum(Node->right);
    }
}

void printTree(node* Node) {
    if (Node != nullptr) {
        cout << Node->value << " ";
        printTree(Node->left);
        printTree(Node->right);
    }
}

int main() {
    node* tree1 = new node(1);

    tree1->left = new node(1);
    tree1->left->left = new node(5);
    tree1->left->right = new node(2);

    tree1->right = new node(2);
    tree1->right->left = new node(6);
    tree1->right->left->left = new node(4);
    tree1->right->right = new node(8);

    printTree(tree1);
    cout << endl;

    node* revTree = mirror(tree1);
    printTree(revTree);
    cout << endl;

    doSum(tree1);
    printTree(tree1);

    return 0;
}
