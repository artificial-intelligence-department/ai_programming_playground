#include <iostream>
#include <cmath>
using namespace std;
template<typename T>
class list{
public:
    list* prev;
    list* next;
    T data;
    list(){
        this->prev = nullptr;
        this->next = nullptr;
    }
};
template<typename T>
list<int>* ins(list<T>* l0){
    //to do:
    //check whether inserting into first
    list<T>* l = l0;
    bool was_null = l==nullptr;
    list<T>* start;
    if(!was_null) start = l;
    int index,n;
    cin >> index >> n;
    T a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    if(l0!=nullptr&&index==0){
        start = l0;
        for(int i=n-1;i>=0;i--){
            list<T>* p = new list<T>;
            p->data = a[i];
            p->next = start;
            p->prev = nullptr;
            start->prev = p;
            start = p;
        }
        return start;
    }else {
        for (int i = 0; i < index - 1; i++) l = l->next;
        for (int i = 0; i < n; i++) {
            list<T> *p = new list<T>;
            p->data = a[i];
            if (l != nullptr)p->next = l->next;
            else p->next = nullptr;
            p->prev = l;
            if (l != nullptr) {
                if (l->next != nullptr)l->next->prev = p;
                l->next = p;
            }
            l = p;
            if (was_null && i == 0) start = l;
//        cout << "check";
        }
        return start;
    }
}

template<typename T>
list<T>* erase(list<T>* l0){
    int index,n;
    cin >> index >> n;
    list<T>* start = l0;
    int curr_ind = 0;
    while(curr_ind < index) {
        start = start->next;
        curr_ind++;
    }
    for(int i=0;i<n;i++){
        if(start->next!=nullptr)start->next->prev = start->prev;
        if(start->prev!=nullptr)start->prev->next = start->next;
        list<T>* p = start->next;
        delete start;
        start = p;
    }
    if(index==0)return start;
    return l0;
}
template<typename T>
void size(list<T>* l0){
    list<T>* start = l0;
    int ans = 0;
    while(start!=nullptr){
        ans++;
        start = start->next;
    }
    cout << ans << '\n';
}
template<typename T>
void get(list<T>* l0){
    int index;
    cin >> index;
    list<T>* start = l0;
    int curr_ind = 0;
    while(curr_ind<index){
        curr_ind++;
        start = start->next;
    }
    cout << start->data << '\n';
}
template<typename T>
void set(list<T>* l0){
    int index, value;
    cin >> index >> value;
    list<T>* start = l0;
    int curr_ind = 0;
    while(curr_ind<index){
        curr_ind++;
        start = start->next;
    }
    start->data = value;
}
template<typename T>
void print(list<T>* l){
    while(l!=nullptr){
        cout << l->data << ' ';
        l=l->next;
    }
}
int main(){
    int q;
    cin >> q;
    list<int>* l = nullptr;
    for(int i=0;i<q;i++){
        string c;
        cin >> c;
        if(c=="insert") l = ins<int>(l);
        if(c=="print") print<int>(l);
        if(c=="get") get<int>(l);
        if(c=="set") set<int>(l);
        if(c=="erase") l = erase(l);
        if(c=="size") size(l);
    }
}