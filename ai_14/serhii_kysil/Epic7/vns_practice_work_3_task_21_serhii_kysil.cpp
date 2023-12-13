#include <iostream>
using namespace std;
void bank(){
    double money;
    cout << "Введіть початковий внесок: ";
    cin >> money;
    double first = money + (0.03 * money);
    double second = first + (0.03 * first);
    cout << "Сума вашого внеску після 2-х років: " << second;
}
int main(){
    double first_om, second_om, summary_om;
    cout << "Величина першого опору (Ом) > ";
    cin >> first_om;
    cout << "Величина другого опору (Ом) > ";
    cin >> second_om;
    summary_om = first_om + second_om;
    cout << "Опір ланцюга: " << summary_om << " Ом" << endl;
    bank();
    return 0;
}
