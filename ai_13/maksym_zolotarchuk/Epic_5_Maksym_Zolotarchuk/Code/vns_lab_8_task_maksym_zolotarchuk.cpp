#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct State
{
 string name;
 string capital;
 long long int population;
 long long int occupied_area;
};

void printState(const State& state)
{
 cout << "Name: " << state.name << endl;
 cout << "Capital: " << state.capital << endl;
 cout << "Population: " << state.population << endl;
 cout << "Occupied Area: " << state.occupied_area << endl;
}

void writetobinfile(const string& filename, const vector<State>& states)
{
 ofstream file(filename, ios::binary);
 if (!file)
 {
  cerr << "Cannot open file!" << endl;
  return;
 }

 for (const State& state : states)
 {
  file.write(reinterpret_cast<const char*>(&state), sizeof(State)); //використовую write для запису в бінарний файл
 }
}

void deletePopulation(vector<State>& states, long long int set_population)
{
 for (int i = 0; i < states.size();)
 {
  if (states[i].population < set_population)
  {
   states.erase(states.begin() + i);
  }
  else
  {
   ++i;
  }
 }
}

 void addState(vector<State>&states, int id, const State & newState) 
 {
  if (id >= 0 && id < states.size()) 
  {
   states.insert(states.begin() + id + 1, newState);
  }
  else 
  {
   states.push_back(newState);
  }
 }

int main()
{
 std::vector<State> states =
 {
    {"Ukraine", "Kyiv", 43000000, 603628},
    {"Poland", "Warsaw", 37750000, 322575},
    {"Israel", "Jerusalem", 9364000, 22145},
    {"China", "Beijing", 1412000000, 9597000}

 };

 writetobinfile("States.bin", states);

 cout << "First edition: " << endl;
 for (const auto& state : states)
 {
  printState(state);
 }

 cout << endl;

 deletePopulation(states, 10000000);

 State newState = { "Turkey", "Ankara", 84780000, 783562 };
 addState(states, 1, newState);

 writetobinfile("States.bin", states);

 cout << "Second edition: " << endl;
 for (const auto& state : states)
 {
  printState(state);
 }

 return 0;
}
