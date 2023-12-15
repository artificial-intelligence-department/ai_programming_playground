#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    //Генеруєм масив з випадкових чисел та друкуєм його
    vector<int> array;
    srand(time(0));
    for(int i = 0; i<n;i++)
    {
        array.push_back(rand() % 1000);
        cout<<array[i]<<" ";
    }

    cout<<"\n";
    //Обираєм номер числа який стерти
    int k;
    cin>>k;
    k-=1;
    //Стиражмо цей елемент
    auto it = array.begin()+k;
    array.erase(it);
    //Вставляємо нулі після кожного парного числа
    for(int na=2;na<array.size();na+=3)
    {
        it = array.begin()+na;
        array.insert(it,0);
    }
    //Друкуємо результат
    for(int i = 0; i<array.size();i++)
    {
        cout<<array[i]<<" ";
    }

    cout<<"\n";
}