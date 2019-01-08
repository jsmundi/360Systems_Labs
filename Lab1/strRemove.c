#include <stdio.h>

void removeSpace(char myStr[]);
void slice_str(const char * str, char * buffer, size_t start, size_t end);
int main ()
{
	char myString[] = "  system  programming";
	//printf("%s\n", myString); 
	removeSpace(myString);
	return 0;
}

void removeSpace(char myStr[])
{
	int strLen = strlen(myStr);
	int start = 0; 
	for(int i = 0; i<=strLen; i++)
	{

		if((myStr[i] != ' ') && (i > 0))
		{
			 start = i;
			 break;
		}
	}
	
	//printf("%i", start);
	
	int x, y = 0;
	char newStr [strLen-start];
	for(x = start; x <= strLen; x++)
	{
		newStr[y] = myStr[x];
		y++;
	}

	printf("%s\n", newStr);

}


