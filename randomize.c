#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int start, end;
	printf("input start of range: ");
	scanf("%d", &start);
	printf("input end of range: ");
	scanf("%d", &end);
	srand(time(0));
	printf("random integer: %d\n", start + rand() % (end - start + 1));
	return 0;
}

