#include <stdio.h>

#define BUCKET_SIZE 100

typedef struct CELL {
  char value;
  int DEL_flag;
} cell;

cell bucket[BUCKET_SIZE];

int ACT_hash(char data, int k){
  int d = (int)data;
  int out;

  return out;
}

int ACT_init(){
  for (int i=0; i<BUCKET_SIZE; i++) {
    bucket[i].DEL_flag = 0;
  }
  return 1;
}

void ACT_insert(char *data){
  int count = 0;
}


int main() {
  int key;
  char input[BUCKET_SIZE];
  printf(">");
  scanf("%s", input);

  if (ACT_init() != 1) {
    return 0;
  }
  puts("Debug");

  for (int i=0; i<BUCKET_SIZE; i++) {
    key = ACT_hash(input[i].value, 0);
  }

  return 0;
}
