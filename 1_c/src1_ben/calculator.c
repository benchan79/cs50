#include <math.h>
#include <stdio.h>


int main(void)
{
    // long x;
    // long y;
    // printf("What's x? ");
    // scanf("%li", &x);
    // printf("What's y? ");
    // scanf("%li", &y);

    // printf("%li\n", x + y);

    // float x;
    // float y;
    // printf("What's x? ");
    // scanf("%f", &x);
    // printf("What's y? ");
    // scanf("%f", &y);

    // printf("%.20f\n", x / y);

    float amount;
    printf("Dollar Amount: ");
    scanf("%f", &amount);
    int pennies = round(amount * 100);
    printf("Pennies: %i\n", pennies);
}