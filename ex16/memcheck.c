#include <stdio.h>

int main(int argc, char *argv[]){
    int foo = 0;
    printf("foo is: %d.\n", foo);
    printf("Sizeof(foo) is: %lu\n", sizeof(foo));
    printf("foo is at memory address: %p.\n", &foo);

}
