#include <iostream>
using namespace std;
int main() {
    int number;

    while (true) 
    {
        // Display menu
        cout << "MENU"<<endl;
        cout << "1. Enter a number"<<endl;
        cout << "2. Exit"<<endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) 
        {
            case 1:
                // User enters a number
                cout << "Enter a number: ";
                cin >> number;

                // Count digits, calculate sum, average, and count zeros
                int countDigits = 0;
                int sum = 0;
                int zeroCount = 0;

                int tempNumber = number;
                while (tempNumber != 0) {
                    int digit = tempNumber % 10;
                    countDigits++;
                    sum += digit;
                    if (digit == 0) {
                        zeroCount++;
                    }
                    tempNumber /= 10;
                }

                // Calculate average
                double average = static_cast<double>(sum) / countDigits;

                // Display results
                cout << "Number of digits: " << countDigits << endl;
                cout << "Sum of digits: " << sum << endl;
                cout << "Average: " << average << endl;
                cout << "Number of zeros: " << zeroCount <<endl;
                break;

                case 2:
                // Exit the program
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;

                default:
                // Invalid choice
                cout << "Invalid choice. Please enter a valid option."<<endl;
        }
    }

    return 0;
}
