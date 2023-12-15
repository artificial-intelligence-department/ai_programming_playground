#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

struct Team {
    char name[20];
    char city[20];
    int players;
    int points;
};

void write_to_file(const char* filename, const vector<Team>& teams) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "Error opening file for writing\n";
        return;
    }
    for (const auto& team : teams) {
        file.write((char*)&team, sizeof(Team));
    }
    file.close();
}

vector<Team> read_from_file(const char* filename) {
    vector<Team> teams;
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Error opening file for reading\n";
        return teams;
    }
    Team team;
    while (file.read((char*)&team, sizeof(Team))) {
        teams.push_back(team);
    }
    file.close();
    return teams;
}

void print_teams(const vector<Team>& teams) {
    for (const auto& team : teams) {
        cout << "Name: " << team.name << ", City: " << team.city
             << ", Players: " << team.players << ", Points: " << team.points << '\n';
    }
}

vector<Team> remove_teams(vector<Team>& teams, int min_points) {
    vector<Team> new_teams;
    for (const auto& team : teams) {
        if (team.points >= min_points) {
            new_teams.push_back(team);
        }
    }
    return new_teams;
}

vector<Team> add_teams(vector<Team>& teams, const vector<Team>& new_teams) {
    vector<Team> all_teams = new_teams;
    all_teams.insert(all_teams.end(), teams.begin(), teams.end());
    return all_teams;
}

int main() {
    // Create some teams
    vector<Team> teams = {
        {"Manchester United", "Manchester", 11, 5},
        {"Real Madrid", "Madrid", 11, 4},
        {"Dynamo Kyiv", "Kyiv", 11, 12}
    };

    // Write teams to file
    write_to_file("teams.bin", teams);

    // Read teams from file
    teams = read_from_file("teams.bin");

    // Print teams
    cout << "Initial teams:\n";
    print_teams(teams);

    // Remove teams with points less than 5
    teams = remove_teams(teams, 5);

    // Print teams after removal
    cout << "\nTeams after removal:\n";
    print_teams(teams);

    // Add new teams
    vector<Team> new_teams = {
        {"Chelsea", "London", 11, 7},
        {"Arsenal", "London", 11, 6}
    };
    teams = add_teams(teams, new_teams);

    // Print teams after addition
    cout << "\nTeams after addition:\n";
    print_teams(teams);

    // Write final teams to file
    write_to_file("teams.bin", teams);

    return 0;
}
