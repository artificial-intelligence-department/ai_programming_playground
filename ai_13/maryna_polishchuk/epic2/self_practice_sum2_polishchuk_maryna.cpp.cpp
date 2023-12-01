//Користувач вводить числа поки не введе нуль. 
//Задача: обчислити суму всіх елементів, середнє арифметичне парних елементів.


#include <iostream>


int main()
{
    int sum=0; // сума усіх елементів 
    int evenSum=0; //сума арних елементів 
    double quan=0; //кількість парних елементів
    double ArifMean; //середнє арифметичне парних елементів

    while (true)
    {
        int m;
        std::cout <<"enter num: ";
        std::cin >> m;
        
        if(m%2==0)
        {
          evenSum+=m; 
          quan++;
        } 

        sum+=m;

        if (m==0)
        {
            quan--;
            ArifMean= evenSum/quan;
            std:: cout << "arithmetical mean: " <<ArifMean << std::endl;
            std:: cout << "Sum of elements: " <<sum;
            return 0;
        }

    }

    return 0;
}