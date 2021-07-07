#include <stdio.h>
#include <stdlib.h>

#define N 7

void addQue(int a);

typedef struct QUE {
  struct QUE *next;
  int point;
}que;


que *root;

// 頂点をキューに追加
void addQue(int a){
  que *p;
  for (p = root; 1; p = p->next) {
    if (p->next == NULL) {
      que *ab = (que *)malloc(sizeof(que));
      p->next = ab;
      p->next->point = a;
      p->next->next = NULL;
      return;
    }
  }
  return;
}

// キューの先頭を見る
que* viewQue(){
  que *ret;
  que *a;
  ret = root->next;
  a = ret->next;
  root->next = a;
  return ret;
}


int main() {
  root = (que *)malloc(sizeof(que));
  addQue(1);
  // Gを有向グラフだとする
  int G[N+1][N+1] = {
    {0},
    //  1, 2, 3, 4, 5, 6, 7
    {0, 0, 1, 1, 0, 0, 0, 0},  // v1
    {0, 0, 0, 0, 1, 1, 0, 0},  // v2
    {0, 0, 0, 0, 1, 0, 1, 0},  // v3
    {0, 0, 0, 0, 0, 0, 0, 0},  // v4
    {0, 0, 0, 0, 0, 0, 0, 0},  // v5
    {0, 0, 0, 0, 0, 0, 0, 1},  // v6
    {0, 0, 0, 0, 0, 0, 0, 0},  // v7
  };

  while (root->next != NULL) {
    int p = viewQue()->point;
    printf("%d=>", p);
    for (int i = 1; i <= N; i++) {
      if (G[p][i] == 1 && G[0][i] == 0) {
        addQue(i);
        // 0行目をフラグとして使う
        G[0][i] = 1;
      }
    }
  }
  printf("Finish!!\n");

  return 0;
}
