#include <stdio.h>
#include <stdbool.h>
#include "utils.h"

int main(void){

  bool num1 = is_number("113");
  bool num2 = is_number("-113");
  bool num3 = is_number("");
  
  printf("\nRESULT: %d, %d, %d", num1, num2, num3);
  return 0;

}
