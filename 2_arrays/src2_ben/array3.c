#include <stdio.h>  

int *getarray()  
{  
  static int arr[3];  
  printf("Enter the elements in an array : ");  
  for (int i = 0; i < 3; i++)  
  {  
      scanf("%d",&arr[i]);  
  }  
  return arr;  
      
}  
int main()  
{  
  int *ptr;  
  ptr = getarray();  
  printf("\nElements that you have entered are :");  
  for (int i = 0; i < 3; i++)  
  {  
      printf("%d ", ptr[i]);  
  }
  printf("\n");
}  