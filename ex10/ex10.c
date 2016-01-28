#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
	// let's make our own array of strings
	char *states[] = {
		"California", "Oregon", "Washington", "Texas"
	};


	int i = 0;
	// go through each string in argv
	// why am I skipping argv[0]?
	for(i = 1; i < argc; i++) {
		if(strcmp(argv[i], "Florida")) {
			printf("You must include Florida. I like Florida.\n");
			return 0;
		}
		printf("arg %d: %s\n", i, argv[i]);
	}
	
	int num_states = 4;	
	for(i = 0; i < num_states; i++) {
		printf("state %d: %s\n", i, states[i]);
	}
	
	return 0;
}
