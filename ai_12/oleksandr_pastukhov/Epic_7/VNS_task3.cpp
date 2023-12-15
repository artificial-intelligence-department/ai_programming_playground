#include <iostream>

int main(){
    using namespace std;

    double priceNotebook, pricePencil;
    int quantityNotebooks, quantityPencils;

    cout << "Введіть ціну зошита: ";
    cin >> priceNotebook;

    cout << "Введіть кількість зошитів: ";
    cin >> quantityNotebooks;

    cout << "Введіть ціну олівців: ";
    cin >> pricePencil;

    cout << "Введіть кількість олівців: ";
    cin >> quantityPencils;

    double totalCost = priceNotebook * quantityNotebooks + pricePencil * quantityPencils;

    cout << "Вартість покупки: " << totalCost << " грн." << endl;

    return 0;
}
