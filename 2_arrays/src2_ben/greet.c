#include <stdio.h>

// *argv[] is a pointer
int main(int argc, char *argv[])
{
    // printf("hello, %s %s %s\n", argv[0], argv[1], argv[2]);

    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("hello, world\n");
    }
}