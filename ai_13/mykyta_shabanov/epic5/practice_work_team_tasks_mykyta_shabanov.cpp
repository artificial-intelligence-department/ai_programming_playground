#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool InputWaiter(string errorText)
{
    char empty;
    cout << errorText
        << "enter anything to continue> ";
    cin >> empty;

    return false;
}

bool CreateNewFile(string fileName, vector<string> &createdFiles)
{
    for (int i = 0; i < createdFiles.size(); i++)
    {
        //перевірка на те чи існує вже такий файл
        if(fileName == createdFiles[i] || (fileName + ".txt") == createdFiles[i])
            return InputWaiter("this file already exist...");
    }
    
    string fileType; int typeLength = 0;
    for (int i = fileName.size() - 1; i >= 0; i--)
    { //перевірка на допустиму назву
        if
        ( fileName[i] == '\\' ||  fileName[i] == '/' ||
            fileName[i] == ':' || fileName[i] == '*' ||
            fileName[i] == '?' || fileName[i] == '"' ||
            fileName[i] == '<' || fileName[i] == '>' ||
            fileName[i] == '|' ) 
        {
            return InputWaiter("Wrong file name. Try again...");
        }

            //дізнаємось який тип файлу хоче створити користувач
        typeLength++;
        if(fileName[i] == '.' && fileType.size() == 0)
        {
            for(int j = 0; j < typeLength; j++)
                fileType += fileName[i + j];
        }
    }

        //якщо користувач не вказав тип створеного файлу,
        //то по дефотлу будемо створювати з типом txt
    if(fileType.size() == 0)
        fileName += ".txt";    

        //безпосереднє створення файлу, все ради чого це було. Ура!
    ofstream fout(fileName);
    createdFiles.push_back(fileName); //додаємо створений файл до загального списку
        //зберігаємо назву файлу
    ofstream wrtieNewFileToList("storageFile.dat", ios::app);
    wrtieNewFileToList << fileName << endl;

    return true;
}

void DeleteFile(int index, vector<string> &allFileNames)
{
    index--;
    if(index < 0 || index > allFileNames.size())
    {
        InputWaiter("wrong index... ");
        return;
    }
    
    vector<string> temp;
    ifstream fin("storageFile.dat");
    ofstream tempStorage("tempStorage.dat");
    
    for(int i = 0; i < allFileNames.size(); i++)
    {
        string line;
        getline(fin, line);
        
        if(i == index)
        {
                //видалення самого файлу
            remove(allFileNames[i].c_str());
            continue;
        }

            //змінюємо вектор з назвами
        temp.push_back(allFileNames[i]);

            //змінюємо файл з назвами
        tempStorage << line << endl;
    }
    allFileNames = temp;

    fin.close();
    tempStorage.close();
    remove("storageFile.dat");
    rename("tempStorage.dat", "storageFile.dat");
}

void SeeAllFiles(vector<string> &createdFiles, bool withDeleting = false)
{
    if(withDeleting)
    {
        cout << "Select which file you want to delete (0 to exit): " << endl;
    } else 
    {
        cout << "All created files: " << endl;
    }
        for (int i = 0; i < createdFiles.size(); i++)
            cout << i+1 << ") " << createdFiles[i] << endl;
        cout << "^^^^^^^^^" << endl;
    
    if(withDeleting)
    {
        cout << "input> ";
        int point;
        cin >> point;
        if(point >= 1 && point <= createdFiles.size())
            DeleteFile(point, createdFiles);
        else if (point != 0)
            InputWaiter("incorect index");
    } else 
    {
        cout << "enter anything> ";
        char empty;
        cin >> empty;
    }
}

bool WriteToFile(string fileName, string content)
{
        //відкриваємо файл щоб можна було записувати з кінця
    ofstream fout(fileName, ios::app);
    
    fout << content << endl;
    InputWaiter("Success!");

    return true;
}

vector<string> AlreadyCreatedFiles(string storageFile = "storageFile.dat")
{
    ifstream fin(storageFile);
    vector<string> result;

    if(fin.is_open())
    {
        string line;
        while (getline(fin, line))
        {
            result.push_back(line);
        }
    } else
    {
        ofstream fout("storageFile.dat");
    }

    return result;
}

int main()
{
    vector<string> allFiles = AlreadyCreatedFiles();

        // << "0. Stop the program" << endl

    while (true)
    {
            //інтерфейс меню
        cout << " #<MENU># " << endl
            << "1. Create New File" << endl
            << "2. See All Created Files" << endl
            << "3. Delete File" << endl;
        // cout << "input> ";
        int point;
        cout << "input> ";
        cin >> point;
        string fileName;

        switch (point)
        {
        case 1:
            cout << "enter file name> ";
            cin >> fileName;
            CreateNewFile(fileName, allFiles);
            break;
        case 2:
            SeeAllFiles(allFiles);
            break;
        case 3:
            SeeAllFiles(allFiles, true);
            break;
        
        default:
            break;
        }
    }
    
}