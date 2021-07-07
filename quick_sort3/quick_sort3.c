#include<stdio.h>
#include<stdlib.h>

void quick_sort(int* a, int n);
void quick_sort_2(int* a, int n);
int partition(int* a, int l, int r);

int main(){
	int i;
	int *number;
	int total;

	printf("入力する数値の総数 = ");
	fflush(0);
	scanf("%d", &total);

	number = (int *)malloc(total * sizeof(int));

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
	quick_sort_2(a, n);
}

void quick_sort_2(int* a, int n){
	int l, r, v;
	int low[30], high[30];
	int sp;

	low[0] = 0;
	high[0] = n-1;
	sp = 1;

	while(sp >0){
		sp--;
		l = low[sp];
		r = high[sp];

		if(l >= r){
			;
		}else{
			v = partition(a, l, r);

			if(v-l < r-v){
				low[sp] = v+1;
				high[sp++] = r;
				low[sp] = l;
				high[sp++] = v-1;
			}else{
				low[sp] = l;
				high[sp++] = v-1;
				low[sp] = v+1;
				high[sp++] = r;
			}
		}
	}
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
