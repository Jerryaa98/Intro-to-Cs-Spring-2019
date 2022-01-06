/*********************************************
Student One (GIRIES ABU AYOUB)
Assignment number: 1
Exercise number: 1
********************************************/


#include <stdio.h>
#define PI 3.141

int main()
{

    double r,a,b;

    printf("Please enter the value of r: ");
    scanf("%lf", &r);
    printf("Please enter the value of a: ");
    scanf("%lf", &a);
    printf("Please enter the value of b: ");
    scanf("%lf", &b);

    double CircleArea = PI * r * r;
    printf("The area of the circle is: %0.2f.\n",CircleArea);

    double RectangleArea = a * b;
    printf("The area of the Rectangle is: %0.2f.\n",RectangleArea);

    double SquareArea = 4 * r * r;
    printf("The area of the Square is: %0.2f.\n",SquareArea);

    double RelativeArea = (CircleArea - RectangleArea) / SquareArea;
    printf("The relative size of the white area is: %0.2f.\n",RelativeArea);

    return 0;
}
