#include <iostream>
#include <string.h>

using namespace std;

const int array_size = 10;
string file_names[array_size];

bool app_exit = false;

string get_file_name()
{
    string file_name;
    cout << "Enter file name: ";
    cin >> file_name;
    cout << endl;
    return file_name;
}

string get_content()
{
    cin.ignore();
    string content;
    cout << "Enter content to write to file: ";
    getline(cin, content);
    cout << endl;
    return content;
}

bool is_existed(const string& file_name) 
{
    for(int i = 0; i < array_size; i++)
    {
        if(file_names[i] == file_name)
        {
            return true;
        }
    }
    return false;
}

bool is_filled()
{
    return !file_names[array_size - 1].empty();
}

void create_file(const string& file_name)
{
    if (!is_filled())
    {
        if (!is_existed(file_name))
        {
            FILE* file = fopen(file_name.c_str(), "w");
            if (file != nullptr)
            {
                fclose(file);
                cout << "File '" << file_name << "' has been successfully created" << endl << endl;
                for (int i = 0; i < array_size; i++)
                {
                    if (file_names[i].empty())
                    {
                        file_names[i] = file_name;
                        break;
                    }
                }
            }
            else
            {
                cout << "Error: File '" << file_name << "' opening is failed" << endl<< endl;
            }
        }
        else
        {
            cout << "Error: File '" << file_name << "' already exists" << endl<< endl;
        }
    }
    else
    {
        cout << "Error: File array is filled" << endl<< endl;
    }
}

void remove_file(const string& file_name)
{
    if (is_existed(file_name))
    {
        int index;
        for (int i = 0; i < array_size; ++i)
        {
            if (file_names[i] == file_name)
            {
                index = i;
                break;
            }
        }
        if (index >= 0)
        {
            file_names[index].clear();
            for (int i = index; i < array_size - 1; ++i)
            {
                file_names[i] = file_names[i + 1];
            }
        }
        if (remove(file_name.c_str()) == 0)
        {
            cout << "File '" << file_name << "' has been successfully removed" << endl << endl;
        }
        else
        {
            cout << "Error: File '" << file_name << "' removing is failed" << endl << endl;
        }
    }
    else
    {
        cout << "Error: File '" << file_name << "' doesn't exist" << endl << endl;
    }
}

void print_file_names()
{
    cout << endl << "----Existing files----" << endl;
    for (int i = 0; i < array_size; i++)
    {
        if (file_names[i].empty())
        {
            break;
        }
        else
        {
            cout << " - " << file_names[i] << endl;
        }
    }
    cout << endl;
}

void clear_file(const string& file_name)
{
    FILE* file = fopen(file_name.c_str(), "w");
    if (file != nullptr)
    {
        fclose(file);
        cout << "File '" << file_name << "' has been cleared" << endl << endl;
    }
    else
    {
        cout << "Error: File '" << file_name << "' opening is failed" << endl << endl;
    }
}

void write_file(const string& file_name)
{
    string content = get_content();
    FILE* file = fopen(file_name.c_str(), "a");
    if (file != nullptr)
    {
        if (fprintf(file, content.c_str()) >= 0)
        {
            cout << "File '" << file_name << "' has been successfully edited" << endl << endl;
        }
        else
        {
            cout << "Error: File '" << file_name << "' hasn't been edited" << endl << endl;
        }
        fclose(file);
    }
    else
    {
        cout << "Error: File '" << file_name << "' opening is failed" << endl << endl;
    }
}

void print_file_content(const string& file_name)
{
    if (is_existed(file_name))
    {
        FILE* file = fopen(file_name.c_str(), "r");
        if (file != nullptr)
        {
            cout << endl << "File '" << file_name << "' content: " << endl << endl;
            char buffer[1024];
            while (fgets(buffer, sizeof(buffer), file))
            {
                cout << buffer;
            }
            cout << endl << endl;
            fclose(file);
        }
        else
        {
            cout << "Error: File '" << file_name << "' opening is failed" << endl;
        }
    }
    else
    {
        cout << "Error: File '" << file_name << "' doesn't exist" << endl;
    }
}

void clear_all_files()
{
    for (int i = 0; i < array_size; i++)
    {
        if (file_names[i].empty())
        {
            break;
        }
        remove(file_names[i].c_str());
        file_names[i].clear();
    }
}

void exit_app()
{
    app_exit = true;
}

int get_action()
{
    int action;
    int action_count = 7;
    do
    {
        cout << " - Print files(1)" << endl
            << " - Create file(2)" << endl
            << " - Remove file(3)" << endl
            << " - Clear file(4)" << endl
            << " - Write file(5)" << endl
            << " - Print file content(6)" << endl
            << " - Exit(7)" << endl
            << "Enter action: ";
        cin >> action;
    } while (action < 1 || action > action_count);
    return action;
}

void File_Managment_App()
{
    while (!app_exit)
    {
        switch (get_action())
        {
        case 1:
            print_file_names();
            break;
        case 2:
            create_file(get_file_name());
            break;
        case 3:
            print_file_names();
            remove_file(get_file_name());
            break;
        case 4:
            print_file_names();
            clear_file(get_file_name());
            break;
        case 5:
            print_file_names();
            write_file(get_file_name());
            break;
        case 6:
            print_file_names();
            print_file_content(get_file_name());
            break;
        case 7:
            exit_app();
            break;
        }
    }
    clear_all_files();
}

int main()
{
    File_Managment_App();
}