#include <stdio.h>
    
int main(void)
{
    int cents;
    do
    {
        printf("Change owed: ");
        scanf("%i", &cents);
    } 
    while (cents < 0);
    printf("Stored: %i\n", cents);
    // return cents;

    int quarters;
    quarters = cents / 25;
    printf("quarters: %i\n", quarters);
    // return quarters;

    int dimes;
    cents = cents % 25;
    dimes = cents / 10;
    printf("dimes: %i\n", dimes);
    // return dimes;

    int nickels;
    cents = cents % 10;
    nickels = cents / 5;
    printf("nickels: %i\n", nickels);
    // return nickels;

    int pennies;
    pennies = cents % 5;
    printf("pennies: %i\n", pennies);
    // return pennies;
}