#include <iostream>
using namespace std;

int main() {
    const int hours_per_shift = 8; 
    const int working_days_per_month = 30 - 4; 
    const int machine_maintenance_hours_per_shift = 1; 
    const int production_hours_per_shift = hours_per_shift - machine_maintenance_hours_per_shift; 

    const int kol_per_hour = 10; 

    int total_production = 0;

    
    total_production += production_hours_per_shift * kol_per_hour * 2; 

    
    total_production *= working_days_per_month;

    cout << "Number of items produced in a working month in a two-shift operation: " << total_production << endl;

    return 0;
}
