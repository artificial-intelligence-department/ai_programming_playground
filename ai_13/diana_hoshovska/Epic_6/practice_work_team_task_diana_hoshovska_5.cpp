#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

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
        if (current->right && current->right != prev) {  //якщо поточний вузол має правого підвузла і він не оброблений
            current = current->right;
        } else {
            int sum = current->val; //обчислюємо суму підвузлів і зберігаємо в поточному вузлі
            if (current->left) {
                sum += current->left->val;
            }
            if (current->right) {
                sum += current->right->val;
            }
            current->val = sum;

            nodeStack.pop(); //батьківський вузол
            prev = current;
            current = nullptr;
        }
    }
}

void printTree(TreeNode* root) {//вивести значення дерева для перевірки
    if (root) {
        printTree(root->left);
        cout << root->val << " ";
        printTree(root->right);
    }
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Original tree: ";
    printTree(root);
    cout << endl;

    tree_sum(root);

    cout << "Modified tree: ";
    printTree(root);
    cout << endl;

    return 0;
}
