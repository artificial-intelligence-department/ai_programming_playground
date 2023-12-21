#include <stdio.h>

typedef struct {
    char title[50];
    char director[50];
    int duration;
    float price;
} VideoCassette;


    VideoCassette newCassettesToAdd[] = {
        {"The Gentlemen", "Guy Ritchie", 113, 120.0},
        {"John Wick", "Chad Stahelski", 101, 110.0},
        {"Men in Black", "	Barry Sonnenfeld", 98, 135.0}
    };
      VideoCassette cassettes[] = {
        {"Django Unchained", "Quentin Tarantino", 165, 150.0},
        {"Inglourious Basterds", "Quentin Tarantino", 153, 140.0},
        {"TENET", "Christopher Nolan", 150, 160.0}
    };




void printContents(const char *filename) {
    FILE *file;
    VideoCassette tapes[10];
    int numTapes = 0;

    // Відкриття файлу для читання
    if ((file = fopen(filename, "rb")) == NULL) {
        perror("\nError opening file");
        return;
    }

    // Читання елементів з файлу
    while (fread(&tapes[numTapes], sizeof(VideoCassette), 1, file) == 1) {
        numTapes++;
    }

    // Виведення вмісту файлу
    for (int i = 0; i < numTapes; i++) {
        printf("Title: %s\n", tapes[i].title);
        printf("Director: %s\n", tapes[i].director);
        printf("Duration: %d\n", tapes[i].duration);
        printf("Price: %.2f\n", tapes[i].price);
        printf("\n");
    }

    // Закриття файлу
    fclose(file);
}

void removeElements(const char *filename, float maxPrice) {
    FILE *file;
    VideoCassette tapes[10];
    int numTapes = 0;

    // Відкриття файлу для читання і запису
    if ((file = fopen(filename, "r+b")) == NULL) {
        perror("\nError opening file");
        return;
    }

    // Читання елементів з файлу та видалення елементів з ціною вищою заданої
    while (fread(&tapes[numTapes], sizeof(VideoCassette), 1, file) == 1) {
        if (tapes[numTapes].price <= maxPrice) {
            numTapes++;
        }
    }

    // Перейти в початок файлу
    rewind(file);

    // Записати елементи, які не були видалені
    fwrite(tapes, sizeof(VideoCassette), numTapes, file);

    // Закриття файлу
    fclose(file);
}

void addElements(const char *filename, VideoCassette *addedTapes, int numNewTapes) {
    FILE *file;

    // Відкриття файлу для додавання
    if ((file = fopen(filename, "ab")) == NULL) {
        perror("\nError opening file");
        return;
    }

    // Додавання нових елементів
    fwrite(addedTapes, sizeof(VideoCassette), numNewTapes, file);

    // Закриття файлу
    fclose(file);
}

int main() {
    FILE *file;
    if ((file = fopen("videotapes.bin", "wb")) == NULL) {
        perror("\nError opening file");
        return 1;
    }

    VideoCassette tapes[] = {
        {"Django Unchained", "Quentin Tarantino", 165, 150.0},
        {"Inglourious Basterds", "Quentin Tarantino", 153, 140.0},
        {"TENET", "Christopher Nolan", 150, 160.0}
    };

    // Запис елементів у файл
    fwrite(tapes, sizeof(VideoCassette), sizeof(tapes) / sizeof(VideoCassette), file);
    fclose(file);

    // Виведення вмісту файлу до видалення 
    printf("Contents before removal:\n");
    printContents("videotapes.bin");

    float maxPrice = 145.0;  // Задана ціна для видалення елементів

    // Знищення елементів із ціною вищою заданої
    removeElements("videotapes.bin", maxPrice);

    // Виведення вмісту файлу після видалення
    printf("\nContents after removal price higher than %.2f:\n", maxPrice);
    printContents("videotapes.bin");


    // Додавання нових елементів
    VideoCassette addedTapes[] = {
        {"The Gentlemen", "Guy Ritchie", 113, 120.0},
        {"John Wick", "Chad Stahelski", 101, 110.0},
        {"Men in Black", "Barry Sonnenfeld", 98, 135.0}
    };
    addElements("videotapes.bin", addedTapes, sizeof(addedTapes) / sizeof(VideoCassette));

    // Виведення вмісту файлу після додавання
    printf("\nContents after addition:\n");
    printContents("videotapes.bin");

    fclose(file);
    return 0;
}
