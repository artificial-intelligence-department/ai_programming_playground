#include <iostream>
#include <vector>

using namespace std;

class List
{
private:
    struct Element
    {
        int value;
        Element *nextElement;

        // Конструктор для створення елемента зі значенням та наступним елементом
        Element(int val, Element *next) : value(val), nextElement(next) {}
    };

    Element *firstElement;

public:
    // Конструктор за замовчуванням
    List() : firstElement(nullptr) {}

    // Додавання елемента на початок списку
    void addElement(int value)
    {
        firstElement = new Element(value, firstElement);
    }

    // Порівняння двох списків на рівність
    bool isEqual(const List &other) const
    {
        Element *currentElement1 = firstElement;
        Element *currentElement2 = other.firstElement;

        while (currentElement1 != nullptr && currentElement2 != nullptr)
        {
            if (currentElement1->value != currentElement2->value)
            {
                return false;
            }
            currentElement1 = currentElement1->nextElement;
            currentElement2 = currentElement2->nextElement;
        }

        // Перевірка, чи обидва елемента дійшли кінця свого списку
        return currentElement1 == nullptr && currentElement2 == nullptr;
    }
};

int main()
{
    List listA;
    listA.addElement(47);
    listA.addElement(19);
    listA.addElement(54);
    listA.addElement(95);

    List listB;
    listB.addElement(47);
    listB.addElement(19);
    listB.addElement(54);
    listB.addElement(94);

    if (listA.isEqual(listB))
    {
        cout << "Lists are equal\n";
    }
    else
    {
        cout << "Lists are not equal\n";
    }

    return 0;
}
