#include <iostream>
#include <fstream>

/*Загальні відомості
В американській системі виміру довжин використовуються ярди, фути, дюйми. 1 Ярд = 3 фути. 1 Фут = 12 дюймів. 1 Дюйм = 2.54 см.
Футбольні поля мають можуть мати різну довжину
Довжина: мінімум 100 ярдів, максимум 130 ярдів.
Ширина: мінімум 50 ярдів, максимум 100 ярдів.

// Довжина задається по варіанту 100 - 110 -120 - 130 для кожної групи інший розмір поля. ШІ -11  100 ярдів, ШІ -12 110 ярдів … і т.д.
*/

#include <string>

using namespace std;

struct Mid{ // struct 19
    double center;
    double left;
    double right;
};

int main(){
    string surname = "Chumachenko";

    int const game_length = 130; //const int 4.

    char owes[12] = {'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'i', 'o', 'u', 'y'}; // char array for голосні 6.
    int vowels = 0; // int var for голосні 1.
    float sur_len = 0; // float var for довжина прізвища 2.
    float letter_with = 0; 

    const float letter_with_coff = 0.8;

    const float yard = 0.9144; // in meters

    double game_length_c = yard * game_length; // double var for довжина поля 3.
    
    // for loop for голосні 10.
    for (int i = 0; i < surname.length(); i++){
        for (int j = 0; j < 12; j++) {
            if (surname[i] == owes[j]){
                vowels++;
                break;
            }
        }
    }

    letter_with = vowels * letter_with_coff;

    int amount_of_let = game_length_c / letter_with; 

    Mid Cent;

    Cent.center = game_length_c / 2;
    Cent.left = Cent.center - 3;
    Cent.right = Cent.center + 3;

    ofstream file("output1.txt"); // output file 16
    file << "при написанні прізвища з лівого краю поля —>  до правого" << endl;
    int lett = 0;
    for(float i = 0; i < game_length_c; i += letter_with){
        lett++;
        if((i + letter_with) >= Cent.left && (i + letter_with) <= Cent.right || i >= Cent.left && i <= Cent.right || (i - letter_with) >= Cent.left && (i - letter_with) <= Cent.right){
            cout << surname[lett%surname.length()] << " " << i << endl;
            file << surname[lett%surname.length()] << " " << i << endl;
        }
    }
    file.close();

    ofstream file1("output2.txt");
    file << "при написанні прізвища з правого краю поля <—  до лівого." << endl;

    lett = amount_of_let;
    for(float i = game_length_c; i > 0; i -= letter_with){
        lett--;
        if((i + letter_with) >= Cent.left && (i + letter_with) <= Cent.right || i >= Cent.left && i <= Cent.right || (i - letter_with) >= Cent.left && (i - letter_with) <= Cent.right){
            cout << surname[lett%surname.length()] << " " << i << endl;
            file1 << surname[lett%surname.length()] << " " << i << endl;
        }
    }
    file1.close();
    

    return 0;
}