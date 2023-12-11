#include <iostream>
using namespace std;

int main()
{

    double price_note = 0;
    while(price_note < 2.75)
    {
        cout<<" Enter a price of notebook(price > 2.75): ";
        cin>> price_note;
    }
    double price_of_cover_note = 0;
    while(price_of_cover_note < 0.5)
    {
        cout<<"Enter a price of cover of notebook(price > 0.5): ";
        cin>> price_of_cover_note;
    }
    int count = 0;
    while(count < 7)
    {
        cout<<"Enter count of notebooks ";
        cout<< "\n (count > 7): ";
        cin>> count;
    }
    cout <<"Purchase price: "<<(price_note +price_of_cover_note) * count<<endl;

    return 0;

}