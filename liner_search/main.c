#include <stdio.h>
#include <stdlib.h>

#define N 20

void ACT_view();
void ACT_input_numbers();
void ACT_liner_search(int target);
void quick_sort(int* a, int n);
void quick_sort_1(int* a, int l, int r);
int partition(int* a, int l, int r);

//配列作成
int Data[N];

int main() {
  int target, n;

  ACT_input_numbers();

  quick_sort(Data, N);
  ACT_view();

  printf("ターゲットを入力 >");
  scanf("%d", &target);

  ACT_liner_search(target);

  return 0;
}



void ACT_liner_search(int target){
  for (int count = 0; count < N; count++) {
    if (Data[count] == target) {
      printf("%d:", count);
      puts("発見");
      return;
    }
  }
  puts("ありません");
}

void ACT_view(){
  for (int count = 0; count < N; count++) {
    printf("%d\t", count);
    printf("%d\n", Data[count]);
  }
}

void ACT_input_numbers(){
  for (int i=0; i < N; i++) {
    Data[i] = (rand() % N) + 1;
  }
}



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
