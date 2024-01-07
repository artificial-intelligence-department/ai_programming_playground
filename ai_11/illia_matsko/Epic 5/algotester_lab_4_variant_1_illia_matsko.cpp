#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print(vector<int>& vector)
{
    for(int i=0; i<vector.size(); i++)
    {
        cout << vector[i] << ' ';
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int arr1[n];
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;
    int arr2[m];
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+m);

    vector<int> result;
    set_difference(arr1, arr1+n, arr2, arr2+m, back_inserter(result));
    cout << result.size() << endl;
    print(result);

    result.clear();
    set_difference(arr2, arr2+m, arr1, arr1+n, back_inserter(result));
    cout << result.size() << endl;
    print(result);

    result.clear();
    set_intersection(arr1, arr1+n, arr2, arr2+m, back_inserter(result));
    cout << result.size() << endl;
    print(result);

    result.clear();
    set_union(arr1, arr1+n, arr2, arr2+m, back_inserter(result));
    cout << result.size() << endl;
    print(result);

    result.clear();
    set_symmetric_difference(arr1, arr1+n, arr2, arr2+m, back_inserter(result));
    cout << result.size() << endl;
    print(result);

    return 0;
}






//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//void print(vector<int>& vector)
//{
//    for(int i=0; i<vector.size(); i++)
//    {
//        if(vector[i] >= 0)
//        {
//            cout << vector[i] << ' ';
//        }
//    }
//    cout << endl;
//}
//
//int min(vector<int>& minus1, vector<int>& minus2, int n, int m, vector<int>& intersection)
//{
//    int counter = 0;
//    for(int i=0; i<n; i++)
//    {
//        for(int j=0; j<m; j++)
//        {
//            if(minus1[i] == minus2[j])
//            {
//                intersection.push_back(minus1[i]);
//                minus1[i] = -1;
//                minus2[j] = -1;
//                counter++;
//                break;
//            }
//        }
//    }
//
//    sort(begin(minus1), end(minus1));
//    sort(begin(minus2), end(minus2));
//    return counter;
//}
//
//void unite(vector<int>& united, int n)
//{
//    vector<int> buffer;
//
//    for(int i=0; i<n; i++)
//    {
//        for(int j=0; j<n; j++)
//        {
//            if(i!=j && united[i] == united[j] && united[i] != -1)
//            {
//                buffer.push_back(united[i]);
//                united[i] = -1;
//                united[j] = -1;
//                n--;
//            }
//        }
//    }
//
//    for(int i=0; i<buffer.size(); i++)
//    {
//        united.push_back(buffer[i]);
//    }
//    sort(begin(united), end(united));
//
//    cout << n << endl;
//}
//
//int main()
//{
//    vector<int> minus1;
//    vector<int> minus2;
//    vector<int> intersection;
//    vector<int> united;
//    vector<int> symmetricalDif;
//
//    int n;
//    cin >> n;
//    int arr1[n];
//    for(int i=0; i<n; i++)
//    {
//        cin >> arr1[i];
//        minus1.push_back(arr1[i]);
//        united.push_back(arr1[i]);
//    }
//
//    int m;
//    cin >> m;
//    int arr2[m];
//    for(int i=0; i<m; i++)
//    {
//        cin >> arr2[i];
//        minus2.push_back(arr2[i]);
//        united.push_back(arr2[i]);
//    }
//
//    int size = min(minus1, minus2, n, m, intersection);
//
//    cout << size << endl;
//    print(minus1);
//
//    cout << size << endl;
//    print(minus2);
//
//    cout << size << endl;
//    print(intersection);
//
//
//    unite(united, n+m);
//    print(united);
//
//    for(int i=0; i<n; i++)
//    {
//        if(minus1[i] >= 0)
//        {
//            symmetricalDif.push_back(minus1[i]);
//        }
//    }
//    for(int i=0; i<m; i++)
//    {
//        if(minus2[i] >= 0)
//        {
//            symmetricalDif.push_back(minus2[i]);
//
//        }
//    }
//    cout << symmetricalDif.size() << endl;
//    print(symmetricalDif);
//
//    return 0;
//}

