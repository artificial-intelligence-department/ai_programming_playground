#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <ctime>
#include <limits>
#include <cmath>

using namespace std;

int main()
{
    vector<char> arr = {'6', '6', '6', '6', '7', '7', '7', '7', '8', '8', '8', '8', '9', '9', '9', '9', '1', '1', '1', '1', 'J', 'J', 'J', 'J', 'Q', 'Q', 'Q', 'Q', 'K', 'K', 'K', 'K', 'A', 'A', 'A', 'A'};
    random_device rd;
    mt19937 g(rd());
    shuffle(arr.begin(), arr.end(), g);

    vector<char> newArr(arr.begin(), arr.begin() + 4);
    arr.erase(arr.begin(), arr.begin() + 4);

    vector<char> newArrr(arr.begin(), arr.begin() + 4);
    arr.erase(arr.begin(), arr.begin() + 4);

    bool svinguess = false;
    bool hoholguess = true;
    bool found = false;
    bool found2 = false;
    bool hohol = false;
    bool foundFour1 = false;
    bool foundFour2 = false;
    bool randombool = false;
    char temp;
    char temp1;
    char temp2;
    char temp3;
    char n;
    char random;
    int foundfourplayer = 0;
    int foundfoursvin = 0;
    int randomIndex;
    string name;
    string answer;
    cout << "Придуймайте назву для вашого гравця: " << endl;
    cin >> name;
    cout << "Привіт, " << name << ", вас вітає гра 'Скринька', бажаєте ознайомитись з правилами гри чи пропустите цей етап? (Yes - ознайомлення з правилами, No - старт гри): ";
    cin >> answer;
    if (answer == "Yes" || answer == "yes")
    {
        goto rules;
    }
    if (answer == "No" || answer == "no")
    {
        goto playercards;
    }
rules:
    cout << "\n--------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Кожен гравець отримує по 4 карти. Гра починається з питання вашому противнику чи є у нього карта певного номіналу, наприклад: \n - У вас є валет? \n - Так \nГравець забирає всі вальти і знову задає питання. Коли Гравець не вгадує карту, він тягне карту з колоди та хід переходить противнику. Якщо хтось з гравців збирає 4 карти одного й того самого номіналу він відкладає їх зі своєї руки та відкладає в сторону тим самим отримує +1 очко. Задача кожного з гравців набрати більше очків ніж противник. Можна питати лише свої карти. Якщо в когось з гравців закінчується карти, гра закінчиться та виводиться рахунок. Успіхів!" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------\n"
         << endl;

playercards:
    hohol = false;
    found = false;
    foundFour1 = false;
    cout << "\n***************************************" << endl;
    cout << "Карти " << name << ": ";
    for (char card : newArr)
    {
        cout << card << " ";
    }
    cout << endl;
    cout << "---------------------------------------" << endl;
    cout << name << ", питай карту, яку хочеш забрати: " << endl;
    cout << "*************************************** " << endl;
    cin >> n;
    for (char card : newArr)
    {
        if (n == card)
        {
            found = true;
            goto hoholguess;
        }
    }
    if (found == false)
    {
        cout << "Ти кого вирішив обманути, в тебе нема такої карти! " << endl;
        goto playercards;
    }
hoholguess:
    if (hoholguess == true)
    {
        if (newArr.size() == 0)
        {
            temp3 = arr[0];
            arr.erase(next(arr.begin(), 0));
            newArr.push_back(temp3);
        }
        for (int i = 0; i < newArrr.size(); i++)
        {
            if (n == newArrr[i])
            {
                hohol = true;
                temp2 = newArrr[i];
                newArrr.erase(next(newArrr.begin(), i));
                newArr.push_back(temp2);
                i--;
            }
            if (i == (newArrr.size() - 1) && hohol == true)
            {
                cout << "\n---------------------------------------" << endl;
                cout << name << ", ти сьогодні фартовий, забираєш всі: " << temp2 << " в КАБАНОСА" << endl;
                cout << "--------------------------------------- " << endl;
                foundFour1 = true;
                goto foundFour;
            }
        }
        temp3 = arr[0];
        arr.erase(next(arr.begin(), 0));
        newArr.push_back(temp3);
        cout << "\n===========================================================" << endl;
        cout << "Нажаль ти не вгадав, тепер черга Кабаноса вгадувати карту!" << endl;
        cout << "===========================================================" << endl;
        svinguess = true;
        goto foundFour;
    }

svinguess:
    if (svinguess == true)
    {
        if (newArrr.size() == 0)
        {
            temp3 = arr[0];
            arr.erase(next(arr.begin(), 0));
            newArrr.push_back(temp3);
        }
        svinguess = false;
        foundFour2 = false;
    random:
        srand(static_cast<unsigned int>(time(nullptr)));
        char randomIndex = rand() % newArrr.size();
        if (randombool == true)
        {
            if (random == newArrr[randomIndex])
            {
                goto random;
            }
        }
        random = newArrr[randomIndex];
        randombool = false;
        cout << "\n***************************************" << endl;
        cout << "Кабанос хоче вкрасти в тебе: " << newArrr[randomIndex] << endl;
        cout << "---------------------------------------" << endl;
        for (int i = 0; i < newArr.size(); i++)
        {
            if (newArrr[randomIndex] == newArr[i])
            {
                temp = newArr[i];
                newArr.erase(next(newArr.begin(), i));
                newArrr.push_back(temp);
                found2 = true;
                i--;
            }
        }

        if (found2 == true)
        {
            cout << "Кабанос вгадав карту: " << newArrr[randomIndex] << " та забариє всіх в " << name << endl;
            cout << "***************************************" << endl;
            svinguess = true;
            found2 = false;
            foundFour2 = true;
            randombool = true;
            goto foundFour4;
        }
        else
        {
            temp1 = arr[0];
            arr.erase(next(arr.begin(), 0));
            newArrr.push_back(temp1);
            cout << "Кабанос не вгадав карту, настала твоя черга! " << endl;
            cout << "***************************************" << endl;
            svinguess = false;
            foundFour2 = false;
            randombool = false;
            goto foundFour4;
        }
    }
foundFour:
    std::sort(newArr.begin(), newArr.end());
    if (newArr.size() > 3)
    {
        for (int i = 0; i <= newArr.size() - 4; ++i)
        {
            if (newArr[i] == newArr[i + 1] && newArr[i] == newArr[i + 2] && newArr[i] == newArr[i + 3])
            {
                cout << "\n=======================================" << endl;
                cout << name << " зібрав всі: " << newArr[i] << endl;
                cout << "=======================================" << endl;
                newArr.erase(newArr.begin() + i, newArr.begin() + i + 4);
                foundfourplayer++;
                break;
            }
        }
    }
    if (arr.size() == 0 && newArr.size() == 0 && newArrr.size() == 0)
    {
        if (foundfourplayer > foundfoursvin)
        {
            cout << "\nWIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            cout << name << "виграв Кабаноса, тепер він відправляється на сало! Рахунок: " << foundfourplayer << ":" << foundfoursvin << endl;
            cout << "WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            return 0;
        }
    }
    else if (arr.size() == 0 && newArr.size() == 0 && newArrr.size() == 0)
    {
        if (foundfourplayer < foundfoursvin)
        {
            cout << "\nWIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            cout << "Кабанос виграв, " << name << " йде засмучений додому, рахунок: " << foundfoursvin << ":" << foundfourplayer << endl;
            cout << "WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            return 0;
        }
    }
    else if (arr.size() == 0 && newArr.size() == 0 && newArrr.size() == 0)
    {
        if (foundfourplayer == foundfoursvin)
        {
            cout << "\nWIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            cout << "Перемогла дружба, Кабанос і " << name << " йдуть додому, рахунок: " << foundfoursvin << ":" << foundfourplayer << endl;
            cout << "WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            return 0;
        }
    }
    else if (newArrr.size() == 0)
    {
        cout << "\n+++++++++++++++++++++++++++++++" << endl;
        cout << "В Кабаноса закінчились карти. Підводимо підсумки! " << endl;
        cout << "+++++++++++++++++++++++++++++++" << endl;
        if (foundfourplayer > foundfoursvin)
        {
            cout << "\nWIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            cout << name << "виграв Кабаноса, тепер він відправляється на сало! Рахунок: " << foundfourplayer << ":" << foundfoursvin << endl;
            cout << "WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            return 0;
        }
        else if (foundfourplayer < foundfoursvin)
        {
            cout << "\nWIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            cout << "Кабанос виграв, " << name << " йде засмучений додому, рахунок: " << foundfoursvin << ":" << foundfourplayer << endl;
            cout << "WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            return 0;
        }
        else if (foundfourplayer == foundfoursvin)
        {
            cout << "\nWIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            cout << "Перемогла дружба, Кабанос і " << name << " йдуть додому, рахунок: " << foundfoursvin << ":" << foundfourplayer << endl;
            cout << "WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            return 0;
        }
    }
    else if (newArr.size() == 0)
    {
        cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "У " << name << " закінчились карти. Підводимо підсумки гри! " << endl;
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        if (foundfourplayer > foundfoursvin)
        {
            cout << "\nWIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            cout << name << " виграв Кабаноса, тепер він відправляється на сало! Рахунок: " << foundfourplayer << ":" << foundfoursvin << endl;
            cout << "WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            return 0;
        }
        else if (foundfourplayer < foundfoursvin)
        {
            cout << "\nWIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            cout << "Кабанос виграв, " << name << " йде засмучений додому, рахунок: " << foundfoursvin << ":" << foundfourplayer << endl;
            cout << "WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            return 0;
        }
        else if (foundfourplayer == foundfoursvin)
        {
            cout << "\nWIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            cout << "Перемогла дружба, Кабанос і " << name << " йдуть додому, рахунок: " << foundfoursvin << ":" << foundfourplayer << endl;
            cout << "WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            return 0;
        }
    }
    std::cin.clear();
    if (foundFour1 == true)
    {
        goto playercards;
    }
    if (foundFour1 == false)
    {
        goto svinguess;
    }

foundFour4:
    std::sort(newArrr.begin(), newArrr.end());
    if (newArrr.size() > 3)
    {
        for (int i = 0; i <= newArrr.size() - 4; ++i)
        {
            if (newArrr[i] == newArrr[i + 1] && newArrr[i] == newArrr[i + 2] && newArrr[i] == newArrr[i + 3])
            {
                cout << "\n=======================================" << endl;
                cout << "Кабанос зібрав всі: " << newArrr[i] << " та відкладає їх в сторону" << endl;
                cout << "=======================================" << endl;
                newArrr.erase(newArrr.begin() + i, newArrr.begin() + i + 4);
                foundfoursvin++;
                break;
            }
        }
    }
    if (arr.size() == 0 && newArr.size() == 0 && newArrr.size() == 0)
    {
        if (foundfourplayer > foundfoursvin)
        {
            cout << "\nWIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            cout << name << "виграв Кабаноса, тепер він відправляється на сало! Рахунок: " << foundfourplayer << ":" << foundfoursvin << endl;
            cout << "WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            return 0;
        }
    }
    else if (arr.size() == 0 && newArr.size() == 0 && newArrr.size() == 0)
    {
        if (foundfourplayer < foundfoursvin)
        {
            cout << "\nWIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            cout << "Кабанос виграв, " << name << " йде засмучений додому, рахунок: " << foundfoursvin << ":" << foundfourplayer << endl;
            cout << "WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            return 0;
        }
    }
    else if (arr.size() == 0 && newArr.size() == 0 && newArrr.size() == 0)
    {
        if (foundfourplayer == foundfoursvin)
        {
            cout << "\nWIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            cout << "Перемогла дружба, Кабанос і " << name << " йдуть додому, рахунок: " << foundfoursvin << ":" << foundfourplayer << endl;
            cout << "WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            return 0;
        }
    }
    else if (newArrr.size() == 0)
    {
        cout << "\n+++++++++++++++++++++++++++++++" << endl;
        cout << "В Кабаноса закінчились карти. Підводимо підсумки! " << endl;
        cout << "+++++++++++++++++++++++++++++++" << endl;
        if (foundfourplayer > foundfoursvin)
        {
            cout << "\nWIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            cout << name << " виграв Кабаноса, тепер він відправляється на сало! Рахунок: " << foundfourplayer << ":" << foundfoursvin << endl;
            cout << "WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            return 0;
        }
        else if (foundfourplayer < foundfoursvin)
        {
            cout << "\nWIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            cout << "Кабанос виграв, " << name << " йде засмучений додому, рахунок: " << foundfoursvin << ":" << foundfourplayer << endl;
            cout << "WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            return 0;
        }
        else if (foundfourplayer == foundfoursvin)
        {
            cout << "\nWIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            cout << "Перемогла дружба, Кабанос і " << name << " йдуть додому, рахунок: " << foundfoursvin << ":" << foundfourplayer << endl;
            cout << "WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            return 0;
        }
    }
    else if (newArr.size() == 0)
    {
        cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "У " << name << " закінчились карти. Підводимо підсумки гри! " << endl;
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        if (foundfourplayer > foundfoursvin)
        {
            cout << "\nWIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            cout << name << "виграв Кабаноса, тепер він відправляється на сало! Рахунок: " << foundfourplayer << ":" << foundfoursvin << endl;
            cout << "WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            return 0;
        }
        else if (foundfourplayer < foundfoursvin)
        {
            cout << "\nWIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            cout << "Кабанос виграв, " << name << " йде засмучений додому, рахунок: " << foundfoursvin << ":" << foundfourplayer << endl;
            cout << "WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            return 0;
        }
        else if (foundfourplayer == foundfoursvin)
        {
            cout << "\nWIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            cout << "Перемогла дружба, Кабанос і " << name << " йдуть додому, рахунок: " << foundfoursvin << ":" << foundfourplayer << endl;
            cout << "WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN WIN" << endl;
            return 0;
        }
    }
    std::cin.clear();
    if (foundFour2 == true)
    {
        goto svinguess;
    }
    if (foundFour2 == false)
    {
        goto playercards;
    }

    cout << "hohol" << endl;
    return 0;
}