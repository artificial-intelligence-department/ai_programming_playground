//Компресія стрічки
#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    getline(cin, line);

    if (line.length() == 1) { 
        cout << line;
        return 0;
    }

    if (line.length() >= 10e5) {
        return 0;
    }

    int count = 1;
    char lat = line[0];

    for (int i = 1; i < line.length() + 1; i++) { // Додаємо одиничку до довжини слова, оскільки індексація елементів масиву починається з нуля
        if (line[i] == lat) {
            count++;
        } else {
            cout << lat << (count > 1 ? to_string(count) : "");
            lat = line[i];
            count = 1;
        }
    }
 
    return 0;
}
