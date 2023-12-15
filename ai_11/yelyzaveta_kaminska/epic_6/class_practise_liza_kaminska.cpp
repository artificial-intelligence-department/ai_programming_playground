#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
}
};
// Рекурсивна функція для створення віддзеркаленого дерева
TreeNode* mirror_flip(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    TreeNode* left_mirror = mirror_flip(root->left);
    TreeNode* right_mirror = mirror_flip(root->right);

    TreeNode* mirrored_node = new TreeNode(root->data);
    mirrored_node->left = right_mirror;
    mirrored_node->right = left_mirror;

    return mirrored_node;
}
// Допоміжна функція для виведення дерева (обхід у глибину)
void print_T(TreeNode* root) {
    if (root != nullptr) {
        print_T(root->left);
        cout << root->data << " ";
        print_T(root->right);
    }
    
}
// Функція для запису кожному батьківському вузлу суми підвузлів
void Tree_sum(TreeNode* root) {
    if (!root) {
        return;
    }

    // Використовуємо обхід у ширину для ітеративного обходу дерева
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        int sum = 0;
        if (current->left) {
            sum += current->left->data;
            q.push(current->left);
        }
        if (current->right) {
            sum += current->right->data;
            q.push(current->right);
        }

        if (current->left || current->right) {
            current->data = sum;
        }
    }
}
void deleteTree(TreeNode* root) {
    if (root != nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    cout << "Origin tree: ";
    print_T(root);
    cout << endl;

    TreeNode* mirrored_root = mirror_flip(root);

    cout << "Mirrored tree: ";
    print_T(mirrored_root);
    cout << endl;

    Tree_sum(root);
    cout << "Modified tree values:" << endl;
    cout << "   " << root->data << endl;
    cout << "  / \\" << endl;
    cout << " " << root->left->data << "   " << root->right->data << endl;
    cout << "/ \\" << endl;
    cout << root->left->left->data << "   " << root->left->right->data << endl;

    delete root->right->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;
    deleteTree(root);
    deleteTree(mirrored_root);

    return 0;
}
