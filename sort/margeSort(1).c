#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_ELEMENTE 10000000

void marge_sort_array(int* a, int low, int high);

int main(){
	int i, j;
	int *number;
	double t;
	clock_t start, end;

	for (int total = 10; total < 10000000; total=total+10) {
		printf("%d,", total);

		number = (int *)malloc(total * sizeof(int));

		for (j = 0; j < 10; j++) {
			for (i=0; i<total; ++i){
				number[i] = rand();
			}

			start = clock();

			marge_sort_array(number, 0, total-1);

			end = clock();

			t = (double)(end-start)/CLOCKS_PER_SEC;

			if (i != 4) {
				printf("%lf", t);
			}else{
				printf("%lf\n", t);
			}
		}
		free(number);
	}

	return 0;
}

int b[MAX_ELEMENTE];

void marge_sort_array(int* a, int low, int high) {
	int mid, i, j, k;

	if(low >= high){
		return;
	}

	mid = (low + high) / 2;

	marge_sort_array(a, low, mid);
	marge_sort_array(a, mid+1, high);

	for (i = low; i <= mid; i++) {
		b[i] = a[i];
	}

	for (i = mid+1, j = high; i <= high; i++, j--) {
		b[i] = a[j];
	}

	i = low;
	j = high;
	for (k = low; k <= high; k++) {
		if (b[i] <= b[j]) {
			a[k] = b[i++];
		}else{
			a[k] = b[j--];
		}
	}
}
