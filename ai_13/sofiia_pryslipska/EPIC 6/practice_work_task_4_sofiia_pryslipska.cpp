#include <iostream>
using namespace std;
// Структура вузла бінарного дерева
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Функція для створення дерева з віддзеркаленням
TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    // Створення нового вузла з обміненими лівим і правим піддеревами
    TreeNode* newNode = new TreeNode(root->data);
    newNode->left = create_mirror_flip(root->right);
    newNode->right = create_mirror_flip(root->left);
    
    return newNode;
}

// Функція для виводу бінарного дерева (приклад)
void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    // Створення бінарного дерева для прикладу
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "A tree before reflection: ";
    printTree(root);
    cout << endl;

    // Створення віддзеркаленого дерева
    TreeNode* mirroredRoot = create_mirror_flip(root);

    cout << "A tree after reflection: ";
    printTree(mirroredRoot);
    cout << endl;


    return 0;
}
