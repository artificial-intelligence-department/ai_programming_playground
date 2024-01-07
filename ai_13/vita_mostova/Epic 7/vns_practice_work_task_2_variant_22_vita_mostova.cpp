#include <iostream> // Використовую директиву include, щоб використати cout та cin із  заголовкового файлу <iostream>
#include <cmath>// Використовую директиву include, для використання pow із  заголовкового файлу <cmath>
using namespace std;//Використовую простір імен std
bool PointBelongsToTheCircle(int x,int y,int a,int b,int R);//Оголошення функції,яка перевіряє чи точка належить колу
int main(){
int a,b,R; //Оголошення змінних типу int
//Вивід повідомлень та зчитування даних,які ввів користувач
cout<<"Please enter coordinates of the center of the circle : "<<endl;
cin>>a>>b;
cout<<"Enter the radius : "<<endl;
cin>>R;
cout<<"Now enter 5 coordinates you want to check : "<<endl;
//Цикл,якому зчитуємо координати 5 точок, викликаємо функцію та виводимо результати
for(int i=0;i<5;i++){
    int x,y;
    cin>>x>>y;
    cout<<"Point ("<<x<<","<<y<<") ";
    cout<< (PointBelongsToTheCircle(x,y,a,b,R)?  "belongs to the circle ": "does not belong to the circle ")<<endl;;
}
return 0;
}
//Функція, яка перевіряє чи точка належить колу
bool PointBelongsToTheCircle(int x,int y,int a,int b,int R){
  int result=pow((x-a),2)+pow((y-b),2);
  return (result==pow(R,2))? true: false; //Використання тернарного оператора для повернення true або false

}