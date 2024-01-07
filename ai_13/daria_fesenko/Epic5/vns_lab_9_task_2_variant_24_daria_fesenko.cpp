#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define BUFSIZE 512
#define BUFWORD 64

static int count_digits(const char *word);
static int first_word(const char **s, char *w);
static void copy_lines_with_duplicate_words(FILE *input, FILE *output);
static int find_word_with_max_digits(FILE *fo);
static int is_word(const char *s, const char *w);

int main()
{
    FILE *fo;
    FILE *fout;
    char line[BUFSIZE];

    if ((fo = fopen("C:/Users/Acer/Desktop/F1.txt", "rt")) == NULL)
    {
        printf("Помилка відкриття вхідного файлу!!!\n");
        return 2;  
    }

    if ((fout = fopen("C:/Users/Acer/Desktop/F2.txt", "wt+")) == NULL)
    {
        printf("Помилка відкриття вихідного файлу!!!\n");
        fclose(fo);
        return 3;  
    }

    copy_lines_with_duplicate_words(fo, fout);

    fclose(fo);
    fclose(fout);

    if ((fo = fopen("C:/Users/Acer/Desktop/F2.txt", "rt")) == NULL)
    {
        printf("Помилка відкриття файлу F2!!!\n");
        return 4; 
    }

    int max_digits_word_number = find_word_with_max_digits(fo);
    printf("Слово з максимальною кількістю цифр знаходиться на позиції: %d\n", max_digits_word_number);

    fclose(fo);

    return 0;
}
static void copy_lines_with_duplicate_words(FILE *input, FILE *output)
{
    char line[BUFSIZE];
    char word[BUFWORD];
    const char *ptr;

    while ((ptr = fgets(line, sizeof(line), input)) != NULL)
    {
        const char *temp_ptr = ptr;

        while (first_word(&temp_ptr, word))
        {
            if (is_word(line, word))
            {
                fputs(line, output);
                break;
            }
        }
    }
}

static int count_digits(const char *word)
{
    int count = 0;
    while (*word)
    {
        if (isdigit(*word))
        {
            count++;
        }
        word++;
    }
    return count;
}

static int find_word_with_max_digits(FILE *fo)
{
    int max_digits = 0;
    int current_word_number = 0;
    int max_digits_word_number = 0;
    char line[BUFSIZE];
    const char *ptr;

    while ((ptr = fgets(line, sizeof(line), fo)) != NULL)
    {
        const char *temp_ptr = ptr;

        while (first_word(&temp_ptr, line))
        {
            char word[BUFWORD];
            int digits = count_digits(line);
            if (digits > max_digits)
            {
                max_digits = digits;
                max_digits_word_number = current_word_number;
            }
            current_word_number++;
        }
    }

    return max_digits_word_number;
}

static int first_word(const char **s, char *w)
{
    const char *p = *s;
    char *t = w;

    while (*p && !isalpha(*p))
        ++p;

    while (isalpha(*p) && (w - t < BUFWORD))
        *w++ = *p++;

    *w = '\0';
    *s = p;

    return (w != t);
}

static int is_word(const char *s, const char *w)
{
    const char *t = s;
    const size_t n = strlen(w);

    while ((s = strstr(s, w)) != NULL)
    {
        if ((t == s || !isalpha(*(s - 1))) && !isalpha(*(s + n)))
            return 1;

        s += n;
    }

    return 0;
}
