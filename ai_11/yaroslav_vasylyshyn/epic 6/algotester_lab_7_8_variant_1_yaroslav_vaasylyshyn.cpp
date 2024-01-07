#include <iostream>
#include <vector>
#include <string>

using namespace std;

class operations
{
    public:
    vector <int> array;
    void insert(int index,int N, vector <int> a)
    {
        array.insert(array.begin() + index, a.begin(), a.end());
    }
    void erase(int index, int value)
    {
        array.erase(array.begin() + index,array.begin() + index + value);
    }
    void set(int index, int value)
    {
        array[index] = value;
    }
    void get(int index)
    {
        cout<<array[index]<<'\n';
    }
    void size()
    {
        cout<<array.size()<<'\n';
    }
    void print()
    {
        for (int i = 0; i < array.size(); i++)
        {
            cout<<array[i]<<" ";
        }
        cout<<'\n';
    }
};
int main(){
    operations op;
    int Q,index,N,value;
    cin>>Q;
    for (int i = 0; i < Q; i++)
    {
        string option;
        cin>>option;
        if (option == "insert")
        {
            cin>>index>>N;
            vector<int> arr;
            for (int i = 0; i < N; i++)
            {
                cin>>value;
                arr.push_back(value);
            }
            op.insert(index, N, arr);
        }else if(option == "erase"){
            int value;
            cin>>index>>value;
            op.erase(index, value);
        }else if(option == "set"){
            cin>>index>>N;
            op.set(index, N);
        }else if(option == "get"){
            cin>>index;
            op.get(index);
        }else if(option == "size"){
            op.size();
        }else if(option == "print"){
            op.print();
        }
    }
    return 0;
}