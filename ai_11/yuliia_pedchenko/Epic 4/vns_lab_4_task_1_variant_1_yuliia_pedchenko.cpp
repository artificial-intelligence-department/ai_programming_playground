// 1) Сформувати одновимірний масив цілих чисел, використовуючи генератор
// випадкових чисел.
// 2) Роздрукувати отриманий масив.
// 3) Знищити елемент із номером К.
// 4) Додати після кожного парного елемента масиву елемент зі значенням 0.
// 5) Роздрукувати отриманий масив
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int min = 3;
    int max = 10;

    srand(time(NULL));

    int num = min + rand() % (max - min + 1);
    // рандомізує кількість елементів в масиві. Оскільки функція rand() виводить дуже великі числа, я знайшла
    // формулу, яка встановить мінімальне і максимальне число, яке може вивести рандомайзер
    int a = num;

    int mass[a];

    min = 1;
    max = 50;

    for (int i = 0; i < a; i++)
    {
        mass[i] = min + rand() % (max - min + 1);
        cout << mass[i] << "  ";
    }
    cout << endl;
    // все те саме, що і зверху, лиш межі трохи інакші

    int k;       //номер елемента, який треба видалити
    cout << "Який елемент треба видалити?" << endl;
    cin >> k;

    if (k > a || k < 1)
    {
        cout << "Елементу з таким номером в цьому масиві немає";
        return 0;
    }
    int mass2[a - 1]; // вводимо новий масив з кількістю елементів а-1, адже один елемент ми видалимо
    k = k - 1;
    for (int i = 0; i < a; i++)
    {
        if (i < k)
        {
            mass2[i] = mass[i];
            cout << mass2[i] << "  ";
        }
        else if (i > k)
        {
            mass2[i - 1] = mass[i];
            cout << mass2[i - 1] << "  ";
        }  // до того, як цикл дійде до елементу k, ми прирівнюємо елементи нового масиву до відповідних в 
           // старому. Елемент k ми пропускаємо, а після нього прирівнюємо елементи нового масиву до попереднього 
           // елементу старого
    }
    cout << endl;
    
    int m;
    if ((a-1)%2==0) m = (a-1)*1.5;  //робимо перевірку. Якщо кількість елементів 2 масиву парна, то в фінальному
    else m = 1 + (a-2)*1.5;         //масиві кількість елементів буде більше за кількість елементів 2 на половину,
    int final_mass[m];              //тобто збільшена в 1.5 рази. Якщо кількість елементів непарна, то після
                                    //елементу 0 ставитись не буде, тож ми віднімаємо від кількості 1, множимо
                                    //на 1.5 і додаємо 1.
                          
    for (int j = 1; j <= m; j++) {          //для цього циклу мені легше було позначити за 1, адже далі я  
        int r = j/3;                        //я використовую формули. j не завжди ділиться націло на 3, але 
        if (j%3==0) final_mass[j-1]=0;      //тип даних int записує лиш цілочисельну частину, а мені це підходить.  
        else final_mass[j-1]=mass2[j-1-r];    //оскільки я позначила j за 1, то маю писати усюди в циклі j-1
        cout << final_mass[j-1] << "  ";
    }
    
    return 0;
}