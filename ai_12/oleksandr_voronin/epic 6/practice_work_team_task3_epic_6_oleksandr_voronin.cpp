#include <iostream>
#include <stack>

using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) : value(v), left(nullptr), right(nullptr) {}
};

void tree_sum(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    stack<TreeNode*> nodeStack;
    TreeNode* cur = root;
    TreeNode* prev = nullptr;

    while (cur || !nodeStack.empty()) {
        while (cur) {
            nodeStack.push(cur);
            cur = cur->left;
        }

        cur = nodeStack.top();

        if (cur->right && cur->right != prev) {
            cur = cur->right;
        } else {
        
            int sum = cur->value;
            if (cur->left) {
                sum += cur->left->value;
            }
            if (cur->right) {
                sum += cur->right->value;
            }

            cur->value = sum;

            nodeStack.pop();
            prev = cur;
            cur = nullptr;
        }
    }
}

void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    printTree(root->left);
    cout << root->value << " ";
    printTree(root->right);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    cout << "Original Tree: ";
    printTree(root);
    cout << endl;

    tree_sum(root);

    cout << "Tree after sum calculation: ";
    printTree(root);
    cout << endl;

    
    delete root;

    return 0;
}
