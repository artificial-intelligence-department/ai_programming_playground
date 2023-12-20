#include <iostream>
#include <string>
#include <algorithm>

template <typename T>
class CustomArray {
private:
    T* elements;
    long int size;
    long int capacity;

public:

    CustomArray() : size(0), capacity(1) {
        elements = new T[capacity];
    }

    ~CustomArray() {
        delete[] elements;
    }

    void insert(long int index, long int count, T* values) {
        if (index < 0 || index > size)
            return;

        if (size + count >= capacity) { //У цьому умовному операторі перевіряється, чи потрібно збільшити розмір масиву для вміщення нових елементів.
            long int changedCapacity = capacity;

            while (size + count >= changedCapacity) { //У цьому циклі розмір changedCapacity подвоюється, доки не буде забезпечено, що новий розмір масиву буде достатнім для вміщення поточного розміру та кількості нових елементів.
                changedCapacity *= 2;
            }
            T* changedElements = new T[changedCapacity];
            size += count; //Розмір об'єкта CustomArray збільшується на кількість нових елементів

            for (int i = 0; i < size; ++i) {
                changedElements[i] = elements[i]; //Копіюється вміст поточного масиву elements в новий масив changedElements
            }

            delete[] elements;
            elements = changedElements;

            std::copy_backward(elements + index, elements + size - count, elements + size); //Здійснюється зсув елементів вправо, щоб звільнити місце для нових елементів в області вставки
            for (size_t i = 0; i < count; ++i) {
                elements[index + i] = values[i];//Копіюються нові значення з values в область вставки у масиві.
            }

            capacity = changedCapacity;
        } else {

            for (int i = size - 1; i >= index; --i) {
                elements[i + count] = elements[i];
            }

            for (int i = 0; i < count; ++i) {
                elements[index + i] = values[i];
            }

            size += count;
        }
    }


    void erase(long int index, long int count) { //Ця функція призначена для видалення елементів із масиву.

        long int deleteCount = std::min(count, size - index);
        for (int i = index; i < size - deleteCount; ++i) {
            elements[i] = elements[i + deleteCount];//Це здійснює зсув елементів вліво, викриваючи місце, яке потрібно видалити.
        }

        size -= deleteCount;
    }


    long int Size() const {
        return size;
    }


    long int Capacity() const {
        return capacity;
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << elements[i] << " ";
        }

    }
    T& operator[](long int index) { //повертає посилання на елемент масиву за вказаним індексом. Це дозволяє отримувати та змінювати значення елементів масиву за допомогою індексації.
        return elements[index];
    }
};

int main() {
    using namespace std;

    long int Q;
    cin >> Q;

    CustomArray<long int> customArray;

    while (Q--) {
        string command;
        cin >> command;
        char action = command[0];//Зчитується рядок команди від користувача у вигляді стрічки (command), і витягується перший символ (дія) цієї команди в змінну action

        long int index, count;
        long int* values;

        switch (action) { //Починається конструкція switch, яка дозволяє обирати виконання різних блоків коду в залежності від значення action
            case 'i':
                cin >> index >> count;

                values = new long int[count];
                for (int i = 0; i < count; ++i) {
                    cin >> values[i];
                }

                customArray.insert(index, count, values);
                delete[] values;

                break;

            case 'e':
                cin >> index >> count;
                customArray.erase(index, count);

                break;

            case 's':
                if (command == "size") {
                    cout << customArray.Size() << endl;
                } else if (command == "set") {
                    cin >> index >> count;

                    if (index >= 0 && index < customArray.Size()) {
                        customArray[index] = count;
                    }
                }
                break;

            case 'c':
                cout << customArray.Capacity() << endl;
                break;

            case 'g':
                cin >> index;

                if (index >= 0 && index < customArray.Size()) {
                    cout << customArray[index] << endl;
                }
                break;

            case 'p':
                customArray.print();
                cout << endl;

                break;

            default:
                cout << "Unknown action\n";
        }
    }

    return 0;
}
