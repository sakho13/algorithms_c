#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_GAKUSEI 2000
#define MAX_KAMOKU 400

struct SEISEKI{
  struct SEISEKI *Link_Student;
  struct SEISEKI *Link_Subject;
  struct GAKUSEI *gakusei;
  struct KAMOKU *kamoku;
  short seiseki;
};

int kamoku_num=0, gakusei_num=0;

struct GAKUSEI{
  struct SEISEKI *Link_Student;
  char *name;
} gakusei[MAX_GAKUSEI];

struct KAMOKU{
  struct SEISEKI *Link_Subject;
  char *name;
} kamoku[MAX_KAMOKU];

void initialize()
{
    int i;

    for(i = 0; i < gakusei_num; i++)
        gakusei[i].Link_Student = NULL;
    for(i = 0; i < kamoku_num; i++)
        kamoku[i].Link_Subject = NULL;
}

void add(int x, int y, short a){
  struct SEISEKI *p;
  if ((p = malloc(sizeof(struct SEISEKI))) == NULL) {
    printf("メモリが足りません");
  }
  p->Link_Student = gakusei[x].Link_Student;
  gakusei[x].Link_Student = p;
  p->Link_Subject = kamoku[y].Link_Subject;
  kamoku[y].Link_Subject = p;
  p->gakusei = &gakusei[x];
  p->kamoku = &kamoku[y];
  p->seiseki = a;
}

short get_seiseki(int x, int y){
  struct SEISEKI *p;
  for (p = gakusei[x].Link_Student; p != NULL; p = p->Link_Student) {
    if (p->kamoku == &kamoku[y]) {
      return (p->seiseki);
    }
  }
  return -1;
}

void print_gakusei(int x){
  struct SEISEKI *p;

  for (p = kamoku[x].Link_Subject; p != NULL; p = p->Link_Subject) {
    printf("%s %d\n", p->gakusei->name, p->seiseki);
  }
}

void ACT_add_subject(){
  if (kamoku_num < MAX_KAMOKU) {
    char *in;
    in = (char *)malloc(20*sizeof(char));
    printf("追加したい教科を入力\n> ");
    scanf("%s", in);
    kamoku[kamoku_num].name = in;
    kamoku_num++;
    printf("追加しました。\n\n");
    printf("%s\n", kamoku_num[0].name);
  }else{
    printf("追加できる上限を超えています。\n");
  }
}

void ACT_add_student(){
  if (gakusei_num < MAX_GAKUSEI) {
    char *in;
    in = (char *)malloc(20*sizeof(char));
    printf("追加したい学生の名前を入力\n> ");
    scanf("%s", in);
    gakusei[gakusei_num].name = in;
    gakusei_num++;
    printf("追加しました。\n\n");
  }else{
    printf("追加できる上限を超えています。\n");
  }
}

void ACT_view_subject(){
  printf("\t科目\t\n");
  for (int i=0; i<kamoku_num; i++) {
    printf("\t%s\t\n", kamoku[kamoku_num].name);
  }
  printf("\n\n");
}
// puts("Debugging");


int main(int argc, char const *argv[]) {
  int act;

  system("cls");

  while(1){
    printf("[操作の選択]\n");
    printf(" 0: 科目 の追加\n");
    printf(" 1: 学生 の追加\n");
    printf(" 2: 追加されている 科目 を表示\n");
    printf(" 3: 直近に追加した 科目 の削除\n");
    printf(" 4: 直近に追加した 学生 の削除\n");

    printf("> ");
    scanf("%d", &act);

    switch (act) {
      case 0:
        system("cls");
        ACT_add_subject();
        break;

      case 1:
        ACT_add_student();
        break;

      case 2:
        ACT_view_subject();
        break;

      case 3:
        break;

      case 4:
        break;

      case 5:
        break;

      default:
        break;
        break;
    }
  }

  return 0;
}
