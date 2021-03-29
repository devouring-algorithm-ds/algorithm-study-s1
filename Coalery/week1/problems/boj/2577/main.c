#include <stdio.h>

int arr[10];

void solve(int val) {
	if(val == 0) return;
	arr[val % 10]++;
	solve(val / 10);
}

int main(void) {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	solve(a*b*c);
	int i;
	for(i=0; i<10; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}
