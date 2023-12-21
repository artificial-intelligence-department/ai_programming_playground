#include <iostream>
#include <string>
#include <cstdio>

using namespace std;


struct STUDENT{
    string name;
    string home_address;
    char group[10];
    int rating;
};


void writeStudentsData(const char* filename , int count){
    FILE *f ;
    STUDENT student;
    if((f = fopen("file.dat" , "wb")) == NULL)exit(1); 

    

    long i;
    for(i = 1; i <= count;i ++){
        printf("Enter name: ");
        getline(cin , student.name);       
        printf("Enter home adress: ");
        getline(cin , student.home_address);
        printf("Enter group: "); scanf("%s" , &student.group);
        printf("Enter rating: "); scanf("%d" , &student.rating);
        cin.ignore();
        printf("--------------------\n");
        fwrite(&student , sizeof(STUDENT) , 1 , f);
        if(ferror(f)){
            printf("Error writing to file\n");
            exit(2);
        }
    }
    fclose(f);
}

void removingStudents(const char* filename , int threshold){
    FILE *tempfile , *f;
    STUDENT student;

    if ((tempfile = fopen("temp.dat" , "wb")) == NULL || (f = fopen("file.dat" , "rb")) == NULL){
        printf("Error opening file\n");
        exit(1);
    }
    for (int i = 0; fread(&student, sizeof(STUDENT), 1, f) == 1; i++){
        if (student.rating < threshold){
            fwrite(&student, sizeof(STUDENT) , 1 ,tempfile);
        }
    }

    fclose(f);
    fclose(tempfile);   

    remove("file.dat");
    rename("temp.dat" , "file.dat");
}

void PrintUpdStudentsData(const char* filename , string& message){
    FILE *f;
    STUDENT student;

    if ((f = fopen(filename , "rb")) == NULL){
        printf("Error opening file\n");
        exit(1);
    }
    for(int i = 0; fread(&student , sizeof(STUDENT) , 1 , f) == 1; i++){
        cout << "Name: " << student.name << endl;
        cout << "Home address: " << student.home_address << endl;
        printf("Group: %s\n" , student.group);
        printf("Rating: %d\n" , student.rating);
        printf("--------------------\n");
        printf("Message: %s\n" , message.c_str());
    }   

    fclose(f);
}

int main(){
    const char* filename = "file.dat";
    int studentcount = 2; 
    int threshold;

    writeStudentsData(filename , studentcount);

    printf("Enter a treshold: "); scanf("%d" , &threshold);
    printf("--------------------\n");

    removingStudents(filename , threshold);

    string message = "Powerede by me";
    PrintUpdStudentsData(filename , message);

    return 0;
}