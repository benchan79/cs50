#include <stdio.h>
#include <stdlib.h>

const int N = 3;

int * get_scores() 
{
    static int r[3];

    r[0] = 1;
    r[1] = 2;
    r[2] = 3;

   return r;
}


int main () 
{
   int *p;
   int i;

   p = get_scores();
	
   for ( i = 0; i < 3; i++ ) {
      printf( "%d\n", *(p + i));
   }

   return 0;
}