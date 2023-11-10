#include <iostream>

using namespace std;

int main()
{

    int m,n ;
    cout<<"Enter m: ";
    cin>>m;
    cout<<"Enter n: ";
    cin>>n;
    
    //1) --m-++n
    cout << "First result: " << --m-++n << endl ; //Пояснення: (--m) - (++n) -> оскільки ++ та -- перед змінною, то виконується перед -, який між ними
    //2) m*n < n++
    bool res2 = m*n < n++;
    cout << "Second result: " << res2 << endl;    //Пояснення: (m*n) - (n++) -> Множення норм, а n++ зробиться вже після віднімання
    //3) n-- > m++ 
    bool res3 = n-- > m++;
    cout << "Third result: " << res3 << endl;     //Пояснення: (n--) > (m++) -> -- та ++ вже після порівняння


}