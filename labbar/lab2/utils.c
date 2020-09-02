#include <stdio.h>

int read_string(char *buf, int buf_siz);
int ask_question_int(char *question);

int main(void){

  int buf_siz = 255;
  int read = 0;
  char buf[buf_siz];

  puts("Läs in en sträng:");
  read = read_string(buf, buf_siz);
  printf("'%s' (%d tecken)\n", buf, read);

  puts("Läs in en sträng till:");
  read = read_string(buf, buf_siz);
  printf("'%s' (%d tecken)\n", buf, read);

  return 0;

}


int ask_question_int(char *question)
{

  int result = 0;
  int conversions = 0;
  do
    {
      printf("%s\n", question);
      conversions = scanf("%d", &result);
      int c;
      do
        {
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
