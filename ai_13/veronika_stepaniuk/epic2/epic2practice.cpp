#include<iostream>
#include<string>

int main()
{
    std::string weather;
    std::cout<<"Input weather conditions (sunny, rainy, cloudy, snowy, windy): ";
    std::cin>>weather;

    if(weather!="sunny"&&weather!="rainy"&&weather!="cloudy"&&weather!="snowy"&&weather!="windy") 
    {std::cout<<"Unpredicted weather condition.";
    return 0;}

    if(weather=="rainy"||weather=="snowy")
    std::cout<<"You should wear a jacket.\n";
    else
    std::cout<<"You don't need to wear a jacket.\n";

    if(weather=="sunny")
    std::cout<<"A great day for a picnic!\n";
    else if(weather=="rainy")
    std::cout<<"Perfect weather to read a book inside!\n";
    else if(weather=="cloudy")
    std::cout<<"Maybe visit a museum?\n";
    else if(weather=="snowy")
    std::cout<<"How about making a snowman?\n";
    else
    std::cout<<"Fly a kite if you have one!\n";

    switch(weather[1])
    {
        case 'u': //sUnny
        std::cout<<"Wear your favorite sneakers!";
        break;
        case 'a': //rAiny
        std::cout<<"Rain boots are a good idea!";
        break;
        case 'l': //cLoudy
        std::cout<<"Today, any shoes are suitable.";
        break;
        case 'n': //sNowy
        std::cout<<"Snow boots will warm your feet!";
        break;
        case 'i': //wIndy
        std::cout<<"Wear something durable!";
        break;
    }
    return 0;
}