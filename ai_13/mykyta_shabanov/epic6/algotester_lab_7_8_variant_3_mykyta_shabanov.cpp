#include <iostream>
using namespace std;

// Binary tree (search)

    //custom type
template<class T>
class BTS 
{
    class Node 
    {
    public:
        T data;
        Node *left;
        Node *right;
        Node *parent;

        Node(T value, Node *left_ptr, Node *right_ptr, Node *parent_ptr) 
        {
            data = value;
            left = left_ptr;
            right = right_ptr;
            parent = parent_ptr;
        }

        explicit Node(T value) : Node(value, nullptr, nullptr, nullptr) {}
    };

    int size;
    Node *root;

    void insert_element(Node *head, Node *new_node) 
    {
        if (new_node == nullptr) return;
        if (head == nullptr) 
        {
            root = new_node;
            size++;
            return;
        }
        Node *current = head;

        if (current->data > new_node->data) 
        {
            if (current->left == nullptr) 
            {
                current->left = new_node;
                new_node->parent = current;
                new_node->left = nullptr;
                new_node->right = nullptr;

                size++;
                return;
            }

            insert_element(current->left, new_node);
        } else if (current->data < new_node->data) 
        {
            if (current->right == nullptr) 
            {
                current->right = (new_node);
                new_node->parent = current;
                new_node->left = nullptr;
                new_node->right = nullptr;

                size++;
                return;
            }
            insert_element(current->right, new_node);

        }
    }
    void delete_BTS(Node* head) 
    {
        if (head == nullptr) return;

        delete_BTS(head->left);
        delete_BTS(head->right);
        delete head;
    }

    void contain(Node *node, T value) 
    {
        Node *current = node;
        if (current == nullptr) 
        {
            cout << "No";
            return;
        } else 
        {
            if (current->data == value) 
            {
                cout << "Yes";
                return;
            } else 
            {
                if (current->data > value)
                    contain(current->left, value);
                else 
                    contain(current->right, value);
            }
        }
    }

    void remove(Node *node) 
    {
        if (node->parent == nullptr) 
        {
            root = nullptr;
            Node *left = node->left;
            Node *right = node->right;
            
            size--;
            delete node;
            if (left != nullptr) 
            {
                left->parent = nullptr;
                root = left;
                insert_element(root, right);
            } else if (right != nullptr) 
            {
                right->parent = nullptr;
                root = right;
            }

        }

        if (node->parent->left == node) 
            node->parent->left = nullptr;
        else
            node->parent->right = nullptr;
            
        Node *left = node->left;
        Node *right = node->right;
        size--;

        delete node;
        insert_element(root, left);
        insert_element(root, right);

    }

    void print(Node *node, std::ostream& out) const 
    {
        Node *current = node;
        if (current == nullptr) return;

        print(current->left, out);
        out << current->data << ' ';
        print(current->right, out);
    }

public:
    BTS() 
    {
        root = nullptr;
        size = 0;
    }

    ~BTS() 
    {
        delete_BTS(root);
    }

    void insertion(T value) 
    {
        insert_element(root, new Node(value));
    }

    void check(T value) 
    {
        contain(root, value);
    }

    int count_size() 
    {
        return size;
    }

    void print_bts(std::ostream& out) const 
    {
        print(root, out);
    }

};

template<class T>

std::ostream& operator<<(std::ostream &out, const BTS<T>& tree)
{
    tree.print_bts(out);
    return out;
}

int main() 
{
    BTS<int> tree;
    int queries;
    string query;
    cin >> queries;

    for (int i = 0; i < queries; ++i) 
    {
        cin >> query;

        if (query == "insert") 
        {
            int element;
            cin >> element;
            tree.insertion(element);
        } else if (query == "size")
            cout << tree.count_size() << endl;
        else if (query == "print") 
            cout << tree << endl;
        else if (query == "contains") 
        {
            int element;
            cin >> element;
            tree.check(element);
            cout << endl;
        }
    }

    return 0;
}