#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult
{
    Success,
    Failure
};

FileOpResult copy_file(const char *source_file, const char *destination_file)
{
    ifstream input_file(source_file);
    ofstream output_file(destination_file);

    if (!input_file.is_open())
    {
        cerr << "Error opening source file: " << source_file << endl;
        return Failure;
    }

    if (!output_file.is_open())
    {
        cerr << "Error opening destination file: " << destination_file << endl;
        return Failure;
    }

    output_file << input_file.rdbuf();

    input_file.close();
    output_file.close();
    return Success;
}

int main()
{
    char source[512], destination[512];
    cout << "Enter the name of the file you want to copy from: ";
    cin.getline(source, sizeof(source));
    cout << "Enter the name of the file you want to copy to: ";
    cin.getline(destination, sizeof(destination));

    FileOpResult result = copy_file(source, destination);

    if (result == Success)
    {
        cout << "File copied successfully.";
    }
    else
    {
        cout << "File copy failed. Apologies.";
    }

    return 0;
}
