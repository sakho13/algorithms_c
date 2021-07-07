#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

/****************************************/

void insertEle(int e);
void show();
int isEmpty();
void deleteEle(int key);


/****************************************/


// 入れたい要素のパラメータ
typedef struct{
  char label[256];  // 貼られているラベル
  int value;        // ラベルに相当する値
}Item;

int fill = 0;     //どこまで埋まっているか


/****************************************/

Item bag[SIZE];     //バッグの作成


int main() {
  int op;             //操作の選択用
  int element;

  system("cls");
  while (1) {
    printf("　[操作を選択]\n");
    printf("　0: 要素の追加\n");
    printf("　1: ラベルの指定\n");
    printf("　2: Bagを見る\n");
    printf("　3: Bagのサイズ(要素数)を知る\n");
    printf("　4: からっぽ？\n");
    printf("　5: とりだし\n");
    printf("　6: 要素の削除\n");
    printf("\n：");
    scanf("%d", &op);
    system("cls");
    if (1) {
      switch (op) {
        case 0: //要素の追加
          if (fill < 50) {
            printf("入れたい要素(自然数)：");
            scanf("%d", &element);

            insertEle(element);

            printf("\n「追加完了」\n");
            break;
          }else{
            printf("バッグの容量を超えている可能性があります！\n");
            printf("要素を追加できませんでした。\n");

            break;
          }
        case 1: //ラベルの指定
          printf("ラベルを貼りたい要素の番号\n");
          show();
          printf("\n\n：");
          scanf("%d", &op);
          printf("ラベル名(BAG%d)：", op);
          scanf("%s", &bag[op-1].label);
          break;
        case 2: //バッグの中身を見る
          show();
          printf("\n\n");
          break;
        case 3: //サイズ
          printf("　サイズ：%d\n\n\n\n", fill);
          break;
        case 4:
          if (isEmpty() == 1) {
            printf("\n\nいえっす！\n\n\n");
          }else{
            printf("\n\nのんのん\n\n\n");
          }
          break;
        case 5:
          printf("取り出したい要素番号は？\n");
          show();
          printf("\n\n：");
          scanf("%d", &op);
          printf("\n取り出したデータ：%d\n\n\n", bag[op-1].value);
          break;
        case 6:
        printf("削除したい要素の番号\n");
        show();
        printf("\n\n：");
        scanf("%d", &op);
        deleteEle(op);
          break;
        default:
          break;
          break;
      }
    }
  }
  return 0;
}



/****************************************/


void insertEle(int e){
    bag[fill].value = e;
    fill++;
}

int isEmpty(){
  return fill == 0;
}

void show(){
  for (int i = 0; i < fill; i++) {
    printf("　・BAG %d：%d：%s\n", i+1, bag[i].value, bag[i].label);
  }
}

void deleteEle(int key){
  for (int i = key-1; i < fill; i++) {
    bag[key-1] = bag[key];
  }
  bag[fill-1].value = 0;
  // bag[fill-1].label = "";
  fill--;
  printf("\n「削除完了」\n");
}
