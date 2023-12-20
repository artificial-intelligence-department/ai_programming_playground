#include <iostream>
#include <queue>
using namespace std;

struct TreeN {
    int value;
    TreeN* left;
    TreeN* right;

    TreeN(int val) : value(val), left(nullptr), right(nullptr) {}
};

void calculateSubtreeSum(TreeN* node) {
    if (node == nullptr) {
        return;
    }

    queue<TreeN*> nodeQueue;
    nodeQueue.push(node);

    while (!nodeQueue.empty()) {
        TreeN* currentNode = nodeQueue.front();
        nodeQueue.pop();

        int leftSubtreeSum = 0;
        int rightSubtreeSum = 0;

        // Обчислення суми піддерева для лівого вузла
        if (currentNode->left != nullptr) {
            leftSubtreeSum = currentNode->left->value;
        }

        // Обчислення суми піддерева для правого вузла
        if (currentNode->right != nullptr) {
            rightSubtreeSum = currentNode->right->value;
        }

        // Обновлення значення поточного вузла
        currentNode->value += leftSubtreeSum + rightSubtreeSum;

        // Додавання лівого та правого нащадка до черги для обробки їх сум
        if (currentNode->left != nullptr) {
            nodeQueue.push(currentNode->left);
        }
        if (currentNode->right != nullptr) {
            nodeQueue.push(currentNode->right);
        }
    }
}

void printTree(TreeN* node) {
    if (node != nullptr) {
        cout << node->value << " ";
        printTree(node->left);
        printTree(node->right);
    }
}

int main() {
    TreeN* root = new TreeN(9);
    root->left = new TreeN(4);
    root->right = new TreeN(14);
    root->left->left = new TreeN(2);
    root->left->right = new TreeN(6);
    root->right->left = new TreeN(11);
    root->right->right = new TreeN(17);

    cout << "Дерeво пeрeд обчислeнням сум: ";
    printTree(root);
    cout << endl;

    calculateSubtreeSum(root);

    cout << "Дeрeво пiсля обчислeння сyм: ";
    printTree(root);
    cout << endl;

    // Очищення пам'яті (за необхідності)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
