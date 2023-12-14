#include <iostream>
#include <cmath>
using namespace std;

int main() {
   //завдання 1
    double price_notebook, price_cover, price, r, v, s, pi=3.14;
    int number;
    cout<<"Enter price of notebook: ";
    cin>>price_notebook;
    cout<<"Enter price of cover: ";
    cin>>price_cover;
    cout<<"Enter number: ";
    cin>>number;
    price = (price_notebook + price_cover)*number;
    cout<<price<<endl;

    //завдання 2
    cout<<"Enter radius: ";
    cin>>r;
    v = 0.75*pi*pow(r,3);
    s = 4*pi*pow(r,2);
    cout<<v<<endl;
    cout<<s<<endl;
    return 0;
}