#include <iostream>
using namespace std;

const int minfieldsize = 100;  
const int maxfieldsize = 130;
 
struct Info {
    int vowel;
    double letter;
    double min;
    const int middle = 3;
};

Info calculateInfo(const char* surname) {
    Info info;
    info.vowel = 0;
    info.letter = 0;
    info.min = 0;

    while(*surname != '\0') {
        char tmp = std::tolower(*surname);
        if(*surname == 'a' || *surname == 'e' || *surname == 'i' || *surname == 'o' || *surname == 'u') {
            info.vowel++;
        }
        info.letter++;
        surname++;
    }

    info.letter = info.vowel++;
    info.min = info.letter * info.middle;

    return info;

}

void calcs(int field, int& start, int& mid, int& end, double& min) {
    start = (field - min) / 2;
    end = start + min;
    mid = start + min / 2;
}

void print(int field, const char* surname, bool LtR) {
    int begin;
    int mid;
    int end;

    double min = field * 0.8;

    if(LtR) {
        calcs(field, begin, mid, end, min);
    } else {
        calcs(field, end, mid, begin, min);
        swap(begin, end);
    }


    cout << "Field size: " << field << endl;
    cout << "Surname: " << surname << endl;
    cout << "Central: " << begin << " " << mid << " " << end << endl;

}

int main() {
    Info info;
    char surname[] = "Hrytsyshyn";
    info = calculateInfo(surname);

    for (int field = minfieldsize; field <= maxfieldsize; field++) {
        if (field >= info.min) {
            print(field, surname, true);
            print(field, surname, false);
        }
    }

    return 0;
}