#include <iostream>
#include <queue>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void tree_sum(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        int sum = 0;
        if (current->left != nullptr) {
            sum += current->left->data;
            q.push(current->left);
        }
        if (current->right != nullptr) {
            sum += current->right->data;
            q.push(current->right);
        }

        current->data = sum;
    }
}

void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        std::cout << current->data << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
    std::cout << std::endl;
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    std::cout << "Оригінальне бінарне дерево: ";
    printTree(root);
    std::cout << std::endl;

    tree_sum(root);
    std::cout << "Бінарне дерево після запису сум підвузлів: ";
    printTree(root);
    std::cout << std::endl;

    return 0;
}
