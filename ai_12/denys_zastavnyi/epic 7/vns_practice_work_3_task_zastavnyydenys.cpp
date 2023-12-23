#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main() {
    double R1, R2;
    const int minResistanceValue = 15; // 4. в коді використана як мінімум одна цілочисельна константа

    do {
        cout << "Enter the value of the first resistance (Ohm) (more than 15): ";
        cin >> R1;
    } while (R1 <= 15);

    do {
        cout << "Enter the value of the second resistance (Ohm) (more than 27.3): ";
        cin >> R2;
    } while (R2 <= 27.3);

    // Розрахунок опору ланцюга при паралельному з'єднанні
    double totalResistance = 1 / (1 / R1 + 1 / R2);

    cout << "Circuit resistance in parallel connection: " << totalResistance << " ohm" << endl;

    return 0;
      ofstream outputFile("output.txt"); // 16. в коді використано функції роботи з файлами, для того, щоб записати у файл
    if (outputFile.is_open()) {
        outputFile << "Circuit resistance in parallel connection: " << totalResistance << " ohm" << endl;
        outputFile.close();
        cout << "The results were written to a file 'output.txt'" << endl;
    } else {
        cout << "Error opening file for writing." << endl;
    }


}
