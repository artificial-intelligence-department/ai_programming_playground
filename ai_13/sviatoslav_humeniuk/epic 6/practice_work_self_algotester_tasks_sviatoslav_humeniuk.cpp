#include <vector>
#include <iostream>

using namespace std;
template<typename T>
struct Dynar{

    T capacity;
    T size;
    T *arra;

    void initial(T oldFr) const{
        for (T i = oldFr; i < capacity; i++) { 
            arra[i] = 0;
        }
    }
    void growFac() {
        capacity *= 2;
        int *tempArra = new T[capacity];
        for (int i = 0; i < size; i++) {
            tempArra[i] = arra[i];
        }
        delete [] arra;
        arra = tempArra;
        initial(size);
    }

    Dynar() {
        capacity = 1;
        size = 0;
        arra = new int[capacity];
    }
    ~Dynar() {
        delete [] arra;
    }

    T& operator[](T index) const{ 
        return arra[index];
    }

    void ADD1() {
        if (size + 1 >= capacity) {
            growFac();
        }
        arra[size++] = 0;
    }
    void SORT(T index1, T index2) const{
        int k = size - index2;
        for (int i = 0; i < k; i++) {
            if ((k - 1 - i) >= index1) {
                arra[size - 1 - i] = arra[k - i - 1];
            }
        }
    }
    void ADD2(T index1, T index2, vector<T> &numes) const{
        for (int i = 0; i < index2; i++) {
            arra[index1+i] = numes[i];
        }
    }
    void ERASE(T fr, T hm) {
        for (int l = fr; l < size; l++) {
            arra[l] = arra[hm+l];
        }
        size = size - hm;
    }
    T getSize() const {
        return size;
    }
    void SIZE() const{
        cout << size;
    }
    void CAPACITY() const {
        cout << capacity;
    }
    friend ostream& operator <<(ostream& os, const Dynar& arra);
};

ostream& operator<<(ostream &os, const Dynar<int>& arra) {
    for (size_t i = 0; i < arra.getSize(); i++) {
        os << arra.arra[i] << ' ';
    }
    cout << endl;
    return os;
}

int main() {
    Dynar<int> arra;
    int index;
    int index1;
    int index2;
    int Q;
    string str;

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> str;
        if (str == "size") {
            arra.SIZE();
            cout << "\n";
            continue;
        }
        if (str == "capacity") {
            arra.CAPACITY();
            cout << "\n";
            continue;
        }
        if (str == "get") {
            cin >> index;
            cout << arra[index] << "\n";
            continue;
        }
        if (str == "erase") {
            cin >> index1 >> index2;
            arra.ERASE(index1, index2);
            continue;
        }
        if (str == "set") {
            cin >> index1 >> index2;
            arra[index1] = index2;
            continue;
        }
        if (str == "insert") {
            cin >> index1 >> index2;
            vector<int> numes(index2);
            for (int n = 0; n < index2; n++) {
                arra.ADD1();
            }
            arra.SORT(index1,index2);
            for (int n = 0; n < index2; n++) {
                cin >> numes[n];
                arra.ADD2(index1, index2, numes);
            }
            continue;
        }
        if (str == "print") {
            cout << arra;
            continue;
        }
    }

    return 0;
}