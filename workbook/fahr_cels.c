#include <stdio.h>

int main () {
	int fahr, cels;
	int max, min, step;

	min = 0;
	max = 300;
	step = 20;
	
	fahr = min;

	while (fahr <= max) {
		cels = 5 * (fahr - 32) / 9;
		printf("%3d %6d\n", fahr, cels);
		fahr = fahr + step;
	}
}

