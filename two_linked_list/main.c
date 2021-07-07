#include<stdio.h>
#include<stdlib.h>

/****************************************************/
typedef struct CELL {
  struct CELL *prev;
  struct CELL *next;
  int data;
} cell_s;
/****************************************************/


/****************************************************/
cell_s *list;
int list_num = 1;
/****************************************************/


/****************************************************/
/** 表示させる関数 ***/
void ACT_view(){
  cell_s *p;
  int c=1;

  system("cls");
  printf("――――――***――――――\n");
  printf(" 順番\t| 値\n");
  for (p = list->next; p != list; p = p->next) {
    printf("%d\t| ", c);
    printf("%d\n", p->data);
    c++;
  }
  printf("――――――***――――――\n");
}

/**先頭**/
void ACT_first(){
  system("cls");
  ACT_view();
}


/** 末尾追加 **/
void ACT_add(int num){
  cell_s *p, *l_prev, *l_next;

  p = (cell_s*)malloc(sizeof(cell_s));
  p->data = num;
  if (list->next == list) {
    list->next = p;
    list->prev = p;
    p->next=list;
    p->prev=list;
  }else{
    for (l_next = list->next; l_next != list; l_next = l_next->next) {
      l_prev = l_next;
    }
    l_prev->next = p;
    p->prev = l_prev;
    p->next = list;
    // puts("Debugging");
  }
  ACT_first();
  printf("追加しました。\n\n\n");
}

/** 場所指定追加 **/
void ACT_insert(int num, int pla){
  int i=0;
  cell_s *current_point, *loop_prev, *loop_next;

  current_point = (cell_s*)malloc(sizeof(cell_s));

  current_point->data = num;

  if (list->next == list) {
    list->next = current_point;
    list->prev = current_point;
    current_point->next=list;
    current_point->prev=list;
  }else{
    for (loop_next = list->next; loop_next != list; loop_next = loop_next->next) {
      if (i+1 == pla) {
        current_point->prev = loop_prev;
        current_point->next = loop_next;
        loop_prev->next = current_point;
        loop_next->prev = current_point;
        ACT_first();
        printf("追加しました。\n\n\n");
        ++i;
      }else if(loop_next == list){
        current_point->prev = loop_prev;
        current_point->next = list;
      }else{
        ++i;
        loop_prev = loop_next;
      }
    }
  }
}

/** 値選択->削除 **/
void ACT_delete(int data){
  cell_s *prev_point, *next_point;

  for (next_point = list->next; next_point != list; next_point = next_point->next) {
    puts("Debugging");
    if (next_point->data == data) {
      prev_point->next = next_point->next;
      next_point->prev = prev_point;
      printf("対象を削除しました。\n");
    }else{
      prev_point = next_point;
    }
  }
}

/**検索**/
void ACT_search(int key){
  cell_s *point;

  for (point = list->next; point != list; point = point->next) {
    if (point->data == key) {
      puts("値を発見しました。");
      return;
    }
  }
}
/****************************************************/


/****************************************************/
int main() {
  int act, x, pla=1;

  list = (cell_s *)malloc(sizeof(cell_s));
  list->data = 0;
  list->prev = list;
  list->next = list;

  ACT_first();

  while (1) {
    printf(" [操作の選択]\n");
    printf(" 0: リストを見る\n");
    printf(" 1: 末尾に値を挿入\n");
    printf(" 2: 場所を指定して値を挿入 (ある程度の要素が必要です。)\n");
    printf(" 3: 指定した値をリストから削除\n");
    printf(" 4: 指定した値の検索\n");
    printf("\n> ");
    scanf("%d", &act);

    switch (act) {
      case 0:
        ACT_view();
        break;

      case 1:
        system("cls");
        ACT_view();
        printf("挿入したい値を教えて下さい。\n\n> ");
        scanf("%d", &x);
        ACT_add(x);
        break;

      case 2:
        system("cls");
        ACT_view();
        printf("挿入したい値を教えて下さい。\n\n> ");
        scanf("%d", &x);
        printf("挿入したい場所を教えて下さい。\n\n> ");
        scanf("%d", &pla);
        ACT_insert(x, pla);
        break;

      case 3:
        system("cls");
        ACT_view();
        printf("削除したい値を教えて下さい。\n\n> ");
        scanf("%d", &x);
        ACT_delete(x);

        break;

      case 4:
        system("cls");
        ACT_view();
        printf("検索したい値を教えて下さい。\n\n> ");
        scanf("%d", &x);
        ACT_search(x);

        break;

      default:
      break;
      break;
    }
  }

  return 0;
}
/****************************************************/
