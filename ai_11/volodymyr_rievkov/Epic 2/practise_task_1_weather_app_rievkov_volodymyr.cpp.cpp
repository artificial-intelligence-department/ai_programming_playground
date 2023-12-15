#include<iostream>
#include<string>
int main()
{
    std::string weather = "";
    std::cout << "Enter weather: ";
    std::cin >> weather;
    if(weather == "sunny")
    {
        std::cout << "You may leave your jacket at home." << std::endl;
    }
    else if(weather == "rainy")
    {
        std::cout << "You should take your jacket." << std::endl;
    }
    else if(weather == "cloudy")
    {
        std::cout << "You may leave your jacket at home." << std::endl;
    }
    else if(weather == "snowy")
    {
        std::cout << "You should take your jacket." << std::endl;
    }
    else if(weather == "windy")
    {
        std::cout << "You may leave your jacket at home." << std::endl;
    }
    else
    {
        std::cout << "You entered wrong weather." << std::endl;
    }
     if(weather == "sunny")
    {
        std::cout << "You may go play volleyball." << std::endl;
    }
    else if(weather == "rainy")
    {
        std::cout << "You may go to the cafe." << std::endl;
    }
    else if(weather == "cloudy")
    {
        std::cout << "You may go for a walk." << std::endl;
    }
    else if(weather == "snowy")
    {
        std::cout << "You may go make snowman." << std::endl;
    }
    else if(weather == "windy")
    {
        std::cout << "You may go to the cinema." << std::endl;
    }
    else
    {
        std::cout << "you entered wrong weather"; 
    }
    switch(weather[0])
    {
        case 's':
        if(weather[1] == 'u')
        {
            std::cout << "You may take sandals." << std::endl; 
        }
        else
        {
            std::cout << "You may take warm boots." << std::endl;
        }
        break;
        case 'r':
        std::cout << "You may take tough sneakers." << std::endl;
        break;
        case 'c':
        std::cout << "You may take sneakers." << std::endl;
        break;
        case 'w':
        std::cout << "You may take sneakers." << std::endl;
        break;
        default:
        std::cout << "You enterd wrong weather." << std::endl;
        break;
    }

}