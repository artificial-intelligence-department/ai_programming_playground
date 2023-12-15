#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    string line;
    vector<string> newlines, v;
    int N1, N2; 
    int line_pos = 0;

    cout << "Enter starting line:\n";
    cin >> N1;
    cout << "Enter ending line:\n";
    cin >> N2;

    ifstream inf("file1.txt", ifstream::in);
    
    if (!inf.is_open()) {
        cout << "Error while opening input file" << endl;
        return 1; 
    }

    while (getline(inf, line)){
        line_pos++;
        if (line_pos >= N1 && line_pos <= N2){
            if (!line.empty() && line[0] == 'A'){
                newlines.push_back(line);
            }
        } else if (line_pos > N2 + 3){
            newlines.push_back(line);
        }
    }
    inf.close();
    
    ofstream outf("file2.txt", ofstream::out | ofstream::trunc);

    if (!outf.is_open()) {
        cout << "Error while opening output file" << endl;
        return 1;
    }
    
    for (const string& newline : newlines) {
        outf << newline << endl;
    }
    
    outf.close();
    
    stringstream ss(newlines.back());

    string word;
    while (getline(ss, word, ' ')) {
        v.push_back(word);
    }
    
    cout << "Number of words in the last line of file 2: " << v.size() << endl;

    return 0;
}

