#include <stdio.h>

int main()
{
  int f0 = 0, f1 = 0, f2 = 0, f3 = 0;
  int i;

  for (i = 1; i < 6; i++)
  {
    f0 = i + f2 - f1 - f3;
    f3 = f2;
    f2 = f1;
    f1 = f0;
  }

  printf("(f0,f1,f2,f3,i) = (%d, %d, %d, %d, %d)\n", f0, f1, f2, f3, i);

  return 0;
}