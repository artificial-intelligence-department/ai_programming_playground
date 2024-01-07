#include <iostream>
using namespace std;
struct tn{
    tn* l;
    tn* r;
    int d;
    tn():d(0),l(nullptr),r(nullptr){}
};
tn* create(int n){
    static int numb = 0;
    tn* x = new tn;
    if(n==1){
        cout << "enter " << numb << ":";
        cin >> x->d;
        numb++;
        return x;
    }
    x->l = create(n-1);
    x->r = create(n-1);
    x->d = x->l->d+x->r->d;
    return x;
}
void print(tn* n){
    if(n->l!=nullptr){
        print(n->l);
        print(n->r);
    }else cout << n->d << ' ';

};
tn* flip(tn* n){
    if(n->l!=nullptr) {
        tn *ans = new tn;
        ans->d = n->d;
        ans->l = flip(n->r);
        ans->r = flip(n->l);
        return ans;
    }else return n;
}
void treesum(tn* n){
    if(n->l==nullptr) return;
    treesum(n->l);
    treesum(n->r);
    n->d = n->l->d + n->r->d;
}
int main(){
    tn* root = create(3);
    print(root);
    cout << '\n' << root->d << '\n';
    tn* root2 = flip(root);
    print(root2);
    cout << '\n' << root2->d << '\n';
}
