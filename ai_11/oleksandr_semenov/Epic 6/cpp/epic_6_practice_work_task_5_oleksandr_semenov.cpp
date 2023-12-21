#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Функція для підрахунку суми підвузлів бінарного дерева
void tree_sum(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        // Обчислення суми підвузлів
        int sum = 0;
        if (current->left != nullptr) {
            sum += current->left->data;
            q.push(current->left);
        }

        if (current->right != nullptr) {
            sum += current->right->data;
            q.push(current->right);
        }

        // Запис суми у батьківський вузол (лише для небудь-яких батьківських вузлів, не листків)
        if (current->left != nullptr || current->right != nullptr) {
            current->data = sum;
        }
    }
}

// Функція для виведення дерева за допомогою обходу в ширину (BFS)
void print_tree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }

        if (current->right != nullptr) {
            q.push(current->right);
        }
    }

    cout << endl;
}

// Функція для звільнення пам'яті, видалення усіх вузлів дерева
void free_tree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);
    delete root;
}

int main() {
    // Приклад використання
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Original Tree: ";
    print_tree(root);

    // Застосування функції для підрахунку суми підвузлів
    tree_sum(root);

    cout << "Tree with Sum: ";
    print_tree(root);

    // Звільнення пам'яті
    free_tree(root);

    return 0;
}
