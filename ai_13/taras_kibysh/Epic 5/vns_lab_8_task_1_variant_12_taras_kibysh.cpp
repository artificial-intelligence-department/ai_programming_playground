#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct Disk {
    char title[50];
    char author[50];
    int duration;
    float price;
};

void writeDisks(FILE* file, const vector<Disk>& disks) {
    for (const Disk& disk : disks) {
        fwrite(&disk, sizeof(Disk), 1, file);
    }
}

void readAndPrintDisks(FILE* file) {
    rewind(file);
    Disk disk;
    while (fread(&disk, sizeof(Disk), 1, file)) {
        cout << "Name of disk: " << disk.title << endl;
        cout << "Author of disk: " << disk.author << endl;
        cout << "Duration of disk: " << disk.duration << " minutes" << endl;
        cout << "Price of disk: $" << disk.price << endl;
        cout << "----------------------" << endl;
    }
}

void removeByDuration(FILE* file, int trigger);

int main() {
    FILE* file;

    // Write data to file
    file = fopen("Disks.bin", "wb");
    if (!file) {
        perror("Error opening file for writing");
        return 1;
    }

    vector<Disk> musicDisks = {
        {"show must go on", "ACDC", 20, 195.5},
        {"christmas song", "chor Abob", 33, 300},
        {"Last love", "Dua Lipa", 40, 120.45}
    };
    writeDisks(file, musicDisks);

    fclose(file);

    cout << "Data has been written to Disks.bin" << endl;

    // Read and print original data
    file = fopen("Disks.bin", "rb");
    if (!file) {
        perror("Error opening file for reading");
        return 1;
    }

    readAndPrintDisks(file);
    fclose(file);

    // Open the file in append mode for further modifications
    file = fopen("Disks.bin", "r+b");
    if (!file) {
        perror("Error opening file for reading and writing");
        return 1;
    }

    // Remove elements based on duration
    int trigger = 33;
    removeByDuration(file, trigger);
     fclose(file);


file = fopen("Disks.bin", "r+b");
    // Read and print updated data
    cout << "___________New list of disk_______________" << endl;
    readAndPrintDisks(file);


    fclose(file);
    return 0;
}

void removeByDuration(FILE* file, int trigger) {
    // Go to the end of the file
    fseek(file, 0, SEEK_END);

    // Calculate the number of records in the file
    long numRecords = ftell(file) / sizeof(Disk);

    // Go back to the beginning of the file
    rewind(file);

    // Read records and filter those with matching duration
    std::vector<Disk> result;
    for (long i = 0; i < numRecords; ++i) {
        Disk currentDisk;
        fread(&currentDisk, sizeof(Disk), 1, file);
        
        if (currentDisk.duration == trigger) {
            Disk disk1 = {"Lost on you", "LP", 36, 100.34};
            Disk disk2 = {"Kadilak", "Dzidzio", 36, 100.34};
            result.push_back(disk1);
            result.push_back(disk2);
        }
        else{
             result.push_back(currentDisk);
        }
    }

    // Truncate the file to remove all existing records
    fclose(file);
    // file = fopen("Disks.bin", "wb");
    // fclose(file);

    // Append the filtered records back to the file
    file = fopen("Disks.bin", "wb");
    for (const Disk& disk : result) {
        fwrite(&disk, sizeof(Disk), 1, file);
    }
    fclose(file);
}
