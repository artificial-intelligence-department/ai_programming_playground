#include<iostream> 
#include<ctime>
using namespace std;

const int students_amount = 30;
const int grades_amount = 20;
const int max_grade = 5;
const int min_grade = 1;
const int subject_amount = 3;
int student_counter = 0;
string subjects[subject_amount] = {"Math   ", "English", "History"};
bool exit_s_r = false;

struct Student
{
    string name;
    string surname;
    int age;
    string study_email;
    int number;
    int s_register[subject_amount][grades_amount];
    float average_grade = 0;
};

Student students[students_amount];
Student sorted_students[students_amount];

string set_name_value(string &name)
{
    cout << "Enter name: ";
    cin >> name;
    return name;
}

string set_surname_value(string &surname)
{
    cout << "Enter surname: ";
    cin >> surname;
    return surname;
}

int set_age_value(int &age)
{
    cout << "Enter age: ";
    cin >> age;
    return age;
}

int get_age()
{
    int age;
    cout << "Enter age: ";
    cin >> age;
    return age;
}

string convert_uppercase_to_lowercase(string str)
{
    str[0] = tolower(str[0]);
    return str;
}

string generate_study_email(Student &student)
{
    return convert_uppercase_to_lowercase(student.name) + "." + convert_uppercase_to_lowercase(student.surname) + "@gmail.com";;
}

void print_student(Student &student)
{
    cout << "-----Student №" << student.number << "-----" << endl;
    cout << "Name: " << student.name << endl;
    cout << "Surame: " << student.surname << endl;
    cout << "Age: " << student.age << endl;
    cout << "Study email: " << student.study_email << endl;
    cout << endl;
}

void print_all_students(Student* students)
{
    cout << "-----------Students list-----------" << endl;
    for(int i = 0; i < students_amount; i++)
    {
        if(students[i].name.empty())
        {
            break;
        }
        print_student(students[i]);
    }
}

Student* find_student(string &name, string &surname)
{
    for(int i = 0; i < students_amount; i++)
    {
        if(name == students[i].name && surname == students[i].surname)
        {
             return &students[i];
        }
    }
    return nullptr;
}

bool student_exists(string &name, string &surname)
{
    for(int i = 0; i < students_amount; i++)
    {
        if(name == students[i].name && surname == students[i].surname)
        {
           return true;
        }        
    }
    return false;
}

void add_student()
{
    if(student_counter == students_amount)
    {
        cout << "Error: Student list is full!" << endl;
    }
    else
    {
    int action;
    string name;
    string surname;
    int age;
    do
    {
        cout << "Press [1] for manual filling or [2] for auto filling: ";
        cin >> action;
    } while (action != 1 && action != 2);
    if(action == 1)
    {
        set_name_value(name);
        set_surname_value(surname);
        set_age_value(age);
    }
    else
    {
        string names[students_amount] = {
        "Aiden", "Brooklyn", "Carter", "Delilah", "Elijah",
        "Faith", "Grayson", "Harper", "Isaiah", "Jasmine",
        "Kaden", "Layla", "Mason", "Nevaeh", "Owen",
        "Peyton", "Quinn", "Riley", "Sophia", "Tyler",
        "Upton", "Vanessa", "Wyatt", "Ximena", "Yasmine",
        "Zane", "Ava", "Brayden", "Chloe", "Daniel"};
        string surnames[students_amount] = {
        "Anderson", "Baker", "Clark", "Davis", "Edwards",
        "Fisher", "Garcia", "Hill", "Irwin", "Johnson",
        "Keller", "Lopez", "Martinez", "Nelson", "Owens",
        "Perez", "Quinn", "Rodriguez", "Smith", "Taylor",
        "Upton", "Valdez", "Watson", "Xavier", "Young",
        "Zimmerman", "Adams", "Brown", "Chavez", "Dixon"};
        do
        {
            name = names[rand() % 30];
            surname = surnames[rand() % 30];
        } while (student_exists(name, surname));
        age = rand() % 13 + 7;
    }
    students[student_counter].name = name;
    students[student_counter].surname = surname;
    students[student_counter].age = age;
    students[student_counter].study_email = generate_study_email(students[student_counter]);
    students[student_counter].number = student_counter + 1;
    student_counter++;  
    cout << endl;
    cout << "You added: " << endl;
    print_student(*find_student(name, surname));
    }   
}

void delete_student()
{
    if(student_counter == 0)
    {
        cout << "Error: Student list is empty!" << endl;
    }
    else
    {
        string name;
        string surname;
        int index;
        set_name_value(name);
        set_surname_value(surname);
        cout << endl;
        Student* student = find_student(name, surname);
        if(student == nullptr)
        {
            cout << "Error: Student was not founded!" << endl;
            cout << endl;
        }
        else
        {
            cout << "You deleted: " << endl;
            print_student(*student);
            index = student->number - 1;
            for(index; index < students_amount - 1; index++)
            {
                students[index] = students[index + 1];
                if(students[index].number != index + 1)
                {
                    students[index].number--;
                }
            }
            student_counter--;
        }
    }
        
}

