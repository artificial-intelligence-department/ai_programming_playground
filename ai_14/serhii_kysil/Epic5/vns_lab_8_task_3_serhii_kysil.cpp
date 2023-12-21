#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;
struct State {
    char name[30];
    char capital[30];
    int population;
    double area;
};
void FillFile(const vector<State>& states, const char* FileName) {
    ofstream fout(FileName, ios::binary);
    if (!fout) {
        cout << "Error opening/creating the file" << endl;
        return;
    }
    for (const State& s : states) {
        fout.write(reinterpret_cast<const char*>(&s), sizeof(State));
    }
    fout.close();
}
void DeleteStatesWithLowPopulation(vector<State>& states, int populationThreshold, const char* FileName) {
    vector<State> updatedStates;
    for (const State& s : states) {
        if (s.population >= populationThreshold) {
            updatedStates.push_back(s);
        }
    }
    states = updatedStates;
    ofstream fout(FileName, ios::binary);
    if (!fout) {
        cout << "Error opening the file for writing" << endl;
        return;
    }
    for (const State& s : updatedStates) {
        fout.write(reinterpret_cast<const char*>(&s), sizeof(State));
    }
    fout.close();
}
bool AddState(vector<State>& states, const char* FileName) {
    State newState;
    cout << "Enter data for the state you want to add:" << endl;
    cout << "Name: ";
    cin.ignore();
    cin.getline(newState.name, sizeof(newState.name));
    cout << "Capital: ";
    cin.getline(newState.capital, sizeof(newState.capital));
    cout << "Population: ";
    cin >> newState.population;
    cout << "Area: ";
    cin >> newState.area;
    string beforeStateName;
    cout << "After which state would you like to insert the new one? Enter the name: ";
    cin.ignore();
    getline(cin, beforeStateName);
    ifstream fin(FileName, ios::binary);
    if (!fin) {
        cout << "Error reading data from the file" << endl;
        return false;
    }
    ofstream fout("temp.bin", ios::binary);
    if (!fout) {
        cout << "Error writing data to the file" << endl;
        return false;
    }
    bool found = false;
    State state;
    while (fin.read(reinterpret_cast<char*>(&state), sizeof(State))) {
        if (strcmp(state.name, beforeStateName.c_str()) == 0) {
            fout.write(reinterpret_cast<const char*>(&newState), sizeof(State));
            found = true;
        }
        fout.write(reinterpret_cast<const char*>(&state), sizeof(State));
    }
    if (!found) {
        cout << "State not found" << endl;
        return false;
    }
    fin.close();
    fout.close();
    remove(FileName);
    rename("temp.bin", FileName);
    return true;
}
void PrintFile(const char* FileName) {
    ifstream fin(FileName, ios::binary);
    if (!fin) {
        cout << "Error reading the file" << endl;
        return;
    }
    State state;
    while (fin.read(reinterpret_cast<char*>(&state), sizeof(State))) {
        cout << "Name: " << state.name << endl;
        cout << "Capital: " << state.capital << endl;
        cout << "Population: " << state.population << endl;
        cout << "Area: " << state.area << endl << endl;
    }
    fin.close();
}
int main() {
    vector<State> states = {
        {"Ukraine\t", "Kyiv\t", 44000000, 603500.0},
        {"Germany", "Berlin", 83000000, 357022.0},
        {"France\t", "Paris\t", 67000000, 551695.0},
        {"Italy\t", "Rome\t", 60300000, 301340.0},
        {"Spain\t", "Madrid", 47000000, 505992.0}
    };
    FillFile(states, "states.bin");
    PrintFile("states.bin");
    DeleteStatesWithLowPopulation(states, 500000, "states.bin");  // видаляємо держави з населенням менше 
    if (!AddState(states, "states.bin")) {
        return 1;
    }
    PrintFile("states.bin");
    return 0;
}
