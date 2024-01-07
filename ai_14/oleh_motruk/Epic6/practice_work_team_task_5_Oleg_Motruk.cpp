#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    static void tree_sum(TreeNode* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            int sum = 0;
            if (current->left != nullptr) {
                q.push(current->left);
                sum += current->left->val;
            }
            if (current->right != nullptr) {
                q.push(current->right);
                sum += current->right->val;
            }

            current->val = sum;
        }
    }

    static void printTree(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        queue<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            TreeNode* current = nodes.front();
            nodes.pop();
            
            if (current->val != 0) {
                cout << current->val << " ";
            }

            if (current->left != nullptr) {
                nodes.push(current->left);
            }
            if (current->right != nullptr) {
                nodes.push(current->right);
            }
        }
        cout << endl;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Original tree values: ";
    TreeNode::printTree(root);

    TreeNode::tree_sum(root);

    cout << "Updated tree values: ";
    TreeNode::printTree(root);

    return 0;
}
