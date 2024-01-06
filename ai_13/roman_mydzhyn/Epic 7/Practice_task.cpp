// Загальні відомості
// В американській системі виміру довжин використовуються ярди, фути, дюйми. 1 Ярд = 3 фути. 1 Фут = 12 дюймів. 1 Дюйм = 2.54 см.
// Футбольні поля мають можуть мати різну довжину
// Довжина: мінімум 100 ярдів, максимум 130 ярдів.
// Ширина: мінімум 50 ярдів, максимум 100 ярдів.


// Використовуючи Ваше прізвище розрахувати найменшу довжину, яка необхідна для розміщення банера з Вашим прізвищем.
//  За умови, що прізвище можна записати лише в 1 ряд, а ширина букви(разом з інтервалом між символами) = кількості голосних букв у Вашому прізвищі * 0.8 метра.
// На основі обчислених розмірів букви визначити символи, які будуть знаходитись на 3-х центральних(по довжині) метрах поля. 
// Обчислення зробити для 2-х випадків:
// 1) при написанні прізвища з лівого краю поля —>  до правого
// 2) при написанні прізвища з правого краю поля <—  до лівого.
// Результат записати.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

	const double letterwide = 0.8; // ширина букви(разом з інтервалом між символами)
	const int sizeofarr = 6;

	stuct Information {
		std:: string surname;
		double letterWidth;
		double min_information_length;
		std:: vector<char> lefttoright;
		std:: vector<char> righttoleft

	}
	void filewriting (const Information & info){
		std:: ofstream fileout("surname.txt")
		if (fileout.is_open()) {
			fileout <<"Letter Width" << info.letterWidth << "meters" << std::endl;
			fileout <<"Minimum Information length: " << info.minIformationLength <<"meters" << std:: endl;
			fileout <<"Symbols left to rigth: ";
			for (char symbol : info.lefttorightSymbol)
				fileout << symbol << " ";
			}
		fileout << std::endl;
		 
		 fileout <<"Symbols right to left: ";
		for (char symbol : info.righttoleftSymbol){
			fileout << symbol << " ";
		
		}
		fileout << std::endl;
		fileout.close();
		else{
			std::cerr << "Unable to open file for writing." << std::endl;
    }
}
void readFromFile() {
    std::ifstream inFile("banner_data.txt");
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl;
        }
        inFile.close();
    } else {
        std::cerr << "Unable to open file for reading." << std::endl;
    }
}

void calculateBannerData(Information* info) {
    int vowelCount = 0;
    for (char letter : data->surname) {
        if (tolower(letter) == 'a' || tolower(letter) == 'e' || tolower(letter) == 'i' || tolower(letter) == 'o' || tolower(letter) == 'u') {
            vowelCount++;
        }
    }
    data->letterWidth = vowelCount * LETTER_WIDTH_MULTIPLIER;

    data->minIformationLength = info->letterWidth * info->surname.length();

    int centralIndex = info->surname.length() / 2;
    for (int i = 0; i < info->surname.length(); ++i) {
        info->lefttoRightSymbols.push_back(info->surname[i]);
        info->righttoLeftSymbols.push_back(info->surname[info->surname.length() - 1 - i]);
    }
}

int main() {
    Information* information = new Information;
    ->surname = "Mydzhyn";

    calculateInformation(information);
    writeToFile(*information);
    readFromFile();

    delete information;

    return 0;
}