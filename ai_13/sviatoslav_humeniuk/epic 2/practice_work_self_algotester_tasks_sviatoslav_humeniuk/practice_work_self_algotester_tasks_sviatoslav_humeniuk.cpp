#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string month[12];
    month[0] = "january";
    month[1] = "february";
    month[2] = "march";
    month[3] = "april";
    month[4] = "may";
    month[5] = "june";
    month[6] = "july";
    month[7] = "august";
    month[8] = "september";
    month[9] = "october";
    month[10] = "november";
    month[11] = "december"; 

    int x;
    string y;

    cout << "I will help you to know your Zodiac sign." << endl; 

    cout << "Enter day: " << endl;
    do {
        cin >> x;

        cout << "Enter month" << endl;
        cin >> y;

    if (x>=22 && y==month[0]){
    cout << "You are aquarius.  ";
}
if (x<=21 && y==month[1]){
    cout << "You are aquarius.  ";
}
if (x>=22 && x<=29 && y==month[1]){
    cout << "You are pisces.";
}
if (x<=21 && y==month[2]){
    cout << "You are pisces. ";
}
if (x>=22 && y==month[2]){
    cout << "You are aries.  ";
}
if (x<=21 && y==month[3]){
    cout << "You are aries.";
}
if (x>=22 && x <= 30 && y==month[3]){
    cout << "You are taurus.";
}
if (x<=21 && y==month[4]){
    cout << "You are taurus.";
}
if (x>=22 && y==month[4]){
    cout << "You are gemini.";
}
if (x<=21 && y==month[5]){
    cout << "You are gemini.";
}
if (x>=22 && x <= 30 && y==month[5]){
    cout << "You are cancer.";
}
if (x<=21 && y==month[6]){
    cout << "You are cancer.";
}
if (x>=22 && y==month[6]){
    cout << "You are leo.";
}
if (x<=21 && y==month[7]){
    cout << "You are leo.";
}
if (x>=22 && y==month[7]){
    cout << "You are virgo.";
}
if (x<=21 && y==month[8]){
    cout << "You are virgo.";
}
if (x>=22 && x <= 30 && y==month[8]){
    cout << "You are libra.";
}
if (x<=21 && y==month[9]){
    cout << "You are libra.";
}
if (x>=22 && y==month[9]){
    cout << "You are scorpio. ";
}
if (x<=21 && y==month[10]){
    cout << "You are scorpio. ";
}
if (x>=22 && x <= 30 && y==month[10]){
    cout << "You are sagittarius.  ";
}
if (x<=21 && y==month[11]){
    cout << "You are sagittarius.  ";
}
if (x>=22 && y==month[11]){
    cout << "You are capricorn. ";
}
if (x<=21 && y==month[0]){
    cout << "You are capricorn. ";
}

        if ((x > 30 && y==month[8]) || (x > 30 && y==month[10]) || (x > 30 && y==month[5]) || (x >= 30 && y==month[1]) || (x > 30 && y==month[3]) || (x > 31 && y==month[0]) || (x > 31 && y==month[2]) || (x > 31 && y==month[4]) || (x > 31 && y==month[6]) || (x > 31 && y==month[7]) || (x > 31 && y==month[9]) || (x > 31 && y==month[11])){
            cout << "There is a mistake." << endl << "Check your date of birth" << endl << "Enter the day" << endl;
        }
    } while ((x > 30 && y==month[8]) || (x > 30 && y==month[10]) || (x > 30 && y==month[5]) || (x >= 30 && y==month[1]) || (x > 30 && y==month[3]) || (x > 31 && y==month[0]) || (x > 31 && y==month[2]) || (x > 31 && y==month[4]) || (x > 31 && y==month[6]) || (x > 31 && y==month[7]) || (x > 31 && y==month[9]) || (x > 31 && y==month[11])); 

    return 0;
}
