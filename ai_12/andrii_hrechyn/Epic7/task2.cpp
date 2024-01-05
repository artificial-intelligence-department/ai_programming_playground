#include <iostream>
#include<fstream>
using namespace std;

double calculate_lengthfield(const string& lastname);         //прототип функції

int main(){
string lastname;
cin >> lastname;    //ініціалізація змінної прізвище та присвоєння їй значення з консолі

double minlength = calculate_lengthfield(lastname);

cout << "The minimum field length required for the banner with the last name \"" << lastname << "\"is: " << minlength << " yards\"";


ofstream outputFile("output.txt");      //відкриття файлу для запaису результатів

//запис у файл результату
outputFile << "The minimum field length required for the banner with the last name \"" << lastname << "\"is: " << minlength << " yards\"";

outputFile.close();     //закриття файлу

    return 0;
}

double calculate_lengthfield(const string& lastname){           //функція для розрахунку довжини поля для розміщення банера з прізвищем
    const double letter_coef = 0.8;         //коефіцієнт ширини букви та інтервалу між символами

    const char vowelsLow[] = {'a', 'e', 'i', 'o','u','y'}; //ініціалізація одновимірного масиву (голосні літери у верхньому та нижньому положенні)
    const char vowelsUp[] = {'A', 'E', 'I', 'O','U','Y'};


    //кількість голосних букв у прізвищі
    int vowel_count = 0;            
    for (char letter : lastname){
        //перевірка чи є літера голосною
        for(int i = 0; i < 6; i++){
            if (letter == vowelsUp[i] || letter == vowelsLow[i]){
                vowel_count++;
                break;                  //у результаті якщо голосна буква знайдена, виходимо з циклу

            }
        }

    }
    //розмір букви з інтервалом між двома символами
    double letter_size = vowel_count * letter_coef;

    //найменша довжина поля, яка обов'язково розміститься в банер
    double minlength = static_cast<double>(static_cast<int>(letter_size / 3.0 + 0.5) * 100); //перевів у ярди використав статік_каст для переведення типу даних
    
    return minlength; //повернення результату
    }