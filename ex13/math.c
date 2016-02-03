#include <stdio.h>

int main(int argc, char *argv[])

{
	char character = argv[1][0];
	printf("Char is %c\n", character);
	printf("Char int  %d\n", character);
	printf("Char converted to uppercase: %c\n", character - 32);
}