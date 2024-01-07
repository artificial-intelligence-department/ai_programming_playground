#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void print_tree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int level_size = q.size();
        for (int i = 0; i < level_size; i++) {
            TreeNode* curr = q.front();
            q.pop();
            cout << curr->val << " ";
            if (curr->left != nullptr) {
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
                q.push(curr->right);
            }
        }
        cout << endl;
    }
}

TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    TreeNode* new_root = new TreeNode(root->val);
    new_root->left = create_mirror_flip(root->right);
    new_root->right = create_mirror_flip(root->left);
    return new_root;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Original tree:" << endl;
    print_tree(root);

    TreeNode* mirrored_root = create_mirror_flip(root);

    cout << "Mirrored tree:" << endl;
    print_tree(mirrored_root);

    return 0;
}