#include <iostream>
#include <vector>
using namespace std;

class List
{
	struct Element
	{
		int value;
		Element *nextElement;
	};

	Element *firstElement;

public:
	List() : firstElement(nullptr) {}

	void addElement(int value)
	{
		Element *newElement = new Element;
		newElement->value = value;
		newElement->nextElement = firstElement;
		firstElement = newElement;
	}

	bool isEqual(List &other)
	{;
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
