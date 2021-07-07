#include<stdio.h>
#include<stdlib.h>

void shell_sort(int *a, int n);

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


	shell_sort(number, i);

	printf("\n昇順ソートした数値\n");
	for (i=0; i<total; ++i){
		printf("%d\n", number[i]);
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

				j -= h;
			}
		}
	}
}
