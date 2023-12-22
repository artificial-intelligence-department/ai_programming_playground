#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Musicdisc {
    string title;
    string author;
    int duration;
    double price;
};

void printFile(const string& filename){
    ifstream file (filename);

    if (!file.is_open()){
        cout << "Error: unable to open file" << endl;
        return;
    }

    Musicdisc disc;

    while (file >> disc.title >> disc.author >> disc.duration >> disc.price){
        cout << "Title: " << disc.title << " Author:" << disc.author <<" Duration: " << disc.duration << " Price:" << disc.price <<endl;
    }
    file.close();
}

void addElement(const string& filename, const Musicdisc& newDisc){
    ofstream file(filename, ios::app);
    
     if (!file.is_open()){
        cout << "Error: unable to open file" << endl;
        return;
    }

    file << newDisc.title << " " << newDisc.author << " " << newDisc.duration << " " << newDisc.price << "\n";
    file.close();
}

void removeElement(const string& filename, int duration) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error: unable to open file" << endl;
        return;
    }

    ofstream tempFile("temp.dat");

    if (!tempFile.is_open()) {
        cout << "Error: unable to open temp file for writing" << endl;
        file.close();
        return;
    }

    Musicdisc disc;
    bool isdeleted = false;

    while (file >> disc.title >> disc.author >> disc.duration >> disc.price) {
        if (disc.duration == duration && !isdeleted) {
            isdeleted = true;
            continue; // Пропускаємо видалений елемент
        }

        tempFile << disc.title << " " << disc.author << " " << disc.duration << " " << disc.price << "\n";
    }

    file.close();
    tempFile.close();

    // Видаляємо оригінальний файл та перейменовуємо тимчасовий на його місце
    remove(filename.c_str());
    rename("temp.dat", filename.c_str());
}

int main (){
    const string filename = "music_discs.dat";
    Musicdisc disc1 = { "Album1", "Artist1", 60, 19.99 };
    Musicdisc disc2 = { "Album2", "Artist2", 90, 24.99 };
    Musicdisc disc3 = { "Album3", "Artist3", 120, 29.99 };

    addElement(filename, disc1);
    addElement(filename, disc2);
    addElement(filename, disc3);

    
    std::cout << "All artist" << endl;
    printFile(filename);

    
    removeElement(filename, 90);

    
   cout << "\nAfter deleting an element:" << endl;
    printFile(filename);

   
    Musicdisc newDisc1 = { "NewAlbum1", "NewArtist1", 75, 21.99 };
    Musicdisc newDisc2 = { "NewAlbum2", "NewArtist2", 80, 27.99 };
    addElement(filename, newDisc1);
    addElement(filename, newDisc2);

    
    cout << "\nAfter adding new elements:" << endl;
    printFile(filename);
    return 0;
}
