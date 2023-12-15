#include <iostream>

int main() {
  int year;
  std::cout << "Enter any year to check if it is a leap year: ";
  std::cin >> year;
  
  if (year < 1000 or year > 9999) {
    std::cout << "ERROR\n";
  } else {
    int remainder_4 = year % 4;
    int remainder_100 = year % 100;
    int remainder_400 = year % 400;
    if (remainder_4 == 0) {
      if (remainder_100 == 0 and remainder_400 != 0) {
        std::cout << "This year is not a leap year\n";
      } else {
        std::cout << "This year is a leap year\n";
      }
    } else {
      std::cout << "This year is not a leap year\n";
    }
  }
}