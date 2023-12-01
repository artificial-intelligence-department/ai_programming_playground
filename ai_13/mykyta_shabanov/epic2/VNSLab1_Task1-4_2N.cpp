/*
    #TASK 4.2 var.4
*/

#include <iostream>

int main()
{
    using namespace std;
    float n, m;

        //prompting
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;

        //calculating
    float result_1 = n++ * m;
    bool
        result_2 = n++ < m,
        result_3 = m-- > m;

        //output
    cout << endl 
        << "1) " << result_1 << endl
        << "2) " << (result_2 == true ? "true" : "false") << endl
        << "3) " << (result_3 == true ? "true" : "false")
        << endl;

    return 0;
}