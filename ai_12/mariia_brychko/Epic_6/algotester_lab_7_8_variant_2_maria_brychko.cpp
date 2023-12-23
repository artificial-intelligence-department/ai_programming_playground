#include <iostream>
#include <string>
using namespace std;

template <typename T>  //шаблон класу. template <typename T> вказує на початок оголошення шаблону класу. 
                       //<typename T> - це параметр шаблону, де T - це тип даних, який буде визначений 
                       //коли клас буде використовуватися.
class DynamicArr{    //оголошуємо клас DynamicArr використовуючи шаблон T, можна створити об'єкти DynamicArr з любим типом даних
    T* array;  // Вказівник на область пам'яті для зберігання елементів масиву
    int size;     
    int capacity; 

public:
//конструктор  //Конструктор викликається при створенні нових об'єктів класу
    DynamicArr(){  //об'єкт класу
        capacity=1;
        array = new T[capacity];   //вказівник на масив типу T. для зберігання елементів масиву.
        size=0;
    }

//деструктор  //Деструктор викликається при знищенні об'єкта класу
    ~DynamicArr(){
        delete[] array;
    }

    void get_size(){
        cout << size << endl;
    }
    void get_capacity(){
        cout << capacity << endl;
    }
    void get_el(int index){
        cout << array[index] << endl;
    }
    void set_el(int index, T number){
        array[index]=number;
    }

    void insert_el(int index, T* numbers, int N){
        if(size+N>=capacity){
            while(size+N>=capacity){
                capacity*=2;
            }
            T* newArray = new T[capacity];  //створюється новий масив newArray розміром capacity.
            for(int i = 0; i < size; i++){
                newArray[i]=array[i];
            }
            delete[] array;
            array = newArray;
        }

        T* newArray = new T[capacity];

        for(int i = 0; i < index && index>0; i++){
            newArray[i]=array[i];
        }
        for(int i = index, j=0; j<N ; i++, j++){
            newArray[i]=numbers[j];
        }
        for(int i = index+N, j = index; j < size; i++, j++){
            newArray[i]=array[j];
        }
        size+=N;
        delete[] array;
        array=newArray;
    }

    void erase_el(int index1, int num){   //num це к-ть елементів які треба видалити
        int index2 = index1+num-1;
        T* newArray = new T[capacity];
        for(int i = 0; i<index1; i++){
            newArray[i]=array[i];
        }
        for(int i = index1, j=index2+1; j < size; i++, j++){
            newArray[i]=array[j];
        }
        size=size-num;
        delete[] array;
        array=newArray;
    }

    //функція operator<< визначена як дружня функція у класі DynamicArr(має доступ до приватних членів цього класу)
    //функція приймає два параметри
//out - посилання на об'єкт потоку ostream до якого буде виведено вміст масиву
//array - посилання на об'єкт класу DynamicArr<T>, вміст якого буде виведено у потік
    friend ostream& operator<<(ostream& out, DynamicArr<T>& array){
        for(int i = 0; i < array.size; i++){
            out << array.array[i] << " ";
        }
        return out;
    }
};

int main(){
    DynamicArr<int> arr;
    int Q;
    cin >> Q;
    string requests;
    for(int i = 0; i < Q; i++){
        cin >> requests;
        if(requests == "insert"){
            int index, N;
            cin >> index >> N;
            int* numbers = new int [N];
            for(int i = 0; i < N; i++){
                cin >> numbers[i];
            }
            arr.insert_el(index, numbers, N);
            delete[] numbers;

        } else if(requests[0]=='s' && requests[1]=='i'){
            arr.get_size();

        } else if(requests[0]=='c'){
            
            arr.get_capacity();
        } else if(requests[0]=='g'){
            int index;
            cin >> index;
            arr.get_el(index);

        } else if(requests[0]=='s' && requests[1]=='e'){
            int index, number;
            cin >> index >> number;
            arr.set_el(index, number);

        } else if(requests[0]=='p'){
            cout << arr;

        } else if(requests[0]=='e'){
            int index1, num;
            cin >> index1 >> num;
            arr.erase_el(index1, num);
        }
    }
    return 0;
}