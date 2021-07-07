#include<stdio.h>
#include<stdlib.h>

#define N 30

/***********************************************************/
//ノードのテンプレ
typedef struct NODE{
  int label;
  struct NODE *branch_0;
  struct NODE *branch_1;
  struct NODE *parent;
}node;
/***********************************************************/

/***********************************************************/
// void ACT_add_NODE();                  //ノードの追加
void ACT_interface();                 //インターフェース
void ACT_step();                      //ノードの移動(前進)
void ACT_back();                      //ノードの移動(後退)
void ACT_reset_NODE(node *target);    //ノードの初期化
void ACT_search_input(int key);       //適正位置に挿入
int ACT_search(int key);              //探索
void ACT_order(node *p);
int ACT_delete(int key);              //データの削除
node *deletemin(node **p);
/***********************************************************/


/***********************************************************/
//グローバル：全体の構造宣言
node *tree, *current_point;
int a[N], rootLabel;
/***********************************************************/


/***********************************************************/
int main() {
  tree = (node *)malloc(sizeof(node));
  current_point = tree;
  tree->parent = NULL;
  tree->branch_0 = NULL;
  tree->branch_1 = NULL;
  current_point->label = rand()%N;
  printf("ルートのラベル:%d", current_point->label);
  for (int count = 0; count < N; count++) {
    a[count] = rand() % N;
    ACT_search_input(a[count]);
  }
  // puts("debugging");
  while (1) {
    ACT_interface();
  }
  return 0;
}
/***********************************************************/


/***********************************************************/
//ノードの新規作成
// void ACT_add_NODE(int act_com, int input_label){
//   if (act_com == 1 || act_com == 2) {
//     node *new_node;
//     new_node = (node *)malloc(sizeof(node));
//     int new_label;
//     ACT_reset_NODE(new_node);
//     new_node->label = input_label;
//     new_node->parent = current_point;
//     switch (act_com) {
//       case 1:
//       current_point->branch_0 = new_node;
//       break;
//
//       case 2:
//       current_point->branch_1 = new_node;
//       break;
//
//       default:
//       break;
//     }
//   }
//   return;
// }

//現在のノード：インターフェース
void ACT_interface(){
  // system("cls");
  int act;
  printf("\n\n【現在のノード】\n");
  printf("\tラベル : %d\n", current_point->label);
  printf("\t枝[1]  : %d->%d\n", current_point->branch_0, current_point->branch_0->label);
  printf("\t枝[2]  : %d->%d\n", current_point->branch_1, current_point->branch_1->label);
  printf("\t親     : %d\n\n", current_point->parent);
  printf("\n【操作】\n");
  printf("\t0: 戻る\n");
  printf("\t1: 枝[1]に進む\n");
  printf("\t2: 枝[2]に進む\n");
  printf("\t3: 行きがけ順でラベルの表示\n");
  printf("\t6: 要素の削除\n");
  printf("\t9: 要素の探索\n");
  printf("\n");
  printf("InputCommand>");
  scanf("%d", &act);
  switch (act){
    case 0:
      ACT_back();
      break;
    case 1:
      ACT_step(act);
      break;
    case 2:
      ACT_step(act);
      break;
    case 3:
      ACT_order(tree);
      break;
    case 6:
      printf("ターゲット>");
      scanf("%d", &act);
      if (ACT_delete(act)) {
        puts("削除！");
      }else{
        puts("削除対象がありません。");
      }
      break;
    case 9:
      printf("ターゲット>");
      scanf("%d", &act);
      if (ACT_search(act)) {
        puts("発見！");
      }else{
        puts("非発見");
      }
      break;
    default:
      break;
  }
  return;
}

//ノードを移動：進む
void ACT_step(int way){
  switch (way) {
    case 1:
      if (current_point->branch_0 != NULL) {
        current_point = current_point->branch_0;
      }else{
        printf("行き先がありません。\n");
      }
      break;

    case 2:
      if (current_point->branch_1 != NULL) {
        current_point = current_point->branch_1;
      }else{
        printf("行き先がありません。\n");
      }
      break;

    default:
      puts("[ERROR]");
      break;
  }
  return;
}

//ノードを移動：戻る
void ACT_back(){
  if (current_point != tree) {
    current_point = current_point->parent;
  }
}

//ノードのリセット
void ACT_reset_NODE(node *target){
  target->branch_0 = NULL;
  target->branch_1 = NULL;
  return;
}

//データの挿入
void ACT_search_input(int key){
  node **p, *new, **sta;

  p = &tree;
  while (*p != NULL) {
    if (key == (*p)->label) {
      return;
    }else if(key < (*p)->label){
      sta = p;
      p = &(*p)->branch_0;
    }else{
      sta = p;
      p = &(*p)->branch_1;
    }
  }
  if ((new = malloc(sizeof(node))) == NULL) {
    puts("「エラー」");
  }
  new->parent = *sta;
  new->branch_0 = NULL;
  new->branch_1 = NULL;
  new->label = key;
  *p = new;
  return;
}

//探索
int ACT_search(int key){
  node *p;

  p = tree;
  while (p != NULL) {
    if (key == p->label) {
      return 1;
    }else if(key < p->label){
      p = p->branch_0;
    }else{
      p = p->branch_1;
    }
  }
  return 0;
}

//行きがけ順
void ACT_order(node *p){
  if (p == NULL) {
    return;
  }
  printf("節%dに立ち寄りました。\n", p->label);
  ACT_order(p->branch_0);
  ACT_order(p->branch_1);
}

//節の削除
int ACT_delete(int key){
  node **p, *x;
  p = &tree;
  while (*p != NULL) {
    if (key == (*p)->label) {   //ラベルと一致
      x = *p;
      if (x->branch_0 == NULL && x->branch_1 == NULL) { //葉の部分
        *p = NULL;
      }else if (x->branch_0 == NULL) {  //片方が葉
        *p = x->branch_1;
      }else if (x->branch_1 == NULL) {  //片方が葉
        *p = x->branch_0;
      }else{
        *p = deletemin(&x->branch_1);
        (*p)->branch_1 = x->branch_1;
        (*p)->branch_0 = x->branch_0;
      }
      free(x);
      return 1;

    }else if(key < (*p)->label){    //一致しなかった場合
      p = &(*p)->branch_0;
    }else{
      p = &(*p)->branch_1;
    }
  }
  return 0;
}

node *deletemin(node **p){
  node *x;
  while ((*p)->branch_0 != NULL) {
    p = &(*p)->branch_0;
  }
  x = *p;
  *p = (*p)->branch_1;
  return x;
}
/***********************************************************/
