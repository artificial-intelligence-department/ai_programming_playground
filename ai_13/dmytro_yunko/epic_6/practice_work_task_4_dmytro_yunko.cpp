#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
    public:
        
        int data;
        TreeNode* left;
        TreeNode* right;

        
        TreeNode(int data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};


class BinaryTree {
    private:
        
        TreeNode* root;

    public:
        
        BinaryTree() {
            root = nullptr;
        }

        
        void insert(int data) {
            
            insert(root, data);
        }

        
        void insert(TreeNode*& node, int data) {
            
            if (node == nullptr) {
                node = new TreeNode(data);
                return;
            }

            
            if (data < node->data) {
                insert(node->left, data);
            } else {
                
                insert(node->right, data);
            }
        }

        
        BinaryTree create_mirror_flip() {
            
            BinaryTree mirroredTree;
            
            create_mirror_flip(root, mirroredTree.root);
            
            return mirroredTree;
        }

        
        void create_mirror_flip(TreeNode* node, TreeNode*& mirroredNode) {
            
            if (node == nullptr) {
                return;
            }

            
            mirroredNode = new TreeNode(node->data);
            
            create_mirror_flip(node->left, mirroredNode->right);
            
            create_mirror_flip(node->right, mirroredNode->left);
        }

        
        void in_order_traversal() {
            
            in_order_traversal(root);
            
            cout << endl;
        }

        
        void in_order_traversal(TreeNode* node) {
            
            if (node != nullptr) {
                
                in_order_traversal(node->left);
                
                cout << node->data << " ";
                
                in_order_traversal(node->right);
            }
        }
        void printTree() {
            
            if (root == nullptr) {
                return;
            }

            
            queue<TreeNode*> q;
            
            q.push(root);
            
            while (!q.empty()) {
                
                int n = q.size();
                
                while (n > 0) {
                    
                    TreeNode* node = q.front();
                    q.pop();
                    cout << node->data << " ";
                    
                    if (node->left != nullptr) {
                        q.push(node->left);
                    }
                    if (node->right != nullptr) {
                        q.push(node->right);
                    }
                    
                    n--;
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

    
    cout << "Original Tree : ";
    tree.in_order_traversal();
    tree.printTree();
    
    BinaryTree mirroredTree = tree.create_mirror_flip();

    
    cout << "Mirrored Tree : ";
    
    mirroredTree.in_order_traversal();
    
    mirroredTree.printTree();
    

    return 0;
}
