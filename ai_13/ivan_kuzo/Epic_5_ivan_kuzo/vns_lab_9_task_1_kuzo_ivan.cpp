#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
int numMaxA(const string& line){
    int num_count=0;
    int num=0;
    int currentA=0;
    string word;
    int max=0;
    istringstream iss(line);
    while(iss>>word){
        num_count++;
        for(char letter : word){
            if(letter=='a'||letter=='A'){
                currentA++;
            }
        
        }
        if (currentA>max){
            max=currentA;
            num =num_count;
        }
    }
    if(num!=0)
        return max;
    else
        return 0;
}
int numMaxA(vector<string>lines){
    int max=0;
    int index=0;
    for(int i=0;i<lines.size();i++){
        if(max<numMaxA(lines[i])){
            max=numMaxA(lines[i]);
            index=i+1;
        }
    }return index;
} 
bool theSameWord(const string& line){
    vector<string>words;
    string word;
    istringstream iss(line);
    while(iss>>word)
        words.push_back(word);
    for (int i=0;i<words.size();i++){
        for (int j=0;j<words.size();j++){
            if(words[i]==words[j] && i!=j)
                return true;
        }
    }return false;
}
void watch(const string& filename){
    ifstream file(filename);
    if(!file.is_open()){
        cerr<<"Trouble with opening";
        return;
    }
    cout<<"Content of file: "<<endl;
    string line;
    while(getline(file,line))
        cout<<line<<endl;
    file.close();
}
int main()
{
    ofstream file("newFile.txt");
    if(!file.is_open()){
        cerr<<"Trouble with opening";
        return 1;
    }
    vector<string>lines;
    for (int i=0;i<10;i++){
        cout<<i+1<<" line of file: ";
        string line;
        getline(cin,line);
        lines.push_back(line);
    }
    for (const auto& raws: lines)
        file<<raws<<endl;
    file.close();
    watch("newFile.txt");
    int a=numMaxA(lines);
    cout<<"the most letters a in a line: "<<a<<endl;

    ifstream file1("newFile.txt");
    if(!file1.is_open()){
        cerr<<"Trouble with opening";
        return 1;
    }
    ofstream file2("newFile2.txt");
    if(!file2.is_open()){
        cerr<<"Trouble with opening";
        return 1;
    }
    string copy;
    while(getline(file1,copy)){
        if(theSameWord(copy))
            file2<<copy<<endl;
    }
    cout<<"with 2+ same words: "<<endl;
    watch("newFile2.txt");

}