#include <iostream> 
#include <queue>
using  namespace std;

struct TreeNode{
    int data;
    TreeNode *right;
    TreeNode *left;

    TreeNode(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode *insert(TreeNode *root, int data){
    if( root == nullptr){
        return new TreeNode(data);
    }

    if( data > root->data){
        root->right = insert(root->right, data);
    }else if(data < root->data){
        root->left = insert(root->left, data);
    }

    return root;
}

void show(TreeNode *root){
    if(root == nullptr){
        return;
    }

    show(root->left);
    cout << root->data << " ";
    show(root->right);
}

TreeNode *create_mirror_flip(TreeNode *root){
    if(root == nullptr){
        return nullptr;
    }
    // Створюємо новий вузол для нового дерева
    TreeNode* mir_root = new TreeNode(root->data);
    
    // Рекурсивно викликаємо функцію для лівого піддерева та присвоюємо його новому правому піддереву
    mir_root->left = create_mirror_flip(root->right);

    // Рекурсивно викликаємо функцію для правого піддерева та присвоюємо його новому лівому піддереву
    mir_root->right = create_mirror_flip(root->left);

    return mir_root;
}

void tree_sum(TreeNode *root){
    if(root == nullptr){
        return;
    }

    queue<TreeNode*> node_q;
    node_q.push(root);

    while (!node_q.empty()){
        TreeNode *current = node_q.front();
        node_q.pop();

        if (current->left != nullptr){
            node_q.push(current->left);
            current->data += current->left->data;
        }

        if (current->right != nullptr){
            node_q.push(current->right);
            current->data += current->right->data;
        } 
    }  
}

int main(){
    TreeNode *root = nullptr;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    cout << "TreeNode: ";
    show(root);
    cout << endl;

    TreeNode *mir_tree = create_mirror_flip(root);
    cout << "New TreeNode: ";
    show(mir_tree);
    cout << endl;

    tree_sum(root);

    cout << "TreeNode after sum: ";
    show(root);

    return 0;
}

