#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#include <stdlib.h>
#include <time.h>

typedef union { 
  int   int_value;
  float float_value;
  char *string_value;
} answer_t;

typedef  bool (*check_func) (char*);
typedef  answer_t (*convert_func) (char*);
extern   char *strdup(const char *);
answer_t ask_question(char *question, check_func check, convert_func convert);
answer_t make_float(char *str);

bool not_empty(char *str);
bool is_number(char *str);
int  read_string(char *buf, int buf_siz);
int  ask_question_int(char *question);

int main(void){
  answer_t ans;
  
  ans = ask_question("I WILL ADD ONE TO THIS NUMBER:", (check_func) is_number, (convert_func) atoi);
  printf("ANSWER IS...%d\n\n", 1 + ans.int_value);

  return 0; 
}


/// String and Chars:

int read_string(char *buf, int buf_siz){
  int buf_cnt = 0;
  char c = ' ';
  while (1){
    // Check to prevent buffer overflows
    if (buf_cnt == (buf_siz - 1)){
      break;
      // Check to show that a buffer overflow has
      // occured.
    }else if (buf_cnt > (buf_siz - 1)){
      printf("ERROR: Buffer Overflow");
      return -1;  
    }else{
      // Get char
      c = getchar();
      if (c != '\n'){
	// Set char in array
	buf[buf_cnt] = c;
	// Count chars in buffer
	// Increment
	buf_cnt += 1;
      }else{
	break;
      }      
    }
  }
  // Mark end of the string 
  buf[buf_siz] = '\0';
  // Increment size to compensate for \0
  return (buf_cnt + 1);
}

bool not_empty(char *str){
  return strlen(str) > 0;
}

char *ask_question_string(char *question){
  return ask_question(question, not_empty, (convert_func) strdup).string_value;
}


/// Integers:

bool is_number(char *str){
  int index = 0;
  // Handle negative numbers
  if (str[0] == '-'){
    index = 1;
  }else if (str[0] == '\0'){
    // Empty string
    return false;
  }
  // Returns false if any character in str is not an element of {0,...,9}
  for (; index < strlen(str); index++){
    if (!isdigit(str[index])) return false;
  }
  return true;
}

int ask_question_int(char *question){
  answer_t answer = ask_question(question, is_number, (convert_func) atoi);
  return answer.int_value;
}


/// Floating Point:

double ask_question_float(char *question){
  return ask_question(question, is_float, make_float).float_value;
}

answer_t make_float(char *str){
  return (answer_t) { .float_value = atof(str) };
}


/// General:

answer_t ask_question(char *question, check_func check, convert_func convert){
  char buffer[255];
  do {
    printf(question);
    read_string(buffer, 255);

    if (check(buffer)) break;
    
  }while (1);

  return convert(buffer);
}
