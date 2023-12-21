#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult { Success, Failure,};

FileOpResult write_to_file(const string &name, const string &content)
{
    ofstream outFile(name, ios_base::out);
    if(!outFile)
    {
        return Failure;
    }
    size_t size = content.size();
    outFile.write((char*)&size, sizeof(size));
    outFile.write(content.c_str(), sizeof(content));
    return Success;
}
FileOpResult read_from_file(const string &name)
{
    ifstream inFile(name, ios::out);
    if(!inFile)
    {
        return Failure;
    }
    size_t size;
    inFile.read((char *)&size, sizeof(size));
    string str(size,' ');
    inFile.read(&str[0], size);

    cout<<"The current text file is: \n"<<str;
    return Success;
}

int main()
{
    string input;
    string action;
    string name;
    while(true)
    {
        cout<<"\nChoose action to do:\n"
        <<"1) write\n"
        <<"2) read\n"
        <<"3) end\n";
        cin>>action;
        cin.ignore();
        if(action == "write")
        {
            cout<<"Enter name of file to write: \n";
            cin>>name;
            cin.ignore();
            getline(cin, input);
            if(write_to_file(name, input)==1)
            {
                cout<<"\nFailure\n";
            }
            else
            {
                cout<<"\nSuccess\n";
            }
        }
        else if(action=="read")
        {
            cout<<"Enter name of file to read: \n";
            cin>>name;
            cin.ignore();
            if(read_from_file(name)==1)
            {
                cout<<"\nFailure\n";
            }
            else
            {
                cout<<"\nSuccess\n";
            }
        }
        else if(action=="end")
        {
            break;
        }
    }
}