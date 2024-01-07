#include <iostream>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Задача 4 - Віддзеркалення дерева
TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode* newRoot = new TreeNode(root->value);

    newRoot->left = create_mirror_flip(root->right);
    newRoot->right = create_mirror_flip(root->left);

    return newRoot;
}

// Задача 5 - Записати кожному батьківському вузлу суму підвузлів
void tree_sum(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    tree_sum(root->left);
    tree_sum(root->right);

    // Підрахунок суми підвузлів і зміна значення поточного вузла
    int leftSum = (root->left != nullptr) ? root->left->value : 0;
    int rightSum = (root->right != nullptr) ? root->right->value : 0;
    root->value += leftSum + rightSum;
}

// Функція для виведення дерева у вигляді тексту для перевірки результату
void print_tree(TreeNode* root) {
    if (root != nullptr) {
        print_tree(root->left);
        cout << root->value << " ";
        print_tree(root->right);
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Original Tree: ";
    print_tree(root);
    cout << endl;

    // Задача 4 - Віддзеркалення дерева
    TreeNode* mirroredTree = create_mirror_flip(root);

    cout << "Mirrored Tree: ";
    print_tree(mirroredTree);
    cout << endl;

    // Задача 5 - Записати кожному батьківському вузлу суму підвузлів
    tree_sum(root);

    cout << "Tree after Sum Calculation: ";
    print_tree(root);
    cout << endl;

    delete root;
    delete mirroredTree;
    
    return 0;
}
