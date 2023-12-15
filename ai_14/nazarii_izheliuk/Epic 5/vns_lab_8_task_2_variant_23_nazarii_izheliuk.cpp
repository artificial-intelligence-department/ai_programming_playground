#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

struct stadium
{
    string name;
    int year;
    int number_of_platforms;
    vector<string> kinds_of_sport;
};

void createFile() {
    ofstream file("C:/Users/Lenovo Gaming/Desktop/file.txt"); 

    //Стадіон 1
    stadium stadium1;

    stadium1.name = "Олімпійський";
    stadium1.year = 1923;
    stadium1.number_of_platforms = 5;

    stadium1.kinds_of_sport.push_back("Футбол");
    stadium1.kinds_of_sport.push_back("Теніс");
    stadium1.kinds_of_sport.push_back("Легка атлетика");

    //Стадіон 2
    stadium stadium2;

    stadium2.name = "Донбас Арена";
    stadium2.year = 2009;
    stadium2.number_of_platforms = 3;

    stadium2.kinds_of_sport.push_back("Футбол");
    stadium2.kinds_of_sport.push_back("Легка атлетика");

    //Стадіон 3
    stadium stadium3;

    stadium3.name = "Арена Львів";
    stadium3.year = 2010;
    stadium3.number_of_platforms = 3;

    stadium3.kinds_of_sport.push_back("Футбол");

    //Стадіон 4
    stadium stadium4;

    stadium4.name = "ЦСК Київ";
    stadium4.year = 1965;
    stadium4.number_of_platforms = 1;

    stadium4.kinds_of_sport.push_back("Футбол");
    stadium4.kinds_of_sport.push_back("Легка атлетика");

    //Вивід стадіону1
    file << stadium1.name << endl;
    file << stadium1.year << endl;
    file << stadium1.number_of_platforms << endl;
    for(int i = 0; i < stadium1.kinds_of_sport.size(); i++){
        file << stadium1.kinds_of_sport[i] << " ";
    }
    file << endl << endl;

    //Вивід стадіону2
    file << stadium2.name << endl;
    file << stadium2.year << endl;
    file << stadium2.number_of_platforms << endl;
    for(int i = 0; i < stadium2.kinds_of_sport.size(); i++){
        file << stadium2.kinds_of_sport[i] << " ";
    }
    file << endl << endl;

    //Вивід стадіону3
    file << stadium3.name << endl;
    file << stadium3.year << endl;
    file << stadium3.number_of_platforms << endl;
    for(int i = 0; i < stadium3.kinds_of_sport.size(); i++){
        file << stadium3.kinds_of_sport[i] << " ";
    }
    file << endl << endl;


    //Вивід стадіону4
    file << stadium4.name << endl;
    file << stadium4.year << endl;
    file << stadium4.number_of_platforms << endl;
    for(int i = 0; i < stadium4.kinds_of_sport.size(); i++){
        file << stadium4.kinds_of_sport[i] << " ";
    }
    file << endl << endl;


    file.close();
    
}

