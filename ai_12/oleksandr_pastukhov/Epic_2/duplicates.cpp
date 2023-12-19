#include<iostream>
#include<string>
#include<map>
#include <cctype>

using std::cout,std::cin,std::map,std::string,std::pair;
void duplicates(string numb){
    for(int symb_idx = 0;symb_idx < numb.size();symb_idx++)
        numb[symb_idx] = tolower(numb[symb_idx]);

    map<char,int>elements;
    for(int i = 0;i < size(numb);i++){
        if(elements.count(numb[i]) == 0)
            elements.insert(pair<char,int>(numb[i],1));
        else
            elements[numb[i]] += 1;
    }
    int duplicates_count = 0;
    for(auto iter{elements.begin()}; iter != elements.end(); iter++){
        if(iter->second > 1)
            duplicates_count += 1;
    }
    cout << duplicates_count;
}
int main(){
    string ask_string;
    cout << "Enter your string: ";
    cin >> ask_string;
    duplicates(ask_string);
    return 1;

}