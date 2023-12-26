#include <iostream>
#include <queue>

using namespace std;

// Визначення структури вузла дерева
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Функція для віддзеркалення дерева
TreeNode *create_mirror_flip(TreeNode *root) {
    // Базовий випадок: якщо вузол є нульовим, повертаємо nullptr
    if (root == nullptr) {
        return nullptr;
    }

    // Створюємо новий вузол зі значенням поточного вузла
    TreeNode *newRoot = new TreeNode(root->data);

    // Рекурсивно віддзеркалюємо праву і ліву вітки та присвоюємо їх новому вузлу
    newRoot->left = create_mirror_flip(root->right);
    newRoot->right = create_mirror_flip(root->left);

    return newRoot;
}

// Функція для виводу дерева у порядку обходу у ширину (BFS)
void levelOrderTraversal(TreeNode *root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode *current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left) {
            q.push(current->left);
        }

        if (current->right) {
            q.push(current->right);
        }
    }
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Original tree: ";
    levelOrderTraversal(root);
    cout << endl;

    // Віддзеркалення дерева
    TreeNode *mirroredRoot = create_mirror_flip(root);

    cout << "Mirrored tree: ";
    levelOrderTraversal(mirroredRoot);
    cout << endl;

    return 0;
}
