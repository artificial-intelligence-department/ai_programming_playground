#include <iostream>

int main() {
    //Вимога 2 - в коді використана як мінімум одна дійсна змінна (дійсні змінні зберігаються в масиві)
    //Вимога 6 - в коді використаний одновимірний масив (масив зберігає введені користувачем координати)
    float x[10], y[10];
    //Вимога 1 - в коді використана як мінімум одна цілочисельна змінна (змінні використовуються як лічильники для підрахунку точок, що відповідають певній умові)
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
    //Вимога 10 - в коді використаний for цикл (цикл використовується для ітеративного введення змінних)
    for(int i = 0; i < 10; i++) {
        std::cout << "Enter point number " << i + 1 << " : ";
        //Вимога 21 - в коді використано оператори виведення та введення даних (використано cin для вводу з консолі)
        std::cin >> x[i] >> y[i];
    }

    //Вимога 9 - в коді використаний while цикл (цикл while використано для перевірки належності кожної точки певній координатній чверті)
    int i = 0;
    while(i < 10) {
        //Вимога 5 - в коді використані умовні оператори та розгалуження (умовні оператори використані для перевірки належності точок координатним чвертям)
        if(x[i] >= 0 && y[i] >= 0) {
            count1++;
        }else if(x[i] <= 0 && y[i] >= 0) {
            count2++;
        }else if(x[i] <= 0 && y[i] <= 0) {
            count3++;
        }else if(x[i] >= 0 && y[i] <= 0){
            count4++;
        }else{
            //Вимога 11 - в коді використано оператори break і continue (оператор continue використовується для переходу до наступної ітерації циклу у разі неналежності точок жодній чверті)
            continue;
        }

        i++;
    }

    if(count1 >= count2 && count1 >= count3 && count1 >= count4) {
        std::cout << "Most points are concentrated in the first quarter";
    }else if(count2 >= count1 && count2 >= count3 && count2 >= count4) {
        std::cout << "Most points are concentrated in the second quarter";
    }else if(count3 >= count1 && count3 >= count2 && count3 >= count4) {
        std::cout << "Most points are concentrated in the third quarter";
    }else{
        std::cout << "Most points are concentrated in the fourth quarter";
    }

    return 0;
}