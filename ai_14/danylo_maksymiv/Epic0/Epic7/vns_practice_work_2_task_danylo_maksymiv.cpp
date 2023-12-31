#include <iostream>                                                                        
#include <cmath>         
using namespace std;            //інклудим модулі потоку вводу/виводу, математичний модуль і неймспейс стд щоб не писати std::

int main()
{
    const double a = 1.7,b=2.3; // ініціалізую змінні
    double z;

    for(double x=-1,y=-2;x<=1;x+=0.9,y+=1)          //поки x<=1(так склалось через особливість умови(діапазон у -більший за х)) х збільшується на 0.9,у на 1 
    {
        double temp = sqrt(a*pow(x,2))+b*pow(y,3);      /* обчислюєм підкореневе значення(без цього не обійтись,у іншому випадку цикл буде 
                                                            виводити nan перші дві ітерації,навіть якщо умова не буде заходити на )*/
       
        z=((x*y)<=0 || temp <= 0) ? pow(a,x)+pow(b,y) : log(temp);  /*якщо ху<=0 або підкореневий вираз <=0 то z приймає 
                                                                    значення a^x+b^y,інакше обчислюється ln з підкореневого виразу */
        
        cout<<"x="<< x <<", y="<< y <<", z="<<z<<endl;       // виводим значення змінних на екран під час кожної ітерації
    }
}