#include <stdio.h>

int main(int argc, char *argv[])
{
	// go through each string in argv

	int i = 0;
	while(i < argc) {
		printf("arg %d: %s\n", i, argv[i]);
		i++;
	}

	// let's make our own array of strrings
	char *states[] = {
		"California", "Oregon", "Washington", "Texas"
	};

	int num_states = 3;
	i = 0; // watch for this
	while(num_states >= i) {
		printf("state %d: %s\n", num_states, states[num_states]);
		num_states --;	
	}

	return 0;
}
