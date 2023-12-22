#include <iostream>
#include <functional>
using namespace std;

template <typename T>
class tree {
private:
    class BSTNode {
    public:
        T value;
        struct BSTNode* parent;
        struct BSTNode* left;
        struct BSTNode* right;
        BSTNode(T value, BSTNode* parent, BSTNode* left, BSTNode* right)
                : value(value), parent(parent), left(left), right(right) {}
        BSTNode() : left(nullptr), right(nullptr), parent(nullptr) {}
        explicit BSTNode(T value)
                : value(value), left(nullptr), right(nullptr), parent(nullptr) {}
    };
    void print(BSTNode *node, std::ostream& out) const {
        BSTNode *current = node;
        if (current == nullptr) {
            return;
        }
        print(current->left, out);
        out << current->value << ' ';
        print(current->right, out);
    }
    void putNode(BSTNode* bstNode, T _val) {
        if (bstNode == nullptr) return;
        if (bstNode->value == _val) return;
        if (_val < bstNode->value) {
            if (bstNode->left == nullptr)
                bstNode->left = new BSTNode(_val, bstNode, nullptr, nullptr);
            else putNode(bstNode->left, _val);
        } else {
            if (bstNode->right == nullptr)
                bstNode->right = new BSTNode(_val, bstNode, nullptr, nullptr);
            else putNode(bstNode->right, _val);
        }
    }
    void removeTree(BSTNode* bstNode) {
        if (bstNode == nullptr) return;
        removeTree(bstNode->left);
        removeTree(bstNode->right);
        delete bstNode;
    }
    BSTNode* findNode(T _val) {
        BSTNode* pBstNode = head;
        while (pBstNode != nullptr) {
            if (pBstNode->value == _val) return pBstNode;
            if (_val < pBstNode->value) pBstNode = pBstNode->left;
            else pBstNode = pBstNode->right;
        }
        return nullptr;
    }
    void appendNode(BSTNode* bstNode, BSTNode* localHead) {
        if (bstNode == nullptr) return;
        if (localHead == nullptr) {
            head = bstNode;
            sizeValue++;
            return;
        }
        if (bstNode->value < localHead->value) {
            if (localHead->left == nullptr) {
                localHead->left = bstNode;
                bstNode->parent = localHead;
                sizeValue++;
            } else appendNode(bstNode, localHead->left);
        } else if (bstNode->value > localHead->value) {
            if (localHead->right == nullptr) {
                localHead->right = bstNode;
                bstNode->parent = localHead;
                sizeValue++;
            } else appendNode(bstNode, localHead->right);
        }
    }
    void removeNode(BSTNode* bstNode) {
        if (bstNode->parent == nullptr) {
            head = nullptr;
            BSTNode* left = bstNode->left, *right = bstNode->right;
            delete bstNode;
            if (left != nullptr) {
                head = left;
                left->parent = nullptr;
                appendNode(right, head);
            } else if (right != nullptr) {
                head = right;
                right->parent = nullptr;
            }
            sizeValue--;
            return;
        }
        if (bstNode->parent->left == bstNode) bstNode->parent->left = nullptr;
        else bstNode->parent->right = nullptr;
        BSTNode* left = bstNode->left, *right = bstNode->right;
        delete bstNode;
        sizeValue--;
        appendNode(left, head);
        appendNode(right, head);
    }

    BSTNode* head;
    int sizeValue;

public:
    tree() {
        head = nullptr;
        sizeValue = 0;
    }
    ~tree() {
        removeTree(head);
    }

    int size() {
        return sizeValue;
    }
    void put(T value) {
        appendNode(new BSTNode(value), head);
    }
    bool has(T value) {
        return findNode(value) != nullptr;
    }
    void remove(T value) {
        BSTNode* node = findNode(value);
        if (node == nullptr) return;
        removeNode(node);
    }


    friend ostream& operator<<(ostream& os, tree<T>& bst) {
        bst.print(bst.head, os);
        return os;
    }
};

int main() {
    tree<int> tree;
    int n;
    string str_input;
    cin >> n;
    int int_input;
    for (int i = 0; i < n; i++) {
        cin >> str_input;
        if (str_input == "insert") {
            cin >> int_input;
            tree.put(int_input);
        }  else if (str_input == "size") {
            cout << tree.size() << endl;
        }  else if (str_input == "print") {
            cout << tree << endl;
        } else if (str_input == "contains") {
            cin >> int_input;
            cout << (tree.has(int_input) ? "Yes" : "No") << endl;
        }
    }
    return 0;
}
