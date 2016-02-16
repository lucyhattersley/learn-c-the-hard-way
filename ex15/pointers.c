#include <stdio.h>

int main() 
{
	int number = 123;
	printf("number: %d\n", number);
	printf("&number: %zd\n", &number);

	int *pr1 = &number;
	printf("pr1: %zd\n", pr1);
	printf("&pr1: %zd\n", &pr1);
	printf("*pr1: %d\n", *pr1);

	printf("Changing number\n");
	printf("---------------\n");

	number = 321;
	printf("number: %d\n", number);
	printf("pr1: %zd\n", pr1);
	printf("*pr1: %d\n", *pr1);

	printf("Creating **pr2\n");
	printf("------------\n");

	int **pr2 = &pr1;
	printf("*pr2: %zd\n", *pr2);
	printf("**pr2: %zd\n", **pr2);
}