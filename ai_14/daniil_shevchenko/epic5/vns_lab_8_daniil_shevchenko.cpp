

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct Stadium
{
    string name;
    int year;
    int playgrounds;
    string sports;
};
ofstream newfile1("TextLab1.txt");
ofstream newfile2("TextLab2.txt");
void getstruct(Stadium array[], int number)
{
    for (int i = 0; i < number; i++)
    {
        cout << "Name = ";
        getline(cin, array[i].name);
        cout << "Building year = ";
        cin >> array[i].year;
        cout << "The number of playgrounds = ";
        cin >> array[i].playgrounds;
        cin.ignore(30000, '\n');
        cout << "Available sports are ";
        getline(cin, array[i].sports);
    }
}
void printstruct(Stadium array[], int number)
{
    for (int i = 0; i < number; i++)
    {
        newfile1 << "Stadium # " << i + 1 << ": " << endl;
        newfile1 << "Name: " << array[i].name << endl;
        newfile1 << "Building year: " << array[i].year << endl;
        newfile1 << "Number of playgrounds: " << array[i].playgrounds << endl;
        newfile1 << "Available sports: " << array[i].sports << endl;
        newfile1 << endl;
    }
}
void printstruct2(vector<Stadium> array, int number)
{
    for (int i = 0; i < number; i++)
    {
        newfile2 << "Stadium # " << i + 1 << ": " << endl;
        newfile2 << "Name: " << array[i].name << endl;
        newfile2 << "Building year: " << array[i].year << endl;
        newfile2 << "Number of playgrounds: " << array[i].playgrounds << endl;
        newfile2 << "Available sports: " << array[i].sports << endl;
        newfile2 << endl;
    }
}


int main()
{
    if (!newfile1 )
    {
        cerr << "Can't open file for writing in";
        exit(1);
    }
    if (!newfile2)
    {
        cerr << "Can't open file for writing in";
        exit(1);
    }

    int N;
    cout << "Enter the number of stadiums: ";
    cin >> N;
    cin.ignore(30000, '\n');
    Stadium* array = new Stadium[N];
    getstruct(array, N);
    printstruct(array, N);
    int year;
    cout << "Enter the year: ";
    cin >> year;
    cin.ignore(30000, '\n');
    vector<Stadium> newarray;
    newarray.resize(N);
    int j = 0;
    for (int i = 0; i < N; i++)
    {
        if (array[i].year >= year)
        {
            newarray[j] = array[i];
            j++;
        }
    }
    newarray.resize(j);
    Stadium additional1;
    Stadium additional2;
    
    cout << "Enter the additional stadiums: " << endl;
    cout << "Name = ";
    getline(cin, additional1.name);
    cout << "Building year = ";
    cin >> additional1.year;
    cout << "The number of playgrounds = ";
    cin >> additional1.playgrounds;
    cin.ignore(30000, '\n');
    cout << "Available sports are ";
    getline(cin, additional1.sports);
    
    cout << "Name = ";
    getline(cin, additional2.name);
    cout << "Building year = ";
    cin >> additional2.year;
    cout << "The number of playgrounds = ";
    cin >> additional2.playgrounds;
    cin.ignore(30000, '\n');
    cout << "Available sports are ";
    getline(cin, additional2.sports);

    int number;
   
    do
    {
        cout << "Enter the number";
        cin >> number;
        
    }
    while (number > j || number <= 0);
    cin.ignore(30000, '\n');
    vector<Stadium> newarray2;
    newarray2.resize(j + 2);
    for (int i = 0; i < number - 1; i++)
    {
        newarray2[i].name = newarray[i].name;
        newarray2[i].year = newarray[i].year;
        newarray2[i].playgrounds = newarray[i].playgrounds;
        newarray2[i].sports = newarray[i].sports;

    }
    newarray2[number - 1].name = additional1.name;
    newarray2[number - 1].year = additional1.year;
    newarray2[number - 1].playgrounds = additional1.playgrounds;
    newarray2[number - 1].sports = additional1.sports;
    
    newarray2[number].name = additional2.name;
    newarray2[number].year = additional2.year;
    newarray2[number].playgrounds = additional2.playgrounds;
    newarray2[number].sports = additional2.sports;

    for (int i = number + 1; i < j + 2; i++)
    {
        newarray2[i].name = newarray[i - 2].name;
        newarray2[i].year = newarray[i - 2].year;
        newarray2[i].playgrounds = newarray[i - 2].playgrounds;
        newarray2[i].sports = newarray[i - 2].sports;

    }
    printstruct2(newarray2, j+2);

    
}

