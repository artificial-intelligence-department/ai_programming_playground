#include <iostream>
using namespace std;

int main() {
    int vik;
    cout << "Введіть ваш вік: ";
    cin >> vik;
    
    if (vik >= 0 && vik <= 1) {
        cout << "Немовля" << endl;
    } else if (vik >= 2 && vik <= 6) {
        cout << "Дитина дошкільного віку" << endl;
    } else if (vik >= 7 && vik <= 10) {
        cout << "Дитина молодшої школи" << endl;
    } else if (vik >= 11 && vik <= 15) {
        cout << "Підліток або дитина середньої школи" << endl;
    } else if (vik >= 16 && vik <= 17) {
        cout << "Старшокласник або юнак/юнка" << endl;
    } else if (vik >= 18 && vik <= 30) {
        cout << "Молода людина" << endl;
    } else if (vik >= 31 && vik <= 60) {
        cout << "Доросла людина" << endl;
    } else if (vik >= 61 && vik <= 79) {
        cout << "Літня людина" << endl;
    } else {
        cout << "Довгожитель (старше 80 років)" << endl;
    }



    return 0;
}