/*==============================================================================================================*/
/*==============================================================================================================*/
/*==============================================================================================================*/
/*==============================================================================================================*/
/*==============================================================================================================*/
/*==============================================================================================================*/
/*==============================================================================================================*/


//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//using namespace std;
//
//void generateRandomArray(int arr[], int& size, int maxSize, int maxElement) {
//    size = rand() % maxSize + 1;
//    for (int i = 0; i < size; ++i) {
//        arr[i] = rand() % maxElement + 1;
//    }
//}
//
//int subtractAndIntersect(vector<int>& minus1, vector<int>& minus2, int n, int m, vector<int>& intersection)
//{
//    int counter = 0;
//    for(int i=0; i<n; i++)
//    {
//        for(int j=0; j<m; j++)
//        {
//            if(minus1[i] == minus2[j])
//            {
//                intersection.push_back(minus1[i]);
//                minus1[i] = -1;
//                minus2[j] = -1;
//                counter++;
//                break;
//            }
//        }
//    }
//
//    sort(begin(minus1), end(minus1));
//    sort(begin(minus2), end(minus2));
//
//    return counter;
//}
//
//void unite(int arr1[], int n, int arr2[], int m, vector<int>& united)
//{
//    vector<int> buffer;
//    int counter = 0;
//
//    for(int i=0; i<n; i++)
//    {
//        for(int j=0; j<m; j++)
//        {
//            if(united[i] == united[n+j])
//            {
//                buffer.push_back(arr1[i]);
//                united[i] = -1;
//                united[n+j] = -1;
//                counter++;
//                break;
//            }
//        }
//    }
//
//    for(int i=0; i<buffer.size(); i++)
//    {
//        united.push_back(buffer[i]);
//    }
//    sort(begin(united), end(united));
//}
//
//void printArray(const int arr[], int size) {
//    for (int i = 0; i < size; ++i) {
//        cout << arr[i] << ' ';
//    }
//    cout << endl;
//}
//
//int main() {
//    for(int l=0; l<500; l++)
//    {
//        cout << "Test #" << l+1 << endl;
//        srand(static_cast<unsigned>(time(nullptr)));
//
//        int array1[100], array2[100];
//        int n, m;
//
//        generateRandomArray(array1, n, 100, 100);
//        generateRandomArray(array2, m, 100, 100);
//
////        cout << n << endl;
////        printArray(array1, n);
////
////        cout << m << endl;
////        printArray(array2, m);
//
//
//
//
//
//
//
//        vector<int> minus1;
//        vector<int> minus2;
//        vector<int> intersection;
//        vector<int> united;
//        vector<int> symmetricalDifference;
//        int arr1[n];
//        for(int i=0; i<n; i++)
//        {
//            arr1[i] = array1[i];
//            minus1.push_back(arr1[i]);
//            united.push_back(arr1[i]);
//        }
//        int arr2[m];
//        for(int i=0; i<m; i++)
//        {
//            arr2[i] = array2[i];
//            minus2.push_back(arr2[i]);
//            united.push_back(arr2[i]);
//        }
//
//        subtractAndIntersect(minus1, minus2, n, m, intersection);
//        int newMinus1Size = 0;
//        sort(begin(minus1), end(minus1));
//        for(int i=0; i<minus1.size(); i++)
//        {
//            if(minus1[i] < 0)
//            {
//                newMinus1Size++;
//            }
//        }
//        int newMinus2Size = 0;
//        sort(begin(minus2), end(minus2));
//        for(int i=0; i<minus2.size(); i++)
//        {
//            if(minus2[i] < 0)
//            {
//                newMinus2Size++;
//            }
//        }
//        int newIntersectionSize = 0;
//        sort(begin(intersection), end(intersection));
//        for(int i=0; i<intersection.size(); i++)
//        {
//            if(intersection[i] < 0)
//            {
//                newIntersectionSize++;
//            }
//        }
//
//
//        unite(arr1, n, arr2, m, united);
//        int newUnitedSize = 0;
//        sort(begin(united), end(united));
//        for(int i=0; i<united.size(); i++)
//        {
//            if(united[i] < 0)
//            {
//                newUnitedSize++;
//            }
//        }
//
//        for(int i=0; i<n; i++)
//        {
//            if(minus1[i] >= 0)
//            {
//                symmetricalDifference.push_back(minus1[i]);
//            }
//        }
//        for(int i=0; i<m; i++)
//        {
//            if(minus2[i] >= 0)
//            {
//                symmetricalDifference.push_back(minus2[i]);
//            }
//        }
//        int newSymDifSize = 0;
//        sort(begin(symmetricalDifference), end(symmetricalDifference));
//        for(int i=0; i<symmetricalDifference.size(); i++)
//        {
//            if(symmetricalDifference[i] < 0)
//            {
//                newSymDifSize++;
//            }
//        }
//
//
//
//
//
//
//
//        sort(array1, array1+n);
//        sort(array2, array2+m);
//
//        vector<int> result;
//        set_difference(array1, array1+n, array2, array2+m, back_inserter(result));
//
//        for(int i=0; i<result.size(); i++)
//        {
//            if(result[i] != minus1[newMinus1Size + i])
//            {
//                cout << endl << endl << "ERROR in minus1" << endl;
//                cout << "STL: " << endl;
//                for(int j=0; j<result.size(); j++)
//                {
//                    cout << result[j] << ' ';
//                }
//                cout << endl << "My: " << endl;
//                for(int j=0; j<minus1.size(); j++)
//                {
//                    cout << minus1[j] << ' ';
//                }
//                break;
//            }
//        }
//
//        result.clear();
//        set_difference(array2, array2+m, array1, array1+n, back_inserter(result));
//
//        for(int i=0; i<result.size(); i++)
//        {
//            if(result[i] != minus2[newMinus2Size + i])
//            {
//                cout << endl << endl << "ERROR in minus2" << endl;
//                cout << "STL: " << endl;
//                for(int j=0; j<result.size(); j++)
//                {
//                    cout << result[j] << ' ';
//                }
//                cout << endl << "My: " << endl;
//                for(int j=0; j<minus2.size(); j++)
//                {
//                    cout << minus2[j] << ' ';
//                }
//                break;
//            }
//        }
//
//        result.clear();
//        set_intersection(array1, array1+n, array2, array2+m, back_inserter(result));
//
//        for(int i=0; i<result.size(); i++)
//        {
//            if(result[i] != intersection[newIntersectionSize + i])
//            {
//                cout << endl << endl << "ERROR in intersection" << endl;
//                cout << "STL: " << endl;
//                for(int j=0; j<result.size(); j++)
//                {
//                    cout << result[j] << ' ';
//                }
//                cout << endl << "My: " << endl;
//                for(int j=0; j<intersection.size(); j++)
//                {
//                    cout << intersection[j] << ' ';
//                }
//                break;
//            }
//        }
//
//        result.clear();
//        set_union(array1, array1+n, array2, array2+m, back_inserter(result));
//
//        for(int i=0; i<result.size(); i++)
//        {
//            if(result[i] != united[newUnitedSize + i])
//            {
//                cout << endl << endl << "ERROR in united" << endl;
//                cout << "STL: " << endl;
//                for(int j=0; j<result.size(); j++)
//                {
//                    cout << result[j] << ' ';
//                }
//                cout << endl << "My: " << endl;
//                for(int j=0; j<united.size(); j++)
//                {
//                    cout << united[j] << ' ';
//                }
//                break;
//            }
//        }
//
//        result.clear();
//        set_symmetric_difference(array1, array1+n, array2, array2+m, back_inserter(result));
//
//        for(int i=0; i<result.size(); i++)
//        {
//            if(result[i] != symmetricalDifference[newSymDifSize + i])
//            {
//                cout << endl << endl << "ERROR in symmetrical" << endl;
//                cout << "STL: " << endl;
//                for(int j=0; j<result.size(); j++)
//                {
//                    cout << result[j] << ' ';
//                }
//                cout << endl << "My: " << endl;
//                for(int j=0; j<symmetricalDifference.size(); j++)
//                {
//                    cout << symmetricalDifference[j] << ' ';
//                }
//                break;
//            }
//        }
//    }
//
//    return 0;
//}