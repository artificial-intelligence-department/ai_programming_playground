#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string input;
    cin >> input;

    if(input.size() == 0) {
        cout << "wrong input>" << endl;
        return 0;
    }

    sort(input.begin(), input.end());

    for(int i = 0; i < input.size(); i++)
        cout << input[i];
    
    return 0;
}