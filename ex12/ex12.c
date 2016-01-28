#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

	int i = 0;
	
	if(argc == 1) {
		printf("You entered no arguments. You suck.\n");
	} else if(argc > 1 || argc < 4) {
		printf("Here's your arguments:\n");
		
		for(i = 0; i < argc; i++) {
			printf("%s ", argv[i]);
		}
		printf("\n");
	} else {
		printf("You have two many arguments. You suck.\n");
	}
	
	if(!strcmp(argv[1], "bingo")) {
		printf("You said the secret word. You win a prize!\n");
	}
	
	return 0;
}