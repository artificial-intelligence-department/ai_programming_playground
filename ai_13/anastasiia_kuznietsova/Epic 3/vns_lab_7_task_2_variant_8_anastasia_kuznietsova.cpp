#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string astrology(int entered_value)
{
    const char* animals[]={"Rat","Ox","Tiger","Rabbit","Dragon","Snake","Horse","Sheep","Monkey","Rooster","Dog","Boar"};
    const char* colors[]={"Green","Red","Yellow","Blue","Black"};
    
    int chinese_year_animal = (entered_value - 1900) % 12;
    int chinese_year_color = (entered_value - 1900) % 5;

    string chinese_year = string(colors[chinese_year_color]) + " " + string(animals[chinese_year_animal]);

return chinese_year;
}

string astrology(string entered_value)
{
    const char* user_sign;
    const char* sign[]={"Aries","Taurus","Gemini","Cancer","Leo","Virgo","Libra","Scorpio","Sagittarius","Capricorn","Aquarius","Pisces"};
    if (entered_value=="April")
    {
        user_sign=sign[0];
    }
    else if (entered_value=="May")
    {
        user_sign=sign[1];
    }
    else if (entered_value=="June")
    {
        user_sign=sign[2];
    }
    else if (entered_value=="July")
    {
        user_sign=sign[3];
    }
    else if (entered_value=="August") 
    {
        user_sign=sign[4];
    }
    else if (entered_value=="September")
    {
        user_sign=sign[5];
    }
    else if (entered_value=="October")
    {
        user_sign=sign[6];
    }
    else if (entered_value=="November")
    {
        user_sign=sign[7];
    }
    else if (entered_value=="December") 
    {
        user_sign=sign[8];
    }
    else if (entered_value=="January")
    {
        user_sign=sign[9];
    }
    else if (entered_value=="February")
    {
        user_sign=sign[10];
    }
    else if (entered_value=="March") 
    {
        user_sign=sign[11];
    }
    else
    {
        cout<<"The data you've etered isn't correct. Please write your month properly.";
        return 0;
    }

return user_sign;
}

int main()
{
    int answer;
    cout<<"Choose a number of what you want to find out:\n";
    cout<<"1. The name of the year according to the old Japanese calendar."<<"\n2. Zodiac sign.\n";
    cin>>answer;

    if(answer==1)
    {
        int entered_value;
        cout<<"Write a year starting from 1900.\n";
        cin>>entered_value;
        cout<<"The "<<entered_value<<" year is the year of the "<<astrology(entered_value)<<"\n";
    }
    else if(answer==2)
    {
        string entered_value;
        cout<<"Write a month.\n";
        cin>>entered_value;
        cout<<"Your zodiac sign is "<<astrology(entered_value)<<"\n";;
    }
    else
    {
        cout<<"The entered numbers doesn't match any provided. Please choose one of the offered ones";
        return 0;
    }

    return 0;
}