#include <iostream>
using namespace std;

int main()
{
// Ініціалізація змінних для ціни зошита, ціни обкладинки та кількості зошитів
    double price_note = 0;

    // Цикл для введення ціни зошита (повинна бути більше 2.75)
    while(price_note < 2.75)
    {
        cout<<" Enter a price of notebook(price > 2.75): ";
        cin>> price_note;
    }
    double price_of_cover_note = 0;

    // Цикл для введення ціни обкладинки зошита (повинна бути більше 0.5)
    while(price_of_cover_note < 0.5)
    {
        cout<<"Enter a price of cover of notebook(price > 0.5): ";
        cin>> price_of_cover_note;
    }
    int count = 0;
    // Цикл для введення кількості зошитів (повинна бути більше 7)
    while(count < 7)
    {
        cout<<"Enter count of notebooks ";
        cout<< "\n (count > 7): ";
        cin>> count;
    }
    // Виведення загальної вартості покупки
    cout <<"Purchase price: "<<(price_note +price_of_cover_note) * count<<endl;

    return 0;// Повертаємо 0 для позначення успішного виконання програми

}