#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

struct Buyer {
    string lastName;
    string firstName;
    string middleName;
    string homeAddress;
    string phoneNumber;
    string creditCardNumber;
};

    vector<Buyer> readBuyersFromFile(const string& filename) {
    vector<Buyer> buyers;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Unable to open the file: " << filename << endl;
        return buyers;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        Buyer buyer;
        iss >> buyer.lastName >> buyer.firstName >> buyer.middleName >> buyer.homeAddress >> buyer.phoneNumber >> buyer.creditCardNumber;
        buyers.push_back(buyer);
    }

    file.close();
    return buyers;
}

void writeBuyersToFile(const string& filename, const vector<Buyer>& buyers) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Unable to open the file: " << filename << endl;
        return;
    }

    for (const auto& buyer : buyers) {
        file << buyer.lastName << ' ' << buyer.firstName << ' ' << buyer.middleName << ' ' << buyer.homeAddress << ' ' << buyer.phoneNumber << ' ' << buyer.creditCardNumber << '\n';
    }

    file.close();
}

int main() {
    const string filename = "buyers.txt";
    vector<Buyer> buyers = readBuyersFromFile(filename);

    if (buyers.size() >= 3) {
        buyers.erase(buyers.begin(), buyers.begin() + 3);
    }

    for (int i = 0; i < 3; ++i) {
        Buyer newBuyer;
        cout << "Enter buyer information:\n";
        cout << "Last Name: ";
        cin >> newBuyer.lastName;
        cout << "First Name: ";
        cin >> newBuyer.firstName;
        cout << "Middle Name: ";
        cin >> newBuyer.middleName;
        cout << "Home Address: ";
        cin >> newBuyer.homeAddress;
        cout << "Phone Number: ";
        cin >> newBuyer.phoneNumber;
        cout << "Credit Card Number: ";
        cin >> newBuyer.creditCardNumber;
        buyers.push_back(newBuyer);
    }
    writeBuyersToFile(filename, buyers);
    return 0;
}
