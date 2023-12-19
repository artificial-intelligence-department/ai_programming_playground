#include <iostream>
#include<ctime>
using namespace std;

// Binary tree (search)

template<class T>//custom type
class BTS {
    class Node {
    public:
        T data;
        Node *left;
        Node *right;
        Node *parent;

        Node(T value, Node *left_ptr, Node *right_ptr, Node *parent_ptr) {
            data = value;
            left = left_ptr;
            right = right_ptr;
            parent = parent_ptr;
        }

        // explicit prohibits this kind of shit:
        // Node* ptr = 15;

        // Now only this is legal
        // Node* ptr = new Node(15);
        // Node* ptr(15);

        // we can reuse constructors of this class and base classes
        explicit Node(T value) : Node(value, nullptr, nullptr, nullptr) {}
        explicit Node(T value, Node* parent) : Node(value, nullptr, nullptr, parent) {}
    };

    int size;
    Node *root;

    void insert_element(Node *head, Node *new_node) {
        if (new_node == nullptr) return;
        if (head == nullptr) {
            root = new_node;
            size++;
            return;
        }
        Node *current = head;

        if (current->data > new_node->data) {
            if (current->left == nullptr) {
                current->left = new_node;
                new_node->parent = current;
                new_node->left = nullptr;
                new_node->right = nullptr;
                size++;
                return;
            }
            insert_element(current->left, new_node);
        } else if (current->data < new_node->data) {
            if (current->right == nullptr) {
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
    void delete_BTS(Node* head) {
        if (head == nullptr) return;

        delete_BTS(head->left);
        delete_BTS(head->right);
        delete head;
    }

    void contain(Node *node, T value) {
        Node *current = node;
        if (current == nullptr) {
            cout << "No";
            return;
        } else {
            if (current->data == value) {
                cout << "Yes";
                return;
            } else {
                if (current->data > value) {
                    contain(current->left, value);
                } else {
                    contain(current->right, value);
                }

            }
        }
    }

    void remove(Node *node) {
        if (node->parent == nullptr) {
            root = nullptr;
            Node *left = node->left;
            Node *right = node->right;
            size--;
            delete node;
            if (left != nullptr) {
                left->parent = nullptr;
                root = left;
                insert_element(root, right);
            } else if (right != nullptr) {
                right->parent = nullptr;
                root = right;
            }

        }
        if (node->parent->left == node) {
            node->parent->left = nullptr;
        } else {
            node->parent->right = nullptr;
        }
        Node *left = node->left;
        Node *right = node->right;
        size--;
        delete node;
        insert_element(root, left);
        insert_element(root, right);

    }

    void print(Node *node, std::ostream& out) const {
        Node *current = node;
        if (current == nullptr) {
            return;
        }
        print(current->left, out);
        out << current->data << ' ';
        print(current->right, out);
    }
    Node* mirror_tree(Node* current)
    {
        if (current == nullptr)
        {
            return current;
        }

        Node* left = mirror_tree((current->left));
        Node* right = mirror_tree((current->right));
        current->left = right;
        current->right = left;

        return current;
    }
    Node* sum_parent(Node* current)
    {
        if (current == nullptr)
        {
            return current;
        }

        Node* left = sum_parent((current->left));
        Node* right = sum_parent((current->right));
        if(left != nullptr && right!= nullptr)
        {
            current->data = left->data + right->data;
        }
        else if(left == nullptr && right != nullptr)
        {
            current->data = right->data;
        }
        else if(right == nullptr && left != nullptr)
        {
            current->data = left->data;
        }





        return current;
    }
public:
    BTS() {
        root = nullptr;
        size = 0;
    }

    ~BTS() {
        delete_BTS(root);
    }
    void sum()
    {
        sum_parent(root);
    }
    void mirror()
    {
        mirror_tree(root);
    }
    void insertion(T value) {
        insert_element(root, new Node(value));
    }

    void check(T value) {
        contain(root, value);
    }

    int count_size() {
        return size;
    }

    void print_bts(std::ostream& out) const {
        print(root, out);
    }

};
template<class T>
// output stream
// cout << tree << endl;
// operator<<(operator<<(cout, tree), endl);
std::ostream& operator<<(std::ostream &out, const BTS<T>& tree)
{
    tree.print_bts(out);
    return out;
}

int main() {
    BTS<int> tree;
    srand(time(0));
    for (int i = 0 ; i < 10; i++)
    {
        tree.insertion(rand() % 100);
    }
    cout<<"Generated tree: ";
    cout<<tree<<endl;
    cout<<"Mirrored tree: ";
    tree.mirror();
    cout<<tree<<endl;
    cout<<"Summed: ";
    tree.sum();
    cout<<tree<<endl;
    return 0;
}
