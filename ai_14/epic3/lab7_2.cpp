#include <iostream>
#include <string>
using namespace std;

int min_element(int n, int a[]) {
    int min = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

int findMinWordLength(const int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (min > arr[i]) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int var;
    cout << "яке завдання:(1,2)";
    cin >> var;

    if (var == 2) {
        int n = 0;
        std::string sentence;
        cin.ignore();
        getline(std::cin, sentence);

        int count = 0;
        int arr[100] = {0};

        for (int i = 0; i < sentence.length(); i++) {
            if (sentence[i] != ' ' && sentence[i] != '\0') {
                count++;
            } else {
                arr[n] = count;
                count = 0;
                n++;
            }
        }

        int min = findMinWordLength(arr, n);

        std::cout << "Length of smallest word: " << min << std::endl;

        return 0;
    }

    if (var == 1) {
        int a[100];
        int n;

        cout << "введіть кількість чисел: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "введіть число " << i + 1 << ": ";
            cin >> a[i];
        }

        int result = min_element(n, a);
        cout << "Мінімальний елемент: " << result << endl;

        return 0;
    }

    return 0;
}