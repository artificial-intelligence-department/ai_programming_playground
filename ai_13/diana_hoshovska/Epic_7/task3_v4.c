#include <stdio.h>
#define pi 3.141529

int main(){
    float p_notebook, p_pencil, sum;
    int q_notebook, q_pencil;
    printf("Task 1\n");     

    printf("Obchyslennya vartosti pokupky. \n");
    printf("Vvedit' pochatkovy dani: \n");

    printf("Enter the price of notebook: ");
    scanf("%f", &p_notebook);

    printf("Enter the number of notebooks: ");
    scanf("%d", &q_notebook);

    printf("Enter the price of pencil: ");
    scanf("%f", &p_pencil);

    printf("Enter the number of pencils: ");
    scanf("%d", &q_pencil);

    sum = (p_notebook*q_notebook) + (p_pencil*q_pencil);
    printf("Sum: %.2f hrn\n", sum);

    printf("Task 2\n");
    float V, h, r1, r2;

    printf("Enter r1: ");
    scanf("%f", &r1);
    printf("Enter r2: ");
    scanf("%f", &r2);
    printf("Enter h: ");
    scanf("%f", &h);
    V = pi*h*(r1*r1-r2*r2);
    printf("Volume of a cylinder: %.2f ", V);

    return 0;
}
