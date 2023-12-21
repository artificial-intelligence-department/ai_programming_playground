#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

constexpr const char* FILE1 = "file1.txt";
constexpr const char* FILE2 = "file2.txt";

int longestWordPosition(const vector<string>& words) {
    if (words.empty())
        return -1;

    int longestPosition = 0;
    for (int i = 0; i < words.size(); ++i) {
        if (words[i].length() > words[longestPosition].length()) {
            longestPosition = i;
        }
    }

    return longestPosition;
}

vector<string> split(const string& line) {
    vector<string> words;
    string word;
    istringstream iss(line);

    while (iss >> word) {
        words.push_back(word);
    }

    return words;
}

bool writeLnIfHasDuplicate(const string& line, const string& filename) {
    vector<string> words = split(line);
    for (int i = 0; i < words.size(); ++i) {
        for (int j = 0; j < words[i].length(); ++j) {
            if (words[i] == words[j]) {
                ofstream outfile(filename, ios::app);
                outfile << line << endl;
                return true;
            }
        }
    }

    return false;
}

int main() {
    ifstream infile1(FILE1);
    ofstream outfile2(FILE2);

    if (!infile1.is_open() || !outfile2.is_open()) {
        cerr << "Error opening files" << endl;
        return 1;
    }

    vector<string> lines;
    vector<string> words;

    string line1;
    while (getline(infile1, line1)) {
        lines.push_back(line1);

        vector<string> s = split(line1);
        words.insert(words.end(), s.begin(), s.end());

        writeLnIfHasDuplicate(line1, FILE2);
    }

    infile1.close();
    outfile2.close();

    int longest_pos = longestWordPosition(words);
    cout    << "Longest word: " << words[longest_pos]
            << " (Position: " << longest_pos << ")" << endl;

    return 0;
}
