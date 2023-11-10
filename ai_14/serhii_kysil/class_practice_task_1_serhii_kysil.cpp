#include <iostream>
using namespace std;
int main() {
    string weather[5] = {"sunny", "rainy", "cloudy", "snowy", "windy"};
    string uswe;
    bool correct = false;
    do {
        cout << "Яка у вас погода на дворі?" << endl;
        for (int i = 0; i < 5; i++) {
            cout << weather[i] << endl;
        }
        cin >> uswe;
        correct = false;  
        for (int i = 0; i < 5; i++) {
            if (uswe == weather[i]) {
                if (uswe != weather[0] && uswe != weather[2] && uswe != weather[4]) {
                    cout << "На вулиці холодно і мокро, одягни куртку." << endl;
                    if (uswe == weather[1]){
                        cout<<"Якщо ж не хочеш гуляти, то це ідеальна погода, щоб почитати книжку всередині !" << endl;
                    }
                    else if (uswe == weather[3]){
                        cout<<"Як щодо того, щоб зліпити сніговика ?)" << endl;
                    }
                } else {
                    cout << "Куртка сьогодні тобі не знадобиться." << endl;
                    if (uswe == weather[0]){
                        cout<<"Це чудовий день для пікніка !"<< endl;
                    }
                    else if(uswe == weather[2]){
                        cout<<"Може відвідати музей ?"<< endl;
                    }
                    else if (uswe == weather[4]){
                        cout<<"Запусти повітряного змія, якщо він у тебе є !" <<endl;
                    }
                }
                switch (i) {
                    case 0:
                        cout << "Взуй улюблені кросівки !)" << endl;
                        break;
                    case 1:
                        cout << "Дощові чоботи - гарна ідея !" << endl;
                        break;
                    case 2:
                        cout << "Сьогодні підходить будь-яке взуття." << endl;
                        break;
                    case 3:
                        cout << "Снігові черевики зігріють твої ноги !" << endl;
                        break;
                    case 4:
                        cout << "Одягни щось міцне !" << endl;
                        break;
                }
                correct = true; 
                break;  
            }
        }
        if (!correct) {
            cout << "Ви ввели незнайому мені погоду, спробуйте знову." << endl;
        }
    } while (!correct);
    system("pause");
    return 0;
}