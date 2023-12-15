#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Dyn_array {
private:
    long* m_array=NULL;
    long m_size = 0;
    long m_capacity = 1;
public:
    Dyn_array() {}

    void insert(long index, long N, vector<long> to_insert) {
        long new_size;
        new_size = m_size+N;
        while (new_size>=m_capacity) { m_capacity*=2; }
        long *new_array = new long[m_capacity];
        long i_n=0, i_o=0;
        while(i_n<index) {
            new_array[i_n] = m_array[i_o];
            i_n++, i_o++;
        } 
        for (long j=0; j<N; j++) {
            new_array[i_n] = to_insert[j];
            i_n++;
        }
        while(i_n<new_size) {
            new_array[i_n] = m_array[i_o];
            i_n++, i_o++;
        } 
        delete[] m_array;
        m_size = new_size;
        m_array = new_array;
    }

    void erase(long index, long N) {
        long new_size;
        new_size = m_size-N;
        long *new_array = new long[m_capacity];
        long i_n=0, i_o=0;
        while(i_n<index) {
            new_array[i_n] = m_array[i_o];
            i_n++, i_o++;
        } 
        while(N>0) { i_o++, --N; }
        while(i_n<new_size) {
            new_array[i_n] = m_array[i_o];
            i_n++, i_o++;
        } 
        delete[] m_array;
        m_size = new_size;
        m_array = new_array;
    }

    long size() {
        return m_size;
    }

    long capacity() {
        return m_capacity;
    }

    long& operator[](long index);

    friend ostream& operator<<(ostream &out, Dyn_array arr);
};

long& Dyn_array::operator[](long index) {
    return m_array[index];
}

ostream& operator<<(ostream &out, Dyn_array arr) {
    for (long i=0; i<arr.m_size; i++) {out << arr[i] << ' ';}
    return out;
}

int main() {
    Dyn_array v;
    long Q;
    cin >> Q;
    vector<string> requests(Q);
    vector<long> change;
    vector<long> ins;
    for (long i=0; i<Q; i++) {
        cin >> requests[i];
        if (requests[i] == "") {i--;}
        else if(requests[i] == "insert") {
            long tmp;
            cin >> tmp;
            change.push_back(tmp);
            cin >> tmp;
            change.push_back(tmp);
            for (long j=0; j<tmp; j++) {
                long tmp2;
                cin >> tmp2;
                ins.push_back(tmp2);
            }
        }
        else if(requests[i] == "erase") {
            long tmp;
            cin >> tmp;
            change.push_back(tmp);
            cin >> tmp;
            change.push_back(tmp);
        }
        else if(requests[i] == "get") {
            long tmp;
            cin >> tmp;
            change.push_back(tmp);
        }
        else if(requests[i] == "set") {
            long tmp;
            cin >> tmp;
            change.push_back(tmp);
            cin >> tmp;
            change.push_back(tmp);
        }
    }
    long change_counter = 0, ins_counter = 0; 
    for (long i = 0; i<Q; i++) {
        if (requests[i] == "insert") {
            vector<long> to_push;
            for (long abc=0;abc<change[change_counter+1];abc++) {to_push.push_back(ins[ins_counter++]);}
            v.insert(change[change_counter],change[change_counter+1],to_push);
            change_counter+=2;
        }
        else if(requests[i] == "erase") {
            v.erase(change[change_counter],change[change_counter+1]);
            change_counter+=2;
        }
        else if(requests[i] == "size") {
            cout << v.size() << endl;
        }
        else if(requests[i] == "capacity") {
            cout << v.capacity() << endl;
        }
        else if(requests[i] == "get") {
            cout << v[change[change_counter++]] << endl;
        }
        else if(requests[i] == "set") {
            v[change[change_counter]] = change[change_counter+1];
            change_counter+=2;
        }
        else if(requests[i] == "print") {
            cout << v << endl;
        }
    }
    return 0;
}