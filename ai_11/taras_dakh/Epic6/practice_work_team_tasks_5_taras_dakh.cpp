#include <iostream>
#include <stack>

struct Node {
    int value;
    Node *leftNode, *rightNode;
    Node(int x) : value(x), leftNode(nullptr), rightNode(nullptr) {}
};

void calculateAndUpdateSum(Node *currentNode) {
    if (!currentNode) {
        return;
    }

    std::stack<Node *> nodeStack;
    nodeStack.push(currentNode);

    while (!nodeStack.empty()) {
        Node *node = nodeStack.top();
        nodeStack.pop();

        if (node->leftNode) {
            nodeStack.push(node->leftNode);
        }

        if (node->rightNode) {
            nodeStack.push(node->rightNode);
        }

        if (node->leftNode || node->rightNode) {
            int leftValue = (node->leftNode) ? node->leftNode->value : 0;
            int rightValue = (node->rightNode) ? node->rightNode->value : 0;
            node->value += leftValue + rightValue;
        }
    }
}

void displayNodeValues(Node *currentNode) {
    if (!currentNode) {
        return;
    }

    displayNodeValues(currentNode->leftNode);
    std::cout << currentNode->value << " ";
    displayNodeValues(currentNode->rightNode);
}

int main() {
    // Приклад використання
    Node *rootNode = new Node(1);
    rootNode->leftNode = new Node(2);
    rootNode->rightNode = new Node(3);
    rootNode->leftNode->leftNode = new Node(4);
    rootNode->leftNode->rightNode = new Node(5);
    rootNode->rightNode->leftNode = new Node(6);
    rootNode->rightNode->rightNode = new Node(7);

    std::cout << "Структура перед обчисленням сум:" << std::endl;
    displayNodeValues(rootNode);

    calculateAndUpdateSum(rootNode);

    std::cout << "\nСтруктура після обчислення сум:" << std::endl;
    displayNodeValues(rootNode);

    return 0;
}
