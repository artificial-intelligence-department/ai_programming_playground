//Завдання 5. Наприкінці травня фірма формує звіт по заробітній
//платі N співробітників за весняний квартал.
//Написати програму, яка запитуватиме суму
//заробітної плати кожного співробітника за березень
//квітень, травень.Необхідно визначити :
//? виплату по кожному співробітнику за квартал;
//? загальну виплату по всім співробітникам за квартал.


#include <iostream>;
using namespace std;
int main() {
	int employees, march, april, may, sum_employees, quarter, k = 0, march_sum = 0, april_sum = 0, may_sum = 0;
	cout << "Enter the number of employees: " ;
	cin >> employees;
	for (int i = 1; i <= employees; i++)
	{
		sum_employees = 0;
		k += 1;
		for (int a = 0; a < 1; a++)
		{
			cout << "Employee |" << k << "| Enter the salary for March: ";
			cin >> march;
			march_sum += march;
			sum_employees += march;
		}
		for (int b = 0; b < 1; b++)
		{
			cout << "Employee |" << k << "| Enter the salary for April: ";
			cin >> april;
			april_sum += april;
			sum_employees += april;
		}
		for (int c = 0; c < 1; c++)
		{
			cout << "Employee |" << k << "| Enter the salary for May: ";
			cin >> may;
			may_sum += may;
			sum_employees += may;
		}
		cout << "Quarter per |" << k << "| employee: " << sum_employees << "$" << endl;
	}
	quarter = march_sum + april_sum + may_sum;
	cout << "Amount per quarter for all employees " << quarter << "$";


}
