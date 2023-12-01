#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


int process(const vector<int>& arr) {
    int count = 0;
    for (int num : arr) {
        if (num % 2 == 0) {
            count++;
        }
    }
    return count;
}


int process(const string& str) {
    int count = 0;
    istringstream iss(str);
    string word;
    while (iss >> word) {
        if (word[0] == 'a' || word[0] == 'A') {
            count++;
        }
    }
    return count;
}

int main() {
    
    int nNumb{0};
    cin>>nNumb;
    vector<int> arr;
    
    for (size_t i = 0; i < nNumb; i++)
    {
        int t{0};
        cin>>t;
        arr.push_back(t);
    }

    
    string str = "apple banana aprf avoerr asrfsd besdrg";
            cin.ignore();
           
            getline(cin, str);

    cout << "Amount of even numbers: " << process(arr) << endl;
    cout << "Amount of words which start from a: " << process(str) << endl;

    return 0;
}