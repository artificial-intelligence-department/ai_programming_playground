#include <iostream>

using namespace std;

int main() {
  double deposit, interest, total;
  int term;
  double annualInterest;

  // ввід необхідних даних
  cout << "Enter initial data: " << endl;
  cout << "Deposit amount: ";
  cin >> deposit;
  cout << "Term (days): ";
  cin >> term;
  cout << "Annual interest rate (in %): ";
  cin >> annualInterest;

  // обчислення
  interest = deposit * annualInterest / 100 * term / 365;
  total = deposit + interest;

  // вивід результату
  cout << "Interest: " << interest << " UAN" << endl;
  cout << "Total amount after the term: " << total << " UAH" << endl;

  return 0;
}
