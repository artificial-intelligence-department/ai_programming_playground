#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int CalculateGolos(string surname){
    int count=0;
    for(int i = 0; i < surname.length(); i++){
        char ch = surname[i];
        if(ch == 'e' || ch == 'a' || ch  == 'i' || ch == 'u' || ch == 'o' || ch == 'y'){
            count++;
        }
    }
    return count;
}

double stadium_length(int length){
    double new_length;
    new_length = length*3*12*0.0254;
    return new_length;
}

void WriteToFile_left(double n, string surname, double word_length, double symbol_length){
    ofstream oFile("banners.txt");
    if(!oFile.is_open()){
        cout << "error1";
        return;
    }
    int i = 1;
    while(i < n){
        oFile << surname;
        i++;
    }
    int number = int(n);
    double r = n - number;
    double l = r*word_length;
    int new_n = l / symbol_length;
    for(int i = 0; i < new_n; i++){
        oFile << surname[i];
    }
    oFile.close();
}

void WriteToFile_right(double n, string surname, double word_length, double symbol_length){
    ofstream oFile("banners2.txt");
    if(!oFile.is_open()){
        cout << "error1";
        return;
    }
    int number = int(n);
    double r = n - number;
    double l = r*word_length;
    int new_n = l / symbol_length;
    for(int i = 0; i < new_n; i++){
        oFile << surname[i];
    }
    int i = 1;
    while(i < n){
        oFile << surname;
        i++;
    }
    oFile.close();
}

double centre(double stadium_length){
    double centre;
    centre = stadium_length/2;
    return centre;
}

string ReadFromFile(){
    ifstream iFile("banners.txt");
    if(!iFile.is_open()){
        cout << "error";
    }
    string line;
    getline(iFile, line);
    iFile.close();
    return line;
}

void print(int left_s, int right_s, string line){

}

struct Stadium{
    int group;
    int length;
    int width;
};

int main(){
    Stadium Shelep = {14, 130, 100};
    string surname = "shelep";
    int count = CalculateGolos(surname);
    float symbol_length = count*0.8;
    double word_length = symbol_length*surname.length();
    double stad_length = stadium_length(Shelep.length);
    double n = stad_length / word_length;
    double center = centre(stad_length);
    WriteToFile_left(n, surname, word_length, symbol_length);
    string line = ReadFromFile();
    cout << line;
    cout << endl;
    double left = center-1.5;
    double right = center+1.5;
    int left_s = left/symbol_length;
    int right_s = right/symbol_length;
    for(int i = left_s-1; i <= right_s-1; i++){
        cout << line[i];
    }
    return 0;
}