#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isPalindrome(int);
bool isPalindrome(const string&, int, int);

string word;
vector<int> numbers {};
int num {};
int normal {};
int reverse {};
int start {};
int finish {};
size_t range {};
bool palindrom {false};


int main(){
    cout << "Enter word or an integer: ";
    cin >> word;
    start = 0;
    finish = word.size() - 1;
    cout << boolalpha << isPalindrome(word, start, finish) << endl;
    
return 0;
}

bool isPalindrome(int num){
    normal = num;
    while (num>0){
        int pos {};
        pos=num%10;
        num /= 10;
        numbers.push_back(pos);

    }
    range = numbers.size();
    for (int i = 0; i < range; i++){
        reverse = reverse*10 + numbers.at(i);
        }
    if (normal == reverse)
        palindrom = true;
    else if (normal != reverse)
        palindrom = false;
    return palindrom;
}
bool isPalindrome(const string &word, int start, int finish) {
    if (start >= finish) {
        return true;
    }
    if (word[start] != word[finish]) {
        return false;
    }
    return isPalindrome(word, start + 1, finish - 1);
    
}
