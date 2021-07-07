// シンプレックス法(リメイク版)

#include <stdio.h>

// START 数値定義

// N = 変数の数(xの数)
#define N 2
// C = 制約条件の数
#define C 2

// 目的関数用 z = a_0 * x_0 + a_1 * x_1 ...
double a_n[N] = {29, 45};
// limit 限界
double limit[C] = {0, 0};
// 目的関数の係数
double z_val[N];
// pivot ピボット
int pivot_row = 0;
int pivot_col = 0;

// ex_matrix
// 最終行はも目的関数の最大値計算用
double ex_matrix[C + 1][N + C + 1] = {
    {2, 8, 1, 0, 60},
    {4, 4, 0, 1, 60},
};

// END 数値定義

// START 関数郡

// showMatrix ex_matrix の表示(主にデバッグ用)
void showMatrix()
{
  printf("current ex_matrix:\n");
  for (int i = 0; i < (C + 1); i++)
  {
    for (int j = 0; j < (C + N + 1); j++)
    {
      printf("%.3f\t", ex_matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
}

// showResult 結果のまとめを表示
void showResult()
{
  printf("[RESULT]:\n");

  for (int i = 0; i < C; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (ex_matrix[i][j] == 1)
      {
        printf("\tx_%d = %.3f\n", j, ex_matrix[i][N + C]);
        break;
      }
    }
  }
  printf("\tmaximized = %.3f\n", ex_matrix[C][N + C]);
}

// check ex_matrixの最終行にマイナスの値があれば1を返す
int check()
{
  // printf("[CHECK]\n");
  for (int i = 0; i < N; i++)
  {
    if (ex_matrix[C][i] < 0)
    {
      return 1;
    }
  }
  return 0;
}

// normalize ピボットを使い正規化
void normalize()
{
  double p = ex_matrix[pivot_row][pivot_col];
  for (int i = 0; i < (N + C + 1); i++)
  {
    ex_matrix[pivot_row][i] = ex_matrix[pivot_row][i] / p;
  }
}

// limitのなかで最小値のインデックス
int least_row()
{
  int p = 0;
  for (int i = 0; i < C; i++)
  {
    if (limit[p] > limit[i])
    {
      p = i;
    }
  }
  return p;
}

// ex_matrixの最終行の中で最小値のインデックス
int least_last_col()
{
  int p = 0;
  for (int i = 0; i < N; i++)
  {
    if (ex_matrix[C][p] > ex_matrix[C][i])
    {
      p = i;
    }
  }
  return p;
}

// calc_limit 限界を計算
void calc_limit()
{
  pivot_col = least_last_col();
  for (int i = 0; i < C; i++)
  {
    limit[i] = 0;
  }

  for (int i = 0; i < C; i++)
  {
    limit[i] = ex_matrix[i][N + C] / ex_matrix[i][pivot_col];
  }

  // printf("limit:\n");
  // for (int i = 0; i < C; i++)
  // {
  //   printf("%.3f\t", limit[i]);
  // }
  // printf("\n\n");
}

// selectPivot ピボットを選ぶ
void selectPivot()
{
  calc_limit();
  pivot_row = least_row();
  pivot_col = least_last_col();
  // printf("pivot_row = %d\n", pivot_row);
  // printf("pivot_col = %d\n\n", pivot_col);
}

// setup 初期設定関数
void setup()
{
  for (int i = 0; i < N; i++)
  {
    // ex_matrix の最終行に重みを追加
    ex_matrix[C][i] = -1 * a_n[i];
  }
  printf("[SETUP]\n");
  showMatrix();
}

// minusRow rownum行目からprow行目を引く
void minusRow(int prow, int rownum)
{
  double p = ex_matrix[rownum][pivot_col];
  for (int i = 0; i < (C + N + 1); i++)
  {
    ex_matrix[rownum][i] = ex_matrix[rownum][i] - (p * ex_matrix[prow][i]);
  }
}

// run 計算実行関数
void run()
{
  // printf("[RUN]\n");
  int count = 0;
  // もしもの無限ループを防止するために制限をつけている
  while (check() && count < 100)
  {
    selectPivot();
    normalize();
    for (int i = 0; i < (C + 1); i++)
    {
      if (pivot_row != i)
      {
        // printf("%d\n", i);
        minusRow(pivot_row, i);
      }
    }

    // カウント
    // printf("[COUNT]: %d\n", count);
    count++;
    showMatrix();
  }
}

// END 関数郡

int main()
{
  showMatrix();
  setup();
  run();
  showResult();
}