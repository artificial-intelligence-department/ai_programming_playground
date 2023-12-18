#include <stdio.h>
#include <string.h>
#define MAXLINE 255

char input[] = "Apartment is very good for Andrew";

void run_to_file1(FILE *F1, char* input);
void copy_to_file2(FILE *F1, FILE *F2);
void amount_symbols(FILE *F2);

int main(){
    FILE *F1, *F2;
    char buf[MAXLINE];

    run_to_file1(F1, input);

    copy_to_file2(F1, F2);

    amount_symbols(F2);
    return 0;
}

void copy_to_file2(FILE *F1, FILE *F2){
    char buf[MAXLINE];
    F1 = fopen("F1.txt", "r");
    F2 = fopen("F2.txt", "w");

    if (F1 == NULL || F2 == NULL) {
        printf("Error, no file opened!\n");
        return;
    }
    char str[1000]={""};
    char arr[1000]={""};
    fgets(str, 1000, F1);
    strcpy(arr, str);
    const char *limits = " ,.;()-";
    char *pw1;
    pw1 = strtok(str, limits);
    while (pw1!=NULL)
    {
        if(*pw1!='a'&&*pw1 !='A'){
            fprintf(F2, "%s ", pw1);
        }
        pw1 = strtok(NULL, limits);
    }
    

    fclose(F1);
    fclose(F2);
}

void amount_symbols(FILE *F2){
    char buf[MAXLINE];
    F2 = fopen("F2.txt", "r");
    if (F2 == NULL) {
        printf("Error, no file opened!\n");
        return;
    }
    if (fgets(buf, MAXLINE, F2) != NULL){
        int length = strcspn(buf, " \t\n\r"); 
        printf("Amount of symbols in F2: %d\n", length);
    }
    fclose(F2);
}

void run_to_file1(FILE *F1, char* input){
    F1 = fopen("F1.txt", "w");
    if (F1 == NULL) {
        printf("Error, no file opened!\n");
        return;
    }
    fputs(input, F1);
    fclose(F1);
}