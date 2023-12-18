#include <iostream>
using namespace std;
unsigned int length = 0;
unsigned int current = 15;
char letter = 'k';
int main() {
    cin >> length;

    for(int i = 0; i < length; i++) {
        cin >> letter;

        if (letter == 'k') {
            if (current != 0) {
                current -= 1;
            }
        }
        else if (letter == 'p') {
            if (current >= 1) {
                current = 15;
            }
            else {
                current = 0;
            }
        }
        else if (letter == 'z') {
            if (current != 0) {
                current = 0;
            }
            else {
                current = 15;
            }
        }
    }
    cout << current;
}
