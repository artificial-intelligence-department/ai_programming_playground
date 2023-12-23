#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;


struct Film {
    string title;
    string director;
    string country;
    string revenue;
};




void printFileContents(const string& path) {
    ifstream file(path);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cerr << "Error opening the file." << endl;
    }
}




void deleteLastTwoLines(const string& path) {
    ifstream inFile(path);
    ofstream tempFile("temp.txt");


    if (!inFile || !tempFile) {
        cerr << "Error opening files." << endl;
        return;
    }


    vector<string> lines;
    string line;


    while (getline(inFile, line)) {
        lines.push_back(line);
    }


    inFile.close();




    if (lines.size() > 1) {
        lines.pop_back();
        lines.pop_back();
    }




    for (const string& l : lines) {
        tempFile << l << endl;
    }


    tempFile.close();


      remove(path.c_str());
    rename("temp.txt", path.c_str());
}




void addElement(const string& path) {
    Film newMovie;




    cout << "Enter the title of the film: ";
    getline(cin, newMovie.title);


    cout << "Enter the director of the film: ";
    getline(cin, newMovie.director);


    cout << "Enter the country of the film: ";
    getline(cin, newMovie.country);


    cout << "Enter the revenue of the film: ";
    getline(cin, newMovie.revenue);




    ofstream outFile(path, ios::app);


    if (!outFile) {
        cerr << "Error opening the file." << endl;
        return;
    }




    outFile << newMovie.title << endl;
    outFile << newMovie.director << endl;
    outFile << newMovie.country << endl;
    outFile << newMovie.revenue << endl;


    outFile.close();
}
int main() {


    string path = "t.txt";




    cout << "File Contents Before Operations:\n";
    printFileContents(path);




    deleteLastTwoLines(path);




    addElement(path);
    cout << "\nFile Contents After Operations:\n";
    printFileContents(path);


    return 0;}
