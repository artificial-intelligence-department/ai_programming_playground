#include <iostream>
#include <functional>

// Algotester Lab 7-8 V2
// Vector

// TODO: Add iterators
template<class T>
class Vector {
private:
    static constexpr int DEFAULT_CAPACITY = 1;
    static constexpr int GROWTH_FACTOR = 2;

    T* data;
    int _size;
    int _capacity;

    void check_capacity() {
        if (_size == _capacity)
            resize(_capacity * GROWTH_FACTOR);
    }

    void check_index(const int index) const {
        if (index < 0 || index > _size)
            throw std::out_of_range("Index out of range");
    }

public:
    explicit Vector(const int capacity) {
        data = new T[capacity];
        _size = 0;
        _capacity = capacity;
    }

    Vector() : Vector(DEFAULT_CAPACITY) {}

    // If we use this ctor, it'll disable IDE warnings
    // (CLion is not that smart tho)
    
    // Vector() {
    //     data = new T[DEFAULT_CAPACITY];
    //     _size = 0;
    //     _capacity = DEFAULT_CAPACITY;
    // }

    Vector(std::initializer_list<T> list)
            : Vector(list.size()) {
        for (auto& value : list) {
            push_back(value);
        }
    }

    ~Vector() {
        _size = 0;
        delete[] data;
    }

    void resize(const int new_capacity) {
        T* new_data = new T[new_capacity];
        for (int i = 0; i < _size; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        _capacity = new_capacity;
    }

    void insert(T value, int index) {
        check_capacity();
        check_index(index);

        for (int i = _size; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        _size++;

        check_capacity();
    }

    void push_back(T value) {
        insert(value, _size);
    }

    // Nodiscard is used to warn the user if the return value is ignored
    // (Function is useless if we just call it)
    [[nodiscard]] int size() const {
        return _size;
    }

    [[nodiscard]] bool empty() const {
        return _size == 0;
    }

    [[nodiscard]] int capacity() const {
        return _capacity;
    }

    void remove(const int index) {
        check_index(index);
        for (int i = index; i < _size - 1; i++) {
            data[i] = data[i + 1];
        }
        _size--;
    }

    void pop_back() {
        remove(_size - 1);
    }

    void foreach(std::function<void(T)> func) const {
        for (int i = 0; i < _size; i++) {
            func(data[i]);
        }
    }

    T& operator[](int index) {
        check_index(index);
        return data[index];
    }
};

template<class T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
    v.foreach([&os](T value) {
        os << value << " ";
    });
    return os;
}

int main() {
    using namespace std;
    Vector<int> v;

    int queries;
    string query;
    cin >> queries;

    for (int i = 0; i < queries; ++i) {
        cin >> query;

        try {
            if (query == "insert") {
                int index, count;
                cin >> index >> count;

                vector<int> values(count);
                for (int j = 0; j < count; ++j)
                    cin >> values[j];

                for (int j = count - 1; j >= 0; --j)
                    v.insert(values[j], index);
            } else if (query == "erase") {
                int index, count;
                cin >> index >> count;

                for (int j = 0; j < count; ++j)
                    v.remove(index);
            } else if (query == "size") {
                cout << v.size() << endl;
            } else if (query == "get") {
                int index;
                cin >> index;
                cout << v[index] << endl;
            } else if (query == "set") {
                int index, value;
                cin >> index >> value;
                v[index] = value;
            } else if (query == "print") {
                cout << v << endl;
            } else if (query == "capacity") {
                cout << v.capacity() << endl;
            }
        }
        // ignore out of range exceptions
        catch (out_of_range&) {}
        catch (exception&) {}
    }
}
