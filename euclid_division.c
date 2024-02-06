#include <euclid_division.h>

#include <stdio.h>

int recursive_gcd(int a, int b) {
	int _r = a % b;

	if(!_r) { 
		return b;
	}

	return recursive_gcd(b, _r);
}

int iterative_gcd(int a, int b) {
	int r;

	while(r = a % b) {
		a = b;
		b = r;
	}	
	
	return b;
}


int gcd_as_linear_combination(int a, int b, int* _gcd) {
	int r;
	int _a[2] = {1, 0};
	int _b[2] = {0, 1};
	int _r[2];

	int __a = a;
	int __b = b;

	while(r = a % b) {
		_r[0] = _a[0] + _b[0] * (-a / b);
		_r[1] = _a[1] + _b[1] * (-a / b);

		// printf("r = %d = %d * %d  +  %d * %d\n", 
		// 		    r, _r[0],__a,  _r[1],__b);

		_a[0] = _b[0];
		_a[1] = _b[1];
		_b[0] = _r[0];
		_b[1] = _r[1];

		a = b;
		b = r;
	}	
	
	if(b == __b) {
		_gcd[0] = 0;
		_gcd[1] = 1;
	} else 
	if(b == __a) {
		_gcd[0] = 1;
		_gcd[1] = 0;
	} else {
		_gcd[0] = _r[0];
		_gcd[1] = _r[1];
	}

	return b;
}
