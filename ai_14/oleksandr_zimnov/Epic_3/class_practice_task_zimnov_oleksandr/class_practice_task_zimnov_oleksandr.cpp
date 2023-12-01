#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, action;
    string temp;
    cout << "Enter the number of books: ";
    cin >> N;
    while(N < 1){
        cout << "Enter the number of books again (it's must be from 1): ";
        cin >> N;
    }
    string* array = new string[N];
    string* array2 = new string[N];
    cin.ignore();
    for (int i = 0; i < N; i++) {
        cout << "Enter " << i+1 << " book: ";
        getline(cin, array[i]);
        array2[i]=array[i];
    }
    do{
    cout << endl << "1) List of books" << endl;
    cout << "2) Take a book" << endl;
    cout << "3) Return a book" << endl;
    cout << "4) Exit" << endl << endl;
    cout << "Choose your action: ";
    cin >> action;
    cout << endl;
    while(action<1 || action>4){
        cout << "Choose your action (it's must be from 1 to 4): ";
        cin >> action;
    }
    if(action==1){
        for(int i=0; i<N; i++){
            if(array2[i]=="0"){
                cout << array[i] << " -- Absent" << endl;
            }else{
                cout << array[i] << endl;
            }            
        }
    }
    if(action==2){
        int correct=0;
        string temp2="Y";
        if(correct==-1){
            tryAgain:
            cout << "This book wasn't found!" << endl;
            do{
            cout << "Do you want to continue? (Y/N)";
            cin >> temp2;
            }
            while(temp2!="Y" && temp2!="N");
        }
        if(temp2=="Y"){
        cout << "Enter a book: ";
        cin.ignore();
        getline(cin, temp);
        for(int i=0; i<N; i++){
            if(array2[i]==temp && array2[i]!="0"){
                array2[i]="0";
                correct++;
            }
        }
        if(correct==0){
            goto tryAgain;
        }
    }}
    if(action==3){
        int correct=0;
        string temp2="Y";
        if(correct==-1){
            tryAgain2:
            cout << "This book wasn't found!" << endl;
            do{
            cout << "Do you want to continue? (Y/N)";
            cin >> temp2;
            }
            while(temp2!="Y" && temp2!="N");
        }
        if(temp2=="Y"){
        cout << "Enter a book: ";
        cin.ignore();
        getline(cin, temp);
        for(int i=0; i<N; i++){
            if(array[i]==temp && array2[i]=="0"){
                array2[i]=array[i];
                correct++;
            }
        }
        if(correct==0){
            goto tryAgain2;
        }
    }}
    }
    while(action!=4);
    return 0;
}
