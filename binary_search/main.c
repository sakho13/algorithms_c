#include <stdio.h>
#include <stdlib.h>

#define N 20

/*********************************************************/
void ACT_view();
void ACT_input_numbers();
void ACT_binay_search(int target);
void quick_sort(int* a, int n);
void quick_sort_1(int* a, int l, int r);
int partition(int* a, int l, int r);
/*********************************************************/



/*********************************************************/
//配列作成
int Data[N];
int lea=0;
int ma=N;
/*********************************************************/



/*********************************************************/
int main() {
  int target, n;

  ACT_input_numbers();

  quick_sort(Data, N);
  ACT_view();

  printf("ターゲットを入力 >");
  scanf("%d", &target);

  ACT_binay_search(target);

  return 0;
}
/*********************************************************/



/*********************************************************/
//表示
void ACT_view(){
  for (int count = 0; count < N; count++) {
    printf("%d\t", count);
    printf("%d\n", Data[count]);
  }
}

//データのインプット
void ACT_input_numbers(){
  for (int i=0; i < N; i++) {
    Data[i] = (rand() % N) + 1;
  }
}


void ACT_binay_search(int target){
  while (lea <= ma) {
    int half = (lea + ma) / 2;
    if (Data[half] == target) {
      printf("発見\n");
      return;
    }else if (Data[half] < target){
      lea = half + 1;
      // puts("debug");
    }else{
      ma = half - 1;
      // puts("debug");
    }
  }
  printf("非発見\n");
  return;
}


//ソート
void quick_sort(int* a, int n){
	quick_sort_1(a, 0, n-1);
}


void quick_sort_1(int* a, int l, int r){
	int v;

	if(l >= r){
		return;
	}
	v = partition(a, l, r);

	quick_sort_1(a, l, v-1);

	quick_sort_1(a, v+1, r);
}


int partition(int* a, int l, int r){
	int i, j, pivot, t;
	i = l-1;
	j = r;

	pivot = a[r];

	for(;;){
		while (a[++i] < pivot)
			;
		while (i < --j && pivot < a[j])
			;
		if(i >= j){
			break;
		}
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	t = a[i];
	a[i] = a[r];
	a[r] = t;

	return i;
}
/*********************************************************/
