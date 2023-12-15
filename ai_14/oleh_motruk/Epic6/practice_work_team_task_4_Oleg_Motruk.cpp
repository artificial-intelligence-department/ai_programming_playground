#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    
    static TreeNode* create_mirror_flip(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* temp = root->left;
        root->left = create_mirror_flip(root->right);
        root->right = create_mirror_flip(temp);

        return root;
    }

    static void printTree(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Original tree: ";
    TreeNode::printTree(root);
    cout << endl;

    TreeNode* mirroredTree = TreeNode::create_mirror_flip(root);

    cout << "Mirrored tree: ";
    TreeNode::printTree(mirroredTree);
    cout << endl;

    return 0;
}
