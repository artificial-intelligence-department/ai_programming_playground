#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

struct state {
    char name[50];
    char capital[50];
    float population = 0;
    float area = 0;
};

void statesWrite(const vector<state> &states) {
    ofstream file("states.bin", ios::binary);
    if (file.is_open()) {
        for (state State: states) {
            file.write(reinterpret_cast<const char *>(&State), sizeof(State));
        }
        file.close();
    }
    else { cout << "Error occurred while opening"; }
}

void deleteState(vector<state> &states, int stateInList) {
    states.erase(states.begin()+stateInList);
    statesWrite(states);
}

void insertState(vector<state> &states, int position, state &State) {
    states.insert(states.begin()+position, State);
    statesWrite(states);
}

void statesPrint() {
    ifstream file("states.bin", ios::binary);
    if (file.is_open()) {
        state State;
        while (file.read(reinterpret_cast<char*>(&State), sizeof(state))) {
            cout << "-----------State-----------" << endl;
            cout << "Name: " << State.name << ";" << endl;
            cout << "Capital: " << State.capital << ";" << endl;
            cout << "Population: " << State.population << ";" << endl;
            cout << "Area: " << State.area << ";" << endl;
            cout << "---------------------------" << endl;
        }
        file.close();
    }
}

int main() {
    vector<state> states;
    state State1;
    strcpy(State1.name, "Switzerland");
    strcpy(State1.capital, "Bern");
    State1.population = 8.7;
    State1.area = 41285;
    state State2;
    strcpy(State2.name, "Poland");
    strcpy(State2.capital, "Warsaw");
    State2.population = 37.7;
    State2.area = 322575;
    state State3;
    strcpy(State3.name, "Moldova");
    strcpy(State3.capital, "Chisinau");
    State3.population = 2.5;
    State3.area = 33484;
    state State4;
    strcpy(State4.name, "Ukraine");
    strcpy(State4.capital, "Kyiv");
    State4.population = 36.7;
    State4.area = 603628;
    state State5;
    strcpy(State5.name, "Germany");
    strcpy(State5.capital, "Berlin");
    State5.population = 36.7;
    State5.area = 603628;
    states.push_back(State1);
    states.push_back(State2);
    states.push_back(State3);
    states.push_back(State4);

    statesWrite(states);
    statesPrint();

    float populationValue;
    int statePosition;
    cout << "Enter minimum population value:";
    cin >> populationValue;
    cout << "Enter state number, after which new state has to be put:";
    cin >> statePosition;
    for (int i = 0; i < states.size(); i++) {
        if (states[i].population < populationValue) {
            deleteState(states, i);
        }
    }
    statesPrint();
    insertState(states, statePosition, State5);
    statesPrint();

    return 0;
}
