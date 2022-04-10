#include <stdio.h>

void exchange_ints();
void inverse_caps();

int main(int argc, char *argv[]) {
	if (argc > 1) {
		switch(argv[1][0]) {
		case 'e': exchange_ints(); break;
		case 'c': inverse_caps(); break;
		}
	} else {
		printf("usage: %s e (exchange integers) or c (inverse char capitalization)\n", argv[0]);
	}
	return 0;
}

void exchange_ints() {
	int i1, i2;
	printf("pick int 1: ");
	scanf("%d", &i1);
	printf("pick int 2: ");
	scanf("%d", &i2);
	i1 ^= i2 ^= i1 ^= i2;
	printf("\ni1: %d, i2: %d\n", i1, i2);
}

void inverse_caps() {
	char ch;
	printf("pick char A-z: ");
	scanf("%c", &ch);
	ch = ch ^ 0b00100000;
	printf("\nresult: %c\n", ch);
}

