
#include <bits/stdc++.h>
#include <string>
using namespace std;
string reverseString(string text)
{


	reverse(text.begin(), text.end());

	// Add space at the end so that the last word is also reversed
	text.insert(text.end(), ' ');

	int n = text.length();

	int j = 0;

	// Find spaces and reverse all words before that
	for (int i = 0; i < n; i++) {

		
		if (text[i] == ' ') {
			reverse(text.begin() + j,text.begin() + i);

			j = i + 1;
		}
	}

	// Remove spaces from the end of the  word that we appended
	text.pop_back();

	
	return text;
}

int main()
{
    string text;
    cout << "Enter a text: "<<endl;
    getline(cin, text);
    cout << "You entered: " << text<<endl;
    string reverse= reverseString(text);

    cout <<"reversed text:  "<<reverse;

    
    return 0;
}






