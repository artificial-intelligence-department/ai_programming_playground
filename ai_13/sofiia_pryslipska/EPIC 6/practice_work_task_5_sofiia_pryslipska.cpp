#include <iostream>
#include <queue>
using namespace std;
struct TreeNode { //представляє вузол бін дерева
    int val; //значення вузла
    TreeNode* left; //покажчики на дочіпні вузли
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void tree_sum(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root); //додає поч. вузол до черги

    while (!q.empty()) {
        TreeNode* current = q.front();//повертає посилання на перший елемент у черзі 
        q.pop();// видаляє перший елемент з черги

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }

        if (current->left != nullptr || current->right != nullptr) {
            int sum = 0;
            if (current->left != nullptr) {
                sum += current->left->val;
            }
            if (current->right != nullptr) {
                sum += current->right->val;
            }
            current->val = sum;
        }
    }
}


void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(8);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(20);

    cout << "Before applying tree_sum: ";
    printTree(root);
    cout << endl;

    tree_sum(root);

    cout << "After applying tree_sum: ";
    printTree(root);
    cout << endl;

    return 0;
}



