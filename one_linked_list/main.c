#include<stdio.h>
#include<stdlib.h>

/*********************************************************/
typedef struct CELL {
  struct CELL *next;
  int data;
} cell_s;
/*********************************************************/


/*********************************************************/
cell_s *list;
/*********************************************************/


/*********************************************************/
//表示
void viewLIST() {
  cell_s *p;
  int i=0;

  system("cls");
  printf("――――――***――――――\n");
  printf(" 順番\t| 値\n");
  for (p = list; p != NULL; p = p->next) {
    if (i==0) {
      i++;
      continue;
    }
    printf("%d\t| ", i);
    printf("%d\n", p->data);
    i++;
  }
  printf("――――――***――――――\n\n");
}

//セルの追加：末尾
void addCELLn(int b) {
  cell_s *p, *next, *prev;
  p = (cell_s *)malloc(sizeof(cell_s));
  p->data = b;
  p->next = NULL;
  if (list->next == NULL) {
    list->next = p;
  }else{
    for (next = list->next; next != NULL; next = next->next) {
      prev = next;
    }
    prev->next = p;
  }
  printf("追加しました。\n\n\n");
}

//セルの追加：任意
void insertCELL(int b, int n) {
  cell_s *p, *next, *prev;
  int i=0;
  p = (cell_s *)malloc(sizeof(cell_s));
  for (next = list->next; next != NULL; next = next->next) {
    i++;
    prev = next;
    if (i==n-1) {
      p->data = b;
      p->next = next->next;
      prev->next = p;
    }
  }
  printf("追加しました。\n\n\n");
}

//セルの削除
void delCELL(int n) {
  cell_s *p, *next, *prev;
  int i=0;
  p = (cell_s *)malloc(sizeof(cell_s));
  for (next = list->next; next != NULL; next = next->next) {
    i++;
    prev = next;
    if (i==n-1) {
      prev->next = next->next->next;
    }
  }
  printf("削除しました。\n\n\n");
}

//セルの検索
void searchCELL(int point){
  cell_s *next;
  int count=1;
  printf("\n\n\n");
  printf(" 順番\t| 値\n");
  for (next = list->next; next != NULL; next = next->next) {
    if (next->data == point) {
      printf("%d\t|", count);
      printf("%d\n", next->data);
      ++count;
    }else{
      ++count;
    }
  }
  printf("\n\n");
}
/*********************************************************/


/*********************************************************/
int main() {
  int act, x, pla;

  list = (cell_s *)malloc(sizeof(cell_s));
  list->data = 0;
  list->next = NULL;

  system("cls");

  while (1) {
    printf(" [操作の選択]\n");
    printf(" 0: リストを見る\n");
    printf(" 1: 末尾に値を挿入\n");
    printf(" 2: 場所を指定して値を挿入 (ある程度の要素が必要です。)\n");
    printf(" 3: 指定した値をリストから削除\n");
    printf(" 4: 指定した値をサーチ\n");
    printf("\n> ");
    scanf("%d", &act);

    switch (act) {
      case 0:
        viewLIST();
        break;

      case 1:
        system("cls");
        viewLIST();
        printf("\n末尾に追加します。\n");
        printf("挿入したい値を教えて下さい。\n\n> ");
        scanf("%d", &x);
        addCELLn(x);
        break;

      case 2:
        system("cls");
        viewLIST();
        printf("\n追加したい値の場所を指定してください。\n\n> ");
        scanf("%d", &pla);
        printf("挿入したい値を教えて下さい。\n\n> ");
        scanf("%d", &x);
        insertCELL(x, pla);
        break;

      case 3:
        system("cls");
        viewLIST();
        printf("\n削除したい値の場所を指定してください。\n\n> ");
        scanf("%d", &pla);
        delCELL(pla);
        break;

      case 4:
        system("cls");
        viewLIST();
        printf("\nサーチしたい値を入力。\n\n> ");
        scanf("%d", &x);
        searchCELL(x);
        break;

      default:
        break;
    }

  }

  return 0;
}
/*********************************************************/