void delete_information(int year){      
    //Стадіон 1
    ofstream file("C:/Users/Lenovo Gaming/Desktop/file1.txt");
    stadium stadium1;

    stadium1.name = "Олімпійський";
    stadium1.year = 1923;
    stadium1.number_of_platforms = 5;

    stadium1.kinds_of_sport.push_back("Футбол");
    stadium1.kinds_of_sport.push_back("Теніс");
    stadium1.kinds_of_sport.push_back("Легка атлетика");

    //Стадіон 2
    stadium stadium2;

    stadium2.name = "Донбас Арена";
    stadium2.year = 2009;
    stadium2.number_of_platforms = 3;

    stadium2.kinds_of_sport.push_back("Футбол");
    stadium2.kinds_of_sport.push_back("Легка атлетика");

    //Стадіон 3
    stadium stadium3;

    stadium3.name = "Арена Львів";
    stadium3.year = 2010;
    stadium3.number_of_platforms = 3;

    stadium3.kinds_of_sport.push_back("Футбол");

    //Стадіон 4
    stadium stadium4;

    stadium4.name = "ЦСК Київ";
    stadium4.year = 1965;
    stadium4.number_of_platforms = 1;

    stadium4.kinds_of_sport.push_back("Футбол");
    stadium4.kinds_of_sport.push_back("Легка атлетика");
    
    
    if(stadium1.year < year){
        //Вивід стадіону2
        file << stadium2.name << endl;
        file << stadium2.year << endl;
        file << stadium2.number_of_platforms << endl;
        for(int i = 0; i < stadium2.kinds_of_sport.size(); i++){
            file << stadium2.kinds_of_sport[i] << " ";
        }
        file << endl << endl;

        //Вивід стадіону3
        file << stadium3.name << endl;
        file << stadium3.year << endl;
        file << stadium3.number_of_platforms << endl;
        for(int i = 0; i < stadium3.kinds_of_sport.size(); i++){
            file << stadium3.kinds_of_sport[i] << " ";
        }
        file << endl << endl;

        //Вивід стадіону4
        file << stadium4.name << endl;
        file << stadium4.year << endl;
        file << stadium4.number_of_platforms << endl;
        for(int i = 0; i < stadium4.kinds_of_sport.size(); i++){
            file << stadium4.kinds_of_sport[i] << " ";
        }
        file << endl << endl;
    }else if(stadium2.year < year){
        //Вивід стадіону1
        file << stadium1.name << endl;
        file << stadium1.year << endl;
        file << stadium1.number_of_platforms << endl;
        for(int i = 0; i < stadium1.kinds_of_sport.size(); i++){
            file << stadium1.kinds_of_sport[i] << " ";
        }
        file << endl << endl;

        //Вивід стадіону3
        file << stadium3.name << endl;
        file << stadium3.year << endl;
        file << stadium3.number_of_platforms << endl;
        for(int i = 0; i < stadium3.kinds_of_sport.size(); i++){
            file << stadium3.kinds_of_sport[i] << " ";
        }
        file << endl << endl;

        //Вивід стадіону4
        file << stadium4.name << endl;
        file << stadium4.year << endl;
        file << stadium4.number_of_platforms << endl;
        for(int i = 0; i < stadium4.kinds_of_sport.size(); i++){
            file << stadium4.kinds_of_sport[i] << " ";
        }
        file << endl << endl;
    }else if(stadium3.year < year){
        //Вивід стадіону1
        file << stadium1.name << endl;
        file << stadium1.year << endl;
        file << stadium1.number_of_platforms << endl;
        for(int i = 0; i < stadium1.kinds_of_sport.size(); i++){
            file << stadium1.kinds_of_sport[i] << " ";
        }
        file << endl << endl;

        //Вивід стадіону2
        file << stadium2.name << endl;
        file << stadium2.year << endl;
        file << stadium2.number_of_platforms << endl;
        for(int i = 0; i < stadium2.kinds_of_sport.size(); i++){
            file << stadium2.kinds_of_sport[i] << " ";
        }
        file << endl << endl;

        //Вивід стадіону4
        file << stadium4.name << endl;
        file << stadium4.year << endl;
        file << stadium4.number_of_platforms << endl;
        for(int i = 0; i < stadium4.kinds_of_sport.size(); i++){
            file << stadium4.kinds_of_sport[i] << " ";
        }
        file << endl << endl;
    }else if(stadium4.year < year){
        //Вивід стадіону1
        file << stadium1.name << endl;
        file << stadium1.year << endl;
        file << stadium1.number_of_platforms << endl;
        for(int i = 0; i < stadium1.kinds_of_sport.size(); i++){
            file << stadium1.kinds_of_sport[i] << " ";
        }
        file << endl << endl;

        //Вивід стадіону2
        file << stadium2.name << endl;
        file << stadium2.year << endl;
        file << stadium2.number_of_platforms << endl;
        for(int i = 0; i < stadium2.kinds_of_sport.size(); i++){
            file << stadium2.kinds_of_sport[i] << " ";
        }
        file << endl << endl;

        //Вивід стадіону3
        file << stadium3.name << endl;
        file << stadium3.year << endl;
        file << stadium3.number_of_platforms << endl;
        for(int i = 0; i < stadium3.kinds_of_sport.size(); i++){
            file << stadium3.kinds_of_sport[i] << " ";
        }
        file << endl << endl;
    }    
}

int main(){
    int year;
    createFile();
    cout << "Введіть рік: ";
    cin >> year;
    delete_information(year);
    return 0;
}
