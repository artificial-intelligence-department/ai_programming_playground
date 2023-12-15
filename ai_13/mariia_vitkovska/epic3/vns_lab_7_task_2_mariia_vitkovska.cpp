#include <iostream>
#include <string>

using namespace std;

void destroy_even_numbers(int arr[], int size) {
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            arr[j] = arr[i];
            j++;
        }
    }
    for (int i = j; i < size; i++) {
        arr[i] = 0;
    }
}

void delete_even_words(string& str) {
    string temp = "";
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            count++;
            if (count % 2 == 0) {
                temp += str.substr(i - count + 1, count);
            }
            else {
                temp += " ";
            }
            count = 0;
        }
        else {
            count++;
        }
    }
    if (count % 2 == 0) {
        temp += str.substr(str.length() - count, count);
    }
    str = temp;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int size = sizeof(arr) / sizeof(arr[0]);
    destroy_even_numbers(arr, size);
    cout << "Array after destroying even elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    string str = "Hello miss Jones . What are your plans for today?";
    delete_even_words(str);
    cout << "String after deleting even words: " << str << endl;

    return 0;
}
