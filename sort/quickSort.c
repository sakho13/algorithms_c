#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void quick_sort(int* a, int n);
void quick_sort_2(int* a, int n);
int partition(int* a, int l, int r);

int main(){
	int i, j;
	int *number;
	double t;
	clock_t start, end;

	for (int total = 10; total < 1000000; total=total+10) {
		printf("%d,", total);

		number = (int *)malloc(total * sizeof(int));

		for (j = 0; j < 5; j++) {
			for (i=0; i<total; ++i){
				number[i] = rand();
			}

			start = clock();

			quick_sort(number, i);

			end = clock();

			t = (double)(end-start)/CLOCKS_PER_SEC;


			if (j != 4) {
				printf("%lf,", t);
			}else{
				printf("%lf\n", t);
			}
		}
		free(number);
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
