// Зеник-шахрай
#include <iostream>

using namespace std;

struct Page
{
    int MarksCount = 0;
    int MarksSum = 0;
};

int main()
{   
    int pages, mark;
    double average = 0, nextAverage;
    int totalSum = 0, totalMarksCount = 0;

    if (!(cin >> pages && pages > 0))
    {
        cout << "Wrong input!\n";
        return 1;
    }

    Page diary[pages];

    for (int i = 0; i < pages; i++)
    {
        if (!(cin >> diary[i].MarksCount && diary[i].MarksCount > 0))
        {
            cout << "Wrong input!\n";
            return 1;
        }

        for (int j = 0; j < diary[i].MarksCount; j++)
        {
            if (!(cin >> mark && mark > 0 && mark < 13))
            {
                cout << "Wrong input!\n";
                return 1;
            }

            diary[i].MarksSum += mark;
        }

        totalSum += diary[i].MarksSum;
        totalMarksCount += diary[i].MarksCount;
        nextAverage = (double) totalSum / totalMarksCount;

        if (average < nextAverage)
        {
            average = nextAverage;
        }
    }


    for(int i = 0; i < pages - 1; i++)
    {
        totalSum -= diary[i].MarksSum;
        totalMarksCount -= diary[i].MarksCount;

        nextAverage = (double) totalSum / totalMarksCount;

        if (average < nextAverage)
        {
            average = nextAverage;
        }
    }

    printf("%.6f", average);

    return 0;
}
