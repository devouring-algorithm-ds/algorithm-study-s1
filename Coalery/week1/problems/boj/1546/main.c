#include <stdio.h>

int main(void) {
	int N;
	int i, max = -1, sum = 0;
	
	scanf("%d", &N);
	
	for(i=0; i<N; i++) {
		int tmp;
		scanf("%d", &tmp);
		max = (tmp > max) ? tmp : max;
		sum += tmp;
	}
	
	printf("%f\n", sum / (double)max * 100.0f / N);
	return 0;
}
