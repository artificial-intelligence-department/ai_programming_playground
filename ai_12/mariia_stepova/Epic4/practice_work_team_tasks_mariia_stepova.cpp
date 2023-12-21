#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) {
        return true;
    }
    
    if (str[start] != str[end]) {
        return false;
    }
    
    return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(int num, int reversedNum = 0)
{
   if(num != 0)
   {
       if(reversedNum == 0)
       {
           int size = -1;
           for(int tmp = num; tmp != 0; tmp /= 10)
                size++;
            
            for(int tmp = num; tmp != 0; tmp /= 10)
                reversedNum += tmp % 10 * pow(10, size--);
            //cout << num << "\t" << reversedNum << endl;
       }  
        if(num % 10 != reversedNum % 10)
            return false;
        return isPalindrome(num / 10, reversedNum / 10);
   }
   
return true;
    
    
}

/*bool isPalindrome(int num) {
    string str = to_string(num);
    return isPalindrome(str, 0, str.length() - 1);
}*/

int main() {
    /*string word;
    cout << "Введіть слово або число: ";
    cin >> word;

    if (isPalindrome(word, 0, word.length() - 1)) {
        cout << "Це слово або число є паліндромом." << endl;
    } else {
        cout << "Це слово або число не є паліндромом." << endl;
    }
*/

int num;
cin >> num;

if (isPalindrome(num)) {
        cout << "Це слово або число є паліндромом." << endl;
    } else {
        cout << "Це слово або число не є паліндромом." << endl;
    }


    return 0;
}
