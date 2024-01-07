#include <iostream>
#include <queue>

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


void outputTree(TreeNode* gilka) 
{
    if (gilka == nullptr) 
    {
        return;
    }

    cout << gilka->value << " ";
    outputTree(gilka->left);
    outputTree(gilka->right);
}


void sumOfTree(TreeNode* gilka) 
{
    if (gilka == nullptr) 
    {
        return;
    }

    queue<TreeNode*> nodesQueue;
    nodesQueue.push(gilka);

    while (!nodesQueue.empty()) 
    {
        TreeNode* currentNode = nodesQueue.front();
        nodesQueue.pop();

        int sum = 0;
        if (currentNode->left != nullptr) 
        {
            nodesQueue.push(currentNode->left);
            sum += currentNode->left->value;
        }

        if (currentNode->right != nullptr) 
        {
            nodesQueue.push(currentNode->right);
            sum += currentNode->right->value;
        }

        currentNode->value += sum;
    }
}

int main() 
{
    
    TreeNode* gilka = new TreeNode(1);
    gilka->left = new TreeNode(2);
    gilka->right = new TreeNode(3);
    gilka->left->left = new TreeNode(4);
    gilka->left->right = new TreeNode(5);

    cout << "Оригінальне дерево: ";
    outputTree(gilka);
    cout << endl;

    
    sumOfTree(gilka);

    cout << "Дерево після обчислення сум: ";
    outputTree(gilka);
    cout << endl;

    
    delete gilka->left->left;
    delete gilka->left->right;
    delete gilka->left;
    delete gilka->right;
    delete gilka;

    return 0;
}
