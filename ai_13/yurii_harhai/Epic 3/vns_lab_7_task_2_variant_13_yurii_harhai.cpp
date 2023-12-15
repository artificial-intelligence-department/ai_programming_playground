#include <iostream>

using namespace std;
void convert(double);
void convert(int, int);
int zsuv {1000000};

int main() {
    double decimal{};
    int chuselnuk = {};
    int znamenuk = {};
    cout <<"Enter decimal number, and chuselnuk i znamenuk separated by space: ";
    cin >> decimal >> chuselnuk >> znamenuk;
    
    convert(decimal); 
    convert(chuselnuk, znamenuk);

    return 0;
}
void convert(double decimal) {
    int chuselnuk = decimal * zsuv;
    int znamenuk = zsuv;

    for(int i = 2; i <= chuselnuk; i++) {
        if(chuselnuk % i == 0 && znamenuk % i == 0) {
            chuselnuk /= i;
            znamenuk /= i;
            i--;
        }
    }

    cout << "Normal: " << chuselnuk << "/" << znamenuk << endl;
}
void convert(int chuselnuk, int znamenuk) {
    double decimal{};
    decimal = static_cast<double> (chuselnuk) / znamenuk;
    cout << "Decimal: " << decimal << endl;
}