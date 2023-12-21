#include <iostream>
#include <queue>
using namespace std;

struct BinaryNode {
    int value;
    BinaryNode* leftChild;
    BinaryNode* rightChild;

    BinaryNode(int val) {
        value = val;
        leftChild = nullptr;
        rightChild = nullptr;
    }
};


BinaryNode* createMirror(BinaryNode* node) {
    if (node == nullptr) {
        return nullptr;
    }
    BinaryNode* leftMirror = createMirror(node->leftChild);
    BinaryNode* rightMirror = createMirror(node->rightChild);

    BinaryNode* mirrorNode = new BinaryNode(node->value);
    mirrorNode->leftChild = rightMirror;
    mirrorNode->rightChild = leftMirror;

    return mirrorNode;
}


void displayTree(BinaryNode* node) {
    if (node != nullptr) {
        displayTree(node->leftChild);
        cout << node->value << " ";
        displayTree(node->rightChild);
    }
}


void calculateSum(BinaryNode* node) {
    if (!node) {
        return;
    }

    queue<BinaryNode*> nodeQueue;
    nodeQueue.push(node);

    while (!nodeQueue.empty()) {
        BinaryNode* currentNode = nodeQueue.front();
        nodeQueue.pop();

        int childrenSum = 0;
        if (currentNode->leftChild) {
            childrenSum += currentNode->leftChild->value;
            nodeQueue.push(currentNode->leftChild);
        }
        if (currentNode->rightChild) {
            childrenSum += currentNode->rightChild->value;
            nodeQueue.push(currentNode->rightChild);
        }

        if (currentNode->leftChild || currentNode->rightChild) {
            currentNode->value = childrenSum;
        }
    }
}


void deleteBinaryTree(BinaryNode* node) {
    if (node != nullptr) {
        deleteBinaryTree(node->leftChild);
        deleteBinaryTree(node->rightChild);
        delete node;
    }
}

int main() {
    BinaryNode* rootNode = new BinaryNode(2);
    rootNode->leftChild = new BinaryNode(5);
    rootNode->rightChild = new BinaryNode(1);
    rootNode->rightChild->leftChild = new BinaryNode(8);
    rootNode->rightChild->rightChild = new BinaryNode(9);

    cout << "Original tree: ";
    displayTree(rootNode);
    cout << endl;

    BinaryNode* mirrorRoot = createMirror(rootNode);

    cout << "Mirrored tree: ";
    displayTree(mirrorRoot);
    cout << endl;

    calculateSum(rootNode);
    cout << "Modified tree values:" << endl;
    cout << "   " << rootNode->value << endl;
    cout << "  / \\" << endl;
    cout << " " << rootNode->leftChild->value << "   " << rootNode->rightChild->value << endl;
    cout << "/ \\" << endl;
    cout << rootNode->rightChild->leftChild->value << "   " << rootNode->rightChild->rightChild->value << endl;

    deleteBinaryTree(rootNode);
    deleteBinaryTree(mirrorRoot);

    return 0;
}
