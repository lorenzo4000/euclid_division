#include <stdio.h>
#include <stdlib.h>

#include <euclid_division.h>

int main(int argc, char** args) {
	if(argc <= 2) {
		printf("error: expected at least 2 arguments\n");
		return -1;
	}

	int a = atoi(args[1]);
	int b = atoi(args[2]);

	int gcd_lc[2];
	printf("gcd : %d\n", gcd_as_linear_combination(a, b, gcd_lc));	

	printf("gcd_lc: (%d, %d)  ===  %d\n", gcd_lc[0], gcd_lc[1], gcd_lc[0] * a + gcd_lc[1] * b);

	return 0;
}
