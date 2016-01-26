#include <stdio.h>

int main(int argc, char *argv[])
{
	// go through each string in argv

	int i = argc -1;
	while(i >= 0) {
		printf("arg %d: %s\n", i, argv[i]);
		i --;
	}

	// let's make our own array of strrings
	char *states[] = {
		"California", "Oregon", "Washington", "Texas"
	};


	// WIP: Trying to add strings from argv to states
	int num_states = argc -1;
	i = 0;
	while(num_states >= i) {
		
	}

	int num_states = 3;
	i = 0; // watch for this
	while(num_states >= i) {
		printf("state %d: %s\n", num_states, states[num_states]);
		num_states --;	
	}

	return 0;
}
