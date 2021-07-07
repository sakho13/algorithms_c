#include<stdio.h>
#include<stdlib.h>

#define N 30

/***********************************************************/
//ノードのテンプレ
typedef struct NODE{
  int label;
  int depth;
  struct NODE *left;
  struct NODE *right;
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
  tree->left = NULL;
  tree->right = NULL;
  current_point->label = rand()%N;  // 初期値はランダム
  tree->depth = 0;  // 深さは0
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
//       current_point->left = new_node;
//       break;
//
//       case 2:
//       current_point->right = new_node;
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
  if ((node *)current_point->left) {
    printf("\t枝[1]  : %d->%d\n", current_point->left, current_point->left->label);
  }else{
    printf("\t枝[1]  : NULL\n");
  }
  if ((node *)current_point->right) {
    printf("\t枝[2]  : %d->%d\n", current_point->right, current_point->right->label);
  }else{
    printf("\t枝[2]  : NULL\n");
  }
  printf("\t親     : %d\n", current_point->parent);
  printf("\t深さ   : %d\n", current_point->depth);
  printf("\n\n【操作】\n");
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
      if (ACT_search(act) == 1) {
        puts("発見！");
      }else{
        puts("非発見");
      }
      break;
    case 10:
      current_point = tree;
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
      if (current_point->left != NULL) {
        current_point = current_point->left;
      }else{
        printf("行き先がありません。\n");
      }
      break;

    case 2:
      if (current_point->right != NULL) {
        current_point = current_point->right;
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
  target->left = NULL;
  target->right = NULL;
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
      p = &(*p)->left;
    }else{
      sta = p;
      p = &(*p)->right;
    }
  }
  if ((new = malloc(sizeof(node))) == NULL) {
    puts("「エラー」");
  }
  new->parent = *sta;
  new->left = NULL;
  new->right = NULL;
  new->label = key;
  new->depth = ((*sta)->depth) + 1;  //深さの加算
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
      p = p->left;
    }else{
      p = p->right;
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
  ACT_order(p->left);
  ACT_order(p->right);
}

//節の削除
int ACT_delete(int key){
  node **p, *x;
  p = &tree;
  while (*p != NULL) {
    if (key == (*p)->label) {   //ラベルと一致
      x = *p;
      if (x->left == NULL && x->right == NULL) { //葉の部分
        *p = NULL;
      }else if (x->left == NULL) {  //片方が葉
        *p = x->right;
      }else if (x->right == NULL) {  //片方が葉
        *p = x->left;
      }else{
        *p = deletemin(&x->right);
        (*p)->right = x->right;
        (*p)->left = x->left;
      }
      free(x);
      return 1;
    }else if(key < (*p)->label){    //一致しなかった場合
      p = &(*p)->left;
    }else{
      p = &(*p)->right;
    }
  }
  return 0;
}

node *deletemin(node **p){
  node *x;
  while ((*p)->left != NULL) {
    p = &(*p)->left;
  }
  x = *p;
  *p = (*p)->right;
  return x;
}

int ACT_check(){
}
/***********************************************************/
