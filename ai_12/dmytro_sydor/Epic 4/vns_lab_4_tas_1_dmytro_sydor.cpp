#include <iostream>

using namespace std;
void rightLoop(int *pArr, int realLen, int k);
void leftLoop(int *pArr, int realLen, int k);

int main()
{
    int N = 100;
    int *arr = new int[N];
    int realLen;

realLen:
    cout << "Введіть реальну довжину (<= 100): ";
    cin >> realLen;

    if (realLen < 3)
    {
        cout << "Неможливо видалити елементи для такого малого масиву , введіть довжину >=3" << endl;
        goto realLen;
    }

    int K;
    cout << "Введіть починаючи з якого елементу ви хочете вивести двонапрямлене кільце: " << endl;
    cin >> K;

    for (int i = 0; i < realLen; i++)
    {
        arr[i] = i + 1;
    }

    rightLoop(arr, realLen, K);

    leftLoop((arr + 1), (realLen - 2), K);

    return 0;
}

void rightLoop(int *pArr, int realLen, int k)
{
    cout << " Right Loop: \t";

    for (int i = k - 1; i < realLen; i++)
    {
        cout << *(pArr + i) << " ";
        if (i == (realLen - 1))
        {
            for (int i = 0; i < k - 1; i++)
            {
                cout << *(pArr + i) << " ";
            }
        }
    }
    cout << endl;
}

void leftLoop(int *pArr, int realLen, int k)
{
    cout << " Left loop: \t";

    for (int i = k - 2; i >= 0; i--)
    {
        cout << *(pArr + i) << " ";
    }

    for (int i = realLen - 1; i >= k - 1; i--)
    {
        cout << *(pArr + i) << " ";
    }

    cout << endl;
}
