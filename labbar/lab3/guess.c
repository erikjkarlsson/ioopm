#include <stdio.h>
#include <stdbool.h>
#include "utils.h"

#include <stdlib.h>
#include <time.h>



int main(void){
  // Buffer for name input
 
  int guess           = 0;  // Current Guess
  int guess_count     = 0;  // Amount of Guesses
  int guess_count_max = 15; // Maximum Amount of Guesses

  // Get Random Number
  seed_random();                
  int num = random_number(100); 

  // Print Rules
  char *buf_name = ask_question_string("Skriv ditt namn: ");

  printf("Du %s, jag tänker på ett tal.\n", buf_name);
  puts("Kan du gissa vilket?\n");

  
  do{
    // Get Guess
    guess = ask_question_int("Nummer: ");

    if (guess == -1) {
      printf("Gissningen är inte ett nummer!\n");
      guess = 0;

    }else{
      // To help with binary search
      if (guess > num){
	puts("För stort!");
      }else if (guess < num){
	puts("För litet!");
      }

      // Exit if Too Much guesses
      if (guess_count >= guess_count_max){
	printf("Slut på gissningar, jag tänkte på %d\n", num);
	return 0;
      }
      
    }
    guess_count++;
    printf("Gissning %d av %d\n", guess_count, guess_count_max);
  }while (guess != num);

  // Succeded, Print Winning Message
  printf("Bingo! Det tog %s %d gissningar\n", buf_name, guess_count);
  printf("att komma fram till %d.\n", num);

  return 0;

}
