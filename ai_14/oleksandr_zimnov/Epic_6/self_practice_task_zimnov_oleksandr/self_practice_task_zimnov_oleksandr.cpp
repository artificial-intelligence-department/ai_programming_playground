#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
const int MAX_PLAYERS = 10;

struct Player {
    string name = "";
    int initiative = 0;
    int health = 0;
    int spellSlots[5] = { 0 };
    int resources = 0;
    int hitDiceCount = 0;
    Player() = default;
    Player(const string& n, int init, int hp, initializer_list<int> ss, int res, int hitDice)
        : name(n), initiative(init), health(hp), resources(res), hitDiceCount(hitDice) {
        copy(ss.begin(), ss.end(), begin(spellSlots));
    }

    void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Initiative: " << initiative << endl;
        cout << "Missing Health: -" << health << endl;
        cout << "Missing Spell Slots: ";
        for (int i = 0; i < 5; ++i) {
            cout << spellSlots[i] << " ";
        }
        cout << endl;
        cout << "Missing Resources: -" << resources << endl;
        cout << "Hit Dice Count: " << hitDiceCount << endl;
        cout << "------------------------\n";
    }

    void saveToFile(ofstream& file) const {
        file << name << " ";
        file << initiative << " ";
        file << health << " ";
        for (int i = 0; i < 5; ++i) {
            file << spellSlots[i] << " ";
        }
        file << resources << " ";
        file << hitDiceCount << "\n";
    }

    void loadFromFile(ifstream& file) {
        file >> name;
        file >> initiative;
        file >> health;
        for (int i = 0; i < 5; ++i) {
            file >> spellSlots[i];
        }
        file >> resources;
        file >> hitDiceCount;
    }
};

void addPlayer(Player players[], int& playerCount) {
    if (playerCount < MAX_PLAYERS) {
        string name;
        int initiative, health, resources, hitDice;
        int spellSlots[5];
        cout << "Enter player name: ";
        cin >> name;
        cout << "Enter player initiative: ";
        cin >> initiative;
        cout << "Enter player health: ";
        cin >> health;
        cout << "Enter player spell slots (5 values): ";
        for (int i = 0; i < 5; ++i) {
            cin >> spellSlots[i];
        }
        cout << "Enter player resources: ";
        cin >> resources;
        cout << "Enter hit dice count: ";
        cin >> hitDice;
        players[playerCount] = Player(name, initiative, health, { spellSlots[0], spellSlots[1], spellSlots[2], spellSlots[3], spellSlots[4] }, resources, hitDice);
        ++playerCount;
    }
    else {
        cout << "Maximum number of players reached.\n";
    }
}

void editPlayerField(Player& player) {
    cout << "Select field to edit:\n";
    cout << "1. Name\n";
    cout << "2. Initiative\n";
    cout << "3. Health\n";
    cout << "4. Spell Slots\n";
    cout << "5. Resources\n";
    cout << "6. Hit Dice Count\n";
    int fieldChoice;
    cout << "Enter your choice: ";
    cin >> fieldChoice;
    switch (fieldChoice) {
    case 1:
        cout << "Enter new player name: ";
        cin >> player.name;
        break;
    case 2:
        cout << "Enter new player initiative: ";
        cin >> player.initiative;
        break;
    case 3:
        cout << "Enter new player health: ";
        cin >> player.health;
        break;
    case 4:
        cout << "Enter new player spell slots (5 values): ";
        for (int i = 0; i < 5; ++i) {
            cin >> player.spellSlots[i];
        }
        break;
    case 5:
        cout << "Enter new player resources: ";
        cin >> player.resources;
        break;
    case 6:
        cout << "Enter new hit dice count: ";
        cin >> player.hitDiceCount;
        break;
    default:
        cout << "Invalid choice. No fields were edited.\n";
    }
}

void savePlayersToFile(const Player players[], int playerCount) {
    ofstream file("players.txt");
    if (file.is_open()) {
        file << playerCount << "\n"; 
        for (int i = 0; i < playerCount; ++i) {
            players[i].saveToFile(file);
        }
        file.close();
        cout << "Player data saved to players.txt\n";
    }
    else {
        cout << "Unable to open players.txt for writing.\n";
    }
}

int loadPlayersFromFile(Player players[]) {
    ifstream file("players.txt");
    if (file.is_open()) {
        int playerCount;
        file >> playerCount;
        for (int i = 0; i < playerCount; ++i) {
            players[i].loadFromFile(file);
        }
        file.close();
        cout << "Player data loaded from players.txt\n";
        return playerCount;
    }
    else {
        cout << "Unable to open players.txt for reading. Starting with an empty player list.\n";
        return 0;
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int playerCount = 0;
    playerCount = loadPlayersFromFile(players);
    while (true) {
        cout << "1. Add Player\n";
        cout << "2. Display Players by Initiative\n";
        cout << "3. Edit Player\n";
        cout << "4. Delete Player\n";
        cout << "5. Save Players to File\n";
        cout << "6. Exit\n";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n";
        switch (choice) {
        case 1: {
            if (playerCount < MAX_PLAYERS) {
                string name;
                int initiative, health, resources, hitDice;
                int spellSlots[5];
                cout << "Enter player name: ";
                cin >> name;
                cout << "Enter player initiative: ";
                cin >> initiative;
                cout << "Enter player health: ";
                cin >> health;
                cout << "Enter player spell slots (5 values): ";
                for (int i = 0; i < 5; ++i) {
                    cin >> spellSlots[i];
                }
                cout << "Enter player resources: ";
                cin >> resources;
                cout << "Enter hit dice count: ";
                cin >> hitDice;
                players[playerCount] = Player(name, initiative, health, { spellSlots[0], spellSlots[1], spellSlots[2], spellSlots[3], spellSlots[4] }, resources, hitDice);
                ++playerCount;
            }
            else {
                cout << "Maximum number of players reached.\n";
            }
            break;
        }
        case 2: {
            sort(players, players + playerCount,
                [](const Player& a, const Player& b) {
                    return a.initiative > b.initiative;
                }
            );
            cout << "------------------------\n";
            for (int i = 0; i < playerCount; ++i) {
                cout << "Player " << i + 1 << ":\n";
                players[i].displayInfo();
            }
            break;
        }
        case 3: {
            int playerIndex;
            cout << "Enter the index of the player to edit: ";
            cin >> playerIndex;
            if (playerIndex >= 1 && playerIndex <= playerCount) {
                Player& player = players[playerIndex - 1];
                cout << "Editing player " << playerIndex << ":\n";
                player.displayInfo();
                editPlayerField(player);
                cout << "Player " << playerIndex << " edited successfully.\n";
            }
            else {
                cout << "Invalid player index.\n";
            }
            break;
        }
        case 4: {
            int playerIndex;
            cout << "Enter the index of the player to delete: ";
            cin >> playerIndex;
            if (playerIndex >= 1 && playerIndex <= playerCount) {
                for (int i = playerIndex - 1; i < playerCount - 1; ++i) {
                    players[i] = players[i + 1];
                }
                --playerCount;
                cout << "Player " << playerIndex << " deleted successfully.\n";
            }
            else {
                cout << "Invalid player index.\n";
            }
            break;
        }
        case 5: {
            savePlayersToFile(players, playerCount);
            break;
        }
        case 6:
            savePlayersToFile(players, playerCount);
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
