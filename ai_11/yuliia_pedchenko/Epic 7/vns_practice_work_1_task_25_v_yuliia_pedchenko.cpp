#include <iostream>
#include <cmath>
using namespace std;
int main(){ 

double a,b;   // в коді використано декілька дійсних з подвійною точністю змінних
const float x=1.23; // в коді використано 2 дійсних константи
const float y=0.79;

// я не знаю, яке значення а і b я отримаю в кінці, тож нехай підрахунки
// проходять на типі даних double

//порахуємо спочатку а:

double undermodule;
undermodule = y + cbrt(pow(x,2));   // в коді використано математичні операції і функції

double module_value;
module_value = abs(pow(x,2)/(undermodule));

a = y + x/(pow(y, 3) + module_value);
cout << "a = " << a << endl;



// тепер порахуємо b:
double tg;
tg = tan(x/2);

b = 1 + pow(tg, 2);
cout << "b = " << b << endl;

return 0;
}