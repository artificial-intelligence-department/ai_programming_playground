#include <iostream>
#include <iomanip>

using namespace std;
//Оголошуємо функцію, яка буде автоматично записувати у ввід
//Символ "\e[1m", що означає увімкнення виводу тексту напівжирним шрифтом
ostream& bold_on(ostream& os)
{
    return os << "\e[1m";
}
//Оголошуємо функцію, яка буде автоматично записувати у ввід
//Символ "\e[0m", що означає вимкнення виводу тексту напівжирним шрифтом
ostream& bold_off(ostream& os)
{
    return os << "\e[0m";
}

int main() 
{
    //оголошення змінних внеску та проценту типу double
    double principal,rate; // для обрахунку з плаваючою точкою
    

    int days; //Оголошення кількості днів позики

    //Ввід Даних
    cout << "Input the amount of contribution: ";
    cin >> principal;

    cout << "Enter the interest rate per year: ";
    cin >> rate;

    cout << "Enter the number of days: ";
    cin >> days;
    //Обрахунок прибутку
    double interest = (principal * rate * days) / (365 * 100);
    //Обрахунок загальної суми після зняття коштів з депозиту
    double sum = interest+principal; 

    // Виведення результату
    //Визначення чіткості виводу даних з плаваючою точкою з точністю до двох знаків після коми
    cout << fixed << setprecision(2); 
    cout << "\n===========================================\n";
                                    //тут включення|        |та виключення напівжирного шрифту
    cout << "  Contribution amount:    " << bold_on << principal << bold_off << " grn\n";
    cout << "  Interest rate per year: " << bold_on << rate << bold_off << " %\n";
    cout << "  Number of days:         " << bold_on << days << bold_off << " days\n";
    cout << "-------------------------------------------\n";
    cout << "  Income:                 "  << interest <<  " grn\n";
    cout << "  The amount after the:   "  << sum << " grn\n";
    std::cout << "===========================================\n";

    return 0;
}
