#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selection_sort(int *a, int n);

int main(){
	int i;
	int *number;
	int total = 100000;
	double t;
	clock_t start, end;

	// printf("入力する数値の総数 = ");
	// fflush(0);
	// scanf("%d", &total);

	number = (int *)malloc(total * sizeof(int));

	for (i=0; i<total; ++i){
		number[i] = rand();
	}

	start = clock();

	selection_sort(number, i);

	end = clock();

	// printf("\n昇順ソートした数値\n");
	// for (i=0; i<total; ++i){
	// 	printf("%d\n", number[i]);
	// }

	t = (double)(end-start)/CLOCKS_PER_SEC;

	printf("時間：%lf\n", t);

	return 0;
}


void selection_sort(int *a, int n){
	int i, j, t, lowest, lowkey;

	for(i = 0; i < n - 1; i++){
		lowest = i;
		lowkey = a[i];
		for(j = i + 1; j < n; j++){
			if(a[j] < lowkey){
				lowest = j; lowkey = a[j];
			}
		}
		t = a[i]; a[i] = a[lowest]; a[lowest] = t;

		// 過程を見せる
		// for(int k = 0; k < n; k++){
		// 	printf("%d", a[k]);
		// 	if(k == n-1){
		// 		printf("\n");
		// 		break;
		// 	}
		// 	else{
		// 		printf(", ");
		// 	}
		// }
	}

}
