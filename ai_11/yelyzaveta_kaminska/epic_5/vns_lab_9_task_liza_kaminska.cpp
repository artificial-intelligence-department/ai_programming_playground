#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void write(const string& filename,const vector<string>& data){
    ofstream file(filename);
    if(file.is_open()){
        for(const auto& line : data){
            file << line << endl; 
        }
        file.close();
    } else{
        cout << "Unable to open file for writing." << endl;
    }

}
void read(const string& filename, vector<string>& data){
    ifstream file(filename);
    string line;
    if(file.is_open()){
        while(getline(file,line)){
            data.push_back(line);
        }
        file.close();
    }else {
        cout << "Unable to open file for writing." << endl;
    }
   
}
int main(){
    vector<string> file_1(10);
    vector<string> file_2(10);
    file_1[0]="Ghty";
    file_1[1]="657";
    file_1[2]="ABC";
    file_1[3]="123";
    file_1[4]="githn";
    file_1[5]="9080";
    file_1[6]="345";
    file_1[7]="Iouhtf";
    file_1[8]="AbC";
    file_1[9]="777";
    write("file_1.txt", file_1);
    vector<string> array_1(10);
    read("file_1.txt", array_1);
    for (auto & element : file_1)
    {
        for(int j=0; j< element.length(); j++){
            if(isdigit(element[j])){
                break;
            }
            else if (j == element.length() - 1) {
                file_2.push_back(element); 
            }     
        }
    };

    for (auto & element : file_2) 
    {
        cout << element << " ";
    }
    return 0;

}
