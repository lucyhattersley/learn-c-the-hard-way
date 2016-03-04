//https://www.youtube.com/watch?v=X1DcpcgSUXw#t=4.743106
// Up to 5:15. Finish watching and entering code
#include <stdio.h>
int main()
{
    int a;
    int *p;
    a = 10;
    p = &a;
    printf("%d\n",a);
    *p = 12;
    printf("%d\n",a);

}