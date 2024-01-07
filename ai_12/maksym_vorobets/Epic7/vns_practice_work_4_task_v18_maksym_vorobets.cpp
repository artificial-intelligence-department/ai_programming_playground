#include <iostream> //дозволяє використовувати виведення(cout) і введеня(cin)
#include <iomanip> //надає інструменти для форматування введення та виведення 

using namespace std;

int main(){
    int start=100, finish=1000; //задаю змінні типу int їх значення
    double price=26.5,  cost; //задаю змінні типу double
    cout<<setw(10)<<"Weigt"<<setw(15)<<"Cost"<<endl; //виводжу основу таблички з маніпулятором setw для відступу один від одного
    for (int i = start; i <= finish; i+=100) //використовую цикл for для розв'язання послідовності
    {
        cost=price*i/finish;
        cout<<setw(10)<<i<<setw(15)<<cost<<endl;//виводимо результат також з маніпулчтором setw
    }
    
return 0;
}