#include<stdio.h>

int a = 9;

int call_file2 (void)
{
  a = 10;
  printf ("Assigning 10 to a\n");
  return 0; 
}
