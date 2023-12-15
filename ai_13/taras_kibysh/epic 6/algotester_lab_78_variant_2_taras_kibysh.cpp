#include <iostream>
#include <string>
#include <algorithm>

class DynamicArray {
private:
    long int* massive;
    long int size;
    long int capacity;

public:

    DynamicArray() : size(0), capacity(1) {
         massive = new long int[capacity];
    }

    ~DynamicArray() {
        delete[] massive;
    }

    void insert(long int A, long int N, long int* value) {
        if (A < 0 || A > size)
            return;

        if (size + N >= capacity) {
            long int changedCapacity = capacity;

            while (size + N >= changedCapacity) {
                changedCapacity *= 2;
            }
            long int* changedArr = new long int[changedCapacity];
            size += N;

            for ( int i = 0; i < size; ++i) {
                changedArr[i] = massive[i];
            }

             delete[] massive;
            massive = changedArr;

            std::copy_backward(massive + A, massive + size - N, massive + size);
            for (size_t i = 0; i < N; ++i) {
                massive[A + i] = value[i];
            }

            
            capacity = changedCapacity;
        } else {

            for ( int i = size - 1; i >= A; --i) {
                massive[i + N] = massive[i];
            }

            for ( int i = 0; i < N; ++i) {
                massive[A + i] = value[i];
            }

            size += N;
        }
    }


    void erase(long int A, long int n) {

        long int deleteCount = std::min(n, size - A);
        for ( int i = A; i < size - deleteCount; ++i) {
            massive[i] = massive[i + deleteCount];
        }

        size -= deleteCount;
    }


    long int Size() {
        return size;
    }


    long int Capacity() {
        return capacity;
    }

    void print(){
        for( int i = 0; i < size; ++i){
            std::cout << massive[i] << " ";
        }

    }
    long int& operator[](long int A) {
        return massive[A];
    }


};

int main() {
    using namespace std;

    long int N;
    cin >> N;

    DynamicArray dynArray;

    while (N--) {
        string answer;
        cin >> answer;
        char sym = answer[0];

        long int A, n;
        long int* value;

        switch (sym) {
            case 'i':
                cin >> A >> n;

                value = new long int[n];
                for ( int i = 0; i < n; ++i) {
                    cin >> value[i];
                }

                dynArray.insert(A, n, value);
                delete[] value;
               
                break;

            case 'e':
                cin >> A >> n;
                dynArray.erase(A, n);
              
                break;

            case 's':
                if (answer == "size") {
                    cout << dynArray.Size() << endl;
                } else if (answer == "set") {
                    cin >> A >> n;

                    if (A >= 0 && A < dynArray.Size()) {
                        dynArray[A] = n;
                    }
                }
                break;

            case 'c':
                cout << dynArray.Capacity() << endl;
                break;

            case 'g':
                cin >> A;

                if (A >= 0 && A < dynArray.Size()) {
                    cout << dynArray[A] << endl;
                }
                break;

            case 'p':
                dynArray.print();
            
                break;

            default:
                cout << "Unknown action\n";
        }
    }


    return 0;
}

  
