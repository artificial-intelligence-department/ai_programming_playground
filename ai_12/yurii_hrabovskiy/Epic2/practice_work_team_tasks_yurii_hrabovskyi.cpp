#include<iostream>
#include<string>

int main()
{   std:: string weather;

    std::cout<<"What the weather is? (choose sunny, rainy, cloudy, snowy or windy)\n";
    std::cin>>weather;

    if ( weather=="sunny" || weather=="cloudy" || weather=="windy" )
        std::cout<<"You don't need to wear a jacket\n";
    else 
        std::cout<<"Take your jacket\n";

    if (weather=="sunny"){
        std::cout<<"It's a great day for a picnic!\n";
    } else if (weather=="rainy"){
        std::cout<<"Perfect weather to read a book inside!\n";
    } else if (weather=="cloudy"){
        std::cout<<"Maybe visit a museum?\n";
    } else if (weather=="snowy"){
        std::cout<<"How about building a snowman?\n";
    } else if (weather=="windy"){
        std::cout<<"Fly a kite if you have one!\n";
    }
    
    switch (weather[1]) {
        case 'u':
            std::cout<<"Wear your favorite sneakers!\n";
            break;
        case 'a':
            std::cout<<"Rain boots are a good idea!\n";
            break;
        case 'l':
            std::cout<<"Any footwear is fine today.\n";
            break;
        case 'n':
            std::cout<<"Snow boots will keep your feet warm!\n";
            break;
        case 'i':
            std::cout<<"Wear something sturdy!\n";
             break;
        default:
            std::cout << "Invalid weather condition input.\n";
            break;
    }
    return 0;
}
    
    
   