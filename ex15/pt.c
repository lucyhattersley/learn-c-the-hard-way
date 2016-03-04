#include <stdio.h>
int main(int argc, char *argv[]) {

    int a = 10;
    int *p = &a;

    printf("a is: %d.\n", a);
    printf("Address of a is: %p.\n", &a);
    printf("*p is: %d.\n", *p);
    printf("p is: %p.\n", p);
    printf("Address of p is: %p\n", &p);
}