#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
// shi 14 dovj 130 shir 90
const int field_dovj = 130;
const int shir = 90;
//const double = dium = 2.54;
int main (){
    const int numVowels = 4; // kormyliuk = 4 vowels
    const double letterShir = numVowels * 0.8;
    double bannerDovj = max(field_dovj, letterShir);
    ofstream outputFile ("banner_result.txt");
    outputFile << "Writing surname\n";
    outputFile << "Minimum Banner Length: " << bannerDovj << "yards\n";
    
    int centralCharsLeftToRight = static_cast<int>(ceil(3/letterShir));
    outputFile << "Central 3 Meters: " << centralCharsLeftToRight << "\n\n";
    
    outputFile << "Writing surname\n";
    outputFile << "Minimum Banner Length: " << bannerDovj << "yards\n";
    
    int centralCharsRightToLeft = static_cast<int>(ceil(3/letterShir));
    outputFile << "Central3 Meters: " << centralCharsRightToLeft << "\n";
    
    outputFile.close();
    return 0;
    }