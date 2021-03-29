#include <stdio.h>

int main(void) {
	int N;
	scanf("%d", &N);
	
	int i, j;
	for(i=0; i<N; i++) {
		char str[80]; 
		scanf("%s", str);
		
		int score = 0;
		int streak = 0;
		for(j=0; str[j] != 0; j++) {
			if(str[j] == 'X') {
				streak = 0;
			} else if(str[j] == 'O') {
				++streak;
				score += streak;
			}
		}
		printf("%d\n", score);
	}
	return 0;
}
