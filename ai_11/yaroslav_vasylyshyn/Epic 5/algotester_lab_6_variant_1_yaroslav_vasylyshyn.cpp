#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
    int N,k;
    cin>>N>>k;
    vector<string> words(N), words_un, buffer;
    unordered_map<string, int> Amountoftimes;
    for (int i = 0; i < N; i++)
    {
        cin>>words[i];
        transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);
        Amountoftimes[words[i]]++;  
    }
    sort(words.begin(), words.end());
    for (auto klutch_or_znach = Amountoftimes.begin(); klutch_or_znach != Amountoftimes.end(); klutch_or_znach++) 
    {
        auto& word = *klutch_or_znach;
    if (word.second >= k)     
        words_un.push_back(word.first);    
    }   
    sort(words_un.begin(),words_un.end());
    unique_copy(words_un.begin(), words_un.end(), back_inserter(buffer));
    vector <char> output, final;
    for (int i = 0; i < words_un.size(); i++)
    {
        for (int j = 0; j < words_un[i].size(); j++)
        {
            output.push_back(words_un[i][j]);
        }
    }
    sort(output.begin(), output.end());
    reverse(output.begin(), output.end());
    unique_copy(output.begin(), output.end(), back_inserter(final));
    if(final.size() == 0)
    cout<<"Empty!";
    else{
        cout<<final.size()<<'\n';
        for (int i = 0; i < final.size(); i++)
        {
            cout<<final[i]<<" ";
        }
    }
    return 0;
}