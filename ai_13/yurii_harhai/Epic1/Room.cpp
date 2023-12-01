#include <iostream>

using namespace std;

int main()
{

    cout <<"Hi mate, it's Sagan's cleaning servise\nPlease enter the number of big rooms u would like to be cleaned: ";

    const double big_room_price {35};
    const double small_room_price {25};
    const double tax {0.06};
    const int valid_for {30};

    int number_of_bigrooms {0};
    int number_of_smallrooms {0};
    cin >> number_of_bigrooms;
    cout << "Now enter the number of small rooms: ";
    cin >> number_of_smallrooms;
    cout << "Number of big rooms: " << number_of_bigrooms << endl;
    cout << "Number of small rooms: " << number_of_smallrooms << endl;
    cout << "Price per big room: " << big_room_price << "$" << endl;
    cout << "Price per small room: " << small_room_price << "$" << endl;
    cout << "Cost: " <<(number_of_bigrooms*big_room_price)+(number_of_smallrooms*small_room_price) <<"$\n";
    cout << "Taxes: " << ((number_of_bigrooms*big_room_price)+(number_of_smallrooms*small_room_price))*tax << "$" << endl;

    cout << "Full cost:" << (number_of_bigrooms*big_room_price)+(number_of_smallrooms*small_room_price) +
     (((number_of_bigrooms*big_room_price)+(number_of_smallrooms*small_room_price))*tax) << "$\n";

    cout << "This estimate is valid for " << valid_for << "days";
    return 0;



}