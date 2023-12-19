#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct TEAM {
    char name[40];
    char city[40];
    int players_number;
    int points_number;
};

void addInformation(const char* filename, int n) {
TEAM* team = new TEAM[n];
ofstream file(filename);

if (!file.is_open()) {
    cout << "Unable to open file!" << endl;
    delete[] team;
    return;
}

for (int i = 0; i < n; i++) {
    cout << "Enter name:" << endl;
    cin.ignore();
    cin.getline(team[i].name, 40);

    cout << "Enter city:" << endl;
    cin.getline(team[i].city, 40);

    cout << "Enter the players number:" << endl;
    cin >> team[i].players_number;

    cout << "Enter the points number:" << endl;
    cin >> team[i].points_number;

    file << team[i].name << "\n";
    file << team[i].city << "\n";
    file << team[i].players_number << "\n";
    file << team[i].points_number << "\n";
}

file.close();
delete[] team;
}

void showInformation(const char* filename, int n) {
TEAM* team = new TEAM[n];
ifstream file(filename);

for (int i = 0; i < n; i++) {
    file.getline(team[i].name, 40);
    file.getline(team[i].city, 40);
    file >> team[i].players_number;
    file >> team[i].points_number;
    file.ignore(); // Ignore newline character

    cout << "Name: " << team[i].name << endl;
    cout << "City: " << team[i].city << endl;
    cout << "The players number: " << team[i].players_number << endl;
    cout << "The points number: " << team[i].points_number << endl;
}

file.close();
delete[] team;
}

void removeTeamsWithLessPoints(TEAM*& team, int& n, int minPoints_number) {
TEAM* newTeam = new TEAM[n];
int newSize = 0;

for (int i = 0; i < n; i++) {
    if (team[i].points_number >= minPoints_number) {
        newTeam[newSize] = team[i];
        newSize++;
    }
}

delete[] team;
team=newTeam;
n=newSize;
}

void addTwoElements(const char* filename, int k) {
k = 2;
TEAM* team = new TEAM[k];

for (int i = 0; i < k; i++) {
    cout << "Enter name:" << endl;
    cin.ignore(); // Ignore newline character
    cin.getline(team[i].name, 40);

    cout << "Enter city:" << endl;
    cin.getline(team[i].city, 40);

    cout << "Enter the players number:" << endl;
    cin >> team[i].players_number;

    cout << "Enter the points number:" << endl;
    cin >> team[i].points_number;
}

ofstream file(filename, ios::out | ios::app);

if (!file.is_open()) {
    cout << "Unable to open file!" << endl;
    delete[] team;
    return;
}

for (int i = k - 1; i >= 0; i--) {
    file.seekp(0, ios::beg); // Move the write pointer to the beginning of the file
    file << "Name: " << team[i].name << "\n";
    file << "City: " << team[i].city << "\n";
    file << "Players Number: " << team[i].players_number << "\n";
    file << "Points Number: " << team[i].points_number << "\n\n";
}

file.close();
delete[] team;
}

int main() {
int n;
int minPoints_number;
cout << "Enter the number of teams:" << endl;
cin >> n;
cout << "Enter the minimal points number:" << endl;
cin >> minPoints_number;
addInformation("f.dat", n);
showInformation("f.dat", n);

TEAM* team = new TEAM[n]; 
ifstream infile("f.dat");
for (int i = 0; i < n; i++) {
    infile.ignore(); 
    infile.getline(team[i].name, 40);

    infile.ignore();
    infile.getline(team[i].city, 40);

    infile >> team[i].players_number;
    infile.ignore(); 
    infile >> team[i].points_number;
}
infile.close();
removeTeamsWithLessPoints(team, n, minPoints_number);
addTwoElements("f.dat", 2);
delete[] team;
return 0;
}