#include <stdio.h>

int main(void) {
	int C, i, N, j;
	scanf("%d", &C);
	
	for(i=0; i<C; i++) {
		int scores[1000] = {0};
		int sum = 0;
		
		scanf("%d", &N);
		for(j=0; j<N; j++) {
			scanf("%d", &scores[j]);
			sum += scores[j];
		}
		float avg = (float)sum / (float)N;
		int greaterCnt = 0;
		for(j=0; j<N; j++) {
			if(scores[j] > avg) {
				greaterCnt++;
			}
		}
		printf("%.3f%%\n", ((float)greaterCnt / (float)N) * 100.0f);
	}
	
	return 0;
}
