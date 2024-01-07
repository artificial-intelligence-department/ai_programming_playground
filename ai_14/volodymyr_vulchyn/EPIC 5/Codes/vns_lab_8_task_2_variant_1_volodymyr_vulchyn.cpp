#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

struct Football_Clubs {
    
    string city;
    string name;
    int points;
    int players;
    
};

// Функція для перетворення структури Футбол_Клабс у послідовність бітів. 
void serializeTeam(ofstream& stream, const Football_Clubs& team) {
    size_t nameSize = team.name.size();
    size_t citySize = team.city.size();

    stream.write((char*)&nameSize, sizeof(size_t));
    stream.write(team.name.c_str(), nameSize);

    stream.write((char*)&citySize, sizeof(size_t));
    stream.write(team.city.c_str(), citySize);

    stream.write((char*)&team.players, sizeof(team.players));
    stream.write((char*)&team.points, sizeof(team.points));
}

// Функція для відновлення початкового стану структури Футбол_Клабс із бітової послідовності.
bool deserializeTeam(ifstream& stream, Football_Clubs& team) {
    size_t nameSize, citySize;

    stream.read((char*)&nameSize, sizeof(size_t));
    if (stream.fail()) {
        return false;
    }

    char nameBuffer[nameSize + 1];
    stream.read(nameBuffer, nameSize);
    nameBuffer[nameSize] = '\0';
    team.name = nameBuffer;

    stream.read((char*)&citySize, sizeof(size_t));
    if (stream.fail()) {
        return false;
    }

    char cityBuffer[citySize + 1];
    stream.read(cityBuffer, citySize);
    cityBuffer[citySize] = '\0';
    team.city = cityBuffer;

    stream.read((char*)&team.players, sizeof(team.players));
    stream.read((char*)&team.points, sizeof(team.points));

    return !stream.fail();
}

// Функція для запису вектора футбольних команд у файл
void writeTeamsToFile(const string& filename, const vector<Football_Clubs>& teams) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cout << "Помилка відкриття файла для запису інформації!" << filename << endl;
        return;
    }
    for (const auto& team : teams) {
        serializeTeam(file, team);
    }
    file.close();
}

// Функція для зчитування вектора футбольних команд з файлу
vector<Football_Clubs> readTeamsFromFile(const string& filename) {
    vector<Football_Clubs> teams;
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Помилка відкриття файла для зчитування інформації!" << filename << endl;
        return teams;
    }
    Football_Clubs team;
    while (deserializeTeam(file, team)) {
        teams.push_back(team);
    }
    file.close();
    return teams;
}

// Функція для виведення інформації про футбольну команду
void printTeam(const Football_Clubs& team) {
    cout << "Name: " << team.name << ", City: " << team.city << ", Players: " << team.players << ", Points: " << team.points << endl;
}

// Функція для виведення інформації про всі футбольні команди у векторі
void printTeams(const vector<Football_Clubs>& teams) {
    for (const auto& team : teams) {
        printTeam(team);
    }
}

// Функція для фільтрації футбольних команд за мінімальною кількістю очок
vector<Football_Clubs> filterTeamsByPoints(const vector<Football_Clubs>& teams, int minPoints) {
    vector<Football_Clubs> newTeams;
    copy_if(teams.begin(), teams.end(), back_inserter(newTeams),
            [minPoints](const Football_Clubs& team) { return team.points >= minPoints; });
    return newTeams;
}

// Функція для об'єднання двох векторів футбольних команд
vector<Football_Clubs> combineTeams(const vector<Football_Clubs>& teams1, const vector<Football_Clubs>& teams2) {
    vector<Football_Clubs> combinedTeams(teams2);
    combinedTeams.insert(combinedTeams.end(), teams1.begin(), teams1.end());
    return combinedTeams;
}

vector<Football_Clubs> newTeams; // Оголошення newTeams поза main для доступності
int main() {
    // Створення футбольних команд
    vector<Football_Clubs> teams = {
        {"Paris SG", "Paris", 15, 11},
        {"FC Porto", "Porto", 2, 11},
        {"Juventus", "Turin", 9, 11},
        {"Napoli FC", "Neapol", 1 , 11},
        {"FC Dortmund", "Dortmund", 14, 11}
    };

    // Запис футбольних команд у файл
    writeTeamsToFile("fcteams.txt", teams);

    // Зчитування футбольних команд з файлу
    teams = readTeamsFromFile("fcteams.txt");

    // Виведення початкових футбольних команд
    cout << "Команди турніру:" << endl;
    printTeams(teams);

    // Фільтрація футбольних команд з менше ніж 9 очками
    newTeams = filterTeamsByPoints(teams, 9);

    // Виведення футбольних команд після видалення
    cout << "\nФутбольні клуби, після видалення тих, які мають менше ніж 9 очок:" << endl;
    printTeams(newTeams);

    // Додавання нових футбольних команд
    vector<Football_Clubs> newTeams2 = {
        {"PSV", "Eindhoven", 5, 11},
        {"Latium", "Rome", 5, 11}
    };
    newTeams = combineTeams(newTeams, newTeams2);

    // Виведення футбольних команд після додавання
    cout << "\nФутбольні клуби, після заміни де-яких іншими:" << endl;
    printTeams(newTeams);

    // Запис остаточних футбольних команд у файл
    writeTeamsToFile("fcteams.txt", newTeams);

    return 0;
}
