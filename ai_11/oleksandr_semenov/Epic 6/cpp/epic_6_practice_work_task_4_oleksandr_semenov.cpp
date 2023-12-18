#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Функція для створення віддзеркаленого дерева
TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    // Створюємо новий вузол з оберненими лівою та правою вітками
    TreeNode* new_root = new TreeNode(root->data);
    new_root->left = create_mirror_flip(root->right);
    new_root->right = create_mirror_flip(root->left);

    return new_root;
}

// Функція для виведення дерева за допомогою обхіду в ширину (BFS)
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

    // Віддзеркалення дерева
    TreeNode* mirrored_root = create_mirror_flip(root);

    cout << "Mirrored Tree: ";
    print_tree(mirrored_root);

    // Звільнення пам'яті
    free_tree(root);
    free_tree(mirrored_root);

    return 0;
}
