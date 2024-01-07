#include <iostream>

using namespace std;

class TreeNode 
{
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) 
    {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};


TreeNode* mirrorFlip(TreeNode* gilka) 
{
    if (gilka == nullptr) 
    {
        return nullptr;
    }

    TreeNode* mirroredgilka = new TreeNode(gilka->value);

    mirroredgilka->left = mirrorFlip(gilka->right);
    mirroredgilka->right = mirrorFlip(gilka->left);

    return mirroredgilka;
}


void outputTreaa(TreeNode* gilka) 
{
    if (gilka == nullptr) 
    {
        return;
    }

    cout << gilka->value << " ";
    outputTreaa(gilka->left);
    outputTreaa(gilka->right);
}

int main() 
{
    TreeNode* gilka = new TreeNode(1);
    gilka->left = new TreeNode(2);
    gilka->right = new TreeNode(3);
    gilka->left->left = new TreeNode(4);
    gilka->left->right = new TreeNode(5);

    cout << "Оригінальне дерево: ";
    outputTreaa(gilka);
    cout << endl;

    TreeNode* mirroredTree = mirrorFlip(gilka);
    cout << "Віддзеркалене дерево: ";
    outputTreaa(mirroredTree);
    cout << endl;

    delete gilka;
    delete mirroredTree;

    return 0;
}
