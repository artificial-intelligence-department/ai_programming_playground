#include <iostream>
#include <stack>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void tree_sum(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    std::stack<TreeNode*> nodes;
    TreeNode* current = root;
    TreeNode* prev = NULL;
    while (current != NULL || !nodes.empty()) {
        while (current != NULL) {
            nodes.push(current);
            current = current->right;
        }
        current = nodes.top();
        nodes.pop();
        if (current->left == NULL && current->right == NULL) {
        } else {
            int left_sum = (current->left != NULL) ? current->left->val : 0;
            int right_sum = (current->right != NULL) ? current->right->val : 0;
            current->val = left_sum + right_sum;
        }
        prev = current;
        current = current->left;
    }
}
void inorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    std::cout << root->val << " ";
    inorderTraversal(root->right);
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    std::cout << "Вхідне дерево (інфіксний обхід): ";
    inorderTraversal(root);
    std::cout << std::endl;
    tree_sum(root);
    std::cout << "Дерево зі сумами підвузлів: ";
    inorderTraversal(root);
    std::cout << std::endl;
    return 0;
}
