#include <iostream>
#include <fstream>

using namespace std;

int main() {
    const int minResistanceValue = 15; // 4. в коді використана як мінімум одна цілочисельна константа

    double R1, R2;
   // 8. в коді використаний do while цикл
 do {
    cout << "Enter the value of the first resistance (Ohms) (greater than " << minResistanceValue << "): ";
    cin >> R1;
} while (R1 <= 15);
do {
    cout << "Enter the value of the second resistance (Ohms) (greater than 27.3): ";
    cin >> R2;
    } while (R2 <= 27.3);

    double totalResistance = 1 / (1 / R1 + 1 / R2);
    // Creating and using a file
    ofstream outputFile("output.txt"); // 16. в коді використано функції роботи з файлами, для того, щоб записати у файл
    if (outputFile.is_open()) {
        outputFile << "Circuit resistance in parallel connection: " << totalResistance << " Ohms" << endl;
        outputFile.close();
        cout << "The results have been written to the 'output.txt' file." << endl;
    } else {
        cout << "Error opening the file for writing." << endl;
    }

    return 0;
}
