#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

void create_first_file()
{
    ofstream outf("F1.txt");

    if(!outf)
    {
        cerr << "Error" << endl;
        exit(1);
    }

    outf << "Last Christmas I gave you my heart\n";
    outf << "But the very next day you gave it away\n";
    outf << "T1his year, to sa23ve 12me fr1om tears\n";
    outf << "213I'll giv13e it 3to someone sp42ecial, special\n";
    outf << "La34st Christ12mas I ga1ve 1you my h2eart\n";
    outf << "But 3948 the 24 very 24 next75 day you gav14e it away\n";
    outf << "This year, to save me from tears\n";
    outf << "I'll give it to someone special\n";
    outf << "Spe76c8ial\n";
    outf << "A face on a lover with a fire in his heart (I gave you mine)\n";
    outf << "A man under cover but you tore him apart\n";
    outf << "Maybe next year I'll give it to someone\n";
    outf << "I'll give it to someone special\n";

    outf.close();
};

void copy_in_file()
{
    ifstream inf("F1.txt");
    ofstream outf("F2.txt");

    if(!outf || !inf)
    {
        cerr << "Error" << endl;
        exit(1);
    }

    string line;
    
    while(getline(inf, line))
    {
        bool number = false;
        
        for(string:: iterator it = line.begin(); it != line.end(); ++it)
        {
            if(isdigit(*it))
            {
                number = true;
            }
        }

        if(!number)
        {
            outf << line << endl;
        }
    }

    inf.close();
    outf.close();
};

void copy_in_file_add()
{
    ifstream inf("F1.txt");
    ofstream outf("F2.txt");

    if(!outf || !inf)
    {
        cerr << "Error" << endl;
        exit(1);
    }

    string line;
    while(getline(inf, line))
    {
        for(string:: iterator it = line.begin(); it != line.end(); ++it)
        {
            if(isdigit(*it))
            {
                it = line.erase(it);
                it--;
            }
        }

        outf << line << endl;
    }

    inf.close();
    outf.close();
};

void counter()
{
    ifstream inf("F2.txt");
    
    if(!inf)
    {
        cerr << "Error" << endl;
        exit(1);
    }

    string line;
    int count = 0;

    while(getline(inf, line))
    {   
        string:: iterator it = line.begin();
            
        if(*it == 'A')
        {
            count++;
        }
    }

    inf.close();

    cout << "The number of lines that start with the letter 'A': " << count << endl;

};

int main()
{
    int choose;
    create_first_file();

    cout << "Do you want to copy all lines that do not contain numbers - 1 or to delete all numbers in lines - 2?" << endl;
    cin >> choose;

    if(choose == 1)
    {
        copy_in_file();
    }

    if(choose == 2)
    {
        copy_in_file_add();
    }
    
    counter();

    return 0;
}
