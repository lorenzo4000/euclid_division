#include <stdio.h>
#include <stdlib.h>

#include <diophantine.h>

int main(int argc, char** args) {
	if(argc <= 3) {
		printf("error: expected at least 3 args: a, b, c\n");
		return -1;
	}
	
	int a = atoi(args[1]);
	int b = atoi(args[2]);
	int c = atoi(args[3]);

	int solution[2];

	int s = diophantine_solve(a, b, c, solution);
	if(!s) {
		printf("the given equation has no integer solution!\n");
		return 0;
	} 
	if(s < 0) {
		printf("error: could not solve the equation.\n");
		return -1;
	}

	printf("found solution: (%d, %d)\n", solution[0], solution[1]);

	return 0;
}
