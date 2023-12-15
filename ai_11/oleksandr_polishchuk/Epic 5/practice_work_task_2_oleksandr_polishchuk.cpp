#include <iostream>
#include <string>
#include <fstream>
#include <vector>


using namespace std;

enum FileOpResult { Success, Opening_failure, Closing_failure };

FileOpResult write_to_file(const char *file_from, const char *file_tot) {
    ifstream from;
    from.open(file_from);
    if (!from.is_open())
    {
        return Opening_failure;
    }
    ofstream tot;
    tot.open(file_tot);
    if (!tot.is_open())
    {
        return Opening_failure;
    }
    else
    { 
        
        string buffer;
        while(getline(from, buffer))
        {
            tot << buffer << "\n";
            
        }
    }
    from.close();
    tot.close();
    if(from.is_open() || tot.is_open()) 
    {
        return Closing_failure;
    }
    
    return Success;
}

int main() {
    string file_from, file_tot;

    cout << "Введіть назву файлу для копіювання з розширенням : ";
    getline(cin, file_from);
    cout << "Введіть назву файлу для запису з розширенням : ";
    getline(cin, file_tot);

    FileOpResult result = write_to_file(file_from.c_str(), file_tot.c_str());

    if (result == Success) 
    {
         cout << "Success";
    } 
    else if (result == Opening_failure) 
    {
        cerr << "Opening_failure";
    } 
    else if (result == Closing_failure)
    {
        cerr << "Closing_failure";
    }

    return 0;
}
