#include <iostream>
#include <fstream>
using namespace std;
struct dlist{
    char d;
    dlist * next;
    dlist * prev;
};
dlist* make(int n){
    auto cur =new(dlist);
    auto first = cur;
    cur->d = 'a';
    cur->prev = nullptr;
    cur->next = nullptr;
    for(int i=1;i<n;i++){
        auto p = new(dlist);
        p->prev = cur;
        p->next = nullptr;
        p->d ='a'+i;
        cur->next = p;
        cur = p;
    }
    return first;
}
void add(dlist* l, int n, char x){
    dlist* cur=l;
    for(int i=0;i<n;i++){
        cur = cur->next;
    }
    auto p = new(dlist);
    p->prev = cur->prev;
    p->next = cur;
    p->d = x;
    if(cur->prev!=nullptr)(cur->prev)->next = p;
    if(cur->next!=nullptr)(cur->next)->prev = p;
}
void show(dlist* l){
    dlist* s = l;
    cout << s->d << ' ';
    while(true){
        if(s->next==nullptr) break;
        s = s->next;
        cout << s->d;
        cout << ' ';
    }
    cout << '\n';
}
void del(dlist* l, int n){
    dlist* cur = l;
    for(int i=0;i<n;i++){
        cur = cur->next;
    }
    cur->next->prev = cur->prev;
    cur->prev->next = cur->next;
    delete cur;
}
void delete_list(dlist* l){
    dlist* p = l;
    while(p->next!=nullptr){
        dlist *r = p;
        p = p->next;
        delete r;
    }
}
void into_file(ofstream &file, dlist* l){
    dlist* p = l;
    int n=0;
    while(p!=nullptr){
        n++;
        p=p->next;
    }
    file << n << '\n';
    p = l;
    while(p!=nullptr){
        file << p->d << ' ';
        p=p->next;
    }
}
dlist* out_of_file(ifstream &file){
    int n;
    file >> n;
    cout << n << '\n';
    dlist* p = make(n);
    for(int i=0;i<n;i++) {
        char input;
        file >> input;
        add(p, i, input);
    }
    return p;
}
int main(){
    dlist* l = make(10);
    show(l);
    add(l, 7, 'b');
    show(l);
    del(l, 4);
    show(l);
    ofstream file;
    file.open("/Users/user/Documents/GitHub/ai_programming_playground/ai_11/danylo_kvit/Epic-6/text.txt", ios::out);
    into_file(file,l);
    delete_list(l);
    file.close();
    ifstream file2;
    file2.open("/Users/user/Documents/GitHub/ai_programming_playground/ai_11/danylo_kvit/Epic-6/text.txt");
    dlist* p = out_of_file(file2);
    show(p);
}
