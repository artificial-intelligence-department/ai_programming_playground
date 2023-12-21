#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    
    TreeNode(int newValue) {
        this->value = newValue;
    }
    
    friend ostream& operator<<(ostream&, const TreeNode*);
};

ostream& operator<<(ostream& out, const TreeNode* node) {
    if (node == NULL) {
        return out;
    }
    out << node->value << " ";
    if (node->left != NULL) {
        out << node->left;
    }
    if (node->right != NULL) {
        out << node->right;
    }
    return out;
}

    
TreeNode* insert(TreeNode* node, int newValue) {
    if (node == NULL) {
        node = new TreeNode(newValue);
        return node;
    }
    else {
        if (newValue == node->value) {
            return node;
        }
        else if (newValue < node->value) {
            if (node->left == NULL) {
                node->left = new TreeNode(newValue);
                return node;
            }
            else {
                insert(node->left, newValue);
                return node;
            }
        }
        else /* means (newValue > node->value) */ {
            if (node->right == NULL) {
                node->right = new TreeNode(newValue);
                return node;
            }
            else {
                insert(node->right, newValue);
                return node;
            }
        }
    }
}

TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    TreeNode* newNode = new TreeNode(root->value);
    newNode->left = create_mirror_flip(root->right);
    newNode->right = create_mirror_flip(root->left);
    return newNode;
}


int calculate(TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    
    if (node->left != NULL || node->left != NULL) {
        int l = calculate(node->left);
        int r = calculate(node->right);
        return l + r;
    }
    else {
        return node->value;
    }
}

void tree_sum(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    root->value = calculate(root);
    tree_sum(root->left);
    tree_sum(root->right);
}

int main() {
    TreeNode* tree = insert(NULL, 6);
    insert(tree, 0);
    insert(tree, 10);
    insert(tree, 2);
    insert(tree, 1);
    insert(tree, 3);
    insert(tree, 11);
    
    cout << tree << "\n";
    
    TreeNode* newTree = create_mirror_flip(tree);
    
    cout << newTree << "\n";
    
    tree_sum(newTree);
    
    cout << newTree << "\n";
    
    return 0;
}