#include <iostream>
using namespace std;

// Структура вузла дерева
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}  //Конструктор ініціалізує значення вузла та встановлює початкові значення вказівників на nullptr.
}; //TreeNode - це ім'я конструктора, що визначає спосіб створення нового об'єкту типу TreeNode. 
//(int val) - це список параметрів конструктора, в якому передається ціле значення val. Це значення буде 
//використане для ініціалізації поля data нового об'єкту TreeNode.
//data(val) - це ініціалізатор поля data об'єкту TreeNode з переданого параметром значення val. У вашому 
//випадку, при створенні нового об'єкту TreeNode, поле data буде ініціалізоване переданим значенням val.
//left(nullptr) та right(nullptr) - це ініціалізатори для полів left та right об'єкту TreeNode.
//початково дочірні вузли будуть відсутніми (nullptr), тобто цей новий вузол буде листком дерева 
//Символи {} позначають тіло конструктора.

// Функція для створення віддзеркаленого дерева
TreeNode* create_mirror_tree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode* mirrored = new TreeNode(root->data);
    mirrored->left = create_mirror_tree(root->right);
    mirrored->right = create_mirror_tree(root->left);

    return mirrored;
}

// Допоміжна функція для виведення дерева
void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    //дерево
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    // Виведення початкового дерева
    cout << "Original tree: ";
    printTree(root);
    cout << endl;

    // Створення віддзеркаленого дерева
    TreeNode* mirroredTree = create_mirror_tree(root);

    // Виведення віддзеркаленого дерева (pre-order)
    cout << "Mirrored tree: ";
    printTree(mirroredTree);
    cout << endl;

    return 0;
}
