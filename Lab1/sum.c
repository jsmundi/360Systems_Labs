#include <stdio.h>

int sum(int n);
int main ()
{
	
	int n = 0;
	printf("Please Enter Your Amazing Number Here: "); 
	scanf("%i",&n);
	int result = 0;
	result = sum(n);
	printf("%i\n", result);
	
	if( (result % 2)  == 0)
	{
	printf("Is Even\n");
	}
	else
	{
	printf("Is Odd\n"); 
	} 
}

int sum(int n)
{

int temp = 0;
for (int i =0; i<n+1; i++)
{
	temp = (temp + (i*i));
}

return temp;

}
