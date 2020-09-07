#include <stdio.h>


typedef int(*int_fold_func)(int, int);
int foldl_int_int(int numbers[], int numbers_siz, int_fold_func f);
int add(int a, int b);
long sum(int numbers[], int numbers_siz);

/// Main:
int main(void){
  int nums[] = {1, 2, 3, 4, 5};
  printf("%ld", sum(nums, 5));


  return 0;
}




/// Functions:
long sum(int numbers[], int numbers_siz){
  return foldl_int_int(numbers, numbers_siz, add);
}


int foldl_int_int(int numbers[], int numbers_siz, int_fold_func f){
  int result = 0;

  for (int i = 0; i < numbers_siz; ++i){
    result = f(result, numbers[i]);
  }
  return result;
}

int add(int a, int b){
  return a + b;
}
