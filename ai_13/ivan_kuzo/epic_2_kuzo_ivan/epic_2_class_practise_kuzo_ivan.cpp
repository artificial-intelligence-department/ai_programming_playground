#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    char w;
    int a=0;
    string Wether;
    vector<string>wether;
    wether.push_back("Sunny");
    wether.push_back("Rainy");
    wether.push_back("Cloudy");
    wether.push_back("Snowy");
    wether.push_back("Windy");

    cout<<"Enter the wether from these variants: "<<endl;
    for(int i=0;i<5;i++){
        cout<<wether[i]<<endl;
    }

    cin>>Wether;
    Wether[0]=toupper(Wether[0]);
    
    for(int i=0;i<5;i++){
        if(wether[i]==Wether)
            a=1;
        if( a==0 && i==4){
            cout<<"Try again: ";
            cin>>Wether;
            Wether[0]=toupper(Wether[0]);
            i=0;
        }
    }

    if(Wether=="Snowy"||Wether=="Rainy"){
        cout<<"Take jacket!!!"<<endl;
    }

    else{
        cout<<"don't take a jacket "<<endl;
    }

    if (Wether=="Snowy"){
        cout<<"Go play snowballs!!!"<<endl;
    }
    else if(Wether=="Sunny"){
        cout<<"Good time for swiming"<<endl;
    }
    else if(Wether=="Cloudy"){
        cout<<"Doing whatever you want"<<endl;
    }
    else if(Wether=="Rainy"){
        cout<<"Beter sitting home"<<endl;
    }
    else{
        cout<<"Take windbreaker"<<endl;
    }

    if(Wether != "sunny")
        w=Wether[0];

    switch (w){
        case'S':
        {
            cout<<"put on warm boots";
            break;
        }
        case'C':
        {
            cout<<"sneakers will suit the most";
            break;
        }
        case'W':
        {
            cout<<"any closed shoes";
            break;
        }
        case'R':
        {
            cout<<"No white shoes!!!";
            break;
        }
        default:
            cout<<"It will be fine in slippers";
    }

    return 0;
}