#include <iostream>
#include <vector>
#include <random>

using namespace std;

vector<int> generateInts() {
    vector<int> result;

    random_device randomDevice;
    mt19937 gen(randomDevice());
    uniform_int_distribution lengthDistribution(4, 10);
    uniform_int_distribution numberDistribution(0, 10);

    int length = lengthDistribution(gen);

    for (int i = 0; i < length; i++) {
        int number = numberDistribution(gen);
        result.push_back(number);
    }

    return result;
}

void printArray(vector<int> array) {
    for (int i = 0; i < array.size(); i++) {
        if (i == 0) {
            cout << '[' << array[i] << ", ";
        }
        else if (i != array.size()-1) {
            cout << array[i] << ", ";
        }
        else {
            cout << array[i] << ']' << endl;
        }
    }
}

void del_by_int(vector<int> &array, int target) {
    for (int i = 0; i < array.size(); i++) {
        if (array[i] == target) {
            array.erase(array.begin() + i);
            --i;
        }
    }
}

int find_first_even(vector<int> &array) {
    for (int i = 0; i < array.size(); i++) {
        if (array[i]%2 == 0) {
            return i;
        }
    }
}

int main() {
    vector<int> array = generateInts();
    printArray(array);

    del_by_int(array, 0);
    printArray(array);

    int firstEvenPos = find_first_even(array);
    if (firstEvenPos != 0) {
        array.insert(array.begin() + firstEvenPos + 1, array[firstEvenPos-1]+2);
        printArray(array);
    }
    else { cout << "First even is at first position, so can't do the calculation"; }

    return 0;
}
