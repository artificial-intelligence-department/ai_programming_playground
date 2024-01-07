#include <iostream>
#include<fstream>
using namespace std;

struct CI
{
    const double duim = 2.54;//константна дійсна змінна з подвійною точністю для запису скільки дюймів є сантиметр
    double lenght;
    double lenght_m = calculations();


double calculations()
{
    return (lenght * 3 * 12 * duim)/100;
}


};

int count_sym(string text)
{
    int count = 0;//Цілочисельна змінна для підрахунку символів
    char arr[] = {'a', 'e', 'i', 'o', 'u', 'y'};
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < text.size(); j++)
        {
            if(text[j] == arr[i])
            {
                count++;
            }

        }
    }
    return count;

}


string medium(string text, double lenght_f , double lenght,  double lenght_of_s)
{
    double buffer = lenght_f;
    while (true)
    {
        buffer = buffer - lenght;
        if(buffer < lenght_f / 2)
        {
            break;
        }

    }
    double buff = lenght_f / 2 - buffer;
    int i = 0;
    string result = "";
    while(buff + lenght_of_s > lenght_of_s)
    {
        buff -= lenght_of_s;
        if(lenght_of_s > buff)
        {
            result += text[i];
        }
        i++;
    }
    return result;
}
string read(const string& path)
{
    string output;
    string line;
    ifstream file;
    // Відкриття файлу для зчитування
    file.open(path, ios_base::app);
    if (!file){

        return "Failure" ;

    }
// Зчитування рядків з файлу та їх об'єднання
    while(getline(file , line))
    {
        output += line;

    }
// Закриття файлу
    file.close();
    return output;
}

int main() {
    CI len;
    len.lenght = 100;
    string name = read("C:/Users/Nout_1/CLionProjects/untitled7/output.txt");
    double interval = count_sym(name) * 0.8;
    double size = name.size() * interval;

    cout<< medium(name,len.calculations(), size, interval);

    return 0;
}
