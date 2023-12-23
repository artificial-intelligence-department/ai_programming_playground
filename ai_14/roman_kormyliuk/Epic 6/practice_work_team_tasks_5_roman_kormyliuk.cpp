#include <iostream>
#include <stack>
using namespace std;
// Визначення структури вузла бінарного дерева
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Функція для обчислення суми підвузлів і запису її у батьківський вузол (ітеративний підхід)
void tree_sum(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Використовуємо стек для ітеративного обходження дерева
    stack<TreeNode*> nodeStack;
    TreeNode* current = root;
    TreeNode* prev = nullptr;

    while (current != nullptr || !nodeStack.empty()) {
        while (current != nullptr) {
            nodeStack.push(current);
            current = current->left;
        }

        current = nodeStack.top();

        // Якщо вузол має правого нащадка і це не бувавий вузол, то переходимо до правого піддерева
        if (current->right != nullptr && current->right != prev) {
            current = current->right;
        } else {
            // Обчислюємо суму підвузлів та записуємо її у батьківський вузол
            int sum = current->value;
            if (current->left != nullptr) {
                sum += current->left->value;
            }
            if (current->right != nullptr) {
                sum += current->right->value;
            }
            current->value = sum;

            nodeStack.pop();
            prev = current;
            current = nullptr;
        }
    }
}

// Функція для виведення значень вузлів дерева (ін-ордер)
void print_tree(TreeNode* root) {
    if (root != nullptr) {
        print_tree(root->left);
        cout << root->value << " ";
        print_tree(root->right);
    }
}

int main() {
    // Приклад використання
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Дерево до змін: ";
    print_tree(root);
    cout << endl;

    tree_sum(root);

    cout << "Дерево після змін: ";
    print_tree(root);
    cout << endl;

    // Очищення пам'яті
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
