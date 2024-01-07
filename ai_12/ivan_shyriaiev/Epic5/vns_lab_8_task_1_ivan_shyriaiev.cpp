#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct applicant{
    string full_name;
    int birth_year;
    int math, ukrainian, english;
    int GPA; 
};
 applicant* createapplicant(const char *file, int amount, applicant v[]){
    FILE *f;
    applicant pers;
        if(!(f=fopen(file,"wb"))){
            cout<<"Failed to open a file";
            exit(1);
        }

        for(int i=0;!feof(f) && i<amount;i++){
            cin.ignore();
            cout<<"Enter full name"<<"\n"; getline( cin, pers.full_name );
            cout<<"Enter birth year"<<"\n"; cin>>pers.birth_year;
            cout<<"Enter scores for math/ukr/english"<<"\n"; cin>>pers.math>>pers.ukrainian>>pers.english;
            cout<<"Enter GPA"<<"\n"; cin>>pers.GPA;
                v[i]=pers;
            fwrite(&pers, sizeof(applicant),1,f);
                if(ferror(f)){
                    cout<<"Failed to write in file";
                    exit(2);
            }
        }
        fclose(f);

    return v;
}
void readapplicants(const char *file, int amount){
    FILE *f;
    applicant pers;
        if (!(f=fopen(file, "rb"))){
            cerr << "Failed to open file!\n";
            exit(1);
        }

        for(int i = 0;!feof(f) && i<amount; i++){
            fread(&pers, sizeof(applicant),1,f);
            cout << "applicant " << i+1 << ":\n";
            cout << pers.full_name<<"\n";
            cout << pers.birth_year<<"\n";
            cout <<"Math: "<< pers.math<<" Ukrainian: "<<pers.ukrainian<<" English: "<< pers.english<<"\n";
            cout <<"GPA: " <<pers.GPA<<"\n";
            cout<<endl;
        }

        fclose(f);
    return;
}
applicant* deleteapplicant(const char *fl, int index, int amount, applicant* v){
    

    for(int i=index;i<amount;i++)
        v[i]=v[i+1];
    amount--;

    fstream f(fl,ios::in|ios::binary);
    if(f){
            f.write( reinterpret_cast<char*>(v),amount*sizeof(applicant));
            f.close();
        } else{
            cout<<"Error!";
        }
        return v;
   
}

void addapplicant(const char *filee,string surname,applicant* v, int amount){

    applicant newpers;
    int i;
        
        cin.ignore();
            cout<<"Enter full name"<<"\n"; getline(cin, newpers.full_name);
            cout<<"Enter birth year"<<"\n"; cin>>newpers.birth_year;
            cout<<"Enter scores for math/ukr/english"<<"\n"; cin>>newpers.math>>newpers.ukrainian>>newpers.english;
            cout<<"Enter GPA"<<"\n"; cin>>newpers.GPA;
            
        for(i=0;i<amount;i++){
            if(v[i].full_name.find(surname)!= string::npos){
                for(int j = amount; j>i;j--)
                    v[j+1]=v[j];
                v[i+1]=newpers;
                break;
            }
            
        } 
        amount++;
        fstream f(filee,ios::out|ios::in | ios::binary);   

        if(f){
            f.write( reinterpret_cast<char*>(v),amount*sizeof(applicant));
            f.close();
        } else{
            cout<<"Error!";
        }
    
}
int main(){
    int i,amount,index;
    string surname;
    applicant everyone[10];


    cout<<"How many applicants do you want to create?\n";
    cin>>amount;
    applicant* everyone2 = createapplicant("f.dat",amount, everyone);
    cout<<endl;

    cout<<"here is all applicants "<<amount<<":\n";
    readapplicants("f.dat", amount);
    cout<<endl;

    cout<<"Chose the applicant you want to delete (out of "<<amount<<"): ";
    cin>>index;
    index--;
    everyone2 = deleteapplicant("f.dat",index, amount, everyone2);
    cout<<endl;
    amount--;
    

    cout<<"here is all applicants "<<amount<<":\n";
    readapplicants("f.dat", amount);
    cout<<endl;

    cout<<"Enter the surname after wich add new appplicant: \n";
   
    cin>>surname;
    addapplicant("f.dat", surname, everyone2, amount);
    cout<<endl;
    amount++;

    cout<<"here is all applicants "<<amount<<":\n";
    readapplicants("f.dat", amount);
    cout<<endl;

    return 0;
}

