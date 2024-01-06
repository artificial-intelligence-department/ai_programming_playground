#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* create_mirror_flip(TreeNode* root){
    // Base case: If the tree is empty, return nullptr
    if (!root) {
        return nullptr;
    }
    // Recursive case: Swap the left and right subtrees
    TreeNode* temp = root->left;
    root->left = create_mirror_flip(root->right);
    root->right = create_mirror_flip(temp);

    return root;
}

// Helper function to print the tree (in-order traversal)
void print_tree(TreeNode* root){
    if (root) {
        print_tree(root->left);
        cout << root->data << " "; //printinf current(parent) node
        print_tree(root->right);
    }
}

void delete_tree(TreeNode* root){
    if (root) {
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
    }
}

void tree_sum(TreeNode* root){
    if (!root || (!root->left && !root->right)) {
        // Якщо вузол порожній або є листком, не змінюємо його значення
        return;
    }

    // Рекурсивно викликаємо для лівого та правого піддерева
    tree_sum(root->left);
    tree_sum(root->right);

    // Змінюємо значення поточного батьківського вузла на суму значень підвузлів
    root->data = (root->left ? root->left->data : 0) + (root->right ? root->right->data : 0);
}

int main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Original Tree: ";
    print_tree(root);
    cout << endl;

    TreeNode* mirroredTree = create_mirror_flip(root);

    cout << "Mirrored Tree: ";
    print_tree(mirroredTree);
    cout << endl;
    
    tree_sum(root);
    cout << "Tree after Sum Calculation: ";
    print_tree(root);
    cout << endl;
    
    delete_tree(root);

    return 0;
}
