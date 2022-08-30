#include <stdio.h>
int main()
{
    float num;
    printf("enter the number");
    scanf("%f", &num);
    printf("\nnormal print:%f", num);
    //to round off to "n" do %.nf while printing
    printf("\nround to 1 decimal: %.1f", num);
    printf("\nround to 2 decimal: %.2f", num);
}
