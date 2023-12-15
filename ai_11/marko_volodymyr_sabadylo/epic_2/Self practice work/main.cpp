#include <iostream>
#include <fcntl.h>

using namespace std;

int main() {
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

    wchar_t oper;
    double a, b;
    wcout << L"Введіть операцію (+, -, *, /): ";
    wcin >> oper;
    wcout << L"Введіть два числа: ";
    wcin >> a >> b;
    switch(oper) {
        case L'+':
            wcout << L"Результат: " << a + b;
            break;
        case L'-':
            wcout << L"Результат: " << a - b;
            break;
        case L'*':
            wcout << L"Результат: " << a * b;
            break;
        case L'/':
            if (b != 0) {
                wcout << L"Результат: " << a / b;
            } else {
                wcout << L"Ділення на нуль неможливе.";
            }
            break;
        default:
            wcout << "Невірна операція! Будь ласка, введіть коректну операцію.";
            break;
    }
    return 0;

}