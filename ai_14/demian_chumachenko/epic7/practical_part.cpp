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

int main(){
    string surname = "Chumachenko";

    int const game_length = 130; //const int 4.

    char owes[12] = {'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'i', 'o', 'u', 'y'}; // char array for голосні 6.
    int vowels = 0; // int var for голосні 1.
    float sur_len = 0; // float var for довжина прізвища 2.
    float letter_with = 0; 

    const float letter_with_coff = 0.8;

    //const float duym = 2.54;
    //const float foot = 12 * duym;
    //const float yard = 3 * foot;

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

    double center = game_length_c / 2;
    double left = center - 3;
    double right = center + 3;

    int lett = 0;
    for(float i = 0; i < game_length_c; i += letter_with){
        lett++;
        if((i + letter_with) >= left && (i + letter_with) <= right || i >= left && i <= right || (i - letter_with) >= left && (i - letter_with) <= right){
            cout << surname[lett%surname.length()] << " " << i << endl;
        }
    }
    
    cout << left << endl;
    cout << center << endl;
    cout << right << endl;

    return 0;
}