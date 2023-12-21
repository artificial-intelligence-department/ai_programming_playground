#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree() : root(nullptr) {}

    void insert(int val) {
        insert(root, val);
    }

    void insert(TreeNode*& node, int val) {
        if (node == nullptr) {
            node = new TreeNode(val);
            return;
        }

        if (val < node->value) {
            insert(node->left, val);
        } else {
            insert(node->right, val);
        }
    }

    BinaryTree createMirroredTree() {
        BinaryTree mirroredTree;
        createMirroredTree(root, mirroredTree.root);
        return mirroredTree;
    }

    void createMirroredTree(TreeNode* node, TreeNode*& mirroredNode) {
        if (node == nullptr) {
            return;
        }

        mirroredNode = new TreeNode(node->value);
        createMirroredTree(node->left, mirroredNode->right);
        createMirroredTree(node->right, mirroredNode->left);
    }

    void inOrderTraversal() {
        inOrderTraversal(root);
        cout << endl;
    }

    void inOrderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->value << " ";
            inOrderTraversal(node->right);
        }
    }

    void printTree() {
        if (root == nullptr) {
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();

            while (levelSize > 0) {
                TreeNode* node = q.front();
                q.pop();
                cout << node->value << " ";

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }

                levelSize--;
            }

            cout << endl;
        }
    }
};

int main() {
    BinaryTree tree;

    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);

    cout << "Original Tree: ";
    tree.inOrderTraversal();
    tree.printTree();

    BinaryTree mirroredTree = tree.createMirroredTree();

    cout << "Mirrored Tree: ";
    mirroredTree.inOrderTraversal();
    mirroredTree.printTree();

    return 0;
}
