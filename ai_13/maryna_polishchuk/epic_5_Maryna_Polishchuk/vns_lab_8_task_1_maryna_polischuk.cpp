#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Car {
  string mark, serialNum, regNum,  graduationYear;
};

void createFile()
{
    ofstream fout("dataStorage.dat", ios::binary);

    if (fout.is_open()) {
        fout.close();
        cout << "file was created>" << endl;
    } else
        cout << "err of creating file>" << endl;

    cout << endl;
}

    //зчитування записаних данних про автомобілі
Car readfile(int index, int carsCount)
{
    ifstream fin("dataStorage.dat");

    string line;

        //тут пропускаємо index машин, щоб прочитати інфу про потрібну
    for (int i = 0; i < index * 4; i++)
        getline(fin, line);    

    Car output;
    for (int i = 0; getline(fin, line); i++)
    {
        switch (i)
        {
        case 0:
            output.mark = line;
            break;
        case 1:
            output.serialNum = line;
            break;
        case 2:
            output.regNum = line;
            break;
        case 3:
            output.graduationYear = line;
            break;
        }
    }
    
    return output;
}

    //додавання нового автомобіля до бінарного файлу
void writeToFile(Car car, int carCount)
{
    ofstream fout("dataStorage.dat", ios::binary | ios::app); //app -> відкриття файлу з кінця для запису в нього якихось данних
    
    if (fout.is_open()) 
    {
        fout << car.mark << endl;
        fout << car.serialNum << endl;
        fout << car.regNum << endl;
        fout << car.graduationYear << endl;
        cout << "car added to file!" << endl;
    } else 
        cout << "Error while try to tead file!" << endl;

  fout.close();
}

Car addCar(int carCount)
{
    Car input;

    cout << "Car mark: "; cin >> input.mark;
    cout << "Car serialNum: "; cin >> input.serialNum;
    cout << "Car regNum: "; cin >> input.regNum;
    cout << "Car graduationYear: "; cin >> input.graduationYear;

    cout << "car added... ";

    writeToFile(input, carCount);
    return input;
}

void deleteInitialCar(vector<Car> &cars, int index) 
{
    ifstream fin("dataStorage.dat");
    ofstream fout("temp.dat");

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Error while try to open file..." << endl;
        return;
    }

    string line;
    vector<Car> tempVect;
    int curLine = 0;

    for (int i = 0; i + index < cars.size()-1; i++)
        tempVect.push_back(cars[i+index]);
    cars = tempVect;
    
    while (getline(fin, line)) 
    {
        curLine++;
            //тут ми перезаписуємо файл
            //основна ідея в тому що ми ігоруємо ті чотири рядки, де 
            //запиcана інф-ія про автомобіль,
            //кількість, скільки треба видалити автомобілів (index)
            //та кількість рядків з інформацією
        if(curLine <= index * 4)
            continue;
        fout << line << endl;
    }

    fin.close();
    fout.close();

        //перезаписуємо файл, в якому зберігається інфа про автомобілі
    remove("dataStorage.dat");
    rename("temp.dat", "dataStorage.dat");
    
    cout << "Car deleted successfully" << endl;
}

int main()
{
    vector<Car> cars;
    int carsCount = 5;

    //createFile();
    
        //зчитуємо з файлу інфу про існуючі машини
    cout << "all info about cars: " << endl;
    for (int i = 0; true; i++)
    {
        cars.push_back(readfile(i, carsCount));
        
        string temp = cars[i].mark; //для дебагу
        if(temp == "")
            break;

        cout << "Car " << i+1 << ": " << endl;
        cout << "   mark: " << cars[i].mark << endl;
        cout << "   serialNum: " << cars[i].serialNum << endl;
        cout << "   regNum: " << cars[i].regNum << endl;
        cout << "   graduationYear: " << cars[i].graduationYear << endl;
    }

        //видаляємо три перших автомобіля
    deleteInitialCar(cars, 3);
    
    if(cars.size() == 0)
        cout << "there are no cars";
    else
    {
        cout << "lefted cars: " << endl;
        for (int i = 0; i < cars.size(); i++)
            cout << "   regNum: " << cars[i].regNum << endl;
    }
    return 0;
}
