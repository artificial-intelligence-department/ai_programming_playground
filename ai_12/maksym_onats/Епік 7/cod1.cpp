#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int countVowels(string str) {
    int count = 0;
    for (char c : str) {
        char lowercaseC = tolower(c);
        if (lowercaseC == 'a' || lowercaseC == 'e' || lowercaseC == 'i' 
            || lowercaseC == 'o' || lowercaseC == 'u') {
            count++;
        }
    }
    return count;
}

int main() {
    string surname;
    cout << "Enter your last name: ";
    getline(cin, surname);

    int vowelCount = countVowels(surname);

    double letterWidth = vowelCount * 0.8;

    const int minLength = 100;
    const int maxLength = 130;
    const int minWidth = 50;
    const int maxWidth = 100;

    double centralWidth = 3.0;

    int length = 110;
    int minLengthField = minLength;
    int requiredLength = ceil(letterWidth / 3.0);

    // Ensure that the calculated length is within the specified bounds
    if (length > minLength) {
        minLengthField = length;
    }

    if (requiredLength < minLength) {
        requiredLength = minLength;
    } else if (requiredLength > maxLength) {
        requiredLength = maxLength;
    }

    cout << "Minimum required length for the banner: " << requiredLength << " yards" << endl;

    int leftOffset = (requiredLength - letterWidth) / 2;
    int rightOffset = requiredLength - leftOffset - letterWidth;

    cout << "Symbols on the 3 central meters (left to right): ";
    for (int i = leftOffset; i < leftOffset + centralWidth; ++i) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Symbols on the 3 central meters (right to left): ";
    for (int i = rightOffset + centralWidth - 1; i >= rightOffset; --i) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
