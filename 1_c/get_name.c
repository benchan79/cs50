#include <stdio.h>

int main(void)
{
    char firstName[30];
    char lastName[30];
    printf("Enter your first name: ");
    scanf("%s", firstName);
    printf("Enter your lirst name: ");
    scanf("%s", lastName);
    printf("Hello %s %s!\n", firstName, lastName);    
}