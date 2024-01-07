#include <iostream>

using namespace std;

int main() {
    // Declaration of variables to store voltage and resistance
    double voltage, resistance;

    // Input voltage from the user
    cout << "Calculation of current in an electric circuit.\n";
    cout << "Enter initial data:\n";

    cout << "Voltage (volts) > ";
    cin >> voltage;

    // Input resistance from the user
    cout << "Resistance (ohms) > ";
    cin >> resistance;

    // Calculate current using Ohm's Law: I = U / R
    double current = voltage / resistance;

    // Output the result
    cout << "Current: " << current << " Amperes.\n";

    return 0;
}