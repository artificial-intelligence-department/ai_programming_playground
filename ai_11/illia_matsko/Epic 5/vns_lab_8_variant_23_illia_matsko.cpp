#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Stadium {
    string name;
    int yearBuilt;
    int numOfFields;
    string sports;
};

void printStadiums(const vector<Stadium>& stadiums) {
    for (int i = 0; i < stadiums.size(); i++) {
        cout << "Name: " << stadiums[i].name << " Year Built: " << stadiums[i].yearBuilt << " Number of Fields: " << stadiums[i].numOfFields << " Sports: " << stadiums[i].sports << endl;
    }
}

void destroyStadiums(std::vector<Stadium>& stadiums, int year) {
    for (auto it = stadiums.begin(); it != stadiums.end(); ) {
        if (it->yearBuilt < year) {
            it = stadiums.erase(it);
        } else {
            it++;
        }
    }
}

void addStadiums(vector<Stadium>& stadiums, int targetIndex) {
    if (targetIndex >= 2 && targetIndex < stadiums.size()) {
        Stadium newStadium1 = {"NEW STADIUM 1", 2022, 1, "Handball"};
        Stadium newStadium2 = {"NEW STADIUM 2", 2022, 1, "Volleyball"};

        stadiums.insert(stadiums.begin() + targetIndex, {newStadium1, newStadium2});
    } else {
        cerr << "Invalid target index for adding stadiums." << endl;
        return;
    }
}

int main() {
    ofstream file1("stadiums.bin", ios::binary);
    if (!file1.is_open()) {
        cerr << "Error opening file1 for writing." << endl;
        return -1;
    }

    vector<Stadium> stadiums = {
            {"Stadium A", 2000, 1, "Football"},
            {"Stadium B", 2005, 2, "Soccer"},
            {"Stadium C", 2010, 1, "Basketball"},
            {"Stadium D", 2015, 3, "Baseball"},
            {"Stadium E", 2020, 1, "Football"},
            {"Stadium F", 2025, 2, "Soccer"},
            {"Stadium G", 2030, 1, "Basketball"},
            {"Stadium H", 2035, 3, "Baseball"}
    };

    file1.write(reinterpret_cast<char*>(stadiums.data()), sizeof(Stadium) * stadiums.size());
    file1.close();

    ifstream file2("stadiums.bin", ios::binary);
    if (!file2.is_open()) {
        cerr << "Error opening file for reading." << endl;
        return -1;
    }

    cout << "Stadiums:" << endl;
    printStadiums(stadiums);

    int targetYear;
    cout << endl << "Enter target year: ";
    cin >> targetYear;
    destroyStadiums(stadiums, targetYear);
    cout << endl << "After destroying stadiums built before " << targetYear << ":" << endl;
    printStadiums(stadiums);

    int targetIndex;
    cout << endl << "Enter target index: ";
    cin >> targetIndex;
    addStadiums(stadiums, targetIndex);
    cout << endl << "After adding new stadiums before index " << targetIndex << ":" << endl;
    printStadiums(stadiums);

    file2.close();

    return 0;
}
