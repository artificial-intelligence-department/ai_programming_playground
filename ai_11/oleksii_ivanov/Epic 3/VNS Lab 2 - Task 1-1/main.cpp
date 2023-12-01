#include <iostream>
#include <cmath>
using std::cout, std::endl;
using SeriesElement = double(unsigned int);

/**
 * Evaluates an element of a series
 * @param n Index of an element
 * @return An element of a series
 */
double evalSeriesElement(unsigned int n) {
    if (n == 0) throw;
    return exp(-sqrt(n));
}

/**
 * Evaluates the sum of first
 * n elements of a series
 * @param element Delegate to calculate the element
 * @param n Count of elements
 */
double evalSumOfSeries(SeriesElement element, unsigned int n) {
    if (n == 0) return 0;

    double sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += element(i);

    return sum;
}

static const int count = 9;

/**
 * Lab 2 - Task 1
 * This code evaluates the sum
 * of the first n elements of the series
 */
int main() {
    cout << evalSumOfSeries(evalSeriesElement, count);
    return 0;
}
