#include<stdio.h>
#include<stdlib.h>


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
void ACT_add_NODE();                  //ノードの追加
void ACT_interface();                 //インターフェース
void ACT_step();                      //ノードの移動(前進)
void ACT_back();                      //ノードの移動(後退)
void ACT_reset_NODE(node *target);    //ノードの初期化
/***********************************************************/


/***********************************************************/
//グローバル：全体の構造宣言
node *tree, *current_point;
/***********************************************************/


/***********************************************************/
int main() {
  tree = (node *)malloc(sizeof(node));
  current_point = tree;
  tree->parent = NULL;
  tree->branch_0 = NULL;
  tree->branch_1 = NULL;
  current_point->label = 0;
  puts("debugging");

  while (1) {
    ACT_interface();
  }

  return 0;
}
/***********************************************************/


/***********************************************************/
//ノードの新規作成
void ACT_add_NODE(int act_com){
  if (act_com == 1 || act_com == 2) {
    node *new_node;
    new_node = (node *)malloc(sizeof(node));
    int new_label;
    ACT_reset_NODE(new_node);
    printf("ラベルの指定\n>");
    scanf("%d", &new_label);
    new_node->label = new_label;
    new_node->parent = current_point;
    switch (act_com) {
      case 1:
      current_point->branch_0 = new_node;
      break;

      case 2:
      current_point->branch_1 = new_node;
      break;

      default:
      break;
    }
  }
  return;
}

//現在のノード：インターフェース
void ACT_interface(){
  system("cls");
  int act;
  printf("\n\n【現在のノード】\n");
  printf("\tラベル : %d\n", current_point->label);
  printf("\t枝[1]  : %d\n", current_point->branch_0);
  printf("\t枝[2]  : %d\n", current_point->branch_1);
  printf("\t親     : %d\n\n", current_point->parent);
  printf("\n【操作】\n");
  printf("\t0: 戻る\n");
  printf("\t1: 枝[1]に進む\n");
  printf("\t2: 枝[2]に進む\n");
  printf("\t9: ノードの新規作成\n\n");
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
    case 9:
      printf("どの枝に追加しますか？(1 or 2)\n>");
      scanf("%d", &act);
      ACT_add_NODE(act);
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
/***********************************************************/
