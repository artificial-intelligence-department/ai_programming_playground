#include <iostream> // Використовую директиву include, щоб використати cout та cin із  заголовкового файлу <iostream>
using namespace std;//Використовую простір імен std
int main(){
    //Оголошення змінних типу double для зберігання опорів кожного з послідовно з'єднаних резисторів
    double R1; 
	double R2;
	double R3;
    //Вивід повідомлень та зчитування даних,які ввів користувач
	cout << "Enter the value of the first resistor :" << endl;
	cin >> R1;
	cout << "Enter the value of the second resistor" << endl;
	cin >> R2;
	cout << "Enter the value of the third resistor" << endl;
	cin >> R3;
	double totalR = R1 + R2 + R3; //Оголошення змінної типу double для зберігання сумарного опору ел.кола
   
	cout << "Resistance of an electric circuit (series connection): " << totalR << endl; //Вивід результату

	return 0;

}