#include <iostream>
#include <vector>
#include <string>

using namespace std;

string wordFormat(string input)
{
    string result;
    int l = input.length();
    for(int i = 0;i<l;i++)
    {
        if(input[i]=='0'&&i!=l-1)
        {
            result+=',';
        }
        else if(input[i]=='0'&&i==l-1)
        {
            break;
        }
        else
        {
            result+=input[i];
        }
    }

    return result;

}

int main()
{
    vector <string> word;

    
    string input;

    while(true)
    {
        getline(cin,input);

        if(input.empty())
        {
            break;
        }
        
        word.push_back(wordFormat(input));
    }

    string output;

    for(int i = 0; i<word.size();i++)
    { 
        if (word[i].length() + 1 > 60) 
        {
            for(int n = 60,j = 0;n-60<word[i].length();n+=60)
            {
                output+='(';
                for(j = n-60;j<n&&j<word[i].length();j++)
                {
                    if(word[i][j]!=','||j<n-1)
                    {
                        output +=word[i][j];
                    }
                }
                output += ")";
            }
        }
        else
        {
            output+='(';
            output+=word[i];
            output+=')';
        }
    }
    cout<<output<<"\n";
}
