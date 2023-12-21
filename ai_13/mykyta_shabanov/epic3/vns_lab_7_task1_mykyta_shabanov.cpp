#include <iostream>
#include <cstdarg>
using namespace std;


int findMinNum(int n, ...) {


    va_list args;
    va_start(args, n);


    int min = va_arg(args, int);


    for (int i = 1; i < n; ++i) {
        int minTemp = va_arg(args, int);
        if (minTemp < min) {
            min = minTemp;
        }
    }


    va_end(args);


    return min;
}


int main()
{
    int howManyNums;
    cout << "Enter how many nums you want to enter: ";
    cin >> howManyNums;


    int fiveNums[5], ten_nums[10], twelveNums[12], minNum;
    if(howManyNums == 5)
    {
        cout << "Enter 5 numbers: ";
        for (int i = 0; i < 5; i++)
            cin >> fiveNums[i];
       
        minNum = findMinNum(5, fiveNums[0], fiveNums[1], fiveNums[2], fiveNums[3], fiveNums[4]);
    } else
    if(howManyNums == 10)
    {
        cout << "Enter 10 numbers: ";
        for (int i = 0; i < 10; i++)
            cin >> ten_nums[i];


        minNum = findMinNum(10, ten_nums[0], ten_nums[1], ten_nums[2], ten_nums[3], ten_nums[4], ten_nums[5], ten_nums[6], ten_nums[7], ten_nums[8], ten_nums[9]);
    } else
    if(howManyNums == 12)
    {
        cout << "Enter 12 numbers: ";
        for (int i = 0; i < 12; i++)
            cin >> twelveNums[i];


        minNum = findMinNum(12, twelveNums[0], twelveNums[1], twelveNums[2], twelveNums[3], twelveNums[4], twelveNums[5], twelveNums[6], twelveNums[7], twelveNums[8], twelveNums[9], twelveNums[10], twelveNums[11]);
    } else
    {
        cout << "wrong input";
        return 0;
    }


    cout << "Minimal number is: " << minNum << endl;


    return 0;
}
