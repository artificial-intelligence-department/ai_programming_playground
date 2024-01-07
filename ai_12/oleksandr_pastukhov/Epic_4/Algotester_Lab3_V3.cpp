#include<iostream>
#include<string>

int main(){
    using namespace std;
    string StartString,FinalString;
    cin >> StartString;

    int counter = 1;

    for(int i = 0;i < StartString.size();i++){
        if(StartString[i] == StartString[i+1])
            counter += 1;
        else{
            FinalString += StartString[i] + (counter > 1 ? to_string(counter) : "");
            counter = 1;
        } 
    }
    cout << FinalString << endl;
    return 0;
}

/*
int main(){
    using namespace std;
    string StartString,FinalString;
    cin >> StartString;
    int counter = 1;
    for(int i = 1;i < StartString.size();i++){
        if(StartString[i] == StartString[i-1])
            counter +=1;
        else{
            if(counter > 1){
                if(i != StartString.size()-1){
                    FinalString += StartString[i-1];
                    FinalString += to_string(counter);
                    counter = 1;
                }
                else{
                    counter += 1;
                    FinalString += StartString[i-1];
                    FinalString += to_string(counter); 
                }
            }
            else{
                FinalString += StartString[i-1];
                counter = 1;
            }
        }
    }
    cout << FinalString;
    return 0;
}
*/