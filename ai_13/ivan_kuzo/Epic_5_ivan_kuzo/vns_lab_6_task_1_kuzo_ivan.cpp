#include <stdio.h>
#include<string.h>
#define n 266

int smollest_word_size(char words[]){
    int min=265;
    int current_size=0;
    for (int i=0;words[i]!='\0';i++){
        if(words[i] != ' ' && words[i]!=',' && words[i]!='.')
            current_size++;
        else{
            if(current_size<min)
                min=current_size;
            current_size=0;
        }
    }
    return min;
}
int main()
{
    char str[n];
    printf("Print a list of words with dot after last: ");
    fgets(str,n,stdin);
    int max_size=smollest_word_size(str);
    printf("max size of word is: %d",max_size);


    return 0;
}