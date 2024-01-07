#include<iostream>

template<class T>
class Dynamic_arr
{
    const int growth_factor = 2;

    T* data ;
    int size;
    int capacity;

    void insert(T value, int index)
    {

        T* buff = new T[size + 1];
        for (int i = 0;i < size; i++) {
           buff[i] = data[i];
        }
        ++size;
        if(size >= capacity)
        {
            capacity *= growth_factor;
        }
        int j;
        for (j = size - 1;j > index; j--) {

                    buff[j] = buff[j - 1];
        }
        buff[j] = value;
        delete[] data;
        data = buff;
    }

    void erase(int index)
    {
        for(int i = index; i < size - 1; i++)
        {
                data[i] = data[i + 1];
        }
        --size;
    }


public:

    Dynamic_arr() : data(nullptr), size(0), capacity(1) {}

    T& operator[](int index)
    {
        return data[index];
    }
    void insertion(T value, int index)
    {
        insert(value, index);
    }
    void deleting(int index)
    {
        erase(index);
    }
    int size_f()
    {
        return size;
    }
    int capacity_f()
    {
        return capacity;
    }
    void print()
    {
        for(int i = 0; i < size; i++) {
            std::cout<<data[i]<<' ';
        }
    }
//destructor
    ~Dynamic_arr() {
        delete[] data;
    }
};




int main()
{
    using namespace std;

    Dynamic_arr<int> vector;

    int count_of_questions;
    string question;
    cin >> count_of_questions;

    for (int i = 0; i < count_of_questions; ++i) {
        cin >> question;


        if (question == "insert") {
            int index, count;
            cin >> index >> count;
            for (int j = count - 1; j >= 0; --j)
            {
                int number;
                cin >> number;
                vector.insertion(number, index);
                index++;
            }
        } else if (question == "erase") {
            int index, count;
            cin >> index >> count;
            for (int j = 0; j < count; ++j)
                vector.deleting(index);
        } else if (question == "size") {
            cout << vector.size_f() << endl;}
        else if (question == "capacity") {
                cout << vector.capacity_f() << endl;
        } else if (question == "get") {
            int index;
            cin >> index;
            cout<< vector[index]<<endl;
        } else if (question == "set") {
            int index, value;
            cin >> index >> value;
            vector[index] = value;
        } else if (question == "print") {
            vector.print();
            cout<<endl;
        }
    }


    return 0;
}
