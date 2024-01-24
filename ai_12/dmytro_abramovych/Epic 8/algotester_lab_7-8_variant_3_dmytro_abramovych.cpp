#include <iostream>
#include <functional>
using namespace std;

// Algotester Lab 7-8 Variant 3

template <typename T>
class BinaryTree
{
private:
    struct TreeNode
    {
    public:
        T value;
        TreeNode *parent;
        TreeNode *left;
        TreeNode *right;
        TreeNode(T value, TreeNode *parent, TreeNode *left, TreeNode *right)
            : value(value), parent(parent), left(left), right(right) {}
        TreeNode(T value)
            : TreeNode(value, NULL, NULL, NULL) {}
    };
    void put_node(TreeNode *inserted_node, TreeNode **head)
    {
        if (inserted_node == NULL)
            return;
        if (*head == NULL)
        {
            *head = inserted_node;
            tree_size++;
            return;
        }
        if (inserted_node->value < (*head)->value)
        {
            if ((*head)->left == NULL)
            {
                (*head)->left = inserted_node;
                inserted_node->parent = (*head);
                tree_size++;
            }
            else
                put_node(inserted_node, &(*head)->left);
        }
        else if (inserted_node->value > (*head)->value)
        {
            if ((*head)->right == NULL)
            {
                (*head)->right = inserted_node;
                inserted_node->parent = (*head);
                tree_size++;
            }
            else
                put_node(inserted_node, &(*head)->right);
        }
    }
    void destruct_tree(TreeNode *node)
    {
        if (node == NULL)
            return;
        destruct_tree(node->left);
        destruct_tree(node->right);
        delete node;
    }
    TreeNode *lookup_for_node(T _val)
    {
        TreeNode *pNode = tree_head;
        while (pNode != NULL)
        {
            if (pNode->value == _val)
                return pNode;
            if (_val < pNode->value)
                pNode = pNode->left;
            else
                pNode = pNode->right;
        }
        return NULL;
    }
    void for_each(TreeNode *head, function<void(T)> delegate)
    {
        if (head == NULL)
            return;
        for_each(head->left, delegate);
        delegate(head->value);
        for_each(head->right, delegate);
    }
    TreeNode *tree_head;
    int tree_size;

public:
    BinaryTree()
    {
        tree_head = NULL;
        tree_size = 0;
    }
    ~BinaryTree()
    {
        destruct_tree(tree_head);
    }

    int size()
    {
        return tree_size;
    }
    bool contains_value(T value)
    {
        return lookup_for_node(value) != NULL;
    }
    void append(T value)
    {
        put_node(new TreeNode(value), &tree_head);
    }
    void for_each(function<void(T)> func)
    {
        for_each(tree_head, func);
    }
    void print_to_stream(ostream &os)
    {
        for_each([&os](T value)
                 { os << value << " "; });
    }
    void print()
    {
        print_to_stream(cout);
    }
    friend ostream &operator<<(ostream &os, BinaryTree<T> &_tree)
    {
        _tree.print_to_stream(os);
        return os;
    }
};

int main()
{
    BinaryTree<int> tree;
    int intbuf, n;
    string strbuf;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> strbuf;
        if (strbuf == "insert")
        {
            cin >> intbuf;
            tree.append(intbuf);
        }
        else if (strbuf == "contains")
        {
            cin >> intbuf;
            cout << (tree.contains_value(intbuf) ? "Yes" : "No") << endl;
        }
        else if (strbuf == "size")
        {
            cout << tree.size() << endl;
        }
        else if (strbuf == "print")
        {
            cout << tree << endl;
        }
    }
    return 0;
}
