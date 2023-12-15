#include <iostream>
#include <vector>
using namespace std;

vector<string> Translate(int count, ...) {
    vector<string> Numbers_in_3;
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i) {
        int num = va_arg(args, int);
        string numberAft = "";
        
        while (num > 0) {
            numberAft = char('0' + num % 3) + numberAft;
            num /= 3;
        }   
        //Numbers_in_3.push_back(numberAft);
        Numbers_in_3.push_back(numberAft.empty() ? "0" : numberAft);
    }

    va_end(args);
    return Numbers_in_3;
}

int main() {
    vector<string> result1 = Translate(3, 2, 26, 3);
    vector<string> result2 = Translate(4, 15, 0, 1, 77);
    vector<string> result3 = Translate(7, 4, 7, 8, 20, 9, 13, 18);

    cout << "Result 1: ";
    for (const auto& i : result1) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Result 2: ";
    for (const auto& i : result2) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Result 3: ";
    for (const auto& i : result3) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
