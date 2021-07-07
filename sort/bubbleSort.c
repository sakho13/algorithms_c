#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubble_sort(int *a, int n);

int main(){
	int i, j, k, n=2;
	int *number;
	double t;
	clock_t start, end;

	for (int total = 10; total < 10000; total=total+10) {
		printf("%d,", total);

		number = (int *)malloc(total * sizeof(int));

		for (k = 0; k < n; k++) {
			for (j = 0; j < 5; j++) {
				for (i=0; i<total; ++i){
					number[i] = rand();
				}

				start = clock();

				bubble_sort(number, i);

				end = clock();

				t = (double)(end-start)/CLOCKS_PER_SEC;

				if (j != 4) {
					printf("%lf,", t);
				}else{
					printf("%lf\n", t);
				}
			}
		}
		free(number);
	}

	return 0;
}


void bubble_sort(int *a, int n){
	int i, j, t;

	for(i = 0; i < n-1; i++){
		for(j = n - 1; j > i; j--){
			if(a[j-1] > a[j]){
				t = a[j];
				a[j] = a[j-1];
				a[j-1] = t;
				}
		}
	}
}
