#include <iostream>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    TreeNode* newRoot = new TreeNode(root->val);
    newRoot->left = create_mirror_flip(root->right);
    newRoot->right = create_mirror_flip(root->left);
    return newRoot;
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
    TreeNode* mirroredRoot = create_mirror_flip(root);
    std::cout << "Дзеркальне дерево (інфіксний обхід): ";
    inorderTraversal(mirroredRoot);
    std::cout << std::endl;
    return 0;
}