int choose_subject()
{
    int subject;
    do
    {
        for(int i = 0; i < subject_amount; i++)
        {
            cout << "---" << subjects[i] << "[" << i + 1 << "]" <<  endl;
        }
        cout << "Choose subject: ";
        cin >> subject;
    } while (subject < 0 || subject > subject_amount);
    return subject - 1;
}

void print_subject_grades(int* student_register)
{
    for(int i = 0; i < grades_amount; i++)
    {
        if(student_register[i] == 0)
        {
            cout << "|0";
        }
        else
        {
            cout << "|" << student_register[i];
        }
    }
    cout << "|" << endl;
}

void give_grade(Student &student)
{
    int subject = choose_subject();
    int grade;
    if(student.s_register[subject][grades_amount - 1] != 0)
    {
        cout << "Error: Register is full!" << endl;
    }
    else
    {
        do
        {
            cout << "Enter grade(" << min_grade << "-" << max_grade << "): ";
            cin >> grade;
        } while (grade > max_grade || grade < min_grade);
        cout << endl;
        for(int i = 0; i < grades_amount; i++)
        {
            if(student.s_register[subject][i] == 0)
            {
                student.s_register[subject][i] = grade;
                break;
            }
        }
    }
}

void set_average_grade(Student &student)
{
    float grades_counter;
    student.average_grade = 0;
    for(int i = 0; i < subject_amount; i++)
    {
        for(int y = 0; y < grades_amount; y++)
        {
            if(student.s_register[i][y] != 0)
            {
                student.average_grade += student.s_register[i][y];
                grades_counter++;
            }
        }
    }
    if(grades_counter != 0)
    {
        student.average_grade /= grades_counter;
    }
    else
    {
        student.average_grade =  grades_counter;
    }
}

void print_student_average_grade(Student &student)
{
    set_average_grade(student);
    cout << "Average grade: " << student.average_grade << endl << endl;;
}

void print_all_subject_grades(Student &student)
{
    for(int i = 0; i < subject_amount; i++)
    {
        cout << "---" << subjects[i];
        print_subject_grades(student.s_register[i]);
        cout << endl;
    }
}

void print_all_students_grades()
{
    cout << "-------------Students grades-------------" << endl;
    for(int i = 0; i < students_amount; i++)
    {
        if(students[i].name.empty())
        {
            break;
        }
        cout << students[i].name << " " << students[i].surname << endl;
        print_all_subject_grades(students[i]);
        print_student_average_grade(students[i]);
        cout << endl;
    }
}

Student* sort_by_progress()
{
    int i;
    Student temp;
    for(i = 0; i < students_amount; i++)
    {
        sorted_students[i] = students[i];
    }
    for (i = 0; i < students_amount - 1; i++)
    {
        for (int y = 0; y < students_amount - i - 1; y++)
        {
            if (sorted_students[y].average_grade < sorted_students[y + 1].average_grade)
            {
                temp = sorted_students[y];
                sorted_students[y] = sorted_students[y + 1];
                sorted_students[y + 1] = temp;
            }
        }
    }
    return sorted_students;
}

void exit_student_register()
{
    exit_s_r = true;
}

int choose_action()
{
    int action;
    do
    {
        cout << " - Find student[1]\n - Add student[2]\n - Delete student[3]\n - Print all student[4]\n - Print all grades[5]\n - Sort all students by progress[6]\n - Exit[7]\n: ";
        cin >> action;
    } while (action < 1  || action > 7);
    cout << endl;
    return action;
}

int choode_action2()
{
    int action;
    do
    {
        cout << " - Print student[1]\n - Give grade[2]\n - Print grades[3]\n - Print average grade[4]\n - Exit[5]\n: ";
        cin >> action;
    } while (action < 1  || action > 5);
    cout << endl;
    return action;
}

void student_register_app()
{
    string name;
    string surname;
    Student *student;
    srand(time(nullptr));
    while(!exit_s_r)
    {
        switch(choose_action())
        {
            case 1: 
                    set_name_value(name);
                    set_surname_value(surname);
                    cout << endl;
                    student = find_student(name, surname);
                    if(student == nullptr)
                    {
                        cout << "Error: Student was not founded!" << endl << endl;
                        break;
                    }
                    while(!exit_s_r)
                    {
                        switch(choode_action2())
                        {
                            case 1: print_student(*student);
                                    break;
                            case 2:
                                    give_grade(*student);
                                    break;
                            case 3: print_all_subject_grades(*student);
                                    break;
                            case 4: print_student_average_grade(*student);
                                    break;
                            case 5: exit_student_register();
                                    break;
                        }
                    }
                    exit_s_r = false;
                    break;
            case 2: add_student();
                    break;
            case 3: delete_student();
                    break;
            case 4: print_all_students(students); 
                    break;
            case 5: print_all_students_grades(); 
                    break;
            case 6: sort_by_progress();
                    print_all_students(sorted_students);
                    break;
            case 7: exit_student_register(); break;
        }
    }
}

int main()
{
    student_register_app();
}