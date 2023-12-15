//
// Created by olehio-p on 11/29/2023.
//
#include <iostream>


int main(int argc, char const *argv[])
{
    const int n = 3, m = 3;
    int array[n][m] = {{1, 2, 3},
                       {4, 5, 6},
                       {7, 8, 9}};

    int average;
    int prev_average;
    int numOfElemsGtAvgInPrevCol;
    int counter;
    for(int i = 0; i < n; i++) {
        prev_average = average;
        average = 0;
        counter = 0;
        numOfElemsGtAvgInPrevCol = 0;
        for(int j = 0; j < m; j++) {
            average += array[j][i];
            counter++;
            if(i != 0 && array[j][i] > prev_average) {
                numOfElemsGtAvgInPrevCol++;
            }
        }
        average /= counter;
        if(i == 0) {
            std::cout << "The average of the first column: " << average << std::endl;
        } else {
            std::cout << "Number of elems greater than average in previous column: "
                      << numOfElemsGtAvgInPrevCol << std::endl;
        }
    }
    return 0;
}
