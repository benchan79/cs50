#include <stdio.h>
#include <string.h>

typedef struct
{
    char* name;
    char* number;
    char* address;
}
person;

int main(void)
{
    person people[2];

    people[0].name = "Carter";
    people[0].number = "+1-617-495-1000";
    people[0].address = "123 abc";

    people[1].name = "David";
    people[1].number = "+1-949-468-2750";
    people[1].address = "456 def";
 
    char get_name[30];
    printf("Name: ");
    scanf("%s", get_name);

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, get_name) == 0)
        {
            // printf("Found %s\n", people[i].number);
            printf("Found\n");
            printf("Number %s\n", people[i].number);
            printf("Address %s\n", people[i].address);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;

}

// int main(void)
// {
//     char* names[] = {"Carter", "David"};
//     char* numbers[] = {"12345", "678910"};

//     char name[30];
//     printf("Name: ");
//     scanf("%s", name);

//     for (int i = 0; i < 2; i++)
//     {
//         if (strcmp(names[i], name) == 0)
//         {
//             printf("Found %s\n", numbers[i]);
//             return 0;
//         }
//     }
//     printf("Not found\n");
//     return 1;

// }