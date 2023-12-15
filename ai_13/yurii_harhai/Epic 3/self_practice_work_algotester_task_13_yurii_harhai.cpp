#include <iostream>
#include <vector>

using namespace std;

int main(){
char choice{0};
vector <int> numbers;
int num {0};
int range {0};
double mean {0};
    menu:{
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
            
        if( choice=='P' || choice=='p' || choice=='A' || choice=='a' || choice=='M' || 
        choice=='m' || choice=='S'|| choice=='s' || choice=='L' || choice=='l' || choice=='Q' || choice=='q')
                done = true;
        else
        cout <<"Oops... You probably wrote smth different. Please try again\n";
        }

        }
        if((choice=='P'||choice=='p')&& range ==0){
                    cout << "0\n";
                    goto menu;
                }
                if((choice=='P'||choice=='p')&& range !=0){
                    for (int i= 0; i < range; i++){
                        cout << numbers.at(i) <<" ";
                    }
                cout << endl;    
                goto menu;
                }   
         
        else if(choice=='A' || choice=='a'){
            cout << "Enter number u want to add: ";
            cin >> num;
            numbers.push_back(num);
            cout << num << " added" << endl;
            goto menu;
            }    
     if(choice=='M' || choice=='m'){
            if(range==0){
                cout << "Unable to determine mean - list is empty" <<endl;
                goto menu;
            }
            else { 
                int suma {};
            for (int i= 0; i < range; i++){
                suma += numbers.at(i);
            }
        mean = suma/range;
        cout << mean << endl;
        goto menu;
        }
     }
        if(choice=='S' || choice=='s'){
           if(range==0){
                cout << "Unable to determine the smallest number - list is empty" << endl;
                goto menu;
                }
            else {
                int min = INT_MAX; 
                for (int i= 0; i < range; i++){
                if (numbers.at(i)< min)
                    min = numbers.at(i);              
                }   
            cout << min << endl;
            }
        goto menu;
        }   
        if(choice=='L' || choice=='l'){
           if(range==0){
                cout << "Unable to the largest number - list is empty" << endl;
                goto menu;}
            else {
           int max = INT_MIN; 
            for (int i= 0; i < range; i++){
                if (numbers.at(i)> max)
                    max = numbers.at(i);              
            }   
        cout << max << endl;
        goto menu;
        }  
        } 
        if(choice=='Q' || choice=='q'){
        cout << "Good bye :)";
        return 0;
        }
    }
    




    
