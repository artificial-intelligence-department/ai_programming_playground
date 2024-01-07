#include <stdio.h>
#include <string.h>

#define MAXLINE 255

int main() {
    FILE *f1, *f2;
    char buf[MAXLINE];
    int N1, N2, currentLine = 0;
    int maxACount = 0, maxALine = 0;

    f1 = fopen("F1.txt", "r");
    if (f1 == NULL) {
        printf("Файл F1.txt не існує. Створюю новий файл.\n");
        f1 = fopen("F1.txt", "w");

        fputs("Рядок 1\n", f1);
        fputs("Рядок 2\n", f1);

        fclose(f1);

        f1 = fopen("F1.txt", "r");
    }

    f2 = fopen("F2.txt", "w");

    if (f2 == NULL) {
        perror("Помилка відкриття файлу F2");
        fclose(f1);
        return 1;
    }

    printf("Введіть N1 та N2: ");
    scanf("%d %d", &N1, &N2);

    while (fgets(buf, MAXLINE, f1) != NULL) {
        currentLine++;
        size_t len = strlen(buf);
        if (len > 0 && buf[len - 1] == 'A') {
            if (currentLine >= N1 && currentLine <= N2) {
                fputs(buf, f2);

                int ACount = 0;
                for (size_t i = 0; i < len; i++) {
                    if (buf[i] == 'A') {
                        ACount++;
                    }
                }
                if (ACount > maxACount) {
                    maxACount = ACount;
                    maxALine = currentLine;
                }
            }
        }
    }

    fclose(f1);
    fclose(f2);

    printf("Файл F2 був успішно створений та заповнений.\n");
    printf("Номер рядка з найбільшою кількістю букв 'А' в F2: %d\n", maxALine);

    return 0;
}
