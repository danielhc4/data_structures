#include <stdio.h>

int main() {
	printf("Array\n\n");

	printf("Declare array 'int a[5]'\n\n");
	int a[5];

	printf("Initialize position 0 'a[0] = 11'\n");
	a[0] = 11;
	printf("Initialize position 1 'a[1] = 4'\n");
	a[1] = 4;
	printf("Initialize position 2 'a[2] = 2'\n");
	a[2] = 2;
	printf("Initialize position 3 'a[3] = 9'\n");
	a[3] = 9;
	printf("Initialize position 4 'a[4] = 7'\n\n");
	a[4] = 7;

	printf("Print values of array a\n\n");
	printf("Print value at position 2 %d\n", a[2]);
	printf("Print value at position 0 %d\n", a[0]);
	printf("Print value at position 1 %d\n", a[1]);
	printf("Print value at position 4 %d\n", a[4]);
	printf("Print value at position 3 %d\n\n", a[3]);

	printf("Declare and initialize array int b[] = {25, 50, 75, 100}\n\n");
	int b[] = {25, 50, 75, 100};

	printf("Print values of array b\n\n");
	printf("Print value at position 3 %d\n", b[3]);
	printf("Print value at position 1 %d\n", b[1]);
	printf("Print value at position 0 %d\n", b[0]);
	printf("Print value at position 2 %d\n", b[2]);

	return 0;
}
