#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void tree_sum(TreeNode* root)
{
    if(root == nullptr)
    {
        return;
    }

    stack<TreeNode*> stackOfNode;
    TreeNode* current = root; //вказівник на поточний вузол
    TreeNode* previous = nullptr; //для відстеження попереднього вузла

    while(current != nullptr || !stackOfNode.empty())
    {
        while(current != nullptr)
        {
            stackOfNode.push(current);
            current = current->left;
        }

        current = stackOfNode.top();

        if(current->left == nullptr && current->right == nullptr)
        {
            stackOfNode.pop();
            previous = current;
            current = nullptr;
        }
        else if(current->right != nullptr && current->right != previous) //якщо є правий вузол, який ще не відвіданий
        {
            current = current->right;
        }
        else
        {
            TreeNode* temp = current;
            current = nullptr;
            stackOfNode.pop(); //видалити поточний вузол зі стеку, так як він вже оброблений

            int sum = temp->data;
            if(temp->left != nullptr)
            {
                sum += temp->left->data;
            }
            if(temp->right != nullptr)
            {
                sum += temp->right->data;
            }

            temp->data = sum;

            previous = temp; //щоб на наступній ітерації циклу правильно визначити, чи було відвідане праве піддерево
        }
    }
}

void printBinaryTree(TreeNode* root)
{
    if(root != nullptr)
    {
        printBinaryTree(root->left);
        cout << root->data << " ";
        printBinaryTree(root->right);
    }
}

int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(10);

    cout << "Original binary tree: ";
    printBinaryTree(root);
    cout << endl;

    tree_sum(root);

    cout << "Tree after sums: ";
    printBinaryTree(root);
    cout << endl;

    return 0;
}
