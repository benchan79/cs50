#include <ctype.h>
//#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 1000

// Compile using this command: "cc round.c -o round -lm"
// Or this command: "gcc round.c -lm"
// Need to link with the math library
// The math library functions are not part of standard C library 
// which is linked by default. So you need to link it yourself.
// https://stackoverflow.com/questions/1033898/why-do-you-have-to-link-the-math-library-in-c

int main(void)
{
    int n = round(5.9084);
    printf("%i\n", n);
    
    int index = round(n * 0.1);
    printf("%i\n", index);
}
