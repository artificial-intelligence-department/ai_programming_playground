#include <iostream>
#include <stack>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode* mirroredRoot = new TreeNode(root->value);
    mirroredRoot->left = create_mirror_flip(root->right);
    mirroredRoot->right = create_mirror_flip(root->left);

    return mirroredRoot;
}

void tree_sum(TreeNode *root) {
    if (!root) {
        return;
    }

    std::stack<TreeNode*> nodeStack;
    TreeNode *current = root;
    TreeNode *prev = nullptr;

    while (current || !nodeStack.empty()) {
        while (current) {
            nodeStack.push(current);
            current = current->left;
        }
        current = nodeStack.top();
        if (current->right && current->right != prev) {
            current = current->right;
        } else {
            int val = current->value;
            if (current->left) {
                val += current->left->value;
            }
            if (current->right) {
                val += current->right->value;
            }
            current->value = val;

            nodeStack.pop();
            prev = current;
            current = nullptr;
        }
    }
}


void printTree(const TreeNode* root) {
    if (root != nullptr) {
        printTree(root->left);
        std::cout << root->value << " ";
        printTree(root->right);
    }
}

int main() {

    TreeNode* tree = new TreeNode(2);
    tree->left = new TreeNode(5);
    tree->right = new TreeNode(8);
    tree->left->left = new TreeNode(11);
    tree->left->right = new TreeNode(14);

    std::cout << "Original tree (from left to right): ";
    printTree(tree);
    std::cout << std::endl;

    TreeNode* mirroredTree = create_mirror_flip(tree);

    std::cout << "Mirrored tree (from left to right): ";
    printTree(mirroredTree);
    std::cout << std::endl;

    tree_sum(tree);
    std::cout << "Tree sum:" << std::endl;
    printTree(tree);

    return 0;
}
