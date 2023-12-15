#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;





bool isPalindrome (string &n){
        static int i {0}; 
    
    
        
        if(n[i]== n[n.length()-(i+1)] && i == n.length()-1 ){
            
            return true;
        }else if( i == n.length()-1){
            return false;
        }
        i++;
        isPalindrome(n);
    

}

bool isPalindrome (vector<int> &n){
    
        static int i {0}; 
        
        if(n[i]== n[n.size()-(i+1)] && i == n.size()-1 ){
            
            

        
            return true;
        }else if( i == n.size()-1){
            return false;
        }
        i++;
        isPalindrome(n);
    
    

}


int main(int argc, const char** argv) {

    string word;
    getline(cin,word);
    string numbsLine; 
    vector<int> numbs; 
    int numb {0};


    
    getline(cin, numbsLine);
    
    
    
    stringstream nsL(numbsLine);

    

    while (nsL >> numb){
        numbs.push_back(numb);
    }
    
    

    cout<< isPalindrome(word);
    cout<< isPalindrome(numbs);


    return 0;
}

