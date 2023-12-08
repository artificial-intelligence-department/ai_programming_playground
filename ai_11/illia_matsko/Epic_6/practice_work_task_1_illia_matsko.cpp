#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr), parent(nullptr) {}
};

TreeNode* mirror(const TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    // Створення нового вузла зі значенням поточного вузла
    TreeNode* newRoot = new TreeNode(root->data);

    // Рекурсивне створення правої вітки нового дерева з лівої вітки поточного дерева
    newRoot->right = mirror(root->left);

    // Рекурсивне створення лівої вітки нового дерева з правої вітки поточного дерева
    newRoot->left = mirror(root->right);

    return newRoot;
}

void tree_sum(TreeNode* Node) {
if (Node == nullptr) {
        return;
    }

    // Рекурсивний виклик функції для лівої вітки
    tree_sum(Node->left);

    // Рекурсивний виклик функції для правої вітки
    tree_sum(Node->right);

    // Зміна значення поточного вузла на суму значень підвузлів
    int newData = 0;
    if (Node->left != nullptr) {
        newData += Node->left->data;
    }
    if (Node->right != nullptr) {
        newData += Node->right->data;
    }
    if(Node->left != nullptr || Node->right != nullptr)
    {
        Node->data = newData;
    }
}

void insert(TreeNode* root, int value) {
    TreeNode* current = root;
    TreeNode* parent = nullptr;

    // Шукаємо вільне місце для вставки
    while (current != nullptr) {
        parent = current;
        if (value < current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    // Створюємо новий вузол
    TreeNode* newNode = new TreeNode(value);
    newNode->parent = parent;

    // Вставляємо новий вузол
    if (value < parent->data) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }
}

// Рекурсивна функція для виводу дерева в порядку "in-order"
void print(TreeNode* Node) {
    if (Node != nullptr) {
        print(Node->left);
        cout << Node->data << " ";
        print(Node->right);
    }
}

int main() {
    // Створення бінарного дерева та вставка елементів
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;
    cout << "Enter the elements: ";
    int value;
    cin >> value;
    TreeNode* root = new TreeNode(value);
    for (int i = 1; i < n; i++) {
        cin >> value;
        insert(root, value);
    }


    cout << "Original tree: ";
    print(root);
    cout << endl;

    // Створення дзерева, де права і ліва вітки міняються місцями
    cout << "Mirrored tree: ";
    print(mirror(root));
    cout << endl;

    // Зміна значень вузлів дерева на суму значень підвузлів
    cout << "Updated tree: ";
    tree_sum(root);
    print(root);

    return 0;
}