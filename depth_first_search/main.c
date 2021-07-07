#include <stdio.h>

#define ROW 9
#define COLUMN 4

int Graph[ROW][COLUMN] = {
  {0},          // 0行目は無駄になってしまう
  {2, 6, 0},    // v1
  {1, 3, 4, 0}, // v2
  {2, 5, 0},    // v3
  {2, 5, 6, 0}, // v4
  {3, 4, 7, 0}, // v5
  {1, 4, 7, 0}, // v6
  {5, 6, 8, 0}, // v7
  {7, 0},       // v8
};

int flag[ROW];

// 初期化関数
void init(){
  for (int i = 0; i < ROW; i++) {
    flag[i] = 0;
  }
}

void dfs(int start, int target){
  int i;
  
  // 訪問フラグを立てる
  flag[start] = 1;
  printf("%d->", start);
  // ターゲットと一致したら終了
  if (start == target) {
    printf("Finish.\n");
    return;
  }
  // 隣接している頂点を調べ上げる
  for (i = 0; Graph[start][i] != 0; i++) {
    // 既に訪問しているかの判定
    if (flag[Graph[start][i]] == 0) {
      // ここで再帰を用いる
      dfs(Graph[start][i], target);
    }
  }
}

int main() {
  init();     // フラグの初期化
  dfs(1, 8);  // 探索開始
  return 0;
}
