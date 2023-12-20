#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

// Структура "Спортивна команда"
struct SportsTeam {
    char name[50];
    char city[20];
    int players;
    int points;
};

// Функція для виведення інформації про команду
void printTeam(const SportsTeam& team) {
    cout << "Назва: " << team.name << endl;
    cout << "Місто: " << team.city << endl;
    cout << "Кількість гравців: " << team.players << endl;
    cout << "Кількість очків: " << team.points << endl;
    cout << "-----------------------" << endl;
}

// Функція для видалення елементів з кількістю очків менше заданої
void removeTeamsBelowPoints(const char* filename, int thresholdPoints) {
    FILE* fileIn = fopen(filename, "rb");
    FILE* tempFile = fopen("temp.bin", "wb");

    if (!fileIn || !tempFile) {
        cerr << "Помилка при відкритті файлу!" << endl;
        return;
    }

    SportsTeam team;
    while (fread(&team, sizeof(SportsTeam), 1, fileIn)) {
        if (team.points >= thresholdPoints) {
            fwrite(&team, sizeof(SportsTeam), 1, tempFile);
        }
    }

    fclose(fileIn);
    fclose(tempFile);

    remove(filename);
    rename("temp.bin", filename);
}

// Функція для додавання 2 елементів на початок файлу
void addTeamsToBeginning(const char* filename) {
    FILE* fileOut = fopen(filename, "ab");

    if (!fileOut) {
        cerr << "Помилка при відкритті файлу!" << endl;
        return;
    }

    SportsTeam team1 = {"Team1", "City1", 11, 20};
    SportsTeam team2 = {"Team2", "City2", 15, 25};

    fwrite(&team2, sizeof(SportsTeam), 1, fileOut);
    fwrite(&team1, sizeof(SportsTeam), 1, fileOut);

    fclose(fileOut);
}

int main() {
    const char* filename = "teams.bin";

    // Додавання даних до файлу
    SportsTeam team1 = {"TeamA", "CityA", 10, 15};
    SportsTeam team2 = {"TeamB", "CityB", 12, 18};

    FILE* fileOut = fopen(filename, "wb");
    fwrite(&team1, sizeof(SportsTeam), 1, fileOut);
    fwrite(&team2, sizeof(SportsTeam), 1, fileOut);
    fclose(fileOut);

    // Виведення початкового вмісту файлу
    FILE* fileIn = fopen(filename, "rb");
    SportsTeam team;

    cout << "Початковий вміст файлу:" << endl;
    while (fread(&team, sizeof(SportsTeam), 1, fileIn)) {
        printTeam(team);
    }

    fclose(fileIn);

    // Видалення елементів та додавання нових
    int thresholdPoints = 17;
    removeTeamsBelowPoints(filename, thresholdPoints);

    cout << "Вміст файлу після видалення елементів з кількістю очків менше " << thresholdPoints << ":" << endl;
    fileIn = fopen(filename, "rb");
    while (fread(&team, sizeof(SportsTeam), 1, fileIn)) {
        printTeam(team);
    }

    fclose(fileIn);

    addTeamsToBeginning(filename);

    cout << "Вміст файлу після додавання елементів на початок:" << endl;
    fileIn = fopen(filename, "rb");
    while (fread(&team, sizeof(SportsTeam), 1, fileIn)) {
        printTeam(team);
    }

    fclose(fileIn);

    return 0;
}