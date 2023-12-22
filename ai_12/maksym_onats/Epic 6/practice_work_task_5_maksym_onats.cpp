#include <iostream>
#include <stack>

// Визначення структури вузла бінарного дерева
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Функція для ітеративного обчислення суми значень підвузлів
void tree_sum(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    std::stack<TreeNode*> nodeStack;
    TreeNode* current = root;
    TreeNode* prev = nullptr;

    while (current || !nodeStack.empty()) {
        while (current) {
            nodeStack.push(current);
            current = current->left;
        }

        current = nodeStack.top();

        // Якщо поточний вузол має праву вітку та не є листком
        if (current->right && current->right != prev) {
            // Обробляємо праву вітку перед зміною значення поточного вузла
            current = current->right;
        } else {
            // Обчислення суми підвузлів та зміна значення вузла
            int sum = current->value;
            if (current->left) {
                sum += current->left->value;
            }
            if (current->right) {
                sum += current->right->value;
            }

            current->value = sum;

            // Позначаємо поточний вузол як вже відвіданий
            nodeStack.pop();
            prev = current;
            current = nullptr;
        }
    }
}

// Функція для виведення дерева в глибокому порядку (pre-order)
void print_preorder(TreeNode* root) {
    if (root != nullptr) {
        std::cout << root->value << " ";
        print_preorder(root->left);
        print_preorder(root->right);
    }
}

int main() {
    // Приклад створення бінарного дерева
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Вивід оригінального дерева
    std::cout << "Original Tree (pre-order): ";
    print_preorder(root);
    std::cout << std::endl;

    // Обчислення сум підвузлів та зміна значень вузлів
    tree_sum(root);

    // Вивід зміненого дерева
    std::cout << "Modified Tree (pre-order): ";
    print_preorder(root);
    std::cout << std::endl;

    return 0;
}
