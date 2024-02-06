#ifndef EUCLID_DIVISION_H
#define EUCLID_DIVISION_H

int recursive_gcd(int a, int b);
int iterative_gcd(int a, int b);
int gcd_as_linear_combination(int a, int b, int* _gcd);


#define gcd(a, b) iterative_gcd(a, b)


#endif // EUCLID_DIVISION_H
