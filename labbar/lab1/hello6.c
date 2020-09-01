#include <stdio.h>

int main(void)
{
  int i = 1;              // deklaration och initiering av iterationsvariabeln
  while (i <= 10)         // iterationsvillkor (utför blocket så länge i är mindre än 11)
  {                       // loop-kropp (utförs så länge iterationsvillkoret är uppfyllt)
    printf("%d\n", 1);    // skriv ut 1, och en radbrytning
    i = i + 1;            // öka i:s värde med 1 (förändring av iterationsvariabeln)
  }
  
  puts(" ########## Fixad version ########## ");
  
  for (int i = 1;
         i <= 10; 
            i++){
 
    printf("%d\n", i); // Antog att programmet skulle skriva ut nummerna 1-10
    
  }
  
  
  return 0;
}