#include <stdio.h>
int maximum(int num1,int num2,int num3)
	{
		int largest=0;
		if(num1>num2)
			largest=num1;
		else
			largest=num2;
			if(num3>largest)
				largest=num3;
		return largest;
}
int main()
{
	int number1,number2,number3,max;
	printf("enter 3 numbers");
	scanf("%d%d%d",&number1,&number2,&number3);
	max=maximum(number1 ,number2 ,number3);
	printf("the maximum value is:%d",max);


	
	getchar();
	getchar();
	return 0;
}
