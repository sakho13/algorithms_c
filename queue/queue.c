#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef long ELEM;

#define QUEUE_SIZE 100


/*************************************************/


ELEM queue[QUEUE_SIZE];
int front, rear;

#define next(a) (((a) + 1) % QUEUE_SIZE)

void error(char *s){
  fprintf(stderr, s);
  exit(1);
}

void init() {
  front = rear = 0;
}

void enqueue(ELEM x) {
  if (next(rear) == front) {
    error("待ち行列がいっぱいなのです！\n\n\n");
  }
  queue[rear] = x;
  rear = next(rear);
  printf("「えんきゅー　完。」\n\n\n");
}

ELEM dequeue(){
  ELEM x;
  if (front == rear) {
    error("待ち行列がからっぽなのです！\n\n\n");
  }
  x = queue[front];
  front = next(front);
  return x;
}

int empty(){
  return front == rear;
}


/***********************************************/


int main() {
  int op;             //操作の選択用
  int element;

  while (1) {
    printf("　[操作を選択]\n");
    printf("　0: えんきゅー\n");
    printf("　1: できゅー\n");
    printf("　2: からっぽ？\n");
    printf("\n：");
    scanf("%d", &op);
    system("cls");
    if (1) {
      switch (op) {
        case 0: //要素の追加
          printf("入れたい要素(実数)：");
          scanf("%d", &element);

          enqueue(element);

          printf("\n「追加完了」\n");
          break;
        case 1: //できゅー
          printf("先頭から要素を取り出す！\n\n");
          printf("取り出した要素：%d\n", dequeue());
          break;
        case 2:
          if (empty() == 1) {
            printf("いえっす！\n\n\n");
          }else{
            printf("のんのん\n\n\n");
          }
        default:
          break;
      }
    }
  }
  return 0;
}
