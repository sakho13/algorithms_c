#include <stdio.h>
#include <stdlib.h>

#define N 7   // 頂点数

int Graph[N+1][N+1] = {
  // 0行目を重さ
  // 0列目(1行目以降)をその頂点の訪問フラグ
  {0, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
  //  1,  2,  3,  4,  5,  6,  7
  {1, 0,  4,  5,  0,  2,  0,  0}, // v1
  {1, 4,  0,  6,  4,  3,  0,  0}, // v2
  {1, 5,  6,  0,  6,  0,  0, 10}, // v3
  {1, 0,  4,  6,  0,  6,  1,  6}, // v4
  {1, 2,  3,  0,  6,  0, 10,  0}, // v5
  {1, 0,  0,  0,  1, 10,  0,  3}, // v6
  {1, 0,  0, 10,  6,  0,  3,  0}, // v7
};

// 二値の最小のものを返す
int min(int a, int b){
  if (a < b) {
    return a;
  }else {
    return b;
  }
}

// 訪れた頂点の数
int count(){
  printf("カウント。\n");
  int ret=0;
  for (int i = 1; i < N+1; i++) {
    // 0は訪問済み
    if (Graph[i][0] == 0) {
      ret++;
    }
  }
  return ret;
}

// 重みの中で最小値の頂点を返す
int selectMin(){
  // デバッグ用
//  printf("選択。\n");
  int x[N];
  int a, min, minIndex;
  for (int i = 0; i < N; i++) {
    x[i] = Graph[0][i+1] * Graph[i+1][0];
    if (x[i] == 0) {
      x[i] = 200000;
    }
  }
  min = x[0];	// 初期値
  minIndex = 0;	// 初期値
  for (int i = 1; i < N; ++i) {
    // 小さいのを探す
    if (min > x[i]) {
      min = x[i];
      minIndex = i;
    }
  }
  return minIndex+1;
}


int main() {
  int n = N+1;
  int target=1; // ターゲットしている頂点
  int X[N]={0};

  Graph[target][0] = 0; // 訪問していることを示す
  Graph[0][target] = 0; // 重みでの開始点
  
  // ダイクストラのメイン部分
  do {
    Graph[target][0] = 0; // 訪問済みを示す
    for (int i = 0; i < N; i++) {
      X[i] = Graph[i+1][0] * Graph[target][i+1];
    }
    for (int i = 1; i < n; i++) {
      if (X[i-1] == 0) {continue;}
      Graph[0][i] = min(Graph[0][i], Graph[0][target]+X[i-1]);
//      printf("%d\n", i);
    }
    target = selectMin(); // 最小値を次のターゲットとする
    // 確認用
//    printf(">>>>%d\n", target);
//    printf(">>>>%d\n", Graph[0][target]);
  } while (target < N);  // 訪れた頂点数が頂点数未満であれば実行

  // 結果を出力する
  printf("終了。。。\n");
  for (int i = 1; i < n; i++) {
    printf("v_%d: %d\n", i, Graph[0][i]);
  }

  return 0;
}
