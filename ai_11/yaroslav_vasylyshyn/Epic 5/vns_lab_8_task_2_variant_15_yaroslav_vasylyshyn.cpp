#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Car{
    string brand;
    int year;
    int price;
    string colour;
};

void write(const Car data[], int size){
    FILE* file_stream1 = fopen("lab8.dat", "wb");

    if (file_stream1 != nullptr) 
    {
        fwrite(data, sizeof(Car), size, file_stream1);
        fclose(file_stream1);
    }else 
        cout << "Error while opening \n";
    
}
void read(Car inserted_data[]){
    FILE* file_stream2 = fopen("lab8.dat", "rb");

    if (file_stream2 != nullptr) 
    {
        fread(inserted_data, sizeof(Car), 3, file_stream2);
        fclose(file_stream2);
    }else 
    cout << "Error while opening \n";    
    
}

int main(){
    int size =3,k,c=0;
    cin>>k;
    Car data[3];
    data[0].brand = "Audi";
    data[0].year = 2021;
    data[0].price = 40000;
    data[0].colour = "White";
    data[1].brand = "Porshe";
    data[1].year = 2023;
    data[1].price = 130000;
    data[1].colour = "Gray";
    data[2].brand = "McLaren";
    data[2].year = 2021;
    data[2].price = 300000;
    data[2].colour = "Dark_Blue";
    write(data, size);
    Car inserted_data[size];
    read(inserted_data);

    cout<<"information about car: \n";
    
    for (int i = 0; i < size; i++)
    {
        cout<<"Car "<<i<<": brand: "<< inserted_data[i].brand <<'\n';
        cout<<"Car "<<i<<": year of manufacture: "<< inserted_data[i].year <<'\n';
        cout<<"Car "<<i<<": price: "<< inserted_data[i].price <<'\n';
        cout<<"Car "<<i<<": colour: "<< inserted_data[i].colour <<'\n';
    }
    cout<<"\n\n";

    for (int i = 0; i < size; i++)
    {
        if(inserted_data[i].year < k)
            c++;  
    }
    size -= c;
    c=0;
    Car sorted_data[size];
    for (int i = 0; i < 3; i++)
    {
        if(inserted_data[i].year>k)
        {
            sorted_data[c]=inserted_data[i];
            c++;  
        }
    }
    write(sorted_data, size);
    Car inserted_sorted_data[size];
    read(inserted_sorted_data);
    for (int i = 0; i < size; i++)
    {
        cout<<"Car "<<i<<": brand: "<< inserted_sorted_data[i].brand <<'\n';
        cout<<"Car "<<i<<": year of manufacture: "<< inserted_sorted_data[i].year <<'\n';
        cout<<"Car "<<i<<": price: "<< inserted_sorted_data[i].price <<'\n';
        cout<<"Car "<<i<<": colour: "<< inserted_sorted_data[i].colour <<'\n';
    }
    cout<<"\n\n";
    Car newCar[1];
    newCar[0].brand = "Mersedes";
    newCar[0].year = 2023;
    newCar[0].price = 200000;
    newCar[0].colour = "Black";

    size++;

    Car new_data[size];
    new_data[0]=newCar[0];
    for (int i = 0; i < size-1; i++)
    {
        new_data[i+1]=inserted_sorted_data[i];
    }
    write(new_data, size);
    Car inserted_sorted_new_data[size];
    read(inserted_sorted_new_data);

    for (int i = 0; i < size; i++)
    {
        cout<<"Car "<<i<<": brand: "<< inserted_sorted_new_data[i].brand <<'\n';
        cout<<"Car "<<i<<": year of manufacture: "<< inserted_sorted_new_data[i].year <<'\n';
        cout<<"Car "<<i<<": price: "<< inserted_sorted_new_data[i].price <<'\n';
        cout<<"Car "<<i<<": colour: "<< inserted_sorted_new_data[i].colour <<'\n';
    }
    return 0;
}