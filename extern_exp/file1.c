#include<stdio.h>

extern int a;
int call_file2 (void);

int main (void)
{
  printf ("The value of a is %d\n", a);
  call_file2();
  printf ("The value of a is %d\n", a);
  return 0;
}
