//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//
//    int result[n][n];
//    for(int i=0; i<n; i++)
//    {
//        cin >> result[0][i];
//    }
//
//    for(int i=0; i<n; i++)
//    {
//        int counter = 1;
//        int k=1;
//        while(k<n-2)
//        {
//            result[k][i] = counter;
//            result[++k][i] = counter * (-1);
//            counter++;
//            k++;
//        }
//
//        if(n-k == 1)
//        {
//            result[k][i] = result[0][i];
//        } else {
//            result[k][i] = floor(result[0][i]/2);
//            result[k+1][i] = result[0][i] - floor(result[0][i]/2);
//        }
//    }
//
//
//    cout << endl;
//    for(int i=0; i<n; i++)
//    {
//        for(int j=0; j<n; j++)
//        {
//            cout << result[i][j] << ' ';
//        }
//        cout << endl;
//    }
//    return 0;
//}






#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int result[n][n];
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    for(int i=0; i<n; i++)
    {
        int counter = 1;
        int k=0;
        while(k<n-2)
        {
            result[k][i] = counter;
            result[++k][i] = counter * (-1);
            counter++;
            k++;
        }

        if(n-k == 1)
        {
            result[k][i] = arr[i];
        } else {
            result[k][i] = arr[i]/2;
            result[k+1][i] = arr[i] - arr[i]/2;
        }
    }

    cout << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}