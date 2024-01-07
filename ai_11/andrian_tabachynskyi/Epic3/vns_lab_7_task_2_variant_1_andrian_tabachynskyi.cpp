#include <iostream>
using namespace std;

int convert(int hours, int minutes) {
    return hours * 60 + minutes;
}

void convert(int totalMinutes, int& hours, int& remainingMinutes) {
    hours = totalMinutes / 60;
    remainingMinutes = totalMinutes % 60;
}

int main() {
    
    int hours = 2;
    int minutes = 30;
    int totalMinutes1 = convert(hours, minutes);

    std::cout << hours << " hours and " << minutes << " minutes is equal to " << totalMinutes1 << " minutes.\n";

    int totalMinutes2 = 170;
    int convertedHours, convertedMinutes;
    convert(totalMinutes2, convertedHours, convertedMinutes);

    std::cout << totalMinutes2 << " minutes is equal to " << convertedHours << " hours and " << convertedMinutes << " minutes.\n";

    return 0;
}
