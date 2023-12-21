#include <iostream>
#include <cstring>
using namespace std;

void onlynumbers(char str[]) 
{
    char *token;

    token=strtok(str, " ");
    while (token != NULL) 
    {
        bool digits=true;

        for (int i=0; i<strlen(token); i++) 
        {
            if (!isdigit(token[i])) 
            {
                digits=false;
                break;
            }
        }
        if (!digits)
        {
            cout<<token<<".";
        }

    token = strtok(NULL, " ");
    }
}


int main() 
{
    char str[256];
    cout<<"Enter a string\n";
    gets(str);
    onlynumbers(str);

return 0;
}