#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr), parent(nullptr) {}
};

TreeNode* mirror(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode* newRoot = new TreeNode(root->data);

    newRoot->right = mirror(root->left);
    newRoot->left = mirror(root->right);

    return newRoot;
}

void tree_sum(TreeNode* Node) {
if (Node == nullptr) {
        return;
    }

    tree_sum(Node->left);
    tree_sum(Node->right);

    int newData = 0;
    if (Node->left != nullptr) {
        newData += Node->left->data;
    }
    if (Node->right != nullptr) {
        newData += Node->right->data;
    }
    if(Node->left != nullptr || Node->right != nullptr)
    {
        Node->data = newData;
    }
}

void insert(TreeNode* root, int value) {
    TreeNode* current = root;
    TreeNode* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (value < current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    TreeNode* newNode = new TreeNode(value);
    newNode->parent = parent;

    if (value < parent->data) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }
}

// "In order" output
void print(TreeNode* Node) {
    if (Node != nullptr) {
        print(Node->left);
        cout << Node->data << " ";
        print(Node->right);
    }
}

int main() {
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;
    cout << "Enter the elements: ";
    int value;
    cin >> value;
    TreeNode* root = new TreeNode(value);
    for (int i = 1; i < n; i++) {
        cin >> value;
        insert(root, value);
    }

    cout << "Original tree: ";
    print(root);
    cout << endl;

    cout << "Mirrored tree: ";
    print(mirror(root));
    cout << endl;

    cout << "Updated tree: ";
    tree_sum(root);
    print(root);

    return 0;
}