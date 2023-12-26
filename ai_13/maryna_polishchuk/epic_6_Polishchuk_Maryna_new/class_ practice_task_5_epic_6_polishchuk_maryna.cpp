#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void print_tree(TreeNode* root) {
    if (root) {
        print_tree(root->left);
        cout << root->data << " ";
        print_tree(root->right);
    }
}

void calculate_tree_sum(TreeNode* root) {
    stack<TreeNode*> nodes; //Створення стеку nodes
    TreeNode* prev = nullptr;//для зберігання попереднього вузла під час обходу.

    //Якщо вхідний вузол root не є nullptr, то додаємо його до стеку.
    if (root)
        nodes.push(root);

    while (!nodes.empty()) {
        TreeNode* current = nodes.top();

    /*Умова перевіряє, чи поточний вузол - перший вузол у своєму піддереві або чи він є лівим або правим нащадком попереднього вузла. 
    Якщо так, то переходимо до наступного вузла у піддереві (лівого, якщо існує, інакше правого).*/
        if (!prev || prev->left == current || prev->right == current) {
            if (current->left)
                nodes.push(current->left);
            else if (current->right)
                nodes.push(current->right);
    //Якщо поточний вузол був лівим нащадком попереднього вузла, перевіряємо наявність правого нащадка поточного вузла.
        } else if (current->left == prev) {
            if (current->right)
                nodes.push(current->right);
                /*Якщо поточний вузол не є першим у своєму піддереві та має обидва нащадки або вже обробив їх, тоді обчислюємо суму його значення 
                та значень лівого та правого нащадків (якщо вони існують) і записуємо цю суму у поле data поточного вузла. Після цього вузол
                видаляється зі стеку, оскільки ми завершили обробку його нащадків.*/
        } else {
            current->data = current->data +
                            (current->left ? current->left->data : 0) +
                            (current->right ? current->right->data : 0);
            nodes.pop();
        }
        //prev оновлюється до поточного вузла для використання у наступній ітерації.
        prev = current;
    }
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    
    cout << "Tree before changes: ";
    print_tree(root);
    cout << endl;

    calculate_tree_sum(root);
    cout << "Tree after adding: ";
    print_tree(root);
    cout << endl;

    return 0;
}
