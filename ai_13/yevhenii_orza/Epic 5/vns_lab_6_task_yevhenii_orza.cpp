#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

string sort_string(string& input){
   string result;
   istringstream inputsting(input);
   ostringstream outputstring;
   while(inputsting >> result){
    sort(result.begin(), result.end());
    outputstring << result << " ";
    }
    return outputstring.str();
}

int main() {
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    string sortedString = sort_string(s);

    cout << "Sorted string: " << sortedString << endl;

    return 0;
}