#include<stdio.h>
#include<stdlib.h>

#define MAX_ELEMENTE 10000

void marge_sort_array(int* a, int low, int high);

int main(){
	int i;
	int *number;
	int total;

	printf("入力する数値の総数 = ");
	fflush(0);
	scanf("%d", &total);

	number = (int *)malloc(total * sizeof(int));	//mallocによるメモリ確保

	printf("%d個の数値を入力 \n", total);
	for (i=0; i<total; ++i){
		printf("%d個目：", i+1);
		fflush(0);
		scanf("%d", &number[i]);
	}

	marge_sort_array(number, 0, total-1);

	printf("\n昇順ソートした数値\n");
	for (i=0; i<total; ++i){
		printf("%d\n", number[i]);
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
