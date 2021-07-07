#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertion_sort(int *a, int n);

int main(){
	int i, j;
	int *number;
	double t;
	clock_t start, end;

	for (int total = 10; total < 100000; total=total+10) {
		printf("%d,", total);

		number = (int *)malloc(total * sizeof(int));

		for (j = 0; j < 5; j++) {
			for (i=0; i<total; ++i){
				number[i] = rand();
			}

			start = clock();

			insertion_sort(number, i);

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

void insertion_sort(int *a, int n){
	int i, j, t;

	for (i = 1; i < n; i++) {
		j = i;

		while (j >= 1 && a[j-1] > a[j]) {
			t = a[j];
			a[j] = a[j-1];
			a[j-1] = t;
			j--;
		}
	}
}
