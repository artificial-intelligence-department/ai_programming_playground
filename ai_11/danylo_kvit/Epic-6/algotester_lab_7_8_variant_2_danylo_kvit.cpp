#include <iostream>
#include <cmath>
using namespace std;
int f(int x){
    if(x==0)return -1;
    if(x==1)return 0;
    return f(x/2)+1;
}
template<typename T>
class arr{
public:
    int siz,cap;
    T* val;
    arr(){
        val = new T[0];
        siz = 0;
        cap = 1;
    }
    void resize(){
        cap = (1<<(f(siz)+1));
    }
    int size(){
        return siz;
    }
    int capacity(){
        return cap;
    }
    void g() {
        int n;
        cin >> n;
        cout << val[n] << '\n';
    }
    void set_v() {
        int n;
        T inp;
        cin >> n >> inp;
        val[n] = inp;
    }
    void insert(){
        int index,n;
        cin >> index >> n;
        int old_size = siz;
        siz+=n;
        if(siz>=cap)resize();
        T* new_arr = new T[cap];
        int j = 0;
        for(int i=0;i<index;i++){
            new_arr[j] = val[i];
            j++;
        }
        for(int i=0;i<n;i++){
            cin >> new_arr[j];
            j++;
        }
        for(int i=0;i<old_size-index;i++){
            new_arr[j] = val[i+index];
            j++;
        }
        delete val;
        val = new_arr;
    }
    void print(){
        for(int i=0;i<siz;i++){
            cout << val[i] << ' ';
        }
        cout << '\n';
    }
    void erase(){
        int index,n;
        cin >> index >> n;
        int old_size = siz;
        siz-=n;
        T* new_arr = new T[cap];
        for(int i=0;i<index;i++){new_arr[i] = val[i];}
        for(int i=index+n;i<old_size;i++){new_arr[i-n] = val[i];}
        delete val;
        val = new_arr;
    }

};
int main(){
    int q;
    cin >> q;
    arr<int> a;
    for(int i=0;i<q;i++){
        string c;
        cin >> c;
        if(c=="insert") a.insert();
        if(c=="print") a.print();
        if(c=="get") a.g();
        if(c=="set") a.set_v();
        if(c=="erase") a.erase();
        if(c=="size") cout << a.size() << '\n';
        if(c=="capacity") cout << a.capacity() << '\n';
    }
}