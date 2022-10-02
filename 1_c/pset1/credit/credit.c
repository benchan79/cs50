#include <stdio.h>

int main(void) 
{
    long number;
    do
    {
        printf("Number: ");
        scanf("%li", &number);
    } 
    while (number < 0);

    // number = 4003600000000014;

    int digit1;
    int sum1 = 0;
    long number1 = number / 10;
    printf("%li\n", number1);

    do
    {
    digit1 = number1 % 10;
    digit1 *= 2;
    digit1 = (digit1 % 10) + (digit1 / 10);
    sum1 += digit1;
    printf("digit1: %i, sum1: %i\n", digit1, sum1);

    number1 = number1 / 100;
    printf("number1: %li\n", number1);
    } 
    while (number1 > 1);
    
    int digit2;
    int sum2 = 0;
    long number2 = number;
    printf("%li\n", number2);

    do
    {
    digit2 = number2 % 10;

    sum2 += digit2;
    printf("digit2: %i, sum2: %i\n", digit2, sum2);

    number2 = number2 / 100;
    printf("number: %li\n", number2);
    } 
    while (number2 > 1);
    
    int sum3 = sum1 + sum2;
    printf("sum3: %i\n", sum3);
    if (sum3 % 10 == 0)
    {
        if (number / 10000000000000 == 34 || number / 10000000000000 == 37)
        {
            printf("AMEX\n");
        }
        else if (number / 100000000000000 == 51 || number / 100000000000000 == 52 || number / 100000000000000 == 53 || number / 100000000000000 == 54 || number / 100000000000000 == 55)
        {
            printf("MASTERCARD\n");
        }
        else if (number / 1000000000000 == 4 || number / 1000000000000000 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}