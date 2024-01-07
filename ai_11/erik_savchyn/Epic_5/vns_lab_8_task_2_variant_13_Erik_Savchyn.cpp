#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct SportsTeams {
    string name;
    string city;
    int players;
    int points;
};

void writeToFile(const string &filename, const SportsTeams *teams, int size) {
    ofstream outFile(filename, ios_base::out | ios_base::binary);
    if (outFile.is_open()) {
        cout << "File is open for writing" << endl;

        for (int i = 0; i < size; i++) {
            outFile.write(reinterpret_cast<const char*>(&teams[i]), sizeof(SportsTeams));
        }
        outFile.close();
        cout << "File write successful" << endl;
    } else {
        cout << "Error opening file for writing" << endl;
    }
}

void readFromFile(const string &filename) {
    ifstream inFile(filename, ios_base::in | ios_base::binary);
    if (inFile.is_open()) {
        cout << "File is open for reading" << endl;

        SportsTeams team;
        int num = 1;

        while (inFile.read(reinterpret_cast<char*>(&team), sizeof(team))) {
            cout << "Team " << num << ")";
            cout << " \tname: " << team.name;
            cout << ";   \tcity: " << team.city;
            cout << ";   \tplayers: " << team.players;
            cout << ";   \tpoints: " << team.points << endl;
            num++;
        }

        inFile.close();
        cout << "File read successful" << endl;
    } else {
        cout << "Error opening file for reading" << endl;
    }
}

void filterAndWriteToFile(const string &inputFilename, const string &outputFilename) {
    ifstream inFile(inputFilename, ios_base::in | ios_base::binary);
    ofstream outFile(outputFilename, ios_base::out | ios_base::binary | ios_base::app);

    if (inFile.is_open() && outFile.is_open()) {
        cout << "Files are open for reading and writing" << endl;

        SportsTeams team;
        while (inFile.read(reinterpret_cast<char*>(&team), sizeof(team))) {
            if (team.points >= 7) {
                outFile.write(reinterpret_cast<const char*>(&team), sizeof(team));
            }
        }

        inFile.close();
        outFile.close();
        cout << "Filtered file write successful" << endl;
    } else {
        cout << "Error opening files for reading or writing" << endl;
    }
}

void appendNewTeams(const string &filename, const SportsTeams *newTeams) {
    ofstream outFile(filename, ios_base::out | ios_base::binary);
    if (outFile.is_open()) {
        cout << "File is open for writing" << endl;

        for (int i = 0; i < 2; i++) {
            outFile.write(reinterpret_cast<const char*>(&newTeams[i]), sizeof(newTeams[i]));
        }
        outFile.close();
        cout << "File append successful" << endl;
    } else {
        cout << "Error opening file for writing" << endl;
    }
}

int main() {
    SportsTeams team[] = {
        {"Liverpool", " Liverpool", 32, 9},
        {"Real Madrid", " Madrid", 28, 7},
        {"Man-er United", " Manchester", 27, 6},
        {"Juventus", " Turin", 22, 8},
        {"Bayern Munich", "Munich", 30, 9},
        {"Paris S-G", " Paris", 28, 7},
        {"AC Milan", " Milan", 25, 5},
        {"Chelsea", " London", 29, 8},
        {"Arsenal", " London", 26, 7},
        {"Borussia Dortmund", " Dortmund", 23, 6}
    };

    const int teamSize = sizeof(team) / sizeof(SportsTeams);

    writeToFile("SportsTeams.bin", team, teamSize);
    readFromFile("SportsTeams.bin");
    
    SportsTeams newTeams[] = {
        {"Barcelona", " Barcelona", 31, 8},
        {"Dynamo", " kyiv     ", 28, 9}
    };

    appendNewTeams("temp.bin", newTeams);
    
    filterAndWriteToFile("SportsTeams.bin", "temp.bin");

    readFromFile("temp.bin");

    return 0;
}
