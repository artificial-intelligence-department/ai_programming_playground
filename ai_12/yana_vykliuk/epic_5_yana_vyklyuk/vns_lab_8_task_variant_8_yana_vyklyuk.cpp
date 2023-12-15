#include <iostream>
#include <cstdio>

using namespace std;
#define n 4

struct Buyer
{
    char name[100];
    char adress[100];
    int number;
    int credit_card;
};

void form()
{
    FILE *f;

    if ((f = fopen("f.txt", "wb")) == NULL)
    {
        perror("Error opening file for writing");
        exit(1);
    }

    Buyer e[n];

    for (int i = 0; i < n; i++)
    {
        // form
        printf("Enter name = ");
        scanf("%s", e[i].name);
        printf("Enter adress = ");
        scanf("%s", e[i].adress);
        printf("Enter phone number = ");
        scanf("%d", &e[i].number);
        printf("Enter credit card = ");
        scanf("%d", &e[i].credit_card);

        // write in file
        fwrite(&e[i], sizeof(Buyer), 1, f);
    }

    fclose(f);
}

void print()
{
    FILE *f = fopen("f.txt", "rb");
    if (f == NULL)
    {
        perror("Error opening file for reading");
        exit(1);
    }

    Buyer e[n];

    fread(e, sizeof(Buyer), n, f);

    for (int i = 0; i < n; i++)
    {
        printf("name = %s \n", e[i].name);
        printf("adress = %s \n", e[i].adress);
        printf("phone number = %d \n", e[i].number);
        printf("credit card = %d \n", e[i].credit_card);
    }

    fclose(f);
}

void delete_elements()
{
    FILE *f = fopen("f.txt", "rb");
    if (f == NULL)
    {
        perror("Error opening file for reading");
        exit(1);
    }

    Buyer e[n];
    int total;

    fseek(f, 0, SEEK_END);
    total = ftell(f) / sizeof(Buyer);
    rewind(f);

    if (total <= 3)
    {
        fclose(f);
        f = fopen("f.txt", "wb");
        fclose(f);
        return;
    }

    // read from file to array
    fread(e, sizeof(Buyer), n, f);
    fclose(f);

    // erase
    for (int i = 0; i < total - 3; i++)
    {
        e[i] = e[i + 3];
    }

    f = fopen("f.txt", "wb");
    if (!f)
    {
        perror("Error opening file for writing");
        exit(1);
    }

    fwrite(e, sizeof(Buyer), total - 3, f);

    fclose(f);
}

void add_elements()
{
    FILE *f = fopen("f.txt", "ab");
    if (f == NULL)
    {
        perror("Error opening file for appending");
        exit(1);
    }

    Buyer new_buyers[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter new name: ";
        scanf("%s", new_buyers[i].name);
        cout << "Enter new address: ";
        scanf("%s", new_buyers[i].adress);
        cout << "Enter new phone number: ";
        scanf("%d", &new_buyers[i].number);
        cout << "Enter new credit card: ";
        scanf("%d", &new_buyers[i].credit_card);

        // write the new buyer to the end of the file
        fwrite(&new_buyers[i], sizeof(Buyer), 1, f);
    }

    fclose(f);
}

int main()
{
    form();
    delete_elements();
    add_elements();
    cout << "\nNew : " << endl;
    print();
    return 0;
}
