#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

void insert(Node*& root, char data) {
    if (!root) {
        root = new Node(data);
        return;
    }

    if (data < root->data) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}

void printTree(Node* root, int depth = 0) {
    if (!root) return;

    printTree(root->right, depth + 1);

    for (int i = 0; i < depth; ++i)
        cout << "   ";
    
    cout << root->data << endl;

    printTree(root->left, depth + 1);
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int countLeaves(Node* root) {
    if (!root) return 0; // Якщо дерево пусте, повертаємо 0

    if (!root->left && !root->right) {
        // Якщо поточний вузол - листок, повертаємо 1
        return 1;
    } else {
        // Якщо поточний вузол не є листком, продовжуємо рекурсивно обчислювати кількість листків
        return countLeaves(root->left) + countLeaves(root->right);
    }
}

int main() {
    Node* root = nullptr;
    char s[] = "18452789";

    for (int i = 0; s[i]; ++i) {
        insert(root, s[i]);
    }

    printTree(root);
    cout << "Number of leaves: " << countLeaves(root) << endl;

    freeTree(root);

    return 0;
}
