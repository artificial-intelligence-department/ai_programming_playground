#include<iostream>




void arrayOutput(int arr[],int start,int end){

    std::cout << "Масив від " << start << " до " << end << ": ";

    for(int i = start;i <= end;i++)

        std::cout << arr[i] << " ";




    std::cout << std::endl;

}




int main(){

    using namespace std;




    int size = 10;

    int StartArr[size];




    for(int i = 0; i < size;i++){

        StartArr[i] = i + 1;

        cout << StartArr[i] << " ";

    } 

    cout << endl;




    int k = 3;

    arrayOutput(StartArr,k,k+1);




    int NewSize = size+2;

    int NewArray[NewSize];                           //у методичці не було векторів, тому я не знаю як додати перший елемент в існуючий масив

    NewArray[0] = NewSize - 1;

    NewArray[NewSize-1] = NewSize;

    for(int i = 1;i < NewSize - 1;i++)

        NewArray[i] = StartArr[i-1];




    /*

    int OddToDeleteSize;

    (NewSize % 2 == 0) ? OddToDeleteSize = NewSize/2 : NewSize/2 + 1; 

    int OddToDeleteArray[OddToDeleteSize];

    int CurrIdx = 0;

    for(int i = 0;i < NewSize;i++){

        if(i % 2 == 0)

            OddToDeleteArray[CurrIdx] = i;

    }

    int EvenCount = NewSize-OddToDeleteSize;

    for(int i = 0;i < EvenCount;i++)

     */




    int distance = 1;

    for(int i = 0;i < NewSize;i++)

        if(i % 2 != 0){

            NewArray[i-distance] = NewArray[i];

            distance +=1;

        }




    arrayOutput(NewArray,k,k+1);




    return 0;

}