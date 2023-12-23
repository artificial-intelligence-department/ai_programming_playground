#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int n;

void create()
{
    fstream f("f1.txt", fstream::out);
    string text;
    cout << "Enter F1 text" << endl;
    for(int i = 0; i < 10; i++)
    {
        getline(cin, text);
        f << text << endl;
    }
    f.close();
}

int golos()
{
    fstream f("f1.txt", fstream::in);

    if(f.is_open())
    {
        string text;
        int e, index = 0;
        int max_count = 0, max_index = 0;
        while (!f.eof())
        {
            e = 0;
            text = "";
            getline(f, text);
            for(int i = 0; i < text.size(); i++)
            {
                text[i] = tolower(text[i]);
                if(text[i] == 'a' || text[i] == 'e' || text[i] == 'u' || text[i] == 'i' || text[i] == 'o')
                {
                    e++;
                }
            }
            if(e >= max_count)
            {
                max_count = e;
                max_index = index;
            }
            index++;
        }
        cout << max_index << endl;
        return max_index;
        f.close();
    }
     else
    {
        cout << "file does not exist" << endl;
    }
};

void copyLine(int n)
{
    fstream f1("f1.txt", fstream::in);
    fstream f2("f2.txt", fstream::out | fstream::app);

    if(f1.is_open() && f2.is_open())
    {
        string line;
        int index=0;
        while(getline(f1, line))
        {
            if(index != n)
            {
                f2 << line << endl;
            }
            ++index;
        }
        f1.close();
        f2.close();
    } else{
        cout << "error" << endl;
        return;
    }
};

void printFile(const char* name){
    fstream f(name, fstream::in);

    if(f.is_open()){
        string line;
        while (!f.eof()){
            line = "";
            getline(f, line);
            cout << line << endl;
        }

        f.close();
    } else{
        cout << "file does not exist1" << endl;
        return;
    }
};

int main()
{
    create();
    cout << endl << "created file:" << endl;
    printFile("f1.txt");
    n=golos();
    copyLine(n);
}
