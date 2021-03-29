#include <stdio.h>

int main(void) {
	int maxLoc = 0, max = 0;
	int i, tmp;
	for(i=0; i<9; i++) {
		scanf("%d", &tmp);
		if(tmp > max) {
			max = tmp;
			maxLoc = i + 1;
		}
	}
	printf("%d\n%d\n", max, maxLoc);
	return 0;
}
