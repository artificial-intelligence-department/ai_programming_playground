#include<iostream>
#include<string.h>
using namespace std;

const int workers_amount = 20;
const char* file_name = "text.txt";
FILE* file;
char delete_surname[20];

struct CoWorker
{
    char name[20];
    char surname[20];
    char by_father[20];
    char job[20];
    int birth_year;
    int salary = 0;
    int number = 0;
};

CoWorker workers_array[workers_amount];

void add_worker()
{
    if(strlen(workers_array[workers_amount - 1].name) == 0)
    {
        file = fopen(file_name, "ab");
        if(file != nullptr)
        {
            cout << endl << "---Add worker---" << endl;
            cout << endl;
            int i;
            for(i = 0; i < workers_amount; i++)
            {
                if(strlen(workers_array[i].name) == 0)
                {
                    cout << "Enter name: ";
                    cin >> workers_array[i].name;
                    cout << "Enter surname: ";
                    cin >> workers_array[i].surname;
                    cout << "Enter byfather: ";
                    cin >> workers_array[i].by_father;
                    cout << "Enter job: ";
                    cin >> workers_array[i].job;
                    cout << "Enter birth year: ";
                    cin >> workers_array[i].birth_year;
                    cout << "Enter salary: ";
                    cin >> workers_array[i].salary;
                    workers_array[i].number = i + 1;
                    cout << endl;
                    break;
                }  
            }
            fwrite(&workers_array[i], sizeof(CoWorker), 1, file);
            fclose(file);
        }
        else
        {
            cout << "Error: File opening is failed" << endl;
        }      
    }
    else
    {
        cout << "Error: List is full" << endl;
    }
}

void print_workers_array()
{
    cout << "-----Workers array-----" << endl;
    cout << endl;
    for(int i = 0; i < workers_amount; i++)
    {
        if(strlen(workers_array[i].name) != 0)
        {
            cout << "---Worker №" << workers_array[i].number << endl;
            cout << " - Name: " << workers_array[i].name << endl;
            cout << " - Surname: " << workers_array[i].surname << endl;
            cout << " - Byfather: " << workers_array[i].by_father << endl;
            cout << " - Job: " << workers_array[i].job << endl;
            cout << " - Birth year: " << workers_array[i].birth_year << endl;
            cout << " - Salary: " << workers_array[i].salary << endl;
            cout << endl;
        }
    }
}

void print_workers_file()
{
    cout << "-----Workers file-----" << endl;
    cout << endl;
    file = fopen(file_name, "rb");
    if(file != nullptr)
    {
        CoWorker worker;
            while(fread(&worker, sizeof(CoWorker), 1, file))
            {
                cout << "---Worker №" << worker.number << endl;
                cout << " - Name: " << worker.name << endl;
                cout << " - Surname: " << worker.surname << endl;
                cout << " - Byfather: " << worker.by_father << endl;
                cout << " - Job: " << worker.job << endl;
                cout << " - Birth year: " << worker.birth_year << endl;
                cout << " - Salary: " << worker.salary << endl;
                cout << endl;
            }          
        fclose(file);   
    }
    else
    {
        cout << "Error: File opening is failed" << endl;
    }   
}

void delete_worker(char* surname)
{
    file = fopen(file_name, "wb");
    if(file != nullptr)
    {
        cout << endl; 
        int i;
        int index;
        for(i = 0; i < workers_amount; i++)
        {
            if(strcmp(workers_array[i].surname, surname) == 0)
            {
                memset(&workers_array[i], 0, sizeof(CoWorker));
                index = i;
                for(index; index < workers_amount - 1; index++)
                {
                    workers_array[index] = workers_array[index + 1];
                    workers_array[index].number--;    
                }
            }
            if(strlen(workers_array[i].name) != 0)
            {
                fwrite(&workers_array[i], sizeof(CoWorker), 1, file);
            } 
        }
        fclose(file);
    }
    else
    {
        cout << "Error: File opening is failed" << endl;
    } 
}

char* get_surname()
{
    cout << endl << "---Delete worker---" << endl;
    cout << "Enter surname: ";
    cin >> delete_surname;
    return delete_surname;
}

void add_worker_after_index()
{
    if(strlen(workers_array[workers_amount - 1].name) != 0)
    {
        cout << "Error: List is full" << endl;
    }
    else
    {
        int number;
        for(int i = 0; i < workers_amount; i++)
        {
            if(strlen(workers_array[i].name) == 0)
            {
                do
                {
                    cout << "Enter index(" << i << " - " << workers_amount - 1 << "): ";
                    cin >> number;
                } while (number < i || number > workers_amount - 1);
                break;
            }
        }
        file = fopen(file_name, "ab");
        if(file != nullptr)
        {
            cout << endl << "---Add worker---" << endl;
            cout << endl;
            int i;
            for(i = 0; i < workers_amount; i++)
            {
                if(i == number && strlen(workers_array[i].name) == 0)
                {
                    cout << "Enter name: ";
                    cin >> workers_array[i].name;
                    cout << "Enter surname: ";
                    cin >> workers_array[i].surname;
                    cout << "Enter byfather: ";
                    cin >> workers_array[i].by_father;
                    cout << "Enter job: ";
                    cin >> workers_array[i].job;
                    cout << "Enter birth year: ";
                    cin >> workers_array[i].birth_year;
                    cout << "Enter salary: ";
                    cin >> workers_array[i].salary;
                    cout << endl;
                    workers_array[i].number = number + 1;
                    break;
                }  
            }
            fwrite(&workers_array[i], sizeof(CoWorker), 1, file);
            fclose(file);
        }
        else
        {
            cout << "Error: File opening is failed" << endl;
        }
    }
}

int main()
{
    file = fopen(file_name, "wb");
    fclose(file);
    add_worker();
    add_worker();
    print_workers_array();
    print_workers_file();
    add_worker_after_index();
    print_workers_array();
    print_workers_file();
    delete_worker(get_surname());
    print_workers_array();
    print_workers_file();
}