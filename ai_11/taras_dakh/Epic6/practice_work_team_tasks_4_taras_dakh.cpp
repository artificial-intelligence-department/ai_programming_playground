#include <iostream>

// Ваша структура TreeNode
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Наша нова структура для роботи з деревом
struct TreeProcessor {
    static TreeNode* createMirrorFlippedTree(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode *newRoot = new TreeNode(root->val);
        newRoot->right = createMirrorFlippedTree(root->left);
        newRoot->left = createMirrorFlippedTree(root->right);

        return newRoot;
    }

    static void printTree(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        printTree(root->left);
        std::cout << root->val << " ";
        printTree(root->right);
    }
};

int main() {
    // Приклад використання
    TreeNode *originalTree = new TreeNode(1);
    originalTree->left = new TreeNode(2);
    originalTree->right = new TreeNode(3);
    originalTree->left->left = new TreeNode(4);
    originalTree->left->right = new TreeNode(5);

    std::cout << "Original Tree: ";
    TreeProcessor::printTree(originalTree);
    std::cout << std::endl;

    TreeNode *flippedTree = TreeProcessor::createMirrorFlippedTree(originalTree);

    std::cout << "Flipped Tree: ";
    TreeProcessor::printTree(flippedTree);
    std::cout << std::endl;

    return 0;
}
