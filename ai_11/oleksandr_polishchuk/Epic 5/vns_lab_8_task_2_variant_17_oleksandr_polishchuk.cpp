#include <iostream>
#include <vector>

using namespace std;

struct FILM
{
    char title[100];
    char producer[100];
    int releaseDate;
    int cost;
};

void makeFile(FILE *f)
{
    f = fopen("Lab8.bin", "wb");
    if (f == NULL)
    {
        perror("Error creating file");
        exit(1);
    }
    fclose(f);
}

void printData(int n, const vector<int> &del, FILE *f, FILM m, FILM mas[])
{
    int elements = n - del.size() + 1;
    if ((f = fopen("Lab8.bin", "rb")) == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    for (int i = 0; i < elements; i++)
    {
        fread(&mas[i], sizeof(FILM), 1, f);
        printf("object: %i\n", i + 1);
        printf("%s\n", mas[i].title);
        printf("%s\n", mas[i].producer);
        printf("%d\n", mas[i].releaseDate);
        printf("%d\n", mas[i].cost);
    }
    fclose(f);
}

void addData(int n, FILE *f, FILM m)
{
    
    if ((f = fopen("Lab8.bin", "wb")) == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    int i;
    cout << "Add " << n << " films\n" << endl;
    //printf("Add n films\n");
    for (i = 1; i <= n; i++)
    {
        printf("\nFilm №%d", i);
        printf("\ntitle=");
        scanf("%s", m.title);

        printf("\nproducer=");
        scanf("%s", m.producer);

        printf("\nrelease_date=");
        scanf("%d", &m.releaseDate);

        printf("\ncost=");
        scanf("%d", &m.cost);

        fwrite(&m, sizeof(FILM), 1, f);
    }
    fclose(f);
}

vector<int> detectWrong(int n, int maxCost, FILE *f, FILM mas[])
{
    int o = 0;
    vector<int> del;
    if ((f = fopen("Lab8.bin", "rb")) == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        fread(&mas[i], sizeof(FILM), 1, f);
        if (mas[i].cost > maxCost)
        {
            del.push_back(i);
            o++;
        }
    }
    fclose(f);
    return del;
}

void deleteData(int n, const vector<int> &del, FILE *f, FILM mas[], FILM m)
{
    
    if ((f = fopen("Lab8.bin", "rb+")) == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    int a = 0;
    for (int i = 0; i < n; i++)
    {
        if (a < del.size() && i == del[a])
        {
            a++;
        }
        else
        {
            fwrite(&mas[i], sizeof(FILM), 1, f);
        }
    }

    fclose(f);
}

void addNewElement(int n, vector<int> del, FILE *f, FILM mas[], FILM )
{
    
    if ((f = fopen("Lab8.bin", "rb+")) == NULL)
    {
        perror("Error opening file");
        exit(1);
    }
    fseek(f, 0, SEEK_SET);
    FILM temp[n]; 
    fread(temp, sizeof(FILM), n, f);

    rewind(f);

    fwrite(&mas[del[0]], sizeof(FILM), 1, f);

    fwrite(temp, sizeof(FILM), n - 1, f);

    fclose(f);
}
int main()
{   
    int n = 0;
    cin >> n ;
    FILE *f;      
    FILM m;       
    FILM mas[n];  
    int maxCost = 0;
    

    makeFile(f);
    addData(n, f, m);

    cout << "Enter maximal cost" << endl;
    cin >> maxCost;
    vector<int> del = detectWrong(n, maxCost, f, mas);

    deleteData(n, del, f, mas, m);
    addNewElement(n, del, f, mas, m);
    printData(n, del, f, m, mas);

    return 0;
}
