#include <stdio.h>
#include <ctype.h>
#include <string.h>

// forward declarations
//int can_print_it(char ch);
void print_letters(char argc[], int arglen);

void print_arguments(int argc, char *argv[])
{
	int i = 0;
	for(i = 0; i < argc; i++) {
		int arglen = strlen(argv[i]);
		print_letters(argv[i], arglen);
	}
}

void print_letters(char arg[], int arglen)
{
	int i = 0;
	
	for(i = 0; i < arglen; i++) {
		char ch = arg[i];
		
		if(isalpha(ch) || isblank(ch)) {
			printf("'%c' == %d ", ch, ch);
		}
	}
	
	printf("\n");
}

// int can_print_it(char ch)
// {
// 	return isalpha(ch) || isblank(ch);
// }

int main(int argc, char *argv[])
{
	print_arguments(argc, argv);
	return 0;
}