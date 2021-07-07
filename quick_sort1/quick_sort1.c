#include<stdio.h>

void quick_sort(int* a, int n);
void quick_sort_1(int* a, int l, int r);
int partition(int* a, int l, int r);

int main(){
	int i;
	int number[100];
	int total;

	printf("入力する数値の総数 = ");
	fflush(0);
	scanf("%d", &total);

	printf("%d個の数値を入力 \n", total);
	for (i=0; i<total; ++i){
		printf("%d個目：", i+1);
		fflush(0);
		scanf("%d", &number[i]);
	}


	quick_sort(number, i);

	printf("\n昇順ソートした数値\n");
	for (i=0; i<total; ++i){
		printf("%d\n", number[i]);
	}

	return 0;
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
