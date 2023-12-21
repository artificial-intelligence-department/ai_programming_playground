#include <iostream>
#include <cstdarg>
#include <iomanip>
#include <vector>
#include <sstream>

using namespace std;

int amountOfDaysBetweenDates(char *date1, char *date2)
{

    tm tm1 = {0};
    tm tm2 = {0};
    istringstream stream1(date1);
    stream1 >> get_time(&tm1, "%d.%m.%y");
    time_t time1 = mktime(&tm1);
    istringstream stream2(date2);
    stream2 >> get_time(&tm2, "%d.%m.%y");
    time_t time2 = mktime(&tm2);
    double d = difftime(time2, time1);

    return int(d) / (24 * 60 * 60);
}

void days(int k, ...)
{
    if (k < 2)
    {
        return;
    }
    vector<char*> dates;
    va_list args;
    va_start(args, k);
    for (int i = 0; i < k; i++)
    {
        dates.push_back(va_arg(args, char *));
    }
    va_end(args);

    for (int a = 0; a < k - 1; a++)
    {
        cout << amountOfDaysBetweenDates(dates.at(a), dates.at(a + 1)) << " ";
    }
    cout << endl;
}

int main()
{
    days(2, "06.10.23", "18.10.24");
    days(4, "16.10.23", "18.10.23", "16.11.23", "18.11.23");
    days(7, "16.10.23", "18.10.23", "16.11.23", "18.11.23", "16.12.23", "18.12.23", "24.12.23");
    return 0;
}
