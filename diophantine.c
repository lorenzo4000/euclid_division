#include <diophantine.h>

#include <stdio.h>
#include <stdlib.h>
#include <euclid_division.h>

int diophantine_has_solution(int a, int b, int c) {
	return !(c % gcd(a, b));
}

// solution : int[2] = {x, y};
int diophantine_solve(int a, int b, int c, int* solution) {
	if(!diophantine_has_solution(a, b, c)) {
		return 0;
	}

	int ab_gcd_lc[2];
	int ab_gcd = gcd_as_linear_combination(a, b, ab_gcd_lc);

	// printf("ab_gcd: %d\n", ab_gcd);
		
	// 	Since ab_gcd divides a and b   =>   c = ab_gcd * h   where h is a non zero integer.
	//  Therefore ...
	
	int h = c / ab_gcd;

	// Now we can write c  =  ab_gcd_lc[0] * h * a  +  ab_gcd_lc[1] * h * b.
	// This means that (ab_gcd_lc[0] * h, ab_gcd_lc[1] * h) is a solution of the equation.
	
	solution[0] = ab_gcd_lc[0] * h;
	solution[1] = ab_gcd_lc[1] * h;

	return 1;	
}
