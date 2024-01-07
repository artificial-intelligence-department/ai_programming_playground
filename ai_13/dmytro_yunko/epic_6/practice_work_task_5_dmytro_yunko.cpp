#include <iostream>
#include<queue>

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

        
        void tree_sum() {
            
            tree_sum(root);
        }

        
        void tree_sum(TreeNode* node) {
            
            if (node == nullptr || (node->left == nullptr && node->right == nullptr)) {
                return;
            }

            
            tree_sum(node->left);
            tree_sum(node->right);

            
            node->data = (node->left ? node->left->data : 0) + (node->right ? node->right->data : 0);
        }

        
        void in_order_traversal() {
            
            in_order_traversal(root);
            
            cout << endl;
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

        
        void in_order_traversal(TreeNode* node) {
            
            if (node != nullptr) {
                
                in_order_traversal(node->left);
                
                cout << node->data << " ";
                
                in_order_traversal(node->right);
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
    
    tree.tree_sum();
    

    
    cout << "Tree After Sum Calculations: ";
    tree.in_order_traversal();
    tree.printTree();

    return 0;
}
