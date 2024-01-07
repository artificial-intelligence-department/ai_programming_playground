#include <iostream>

using namespace std;

// Створення структури для вузла бінарного дерева
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Функція для створення віддзеркаленого дерева
TreeNode* create_mirror_flip(TreeNode *root) {
    if (root == nullptr) {
        return nullptr; 
    }

    
    TreeNode *newNode = new TreeNode(root->val);

    
    newNode->left = create_mirror_flip(root->right); 
    newNode->right = create_mirror_flip(root->left);

    return newNode; 
}

// Функція для виведення значень вузлів бінарного дерева
void print_tree(TreeNode *root) {
    if (root == nullptr) {
        return; // Якщо вузол порожній (null), завершуємо виконання функції
    }
    
    cout << root->val << " " ;
    // Рекурсивний виклик для лівого та правого піддерев
    print_tree(root->left); 
    print_tree(root->right); 
}

int main() {
    // створення бінарного дерева
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Оригінальне дерево: ";
    print_tree(root); 

    TreeNode *mirrorTree = create_mirror_flip(root); // Створення віддзеркаленого дерева

    cout << "\nВіддзеркалене дерево: ";
    print_tree(mirrorTree); 

    return 0;
}