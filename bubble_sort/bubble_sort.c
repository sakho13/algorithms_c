#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int *a, int n);

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


	bubble_sort(number, i);

	printf("\n昇順ソートした数値\n");
	for (i=0; i<total; ++i){
		printf("%d\n", number[i]);
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
				// 過程を見せる
				for(int k = 0; k < n; k++){
					printf("%d", a[k]);
					if(k == n-1){
						printf("\n");
						break;
					}
					else{
						printf(", ");
					}
				}
		}
	}
}
