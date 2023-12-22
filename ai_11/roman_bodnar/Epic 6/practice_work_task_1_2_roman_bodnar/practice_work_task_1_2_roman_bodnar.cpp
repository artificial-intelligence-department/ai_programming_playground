#include <iostream>
#include <random>
using namespace std;

struct TreeNode
{
    int Value;
    TreeNode *Left;
    TreeNode *Right;
    TreeNode *Parent;

    TreeNode(int value, TreeNode *left, TreeNode *right, TreeNode *parent)
            : Value(value), Left(left), Right(right), Parent(parent) {}
    TreeNode() : Left(NULL), Right(NULL), Parent(NULL) {}
    TreeNode(int value) : TreeNode(value, NULL, NULL, NULL) {}
};

void insert(TreeNode *pParent, int value)
{
    if (pParent == NULL)
        return;

    if (value < pParent->Value)
    {
        if (pParent->Left == NULL)
            pParent->Left = new TreeNode(value, NULL, NULL, pParent);
        else
            insert(pParent->Left, value);
    }
    else if (value > pParent->Value)
    {
        if (pParent->Right == NULL)
            pParent->Right = new TreeNode(value, NULL, NULL, pParent);
        else
            insert(pParent->Right, value);
    }
}

TreeNode *search(TreeNode *root, int value)
{
    if (root == NULL)
        return NULL;
    TreeNode *pRoot = root;
    while (pRoot != NULL)
    {
        if (value == pRoot->Value)
            return pRoot;
        else if (value < pRoot->Value)
            pRoot = pRoot->Left;
        else if (value > pRoot->Value)
            pRoot = pRoot->Right;
    }
    return NULL;
}

void deleteTree(TreeNode **root)
{
    TreeNode *pRoot = *root;
    if (*root == NULL)
        return;
    deleteTree(&(pRoot->Left));
    deleteTree(&(pRoot->Right));
    delete pRoot;
    *root = NULL;
}

void printTree(TreeNode *root)
{
    if (root == NULL)
        return;
    printTree(root->Left);
    cout << root->Value << " ";
    printTree(root->Right);
}

TreeNode *randomTree(uniform_int_distribution<int> &d, int size = 10)
{
    random_device rd;
    mt19937 generator(rd());
    TreeNode *root = new TreeNode(d(generator));
    for (int i = 2; i <= size; i++)
        insert(root, d(generator));

    return root;
}

TreeNode *create_mirror_flip(TreeNode *pRoot)
{
    if (pRoot == NULL)
        return NULL;

    TreeNode *pNewRoot = new TreeNode(pRoot->Value);
    pNewRoot->Right = create_mirror_flip(pRoot->Left);
    pNewRoot->Left = create_mirror_flip(pRoot->Right);

    return pNewRoot;
}

void tree_sum(TreeNode *pRoot)
{
    if (pRoot == NULL)
        return;

    if (pRoot->Left == NULL && pRoot->Right == NULL)
        return;

    tree_sum(pRoot->Left);
    tree_sum(pRoot->Right);

    if (pRoot->Left != NULL || pRoot->Right != NULL)
    {
        pRoot->Value = 0;
        if (pRoot->Left != nullptr)
            pRoot->Value += pRoot->Left->Value;
        if (pRoot->Right != nullptr)
            pRoot->Value += pRoot->Right->Value;
    }

    return;
}

int main()
{
    uniform_int_distribution<int> dist(1, 100);

    TreeNode *root1 = randomTree(dist, 15);
    cout << "Task 1\n";
    cout << "Before flip: ";
    printTree(root1);
    cout << "\nAfter flip: ";
    TreeNode *flipped = create_mirror_flip(root1);
    printTree(flipped);
    // cout << "\nBefore flip: ";
    // printTree(root1);

    cout << "\nTask 2\n";
    cout << "Sum: ";
    tree_sum(root1);
    printTree(root1);

    deleteTree(&root1);
    deleteTree(&flipped);
    return 0;
}