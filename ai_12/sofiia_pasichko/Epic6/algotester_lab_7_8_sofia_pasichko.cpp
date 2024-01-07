#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int number) : data(number), left(nullptr), right(nullptr) {}
};


TreeNode* createNewTree() {
    return nullptr;
}

TreeNode* insert(TreeNode* root, int number) {
    if (root == nullptr) {
        return new TreeNode(number);
    }

    if (number < root->data) {
        root->left = insert(root->left, number);
    } else if (number > root->data) {
        root->right = insert(root->right, number);
    }
    return root;
}

bool contains(TreeNode* node, int number) {
    while (node != nullptr) {
        if (number == node->data) {
            return true;
        } else if (number < node->data) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return false;
}

int size(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    int leftSize = size(node->left);
    int rightSize = size(node->right);
    int size = 1 + leftSize + rightSize;
    return size;
}

void print(TreeNode* node) {
    if (node != nullptr) {
        print(node->left);
        cout << node->data << " ";
        print(node->right);
    }
}

int main() {
    int Q;
    cin >> Q;

    TreeNode* root = createNewTree();

    for (int i = 0; i < Q; i++){
        string option;
        cin >> option;

        if (option == "insert") {
            int number;
            cin >> number;
            root = insert(root, number);
        } else if (option == "contains") {
            int number;
            cin >> number;
            if (contains(root, number)==true) {
                cout << "Yes"<< endl;
            } else {
                cout << "No" << endl;
            }
        } else if (option == "size") {
            cout << size(root) << endl;
        } else if (option == "print") {
            print(root);
            cout << endl;
        }
    }
    return 0;
}