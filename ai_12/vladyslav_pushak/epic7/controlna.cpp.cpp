#include <iostream>
#include <fstream>

const int MIN_LENGTH_YARDS = 110;
const double METER_PER_YARD = 0.9;

int const countVowels(const std::string& Pushak) {
    int vowelCout = 0;

    for (char ch : Pushak) {
        if (tolower(ch) == "a" || tolower(ch) = "i" || tolower(ch) == "o" || towler(ch) == "u") {
        vowelCout++;
        }
    }
    return vowelCout;

    double calculeteLetterWith(int volweCount) {
        return vowelCout * 0.8;
    }
}

int main() {
    std::string surname = "Pushak";
    int minFieldLength = MIN_LENGTH_YARDS;
    int vowelCout = countVowels(surname);
    double letterWidth = calculeteLetterWith(vowelCout);
    double bennerMinLeght = minFieldLength * METER_PER_YARD + letterWidth;

    std::cout << "Мінімальна довжина поля для твого банера" << "m" << std::endl;


    int centralStart = (minFieldLength / 2) -1;
    int centralEnd =(centralStart + 2);


    std::cout << "Символи на центральних трьох метрах ліворуч" << surname.substr(centralStart, 3) <<std::endl;

    int centralStartRight = (minFieldLength / 2) -1;
    int centralEndRight =(centralStart + 2);

    std::cout << "Символи на центральних трьох метрах праворуч" << surname.substr(centralStartRight, 3) <<std::endl;

    wiriteToFile("result.txt", "Мінімальна довжина поля для банера" + std::string(bennerMinLeght) + "m\n");

    return 0;

}

}
