#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char surname[40];
    char name[40];
    char father_name[40];
    char phone_number[20];
    char group[10];
    float grades[3];
} STUDENT;

void addStudentToFile(FILE *file) {
    STUDENT student;

    printf("Прізвище: "); scanf("%s", student.surname);
    printf("Ім'я: "); scanf("%s", student.name);
    printf("По батькові: "); scanf("%s", student.father_name);
    printf("Номер телефону: "); scanf("%s", student.phone_number);
    printf("Група: "); scanf("%s", student.group);
    printf("Оцінки (3): "); scanf("%f %f %f", &student.grades[0], &student.grades[1], &student.grades[2]);

    fwrite(&student, sizeof(STUDENT), 1, file);
}

void printStudentsFromFile(FILE *file) {
    STUDENT student;

    while (fread(&student, sizeof(STUDENT), 1, file) == 1) {
        printf("Прізвище: %s\n", student.surname);
        printf("Ім'я: %s\n", student.name);
        printf("По батькові: %s\n", student.father_name);
        printf("Номер телефону: %s\n", student.phone_number);
        printf("Група: %s\n", student.group);
        printf("Оцінки: %f %f %f\n", student.grades[0], student.grades[1], student.grades[2]);
        printf("                      \n");
    }
}

void destroyStudentsInGroup(FILE *sourceFile, FILE *tempFile, const char groupToDelete[10], float averageGradeThreshold) {
    STUDENT student;

    rewind(sourceFile);
    rewind(tempFile);

    while (fread(&student, sizeof(STUDENT), 1, sourceFile) == 1) {
        float averageGrade = (student.grades[0] + student.grades[1] + student.grades[2]) / 3.0;

        if (strcmp(student.group, groupToDelete) != 0 || averageGrade >= averageGradeThreshold) {
            fwrite(&student, sizeof(STUDENT), 1, tempFile);
        }
    }
    rewind(tempFile);
    rewind(sourceFile);

    while (fread(&student, sizeof(STUDENT), 1, tempFile) == 1) {
        fwrite(&student, sizeof(STUDENT), 1, sourceFile);
    }
}

int main() {
    FILE *file, *tempFile;

    if ((file = fopen("students.dat", "ab+")) == NULL) {
        perror("Помилка при відкритті файлу");
        exit(1);
    }

    if ((tempFile = fopen("temp.dat", "w+b")) == NULL) {
        perror("Помилка при відкритті тимчасового файлу");
        fclose(file);
        exit(1);
    }
    for (int i = 1; i <= 2; i++) {
        addStudentToFile(file);
    }

    printf("Студенти в файлі:\n");
    printStudentsFromFile(file);

    destroyStudentsInGroup(file, tempFile, "IT-101", 60.0);
    addStudentToFile(file);

    printf("\nСписок студентів оновлено:\n");
    printStudentsFromFile(file);

    fclose(file);
    fclose(tempFile);

    return 0;
}
