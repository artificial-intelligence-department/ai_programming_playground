#include <iostream>
#include <string>


using namespace std;

int main()
{
    std::string car_brend;
    std::cout << "Вкажіть марку авто \n";
    std::cin >> car_brend;

    if (car_brend != "Audi" && car_brend != "BMW" && car_brend != "Toyota" && car_brend != "Volkswagen" && car_brend != "Lexus")
    {
        std::cout << "Вкажіть одну з цих марок авто (Audi, BMW, Lexus, Toyota, Volkswagen)\n";
        std::cin >> car_brend;
    }


    if (car_brend == "Audi")
    {
        std::cout << R"(
        Цей автомобіль буде найзручнішим для сімейного використання
        Ціна цього автомобіля 15000$
        До комлектації будуть входити чохли на сидіння)";
    }
    else if (car_brend == "Lexus")
    {
        std::cout << R"(
        Машина для тих хто любить розкіш
        Ціна цього автомобіля 14550$
        Гарантія на 1 рік безкоштовного обслуговування на сто)";
    }
    else if (car_brend == "Toyota")
    {
        std::cout << R"(
        Цей автомобіль ідеально підійде для бездоріжжя
        Ціна цього автомобіля 18800$
        Вам безкоштовно вмонтують бризговики)";
    }
    else if (car_brend == "BMW")
    {
        std::cout << R"(
        Якщо вам потрібна потужність, то цей варіант саме для вас
        Ціна цього автомобіля 16500$
        Вашим подарунком стане набір догляду за салоном)";
    }
    else if (car_brend == "Volkswagen")
    {
        std::cout << R"(
        Ця машина є поєнанням ціни та якості, буде служити довго
        Ціна цього автомобіля 11500$
        Бонусом буде набір зимової резини)";
    }
    return 0;
}