#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX_HEAP 100000000

void downheap(int from, int to);
void heapsort();

int a[MAX_HEAP+1];
int n=0;

int main(){
	int i, j;
	double t;
	clock_t start, end;

	for (n = 10; n <100000000; n=n+10) {
		printf("%d,", n);

		for (j = 0; j < 10; j++) {
			for (i=0; i<n; ++i){
				a[i] = rand();
			}

			start = clock();

			heapsort();

			end = clock();

			t = (double)(end-start)/CLOCKS_PER_SEC;

			if (i != 4) {
				printf("%lf", t);
			}else{
				printf("%lf\n", t);
			}
		}
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
