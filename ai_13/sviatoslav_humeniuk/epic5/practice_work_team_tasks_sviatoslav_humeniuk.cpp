#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main() {
    time_t t = time(0);    // Отримання поточного часу
    tm* now = localtime(&t);

    char tme[20];    // Форматування часу

    strftime(tme, 20, "%Y-%m-%d %H:%M:%S", now);

    ofstream file("F1.txt");    // Запис часу у файл
    
    if (file.is_open()) {
        file << tme;
        file.close();
        cout << "success" << endl;
    } else {
        cout << "fail" << endl;
    }

    return 0;
}
