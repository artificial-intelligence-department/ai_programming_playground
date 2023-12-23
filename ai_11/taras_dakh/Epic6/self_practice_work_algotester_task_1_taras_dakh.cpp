#include <iostream>
#include <string>
using namespace std;

struct Cars {
    int year;
    double enginevolume;
    string model;
    string country;
};
int main() {
    int numofcars;
    cout << "Enter the number of cars: ";
    cin >> numofcars;
    Cars* cars = new Cars[numofcars];
    for (int i = 0; i < numofcars; ++i) {
        cout <<"Enter information about car: " << (i + 1) << endl;
        cout << "Model: ";
        cin.ignore();
        getline(cin, cars[i].model);
        cout<<"Country: ";
        cin>> cars[i].country;
        cout << "Year: ";
        cin >> cars[i].year;
        cout << "Engine volume: ";
        cin >> cars[i].enginevolume;
        
    }
    cout << endl;
    cout << "Car Information:" << endl;
    for (int i = 0; i < numofcars; ++i) {
        cout << "Car " << (i + 1) << endl;
        cout << "Model: " << cars[i].model << endl;
        cout << "Country: "<< cars[i].country<<endl;
        cout << "Year: " << cars[i].year << endl;
        cout << "Engine volume: " << cars[i].enginevolume << endl;
    }
    
    return 0;
}
