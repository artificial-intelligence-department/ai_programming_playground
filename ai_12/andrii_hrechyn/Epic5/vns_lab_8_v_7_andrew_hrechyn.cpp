#include<iostream>
#define LIST 4
using namespace std;

struct student{
    char Name[20];
    char Surname[20];
    char familyname[20];
    char Address[50];
    int address_number;
    char Group[10];
    int group_number;
    int phonenumber;
    int Rating;
};
void remove_low_rating_students(student arr[], int threshold) {
    int newSize = 0;

    for (int i = 0; i < LIST; i++) {
        if (arr[i].Rating >= threshold) {
            arr[newSize] = arr[i];
            newSize++;
        }
    }
    for(int i=0; i<newSize; i++){
        printf("%s ", arr[i].Name);
    }
    return;
    
}

    int main(){
    int* count = NULL;

    int average_rating = 90;
    cout << "Program starts" << __DATE__ << __TIME__;
    struct student st[LIST];
    FILE* fp = fopen("HELPER.txt", "r");
    int sum = 0;
    int ind_arr[LIST] = {0};
   
    for(int i = 0; i < LIST; i++){
        fscanf(fp, "%s %s %s %s %d %s %d %d %d", st[i].Name, st[i].Surname, st[i].familyname,
        st[i].Address, &st[i].address_number, st[i].Group, &st[i].group_number, &st[i].phonenumber, &st[i].Rating);
    }
    fclose(fp);
    fp = freopen("FINAL.txt", "w", stdout);
    puts("\tList of students:");
    
    for(int i = 0; i < LIST; i++){
        printf("Name: %-10s Surname: %-20s Familyname: %-20s Address: %-15s Address number: %-3d Group: %s Group number: %d Phone number: %010d Rating: %d\n", 
        st[i].Name, st[i].Surname, st[i].familyname, st[i].Address, st[i].address_number, st[i].Group, st[i].group_number, st[i].phonenumber, st[i].Rating);
    }

    printf("Bad students to delete:  ");
    remove_low_rating_students(st, average_rating);
    printf("\n");
    
    fseek(fp, 0, SEEK_END);
    printf("Adding text: 3 December is my birthday!!! ");

    fclose(fp);
    return 0;
}
