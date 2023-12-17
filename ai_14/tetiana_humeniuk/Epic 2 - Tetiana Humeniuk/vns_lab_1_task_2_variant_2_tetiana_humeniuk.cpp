<<<<<<< HEAD
#include <iostream>
using namespace std;
int main()
{
    cout<<"enter two numbers  with gap:\n";
    int n;
    int m;
    cin>>n>>m;
    cout<<(++n*++m)<<endl;
    cout<<(m++<n)<<endl;
    cout<<(n++>m);
    return 0;
}
=======
#include <iostream>
using namespace std;
int main()
{
    cout<<"enter two numbers  with gap:\n";
    int n;
    int m;
    cin>>n, m;
    cout<<(++n*++m)<<endl;
    cout<<(m++<n)<<endl;
    cout<<(n++>m);
    return 0;
}
>>>>>>> 752bdc72e3aee37bfd7b872441d591f34f62d552
