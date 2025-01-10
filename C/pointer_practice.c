#include <stdio.h>

int main()
{
	int p = 394;
	int *x = &p;
    
	printf("The value of p is %d\n", p);
	printf("The address of p is %p\n", x);
	printf("The value of p is %d\n", *x);
	printf("The address of p is %p\n", &p);
	printf("p is %d\n", *(&p));
    
	return 0;
}