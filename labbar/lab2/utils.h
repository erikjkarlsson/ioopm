#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int ask_question_int(char *question);
bool is_number(char *str);

int read_string(char *buf, int buf_siz);
char *ask_question_string(char *question, char *buf, int buf_siz);


int ask_question_int(char *question){
  int result = 0;
  int conversions = 0;
  do{
      printf("%s\n", question);
      conversions = scanf("%d", &result);
      int c;
      do{
          c = getchar();
        }
      while (c != '\n');
      putchar('\n');
    }
  while (conversions < 1);
  return result;
}

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

char *ask_question_string(char *question, char *buf, int buf_siz){
  // Stores the length if the string
  int size;
  do{
    printf("%s", question);
    size = read_string(buf, buf_siz);
    // Repeat read if input is nothing i.e size = 0
  } while (size == 0);
  
  return 0;
}

bool is_number(char *str)
{
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



#endif
