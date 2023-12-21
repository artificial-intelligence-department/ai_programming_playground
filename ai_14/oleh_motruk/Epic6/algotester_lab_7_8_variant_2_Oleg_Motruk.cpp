#include <iostream>
#include <sstream>
using namespace std;

template <typename T>
class dynamic_array{
    private:
        T* array;
        int max_size;
        int lenght;
    public:
        dynamic_array(){
            max_size = 1;
            lenght = 0;
            array = new T[max_size];
        }
        ~dynamic_array(){
            delete[] array;
        }
        void get(int index){
            if(index < 0 || index >= lenght){
                return;
            }
            else{
                cout << array[index] << endl;
            }
        }

        void size(){
            cout << lenght << endl;
        }

        void capacity(){
            cout << max_size << endl;
        }

        void set(int index, T number){
            if(index < 0 || index >= lenght){
                exit(0);
            }
            else{
                array[index] = number;
            }
        }

        void insert(int index, T* number, int size_of_array){
            if(index < 0){
                exit(0);
            }
            while (lenght + size_of_array >= max_size)
            {
                max_size *= 2;
                T* new_array = new T[max_size];
                for(int i = 0; i < lenght; i++){
                    new_array[i] = array[i];
                }
                delete[] array;
                array = new_array;
            }
            lenght += size_of_array;
            copy_backward(array + index, array + lenght - size_of_array, array + lenght);
            for(int i = 0; i < size_of_array;i++){
                array[index + i] = number[i];
            }
        }

        void erase(int index , int number){
            if(index < 0 || index >= lenght || index < 0){
                exit(0);
            }
            int elements_to_remove = number;
            if(index + number > lenght){
                elements_to_remove = lenght - index;
            }
            for(int i = index; i < lenght - elements_to_remove; i++){
                array[i] = array[i + elements_to_remove];
            }
            lenght -= elements_to_remove;
        }
        void print(){
            for(int i = 0; i < lenght; i++){
                cout << array[i] << " ";
            }
        }
};

int main(){
    string operat;

    dynamic_array<int> array;

    int q;
    cin >> q;

    for(int i = 0; i < q; i++){
        cin >> operat;

        if(operat == "insert"){
            int index;
            int size_of_array;
            cin >> index >> size_of_array;
            int* number = new int[size_of_array];
            for(int i = 0; i < size_of_array; i++){
                cin >> number[i]; 
            }
            array.insert(index, number , size_of_array);
        }
        else if(operat == "get"){
            int index;
            cin >> index;
            array.get(index);
        }
        else if(operat == "size"){
            array.size();
        }
        else if(operat == "set"){
            int index;
            int number;
            cin >> index >> number;
            array.set(index, number);
        }
        else if (operat == "erase"){
            int index;
            int amount_of_elements;
            cin >> index >> amount_of_elements;
            array.erase(index, amount_of_elements);
        }
        else if(operat == "print"){
            array.print();
        }
        else if(operat == "capacity"){
            array.capacity();
        }
    }   
    return 0;
}