#include <stdio.h>
#include <stdlib.h>

// BST - binary search tree
typedef struct BSTNode {
    int value;

    struct BSTNode* parent;
    struct BSTNode* left;
    struct BSTNode* right;
} TreeNode;

TreeNode* create_bst_root(int value);
TreeNode* create_node(int value, TreeNode* parent);
void emplace(TreeNode* root, int value);
void delete_tree(TreeNode* root);
// In order traversal printing
void inorder_print(TreeNode* root);
// End BST

// Task 4
TreeNode *create_mirror_flip(TreeNode *node);
void Task4(TreeNode *root);

// Task 5
TreeNode* tree_sum(TreeNode *root); // I made it a safe procedure
void Task5(TreeNode *root);

int main() {
    int values[] = {7, 3, 11, 1, 5, 9, 13, 0, 2, 4, 6, 8, 10, 12, 14}, n = 15;

    TreeNode *root = create_bst_root(values[0]);
    for (int i = 1; i < n; i++) emplace(root, values[i]);

    Task4(root);
    printf("\n");
    Task5(root);

    delete_tree(root);
    return 0;
}

void Task4(TreeNode *root) {
    printf("Task 4:\n");

    printf("Original tree: ");
    inorder_print(root);

    printf("\nMirror tree: ");
    TreeNode *mirror = create_mirror_flip(root);
    inorder_print(mirror);

    delete_tree(mirror);
}

void Task5(TreeNode *root) {
    printf("Task 5:\n");
    printf("Original tree: ");
    inorder_print(root);
    printf("\nTree sum: ");
    TreeNode *sum = tree_sum(root);
    inorder_print(sum);

    delete_tree(sum);
}

TreeNode* create_bst_root(int value) {
    return create_node(value, NULL);
}

TreeNode* create_node(int value, TreeNode* parent) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->left = node->right = NULL;
    node->value = value;
    node->parent = parent;
    return node;
}

void emplace(TreeNode* root, int value) {
    if (root->value == value) return;

    if (value < root->value) {
        if (root->left == NULL) root->left = create_node(value, root);
        else emplace(root->left, value);
    } else {
        if (root->right == NULL) root->right = create_node(value, root);
        else emplace(root->right, value);
    }
}

void delete_tree(TreeNode* root) {
    if (root == NULL) return;

    delete_tree(root->left);
    delete_tree(root->right);
    free(root);
}

void inorder_print(TreeNode* root) {
    if (root == NULL) return;

    inorder_print(root->left);
    printf("%d ", root->value);
    inorder_print(root->right);
}

TreeNode *create_mirror_flip(TreeNode *node) {
    if (node == NULL) return NULL;

    TreeNode *mirror = create_node(node->value, node->parent);
    if (node->right) mirror->left = create_mirror_flip(node->right);
    if (node->left) mirror->right = create_mirror_flip(node->left);

    return mirror;
}

TreeNode* tree_sum(TreeNode *root) {
    if (root == NULL) return NULL;

    TreeNode *sum = create_node(root->value, NULL);
    sum->left = tree_sum(root->left);
    sum->right = tree_sum(root->right);

    if (sum->left == NULL && sum->right == NULL) return sum;

    sum->value = 0;
    if (sum->left != NULL) sum->value += sum->left->value;
    if (sum->right != NULL) sum->value += sum->right->value;

    return sum;
}
