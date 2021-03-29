#include <stdio.h>

int arr[42];

int main(void) {
	int i;
	for(i=0; i<10; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr[tmp % 42]++;
	}
	int cnt = 0;
	for(i=0; i<42; i++) {
		if(arr[i] != 0) {
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
