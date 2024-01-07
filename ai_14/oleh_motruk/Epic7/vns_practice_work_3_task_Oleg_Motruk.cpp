#include <iostream>

using namespace std;

int main(){
    int copybooks;
    int pencil;
    const float cost_of_copybook = 2.75;
    const float cost_of_pencil = 0.85;

    cout << "Enter amount of copybooks: ";
    cin >> copybooks;

    cout << "Enter amount of pencil: ";
    cin >> pencil;

    float total_cost = cost_of_copybook * copybooks + cost_of_pencil * pencil;
    cout << "Total cost: " << total_cost << endl;
    return 0;
}