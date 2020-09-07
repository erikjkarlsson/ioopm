#ifndef __UTILS_H__
#define __UTILS_H__

typedef union { 
  int   int_value;
  float float_value;
  char *string_value;
} answer_t;

typedef  bool (*check_func) (char*);
typedef  answer_t (*convert_func) (char*);
extern   char *strdup(const char *);

int seed_random(void);
int random_number(int range);
int read_string(char *buf, int buf_siz);
void clear_buffer(char *buffer);

bool not_empty(char *str);
bool is_number(char *str);

answer_t make_float(char *str);
answer_t ask_question(char *question, check_func check, convert_func convert);

char  *ask_question_string(char *question);
double ask_question_float(char *question);
int    ask_question_int_safe(char *question, int buffer_size);
int    ask_question_int(char *question);

#endif
