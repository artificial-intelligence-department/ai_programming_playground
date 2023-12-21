#include <iostream>
#include <vector>
#include <string>

using namespace std;
char letter_convertor(char& );
void print(vector<int>);
void add(int);
void find_mean(double suma = 0);
void smallest();
void largest();

char choice{};
vector <int> numbers;
int num {};
size_t range {};
double mean {};


int main(){
    menu:
    {
            bool done = false;
        while(!done){
        range = numbers.size(); 
            cout << "P - Print numbers\n" <<
            "A - Add number\n" <<
            "M - Display mean of the numbers\n" <<
            "S - Display the smallest number\n" <<
            "L - Display the largest number\n" <<
            "Q - Quit\n" <<
            "Enter your choice: ";
            cin >> choice;
            letter_convertor(choice);
        if( choice=='P' || choice=='A'|| choice=='M' || 
        choice=='S'|| choice=='L' || choice=='Q' )
                done = true;
        else
        cout <<"Oops... You probably wrote smth different. Please try again\n";
        }
        
}
switch (choice)
{
case 'P':
    print(numbers);
    goto menu;
case 'A':
    add(num);
    goto menu;
case 'M':
    find_mean();
    goto menu;
case 'S':
    smallest();
    goto menu;
case 'L':
    largest();
    goto menu;
case 'Q':
    cout << "Have a nice day :)";
    break;
 }
}

char letter_convertor(char &choice){
    if (choice >= 'a' && choice <= 'z'){
        choice = choice - 32;
    }
    return choice;
}
void print(vector<int> numbers){
    if (range == 0)
        cout << "there is no numbers to print" << endl;
    if (range != 0){
        for (int i= 0; i < range; i++){
            cout << numbers.at(i) <<" ";
        }
    cout << endl;    
    }
}
void add(int num){
    cout << "Enter number u want to add: ";
            cin >> num;
            numbers.push_back(num);
            cout << num << " added" << endl;
}
void find_mean(double suma){
        if(range==0){
            cout << "Unable to determine mean - list is empty" <<endl;
        }
        else { 
            
        for (int i= 0; i < range; i++){
            suma += numbers.at(i);
        }
    mean = suma/range;
    cout << mean << endl;
    
    }
}
void smallest(){
    if(range==0){
            cout << "Unable to determine the smallest number - list is empty" << endl;
            }
    else {
        int min = INT_MAX; 
        for (int i= 0; i < range; i++){
        if (numbers.at(i)< min)
            min = numbers.at(i);              
        }   
    cout << min << endl;
    }
}
void largest(){
    if(range==0)
        cout << "Unable to the largest number - list is empty" << endl;
                
    else {
        int max = INT_MIN; 
        for (int i= 0; i < range; i++){
            if (numbers.at(i)> max)
                max = numbers.at(i);              
    }   
        cout << max << endl;
    }
}
