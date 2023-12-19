#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;

    Node(int val): key(val), left(nullptr), right(nullptr){}
};

Node* insertEl(Node* root, int number){
    Node* newNode = new Node(number);
    if(root==nullptr){
        root = newNode;
        return root;
    }
    if(number>root->key){
        root->right=insertEl(root->right, number);
    }
    if(number<root->key){
        root->left=insertEl(root->left, number);
    }
    return root;
}

Node* createTree(int arr[], int size){
    Node* root = nullptr;
    for(int i = 0; i < size; i++){
        root = insertEl(root, arr[i]);
    }
    return root;
}

void showTree(Node* root){
    Node* current = root;
    if(current!=nullptr){
        showTree(current->left);
        cout << current->key << " ";
        showTree(current->right);
    }
}

Node* createMirrorFlip(Node* root){
    if(root!=nullptr){
        Node* tmp = root->left;
        root->left=root->right;
        root->right=tmp;
        createMirrorFlip(root->left);
        createMirrorFlip(root->right);
    }
    return root;
}

void showTree_w(Node* root){
    if(root==nullptr){
        cout << "the tree is empty" << endl;
        return;
    }
    
    queue<Node*> tree;
    tree.push(root);
    while(!tree.empty()){
        Node* current = tree.front();
        tree.pop();
        cout << current->key << " ";
        if(current->left!=nullptr){
            tree.push(current->left);
        }
        if(current->right!=nullptr){
            tree.push(current->right);
        }
    }
}

void sumTree(Node* root){
    if(root==nullptr){
        return;
    }
    sumTree(root->left);
    sumTree(root->right);
    if(root->left==nullptr && root->right==nullptr){
        root->key+=0;
    } else{
        int sum = 0;
        if(root->left!=nullptr){
            sum+=root->left->key;
        }
        if(root->right!=nullptr){
            sum+=root->right->key;
        }
        root->key=sum;
    }
}

int main(){
    int arr[] = {15, 9, 25, 5, 12, 20, 30, 3, 7, 10, 13, 16, 22, 27, 31};
    int size = sizeof(arr)/sizeof(int);

    Node* tree = createTree(arr, size);
    
    cout << "treee: ";
    showTree(tree);

    cout << endl;
    Node* newtree = createMirrorFlip(tree);
    cout << "mirror tree: ";
    showTree(newtree);
    cout << endl;

    int arr2[] = {7, 4, 10, 2, 5, 8, 12, 1, 3};
    int size2 = sizeof(arr2)/sizeof(int);

    Node* tree2 = createTree(arr2, size2);
    
    cout << "tree: ";
    showTree_w(tree2);

    sumTree(tree2);
    cout << endl << "sum tree: ";
    showTree_w(tree2);

    return 0;
}