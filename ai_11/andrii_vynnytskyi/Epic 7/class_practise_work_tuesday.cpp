#include <iostream>
using namespace std;

int count_sym(string text)
{
    int count = 0;
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


int main() {
    const double duim = 2.54;
    const int lenght = 100;
    double lenght_m = (lenght * 3 * 12 * duim)/100;
    string name = "Vynnytskyi";
    double interval = count_sym(name) * 0.8;
    double size = name.size() * interval;

    cout<< medium(name,lenght_m, size, interval);
    
    return 0;
}
