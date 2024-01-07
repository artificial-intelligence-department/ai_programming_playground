#include <iostream>
#include <list>
#include <string>

using namespace std;

class LinkedList {
private:
    list<string> elements;

public:
    void append(const string& element) {
        elements.push_back(element);
    }

    void deleteKElements(const list<int>& indexes) {
        for (auto it = indexes.rbegin(); it != indexes.rend(); ++it) {
            if (*it >= 0 && *it < elements.size()) {
                auto iter = elements.begin();
                advance(iter, *it);
                elements.erase(iter);
            }
        }
    }

    void addKElementsToStart(const list<string>& newElements) {
        elements.insert(elements.begin(), newElements.begin(), newElements.end());
    }

    void print() const {
        if (elements.empty()) {
            cout << "Список порожній" << endl;
        } else {
            for (const auto& element : elements) {
                cout << element << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    LinkedList list;

    list.append("One");
    list.append("Two");
    list.append("Three");
    list.append("Four");

    cout << "Список після додавання елементів: ";
    list.print();

    list.deleteKElements({1, 3});

    cout << "Список після знищення елементів: ";
    list.print();

    list.addKElementsToStart({"NewOne", "NewTwo"});

    cout << "Список після додавання елементів у початок: ";
    list.print();

    return 0;
}
