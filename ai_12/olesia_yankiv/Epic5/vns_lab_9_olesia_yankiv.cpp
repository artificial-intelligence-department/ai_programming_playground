#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE 512
#define BUFWORD 64

static int first_word(const char** s, char* w);
static int is_word(const char* s, const char* w);
static int count_consonants(const char* str);

int main() {
    char line[BUFSIZE];
    char word[BUFWORD];
    const char* ptr;
    
    FILE* fo;
    if ((fo = fopen("F1.txt", "rt")) == NULL) {
        // error!
        printf("Error opening file F1.txt!!!\n");
        return 1;
    }

    FILE* fout = fopen("F2.txt", "wt+");
    if (fout == NULL) {
        // error!
        printf("Error creating/opening file F2.txt!!!\n");
        fclose(fo);
        return 1;
    }

    // Copy lines from F1 to F2 where the line does not contain the first word
    while ((ptr = fgets(line, sizeof(line), fo)) != NULL) {
        if (!first_word(&ptr, word))
            continue;

        if (!is_word(ptr, word))
            fputs(line, fout);
    }

    // Close the files
    fclose(fo);
    fflush(fout);
    fclose(fout);

    // Count consonants in the first line of F2
    FILE* f2 = fopen("F2.txt", "rt");
    if (f2 == NULL) {
        // error!
        printf("Error opening file F2.txt!!!\n");
        return 1;
    }

    if (fgets(line, sizeof(line), f2) != NULL) {
        int consonantCount = count_consonants(line);
        printf("Number of consonants in the first line of F2: %d\n", consonantCount);
    }

    fclose(f2);

    return 0;
}

// Extracts the first word in the string
static int first_word(const char** s, char* w) {
    const char* p = *s;
    char* t = w;

    while (*p && !isalpha(*p))
        ++p;

    while (isalpha(*p) && (w - t < BUFWORD))
        *w++ = *p++;

    *w = '\0';
    *s = p;

    return (w != t);
}

// Checks if a word exists in the string
static int is_word(const char* s, const char* w) {
    const char* t = s;
    const size_t n = strlen(w);

    while ((s = strstr(s, w)) != NULL) {
        if ((t == s) || !isalpha(*(s - 1)) && !isalpha(*(s + n)))
            return 1;

        s += n;
    }

    return 0;
}

// Count consonants in a string
static int count_consonants(const char* str) {
    int count = 0;
    while (*str) {
        char c = tolower(*str);
        if (isalpha(c) && strchr("aeiou", c) == NULL) {
            count++;
        }
        str++;
    }
    return count;}
