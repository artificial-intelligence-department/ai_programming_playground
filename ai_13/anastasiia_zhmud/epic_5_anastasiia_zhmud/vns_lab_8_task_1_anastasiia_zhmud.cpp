#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
 struct stadium
 {
    string name;
    int year;
    int playgrounds;
    string kindofsport;
 };
 int main(){
     int k=0,n=0, elements=0;
     stadium m;
     FILE* sdiums;
     sdiums = fopen("stadiums.dat", "wb");
     if ((sdiums=fopen("stadiums.dat", "wb"))==NULL){
      cout<<"Eror!";
      exit(1);
     } 
     cout<<"How much stadiums do you want to add?   ";
     cin>>k;
     vector<stadium> mas;
     for(int i=1; i<=k; i++){
      cout<<"Stadium "<<i<<endl;
      cout<<"Enter a name:  \n";
      cin>>m.name;
      cout<<"Enter a year:   \n";
      cin>>m.year;
      cout<<"Enter a number of playgrounds:   \n";
      cin>>m.playgrounds;
      cout<<"Enter a kind of sports:   \n";
      cin.ignore();
      getline(cin, m.kindofsport);
      mas.push_back(m);
      fwrite(&m, sizeof(stadium), 1, sdiums);
        if (ferror(sdiums)) {
            exit(1);
        }
     }
     fclose(sdiums);
     sdiums = fopen("stadiums.dat", "rb");
     if ((sdiums=fopen("stadiums.dat", "rb"))==NULL){
      cout<<"Eror!";
      exit(1);}
     for(int i=0; i<k; i++){
      fread(&m, sizeof(stadium), 1, sdiums);
      cout<<"Stadium "<<i+1<<endl;
      cout<<mas[i].name<<endl;
      cout<<mas[i].year<<endl;
      cout<<mas[i].playgrounds<<endl;
      cout<<mas[i].kindofsport<<endl<<endl;
     }
     fclose(sdiums);
     int filtr=0;
     cout<<"Enter the year from which you want to see the stadiums:  ";
     cin>>filtr;
     for(int i=0; i<k; i++){
      if(mas[i].year<filtr){
            mas.erase(mas.begin() + i);  
            k--; 
            i--;
            n++;
      }
     }
      FILE* sdiums_after1;
      sdiums_after1=fopen("stadiums_after_change.dat", "wb");
      if ((sdiums_after1=fopen("stadiums_after_change.dat", "wb"))==NULL){
      cout<<"Eror!";
      exit(1);}
      int ns = mas.size();
      for (int i = 0; i <ns; i++) {
        fwrite(&m, sizeof(stadium), 1, sdiums_after1);
      }
      fclose(sdiums_after1);
      cout<<"File after first change:  \n"<<endl;
      sdiums_after1 = fopen("stadiums_after_change.dat", "rb");
      if ((sdiums_after1=fopen("stadiums_after_change.dat", "rb"))==NULL){
      cout<<"Eror!";
      exit(1);}
      for (int i = 0; i <ns; i++) {
        fread(&m, sizeof(stadium), 1, sdiums_after1);
        cout << "Stadium " << i + 1 << endl;
        cout << mas[i].name << endl;
        cout << mas[i].year << endl;
        cout << mas[i].playgrounds << endl;
        cout << mas[i].kindofsport << endl << endl;
    }
     fclose(sdiums_after1);
     FILE* sdiums_after2;
     sdiums_after2 = fopen("stadiums_after_change_1.dat", "wb");
     if ((sdiums_after2=fopen("stadiums_after_change_1.dat", "wb"))==NULL){
      cout<<"Eror!";
      exit(1);}
     cout<<"Enter the number of the stadium before which you want to put the entered stadiums:   \n";
     cin>>elements;
     cout<<"\nEnter a stadiums you want to add:  \n";
     for(int i=1; i<=2; i++){
      cout<<"Stadium "<<i<<endl;
      cout<<"Enter a name:  \n";
      cin>>m.name;
      cout<<"Enter a year:   \n";
      cin>>m.year;
      cout<<"Enter a number of playgrounds:   \n";
      cin>>m.playgrounds;
      cout<<"Enter a kind of sports:   \n";
      cin.ignore();
      getline(cin, m.kindofsport);
      mas.emplace(mas.begin()+(elements-1), m);
      fwrite(&m, sizeof(stadium), 1, sdiums_after2);
     }
     fclose(sdiums_after2);
     int newSize = mas.size();
     sdiums_after2 = fopen("stadiums_after_change_1.dat", "rb");
     if ((sdiums_after2=fopen("stadiums_after_change_1.dat", "rb"))==NULL){
      cout<<"Eror!";
      exit(1);}
     for(int i=0; i<newSize; i++){
      fread(&m, sizeof(stadium), 1, sdiums_after2);
      cout<<"Stadium "<<i+1<<endl;
      cout<<mas[i].name<<endl;
      cout<<mas[i].year<<endl;
      cout<<mas[i].playgrounds<<endl;
      cout<<mas[i].kindofsport<<endl<<endl;
     }
     fclose(sdiums_after2);
}