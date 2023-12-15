#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct SportsTeam {
    char teamName[50];
    char cityName[50];
    int playersCount;
    int points;
};

vector<SportsTeam> readToFile(const string& sportTeam) {
    vector<SportsTeam> teams;
    ifstream file(sportTeam, ios::binary);//для читання з файлу 

    if (file.is_open()) {
        SportsTeam team;
        while (file.read(reinterpret_cast<char*>(&team), sizeof(SportsTeam))) 
        {
            teams.push_back(team);
        }
        file.close();
    }

    return teams;
}

void writeToFile(const string& sportTeam, const vector<SportsTeam>& teams) {
    ofstream file(sportTeam, ios::binary);

    if (file.is_open()) {
        for (const SportsTeam& team : teams) {
            file.write(reinterpret_cast<const char*>(&team), sizeof(SportsTeam));
        }
        file.close();
    }
}

int main() 
{
    vector<SportsTeam> teams = readToFile("teams.bin");

    int minPoints = 15;

    teams.erase(remove_if(teams.begin(), teams.end(), [minPoints](const SportsTeam& team) {
        return team.points < minPoints;
        }), teams.end());

    for (int i = 0; i < 2; i++) {
        SportsTeam newTeam;
        cout << "| Enter details for new team #" << i + 1 << ":\n";
        cout << "| Name: ";
        cin >> newTeam.teamName;
        cout << "| City: ";
        cin >> newTeam.cityName;
        cout << "| Players count: ";
        cin >> newTeam.playersCount;
        cout << "| Points: ";
        cin >> newTeam.points;
        teams.insert(teams.begin(), newTeam);
    }


    writeToFile("teams.bin", teams);

    return 0;
}