//
// Created by olehio-p on 12/10/2023.
//
#include <iostream>

void translateMinutesIntoHoursAndMinutes(int, int*);

int main(int argc, char const *argv[])
{
    int timeInterval = 0;
    int result[2];

    std::cout << "Please enter the time interval (in minutes): ";
    std::cin >> timeInterval;

    translateMinutesIntoHoursAndMinutes(timeInterval, result);
    printf("%d minutes is: %d h. %d min\n", timeInterval, result[0], result[1]);

    return 0;
}

void translateMinutesIntoHoursAndMinutes(int timeInterval, int* result) {
    int hours, minutes;
    hours = timeInterval / 60;
    minutes = (timeInterval - hours * 60) % 60;

    result[0] = hours;
    result[1] = minutes;
}