#include <stdio.h>
#include <stdbool.h>
#include "utils.h"

#include <stdlib.h>
#include <time.h>

int print_guesses(int *guess_count, int guess_count_max);
int guess_number(int *guess, int answer);
int print_success(char *name, int guesses, int answer);
int initialize(char *name, int name_buffer_size);
char *ask_question_string(char *question, char *buf, int buf_siz);



int main(void){
  int buf_siz_name = 20;
  char buf_name[buf_siz_name];
  
  int guess = 20;
  int guess_count = 0;
  int guess_count_max = 15;
  
  seed_random(); // Seed random number
  int num = random_number(100); // Get 
  initialize(buf_name, buf_siz_name);
  
  do{
    guess_number(guess, num);
    print_guesses(guess_count, guess_count_max);
    
    if (guess_count >= guess_count_max){
      printf("Slut på gissningar, jag tänkte på %d", num);
      return 0;
    }      
  }while (guess != num);

  print_success(buf_name, guess_count, num);
  return 0;
}



int guess_number(int guess, int answer){
    *guess = ask_question_int("");
    *guess_count++;

    if (guess > answer){
      puts("För stort!\n");
    }else if (guess < answer){
      puts("För litet!\n");
    }
  return 0;
}


int print_guesses(int guess_count, int guess_count_max){


  printf("Gissing %d av %d\n", guess_count, guess_count_max);
  
  return 0;
}


int initialize(char *name, int name_buffer_size){
  ask_question_string("Skriv ditt namn: ",
		      name,
		      name_buffer_size);

  printf("Du %s, jag tänker på ett tal.\nKan du gissa vilket?", name);

  return 0;
}


int print_success(char *name, int guesses, int answer){
  printf("Bingo! Det tog %s %d många gissningar\n",
	 name,
	 guesses);
  
  printf("att komma fram till %d.\n", answer);

  return 0;
}
