#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

     ~TreeNode() {
    delete left;
    delete right;
     }
};


TreeNode *create_mirror_flip(TreeNode *root) {
    if (!root)
     return nullptr;

   TreeNode *mirroredRoot = new TreeNode(root->val);


    mirroredRoot->right = create_mirror_flip(root->left);
    mirroredRoot->left = create_mirror_flip(root->right);

    return mirroredRoot;
}

// Допоміжна функція для виводу дерева в порядку обходу в ширину
void printTree(TreeNode *root) {
    if (root == NULL) {
        return;
    }

    std::cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    // Приклад використання
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(5);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(9);

    std::cout << "Original tree: ";
    printTree(root);
    std::cout << std::endl;

    TreeNode *mirrorRoot = create_mirror_flip(root);

    std::cout << "Mirrored tree: ";
    printTree(mirrorRoot);
    std::cout << std::endl;

    return 0;
}
