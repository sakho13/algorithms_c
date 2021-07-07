#include <stdio.h>
#include <stdlib.h>

#define N 6   // 頂点数

int Graph[N+1][N+1] = {
  {0, 10000, 10000, 10000, 10000, 10000, 10000},
  {1, 0,  4,  3,  0,  0,  0},  // v1
  {1, 4,  0,  0,  1,  0,  5},  // v2
  {1, 3,  0,  0,  4,  3,  0},  // v3
  {1, 0,  1,  4,  0,  3,  0},  // v4
  {1, 0,  0,  3,  3,  0,  2},  // v5
  {1, 0,  5,  0,  0,  2,  0},  // v6
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
  int ret=0;
  for (int i = 1; i < N+1; i++) {
    if (Graph[i][0] == 0) {
      ret++;
    }
  }
  return ret;
}

// 重みの中で最小値の頂点を返す
int selectMin(){
  int x[N];
  int a, min, minIndex;
  for (int i = 0; i < N; i++) {
    x[i] = Graph[0][i+1] * Graph[i+1][0];
    if (x[i] == 0) {
      x[i] = 20000;
    }
  }
  min = x[0];
  minIndex = 0;
  for (int i = 1; i < N; ++i) {
    if (min > x[i]) {
      min = x[i];
      minIndex = i;
    }
  }
  return minIndex+1;
}

int main() {
  int n = N+1;
  int target=1; // ターゲットしている頂点（初期化1）
  int X[N]={0};

  Graph[target][0] = 0;
  Graph[0][target] = 0;  // 重みでの開始点
  do {
    Graph[target][0] = 0;
    for (int i = 0; i < N; i++) {
      X[i] = Graph[i+1][0] * Graph[target][i+1];
    }
    for (int i = 1; i < n; i++) {
      if (X[i-1] == 0) {continue;}
      Graph[0][i] = min(Graph[0][i], Graph[0][target]+X[i-1]);
    }
    target = selectMin();
  } while (count() < N);

  printf("終了。。。\n");
  for (int i = 1; i < n; i++) {
    printf("v_%d: %d\n", i, Graph[0][i]);
  }

  return 0;
}
