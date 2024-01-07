#include <cstdio>
#include <string>
#include <string>

using namespace std;

void cpf(const char*filename , const char* cpyf){

    FILE *f = fopen(filename , "r");
    FILE  *cpyfile = fopen(cpyf , "w");


    if(f == NULL || cpyf == NULL){
        printf("Error opening file\n");
        exit(1);
    }

    char line[255];

    while(fgets(line , sizeof(line) , f)){
        if(line[0] != 'A'){
            fputs(line , cpyfile);
        }
    }

    fclose(f);
    fclose(cpyfile);
}

void LenghtOfFirstWord(const char* filename){
    FILE *cpyfile = fopen(filename , "r");

    if(!cpyfile){
        printf("Error opening file\n");
        exit(1);
    }

    char line[255];
    fscanf(cpyfile ,"%s" , line);

    fclose(cpyfile);

    int lenght = 0;

    for(int i = 0; line[i] != '\0'; i++){
        lenght++;
    }

    printf("Lenght of first word: %d\n" , lenght);
}

int main(){

    const char* filename = "file.txt";
    const char* cpyf = "cpyfile.txt";

    cpf(filename , cpyf);

    LenghtOfFirstWord(cpyf);

    return 0;
}