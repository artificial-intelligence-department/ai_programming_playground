#include <iostream>
#include <string>
using namespace std;

template <typename nameType>
struct templateArray {
    int size = 0, capacity = 1;
    nameType* Structure_1;

    templateArray() {
        Structure_1 = new nameType[1];
    }

    void enterElements(int index, int mainarray[], int Q) {
        if (capacity > size + Q) {
            for (int i = size - 1; i > index - 1; i--) {
                Structure_1[i + Q] = Structure_1[i];
            }
            for (int i = 0; i < Q; i++) {
                Structure_1[i + index] = mainarray[i];
            }
            size += Q;
        }
        else {
            while (capacity <= size + Q) {
                capacity = capacity * 2;
            }
            nameType* Structure_2 = new nameType[capacity];
            for (int i = 0; i < index; i++) {
                Structure_2[i] = Structure_1[i];
            }
            for (int i = 0; i < Q; i++) {
                Structure_2[i + index] = mainarray[i];
            }
            for (int i = index; i < size; i++) {
                Structure_2[i + Q] = Structure_1[i];
            }
            delete[] Structure_1;
            Structure_1 = Structure_2;
            size += Q;
        }
    }
    void Erase(int index, int q) {

        for (int i = index; i < size; ++i) {
            Structure_1[i] = Structure_1[i + q];
        }
        size -= q;
    }

    int Size() {
        return size;
    }

    int Capacity() {
        return capacity;
    }

    nameType& operator[](int index) {
        return Structure_1[index];
    }

    friend ostream& operator<<(ostream& os, const templateArray& array) {
        for (int i = 0; i < array.size; ++i) {
            os << array.Structure_1[i] << ' ';
        }
        return os;
    }
};

int main() {


    templateArray<int> Structure_1;

    int H;
    cin >> H;

    for (int i = 0; i < H; i++) {
        string trigger;
        cin >> trigger;

        if (trigger == "insert") {
            int index,Q;
            cin >> index >> Q;

            int* values = new int[Q];
            for (int i = 0; i < Q; i++) {
                cin >> values[i];
            }
            Structure_1.enterElements(index, values, Q);
        }
        else if (trigger == "erase") {
            int index, q;
            cin >> index >> q;
            Structure_1.Erase(index, q);
        }
        else if (trigger == "size") {
            cout << Structure_1.Size() << endl;
        }
        else if (trigger == "capacity") {
            cout << Structure_1.Capacity() << endl;
        }
        else if (trigger == "get") {
            int index;
            cin >> index;
            cout << Structure_1[index] << endl;
        }
        else if (trigger == "set") {
            int index;
            cin >> index;
            cin >> Structure_1[index];
        }
        else if (trigger == "print") {
            cout << Structure_1 << endl;
        }
    }

    return 0;
}
