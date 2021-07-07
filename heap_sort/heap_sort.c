#include<stdio.h>

#define MAX_HEAP 1000

void downheap(int from, int to);
void heapsort();

int a[MAX_HEAP+1];
int n=0;

int main(){
	int i;

	printf("入力する数値の総数 = ");
	fflush(0);
	scanf("%d", &n);

	printf("%d個の数値を入力 \n", n);
	for (i = 1; i <= n; ++i){
		printf("%d個目：", i);
		fflush(0);
		scanf("%d", &a[i]);
	}

	heapsort();

	printf("\n昇順ソートした数値\n");
	for (i = n; i > 0; --i){
		printf("%d\n", a[i]);
	}

	return 0;
}

void downheap(int from, int to){
  int i, j;
  int val;

  val = a[from];
  i = from;

  while (i <= to/2) {
    j = i * 2;
    if(j+1 <= to && a[j] > a[j+1]){
      j++;
    }

    if(val <= a[j])
      break;

    a[i] = a[j];
    i = j;
  }
  a[i] = val;
}

void heapsort(){
  int i;
  int tmp;

  for(i = n/2; i >= 1; i--){
    downheap(i, n);
  }

  for(i = n; i >= 2; i--){
    tmp = a[1];
    a[1] = a[i];
    a[i] = tmp;
    downheap(1, i-1);
  }
}
