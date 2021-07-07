#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENT 100
#define MAX_SUBJECT 100

/*********************************************/
void ACT_Hello();
void ACT_which_view();
void ACT_view_student();
void ACT_view_subject();
void ACT_action_interface();
void ACT_action_select();
void ACT_select_int();
int ACT_select_act();
//諸々追加関数
void ACT_add_subject();
void ACT_add_student();
void ACT_add_seiseki();
//成績表示関数
void ACT_view_seiseki_student();
void ACT_view_seiseki_subject();
/*********************************************/



/*********************************************/
int fill_subject, fill_student;
/*********************************************/



/*********************************************/
typedef struct SEISEKI_CELL{
  struct SEISEKI_CELL *student_link;
  struct SEISEKI_CELL *subject_link;
  struct STUDENT *student;
  struct SUBJECT *subject;
  char *subject_name;
  char *student_name;
  short seiseki;
} seiseki_cell;

struct STUDENT{
  struct SEISEKI_CELL *student_link;
  char *name;
} student[MAX_STUDENT];

struct SUBJECT{
  struct SEISEKI_CELL *subject_link;
  char *name;
} subject[MAX_SUBJECT];
/*********************************************/



/*********************************************/
int main() {
  fill_subject = 0;
  fill_student = 0;
  system("cls");
  ACT_Hello();

  while (1) {
    ACT_action_select();
  }

  return 0;
}
/*********************************************/



/*********************************************/
void ACT_Hello(){
  printf("これは「多重リスト」を実装するためのプログラムです。\n\n\n");
  return;
}

void ACT_which_view(){
  int n;
  printf("\n\n「表示」\n");
  puts("0 :生徒　一覧");
  puts("1 :教科　一覧");
  puts("2 :成績(生徒)　一覧");
  puts("3 :成績(教科)　一覧");
  printf("\n>");
  scanf("%d", &n);
  switch (n) {
    case 0:
      ACT_view_student();
      break;

    case 1:
      ACT_view_subject();
      break;

    case 2:
      ACT_view_seiseki_student();
      break;

    case 3:
      ACT_view_seiseki_subject();
      break;

    default:
      return;
      break;
  }
}

void ACT_view_student(){
  printf("順番\t: 生徒名\n");
  for (int count = 0; count < MAX_STUDENT; count++) {
    if (student[count].name == NULL) {
      printf("\n\n\n");
      return;
    }
    printf("%d\t:", count);
    printf("%s\n", student[count].name);
  }
}
// puts("Debugging!!");

void ACT_view_subject(){
  printf("順番\t: 教科名\n");
  for (int count = 0; count < MAX_SUBJECT; count++) {
    if (subject[count].name == NULL) {
      printf("\n\n\n");
      return;
    }
    printf("%d\t:", count);
    printf("%s\n", subject[count].name);
  }
}

void ACT_action_interface(){
  puts("1  :表示");
  puts("2  :教科　の　追加");
  puts("3  :生徒　の　追加");
  puts("0  :成績　の　追加");
}


int ACT_action_input(){
  int f_act;
  printf("\n>");
  scanf("%d", &f_act);
  return f_act;
}


void ACT_action_select(){
  ACT_action_interface();
  int act = ACT_action_input();
  switch (act) {
    case 1:
      ACT_which_view();
      break;

    case 2:
      ACT_add_subject();
      break;

    case 3:
      ACT_add_student();
      break;

    case 0:
      if (fill_student == 0 || fill_subject == 0) {
        printf("生徒か教科が入力されていません。\n入力してください。\n");
        break;
      }else{
        ACT_add_seiseki();
        break;
      }

    default:
      break;
      break;
  }
}


void ACT_add_subject(){
  char *new_subject_name;
  new_subject_name = (char *)malloc(32 * sizeof(char));
  puts("教科の追加を行います。");
  printf(">");
  scanf("%s", new_subject_name);
  subject[fill_subject].name = new_subject_name;
  fill_subject++;
  printf("教科「%s」を追加しました。\n\n\n", new_subject_name);
}


void ACT_add_student(){
  char *new_student_name;
  new_student_name = (char *)malloc(32 * sizeof(char));
  puts("生徒の追加を行います。");
  printf(">");
  scanf("%s", new_student_name);
  student[fill_student].name = new_student_name;
  fill_student++;
  printf("生徒「%s」を追加しました。\n\n\n", new_student_name);
}


void ACT_add_seiseki(){
  int def_subject, def_student, score;
  system("cls");
  ACT_view_subject();
  printf("「教科」の選択(数字)\n\n>");
  scanf("%d", &def_subject);
  ACT_view_student();
  printf("「生徒」の選択(数字)\n\n>");
  scanf("%d", &def_student);
  if (def_subject <= fill_subject && def_student <= fill_student) {
    seiseki_cell *new, *point_student, *poin_subject;
    new = (seiseki_cell *)malloc(sizeof(seiseki_cell));
    new->subject_name = subject[def_subject].name;
    new->student_name = student[def_student].name;
    new->student_link = student[def_student].student_link;
    student[def_student].student_link = new;
  	new->subject_link = subject[def_subject].subject_link;
    subject[def_subject].subject_link = new;
    new->student = &student[def_student];
  	new->subject = &subject[def_subject];
    printf("「成績」の入力(数字)\n\n>");
    scanf("%d", &score);
    new->seiseki = score;
  }else{
    puts("どちらかが範囲外の数字です。");
  }
  return;
}

void ACT_view_seiseki_student(){
  int get_student;
  seiseki_cell *point;
  system("cls");
  ACT_view_student();
  printf("閲覧したい生徒(数字)の成績\n\n>");
  scanf("%d", &get_student);
  printf(" 教科名\t| 成績\n");
  for (point = student[get_student].student_link; point != NULL; point = point->student_link) {
    printf("%s\t| %d\n", point->subject_name, point->seiseki);
  }
}

void ACT_view_seiseki_subject(){
  int get_subject;
  seiseki_cell *point;
  system("cls");
  ACT_view_subject();
  printf("閲覧したい教科(数字)の成績\n\n>");
  scanf("%d", &get_subject);
  printf(" 生徒名\t| 成績\n");
  for (point = subject[get_subject].subject_link; point != NULL; point = point->subject_link) {
    printf("%s\t| %d\n", point->student_name, point->seiseki);
  }
}
/*********************************************/
