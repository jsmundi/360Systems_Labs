#include <stdio.h>


void removeSpace(char myStr[]);

int main ()
{
	char myString[] = "  system  programming";
	//printf("%s\n", myString); 
	removeSpace(myString);
	return 0;
}

/*
	Remove only leading spaces from a string.
*/
void removeSpace(char myStr[])
{
	int strLen = strlen(myStr);
	int start = 0; 
	for(int i = 0; i<=strLen; i++)
	{

		//Check for spaces in front of string
		if((myStr[i] != ' ') && (i > 0))
		{
			 start = i;
			 break;
		}
	}
		
	int x, y = 0;
	char newStr [strLen-start];

	//Copy the string to a new array
	for(x = start; x <= strLen; x++)
	{
		newStr[y] = myStr[x];
		y++;
	}
	printf("%s\n", newStr);
}


