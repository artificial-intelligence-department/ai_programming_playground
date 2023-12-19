#include <iostream>

double from_yards_to_meters(double yards) { return (yards*3*12*2.54/100); }
//ШІ-11 Стожук Роман
int main() {
    const double field_length=from_yards_to_meters(100);
    const double width_of_letter=2*0.8;
    const int n_length=8;
    char name[n_length]="Stozhuk";
    double n_width=width_of_letter*n_length;
    std::cout << "Minimum length of field to install one banner" << n_width << std::endl;
    double field_center=field_length/2;
    int letters_on_field=(int)(field_length/width_of_letter);
    double counter_start=0,counter_end=width_of_letter;
    std::cout << "Starting from the left at the center of field is: ";
    for (int n=0;n<letters_on_field;n++) {
        if (((counter_start>field_center-1.5) && (counter_start<field_center+1.5)) ||
        ((counter_end>field_center-1.5) && (counter_end<field_center+1.5))) {std::cout << name[n%7] << ' ';}
        counter_start+=width_of_letter;
        counter_end+=width_of_letter;
    }
    counter_start=(letters_on_field-1)*width_of_letter, counter_end=letters_on_field*width_of_letter;
    std::cout << "\nStarting from the right at the center of field is: ";
    for (int n=letters_on_field-1;n>=0;n--) {
        if (((counter_start>field_center-1.5) && (counter_start<field_center+1.5)) ||
        ((counter_end>field_center-1.5) && (counter_end<field_center+1.5))) {std::cout << name[n%7] << ' ';}
        //тут коректний механізм знаходження літер, але виводяться в протилежному порядку, на жаль
        counter_start-=width_of_letter;
        counter_end-=width_of_letter;
    }
    return 0;
}