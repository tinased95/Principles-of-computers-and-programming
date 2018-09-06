#include <stdio.h>
int square(int n)
{
	int square=n*n;
	return square;
}
int main()
{
	int n;
	printf("enter number");
	scanf("%d",&n);
	printf("the square of %d is : %d",n,square(n));
	
	getchar();
	getchar();
	return 0;
}
