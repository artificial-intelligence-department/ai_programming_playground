#include <iostream>
using namespace std;

template <class Type>
class binary_tree
{
private:
    struct _node
    {
    public:
        Type val;
        struct _node *_upper;
        struct _node *_left;
        struct _node *_right;

        _node(Type val, _node *upper, _node *left, _node *right)
            : val(val), _upper(upper), _left(left), _right(right) {}

        _node() : _left(NULL), _right(NULL), _upper(NULL) {}

        _node(Type val)
            : _node(val, NULL, NULL, NULL) {}
    };

    // Helper for finalizer
    void finalize(_node *_root)
    {
        if (_root == NULL)
            return;

        finalize(_root->_left);
        finalize(_root->_right);
        delete _root;
    }

    _node *find(Type val)
    {
        _node *current = treeRoot;
        while (current != NULL)
        {
            if (current->val == val)
                return current;
            if (val < current->val)
                current = current->_left;
            else
                current = current->_right;
        }
        return NULL;
    }

    void putNode(_node *node, _node *_root)
    {
        if (node == NULL)
            return;

        if (_root == NULL)
        {
            treeRoot = node;
            treeSize++;
            return;
        }

        if (node->val < _root->val)
        {
            if (_root->_left == NULL)
            {
                _root->_left = node;
                node->_upper = _root;
                treeSize++;
            }
            else
                putNode(node, _root->_left);
        }
        else if (node->val > _root->val)
        {
            if (_root->_right == NULL)
            {
                _root->_right = node;
                node->_upper = _root;
                treeSize++;
            }
            else
                putNode(node, _root->_right);
        }
    }

    void destroyNode(_node *node)
    {
        if (node->_upper == NULL)
        {
            treeRoot = NULL;

            _node *left = node->_left, *right = node->_right;
            delete node;

            if (left != NULL)
            {
                treeRoot = left;
                left->_upper = NULL;
                putNode(right, treeRoot);
            }
            else if (right != NULL)
            {
                treeRoot = right;
                right->_upper = NULL;
            }

            treeSize--;
            return;
        }

        if (node->_upper->_left == node)
            node->_upper->_left = NULL;
        else
            node->_upper->_right = NULL;

        _node *left = node->_left, *right = node->_right;

        delete node;
        treeSize--;

        putNode(left, treeRoot);
        putNode(right, treeRoot);
    }

    void printToStream(ostream &os, _node *currentParent)
    {
        if (!currentParent)
            return;

        printToStream(os, currentParent->_left);
        os << currentParent->val << ' ';
        printToStream(os, currentParent->_right);
    }

    _node *treeRoot;
    int treeSize;

public:
    binary_tree()
    {
        treeRoot = NULL;
        treeSize = 0;
    }

    ~binary_tree()
    {
        finalize(treeRoot);
    }

    int get_size()
    {
        return treeSize;
    }

    void put(Type val)
    {
        putNode(new _node(val), treeRoot);
    }

    bool has(Type val)
    {
        return find(val) != NULL;
    }

    void destroy(Type val)
    {
        _node *node = find(val);
        if (node == NULL)
            return;
        destroyNode(node);
    }

    friend ostream &operator<<(ostream &os, binary_tree<Type> &t)
    {
        t.printToStream(os, t.treeRoot);
        return os;
    }
};

int main()
{
    binary_tree<int> _tree;

    int Q;
    string line;
    cin >> Q;

    for (int i = 0; i < Q; ++i)
    {
        cin >> line;

        if (line == "insert")
        {
            int element;
            cin >> element;
            _tree.put(element);
        }
        else if (line == "size")
        {
            cout << _tree.get_size() << endl;
        }
        else if (line == "print")
        {
            cout << _tree << "\n";
        }
        else if (line == "contains")
        {
            int element;
            cin >> element;
            cout << (_tree.has(element) ? "Yes" : "No") << endl;
        }
    }

    return 0;
}