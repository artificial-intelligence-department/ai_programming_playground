#include <iostream>
#include <stack>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

void tree_sum(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    std::stack<TreeNode*> nodeStack;
    TreeNode* prevNode = nullptr;

    while (root != nullptr || !nodeStack.empty()) {
        while (root != nullptr) {
            nodeStack.push(root);
            root = root->left;
        }

        root = nodeStack.top();

        if (root->right == nullptr || root->right == prevNode) {
            // Обробляємо вузол
            if (root->left != nullptr) {
                root->value += root->left->value;
            }
            if (root->right != nullptr) {
                root->value += root->right->value;
            }

            nodeStack.pop();
            prevNode = root;
            root = nullptr;
        } else {
            root = root->right;
        }
    }
}

int main() {
    // Створення дерева
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Виклик функції для оновлення значень батьківських вузлів
    tree_sum(root);

    // Вивід значень після оновлення
    std::cout << "Updated tree values:\n";
    std::cout << "Root: " << root->value << "\n";
    std::cout << "Left child: " << root->left->value << "\n";
    std::cout << "Right child: " << root->right->value << "\n";

    // Очистка пам'яті
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}


