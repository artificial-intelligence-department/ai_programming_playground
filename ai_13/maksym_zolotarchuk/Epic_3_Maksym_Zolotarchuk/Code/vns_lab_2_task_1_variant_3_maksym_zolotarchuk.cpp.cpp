#include <iostream>
#include <cmath>
#include <cwchar>
#include <Windows.h>
using namespace std;

int main() {
setlocale(LC_ALL, "ukr");
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
int sum = 0;

for (int i = 1; i < 200; i += 2) {

  sum += i;
}

wprintf(L"Сума всіх непарних чисел менше 200: %ld " , sum);

return 0;

}