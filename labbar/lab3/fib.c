#include <stdio.h>
#include <stdlib.h>

int fib(int num);

/// Den ointressanta main()-funktionen
int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s number\n", argv[0]);
  }
  else
  {
    int n = atoi(argv[1]);
    if (n < 2)
    {
      printf("fib(%d) = %d\n", n, n);
    }
    else
    {
      printf("fib(%s) = %d\n", argv[1], fib(n));
    }
  }
  return 0;
}


/// Den intressanta delen av programmet
int fib(int num){
  int fib_iter(int a, int b, int n){
    if (n <= 1) return a;             // Base Case
    return fib_iter(a + b, a, n - 1); // Tail Recursion
  }
  return fib_iter(1, 0, num);
}
