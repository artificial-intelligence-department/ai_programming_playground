#include<iostream>
#include<random>//підключаємо бібліотеку для генерації випадкових чисел
#include<time.h>//підключаємо цю бібліотеку для того щоб використовувати час як сід для рандому
using namespace std;

int main(){
    int nums[2][5];//двовимірний масив у якому зберігаємо числа
    double sum = 0;
    srand(time(0));//сід рандому

    for(int i=0;i<2;i++){// в циклі одразу створюємо число, виводимо його на екран і рахуємо суму  
        for(int j=0;j<5;j++){
            nums[i][j]=rand()%10 + 1;
            cout<<nums[i][j]<<" ";
            sum += nums[i][j];
        }
    }

    cout<<"\narithmetic mean of this sequence: "<<sum/10;//виводимо середнє арифметичне
   
}