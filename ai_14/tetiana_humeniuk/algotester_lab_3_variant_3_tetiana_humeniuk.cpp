#include <stdio.h>  
#include <string.h>

int main() {
    char S[100000];
    scanf("%s", S);

    int size = strlen(S);
    char S_compressed[size * 2];

    int index = 0;
    for (int i = 0; i < size; ++i) 
    {
        int count = 1;
        while (i < size - 1 && S[i] == S[i + 1]) 
        {
            count++;
            i++;
        }

        S_compressed[index] = S[i];
        index++;

        if (count > 1) 
        {
            sprintf(S_compressed + index, "%d", count); 
            index += snprintf(NULL, 0, "%d", count);  
        }
    }
    for (int i = 0; i < index; i++) {
        printf("%c", S_compressed[i]);
    }

    return 0;
}

