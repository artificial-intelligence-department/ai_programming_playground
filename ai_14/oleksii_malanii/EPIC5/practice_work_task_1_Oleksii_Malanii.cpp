#include <fstream>
#include <string>
using namespace std;
bool write(const string& filename, const string& content) {
   ofstream file(filename);
    if (!file.is_open()) {
        return false; 
    }
    file << content;
    file.close();
    return true; 
}
