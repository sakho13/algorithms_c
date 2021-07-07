#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void shell_sort(int *a, int n);

int main(){
	int i, j;
	int *number;
	double t;
	clock_t start, end;

	for (int total = 10; total < 100000000; total=total+10) {
		printf("%d,", total);

		number = (int *)malloc(total * sizeof(int));

		for (j = 0; j < 5; j++) {
			for (i=0; i<total; ++i){
				number[i] = rand();
			}

			start = clock();

			shell_sort(number, i);

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


void shell_sort(int *a, int n){
	int h, i, j, t;

	for(h = 1; h < n/9; h = h * 3 + 1)
		;

	for(; h >0; h /= 3){
		for(i = h; i < n; i++){
			j = i;
			while(j >= h && a[j-h] > a[j]){
				t = a[j];
				a[j] = a[j-h];
				a[j-h] = t;

				j -= h;
			}
		}
	}
}
