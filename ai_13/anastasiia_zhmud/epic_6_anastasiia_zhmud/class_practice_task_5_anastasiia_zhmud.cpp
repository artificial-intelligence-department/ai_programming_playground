#include <iostream>
using namespace std;
struct Tree{
    int v;
    Tree* left;
    Tree* right;

    Tree(int value) : v(value), left(NULL), right(NULL) {}
};
void print(Tree* root, int s = 0) {
    int c = 3;
    if (root == NULL) {
        return;
    }
    s=s+c;
    print(root->right, s);
    cout << endl;
    for (int i = c; i < s; i++) {
        cout << " ";
    }
    cout << root->v << "\n";
    print(root->left, s);
}
int tree_sum(Tree* root){
    if ( root == NULL) {
        return 0;
    }
    if (root->right == NULL && root->left == NULL) {
        return root->v;
    }
    int ls= tree_sum(root->left);
    int rs = tree_sum(root->right);
    root->v = ls + rs;
    return root->v;
}
int main(){
    Tree* root = new Tree(1);
    root->left = new Tree(5);
    root->right = new Tree(3);
    root->left->left = new Tree(0);
    root->left->right = new Tree(7);
    root->right->right = new Tree(2);

    cout << "Before:" << endl;
    print(root);
    cout << endl;
    tree_sum(root);
    cout << "After: " << endl;
    print(root);
    return 0;
}