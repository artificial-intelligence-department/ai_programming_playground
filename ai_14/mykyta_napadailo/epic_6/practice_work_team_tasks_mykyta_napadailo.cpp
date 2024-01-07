#include <iostream>
using namespace std;

struct Node 
{
    int key;
    Node* next;
};

struct TreeNode {
    int key;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : key(x), left(nullptr), right(nullptr) {}
};

Node* createList(int value)
{
    Node* ptr = new Node;
    ptr -> key = value;
    ptr -> next = nullptr;
    return ptr;
}

void addNode(Node* list, int value)
{
    Node* tmp = list;
    while (tmp -> next != nullptr)
    {
        tmp = tmp -> next;
    }
    Node* new_Node = new Node;
    new_Node -> key = value;
    new_Node -> next = nullptr;
    tmp -> next = new_Node;
}

void printList(Node* head, string whtspc)
{
    Node* current = head;
    while (current != nullptr)
    {
        cout << current -> key << whtspc;
        current = current -> next;
    }
    cout << endl;
}

Node* reverse(Node* list1)
{
    Node *current = list1;
    Node *next = nullptr;
    Node *prev = nullptr;
    while (current != nullptr)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

bool compare(Node *list1, Node *list2)
{
    Node *cur1 = list1, *cur2 = list2;
    while (cur1 != nullptr && cur2 != nullptr)
    {
        if (cur1 -> key != cur2 -> key) return false;
        cur1 = cur1 -> next;
        cur2 = cur2 -> next;
    }
    return (cur1 == nullptr && cur2 == nullptr);
}

void deleteList(Node *head)
{
    while (head != nullptr)
    {
        Node *tmp = head;
        head = head -> next;
        delete tmp;
    }
}

Node *add(Node *list1, Node *list2) 
{
    Node *h1 = list1, *h2 = list2;
    Node *SUM = nullptr;
    Node *tail = nullptr;
    int carry = 0;

    while (h1 != nullptr || h2 != nullptr || carry) 
    {
        int sum = carry;
        if (h1 != nullptr) 
        {
            sum += h1->key;
            h1 = h1->next;
        }
        if (h2 != nullptr) 
        {
            sum += h2->key;
            h2 = h2->next;
        }
        carry = sum / 10;
        sum = sum % 10;

        Node *newNode = new Node;
        newNode->key = sum;
        newNode->next = nullptr;

        if (SUM == nullptr) 
        {
            SUM = tail = newNode;
        } else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return SUM;
}

TreeNode* create_mirror_flip(TreeNode *root) 
{
    if (root == nullptr) 
    {
        return nullptr;
    }
    TreeNode *newNode = new TreeNode(root -> key);
    newNode -> left = create_mirror_flip(root -> right);
    newNode -> right = create_mirror_flip(root -> left);

    return newNode;
}

void inorderTraversal(TreeNode *root) 
{
    if (root == nullptr) 
    {
        return;
    }
    inorderTraversal(root -> left);
    cout << root -> key << " ";
    inorderTraversal(root->right);
}

void treeSum(TreeNode *root)
{
    if (root == nullptr || root -> left == nullptr && root -> right == nullptr) return;
    treeSum(root -> left);
    treeSum(root -> right);

    int value_left = (root -> left != nullptr) ? root -> left -> key : 0;
    int value_right = (root -> right != nullptr) ? root -> right -> key : 0;
    root -> key = value_left + value_right;
}

int main()
{
    // Task 1
    cout << "==================================\n";
    cout << "\t TASK 1\n";

    Node* head = createList(1);
    for (int i = 2; i <= 8; i++)
    {
        addNode(head, i);
    }
    printList(head, " ");
    head = reverse(head);
    printList(head, " ");

    deleteList(head);
    cout << "==================================\n";

    // Task 2
    cout << "\t TASK 2\n";

    Node *head1 = createList(1);
    Node *head2 = createList(1);
    for (int i = 2; i <= 8; i++)
    {
        addNode(head1, i);
        addNode(head2, i);
    }
    addNode(head2, 9);

    printList(head1, " ");
    printList(head2, " ");

    if (compare(head1, head2)) 
    {
        cout << "These lists are equal\n";
    } 
    else cout << "These lists are not equal\n";
    
    deleteList(head1);
    deleteList(head2);
    cout << "==================================\n";

    // Task 3
    cout << "\t TASK 3\n";

    Node *num1 = createList(3);
    addNode(num1, 7);
    addNode(num1, 9);
    cout << "The first number: ";
    printList(num1, "");

    Node *num2 = createList(9);
    addNode(num2, 7);
    addNode(num2, 3);
    cout << "The second number: ";
    printList(num2, "");

    Node *sum = reverse(add(num1, num2));
    cout << "The sum of two numbers: ";
    printList(sum, "");

    deleteList(num1);
    deleteList(num2);
    deleteList(sum);
    cout << "==================================\n";

    // Task 4
    cout << "\t TASK 4\n";
    
    TreeNode *root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);
    root -> right -> left = new TreeNode(6);
    root -> right -> right = new TreeNode(7);

    cout << "Original tree: ";
    inorderTraversal(root);
    cout << endl;

    TreeNode *mirrorFlipped = create_mirror_flip(root);
    cout << "Mirror-flipped tree: ";
    inorderTraversal(mirrorFlipped);
    cout << endl;
    cout << "==================================\n";

    // Task 5
    cout << "\t TASK 5\n";

    cout << "Original tree: ";
    inorderTraversal(root);
    cout << endl;

    treeSum(root);
    cout << "A tree of sums: ";
    inorderTraversal(root);

    cout << "\n==================================\n";

}