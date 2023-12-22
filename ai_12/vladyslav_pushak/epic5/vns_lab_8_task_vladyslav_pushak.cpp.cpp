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
    {"Men in Black", "Barry Sonnenfeld", 98, 135.0}
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

    if ((file = fopen(filename, "rb")) == NULL) {
        perror("\nError opening file");
        return;
    }

    while (fread(&tapes[numTapes], sizeof(VideoCassette), 1, file) == 1) {
        numTapes++;
    }

    for (int i = 0; i < numTapes; i++) {
        printf("Title: %s\n", tapes[i].title);
        printf("Director: %s\n", tapes[i].director);
        printf("Duration: %d\n", tapes[i].duration);
        printf("Price: %.2f\n", tapes[i].price);
        printf("\n");
    }

    fclose(file);
}

void removeElements(const char *filename, float maxPrice) {
    FILE *file;
    VideoCassette tapes[10];
    int numTapes = 0;

    if ((file = fopen(filename, "r+b")) == NULL) {
        perror("\nError opening file");
        return;
    }

    while (fread(&tapes[numTapes], sizeof(VideoCassette), 1, file) == 1) {
        if (tapes[numTapes].price <= maxPrice) {
            numTapes++;
        }
    }

    rewind(file);

    fwrite(tapes, sizeof(VideoCassette), numTapes, file);

    fclose(file);
}

void addElements(const char *filename, VideoCassette *addedTapes, int numNewTapes) {
    FILE *file;

    if ((file = fopen(filename, "ab")) == NULL) {
        perror("\nError opening file");
        return;
    }

    fwrite(addedTapes, sizeof(VideoCassette), numNewTapes, file);

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

    fwrite(tapes, sizeof(VideoCassette), sizeof(tapes) / sizeof(VideoCassette), file);
    fclose(file);

    printf("Contents before removal:\n");
    printContents("videotapes.bin");

    float maxPrice = 145.0;

    removeElements("videotapes.bin", maxPrice);

    printf("\nContents after removal price higher than %.2f:\n", maxPrice);
    printContents("videotapes.bin");

    VideoCassette addedTapes[] = {
        {"The Gentlemen", "Guy Ritchie", 113, 120.0},
        {"John Wick", "Chad Stahelski", 101, 110.0},
        {"Men in Black", "Barry Sonnenfeld", 98, 135.0}
    };
    addElements("videotapes.bin", addedTapes, sizeof(addedTapes) / sizeof(VideoCassette));

    printf("\nContents after addition:\n");
    printContents("videotapes.bin");

    fclose(file);
    return 0;
}
