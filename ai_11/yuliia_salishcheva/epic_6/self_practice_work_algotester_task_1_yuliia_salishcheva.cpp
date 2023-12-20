#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void output(const vector <int>& vector) {
    cout << vector.size() << endl;
    for (int i = 0; i < vector.size(); i++) {
        cout << vector[i] << " ";
    }
    cout << "\n\n";
}
vector<int> inputVector(const int& size)
{
    vector <int> vector(size);
    for (int i = 0; i < size; i++) {
        cin >> vector[i];
    }
    return vector;
}


int main() {
    int size1, size2;

    cin >> size1;
    vector <int> vector1 = inputVector(size1);

    cin >> size2;
    vector <int> vector2 = inputVector(size2);;

    sort(vector1.begin(), vector1.end());
    sort(vector2.begin(), vector2.end());

    //різниця N-M
    vector <int> test;

    set_difference(vector1.begin(), vector1.end(), vector2.begin(), vector2.end(), back_inserter(test));
    output(test);

    //різниця M-N
    test.clear();
    set_difference(vector2.begin(), vector2.end(), vector1.begin(), vector1.end(), back_inserter(test));
    output(test);

    //їх перетин
    test.clear();
    set_intersection(vector1.begin(), vector1.end(), vector2.begin(), vector2.end(), back_inserter(test));
    output(test);

    //їх об'єднання
    test.clear();
    set_union(vector1.begin(), vector1.end(), vector2.begin(), vector2.end(), back_inserter(test));
    output(test);

    //їх симетричну різницю
    test.clear();
    set_symmetric_difference(vector1.begin(), vector1.end(), vector2.begin(), vector2.end(), back_inserter(test));
    output(test);

    return 0;
}
