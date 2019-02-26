#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void reverse(int fd1);
int main(int argc, char const *argv[])
{

	int fd = 0; 
	char ch[256];
	int offset = 0;
    int got = 0; 
    int x = 0; 

	if (argc < 2)
	{
		printf("No File provided for reading\n");
		return 1;
	}

	fd = open(argv[1], O_RDWR, 0);
	
	if (fd == 0)
	{
		printf("Unable to open the file\n");
	}

    reverse(fd); 

	close(fd);

	return 0;
}

void reverse(int fd1)
{
    char c; 
    int a = 0 ;
    a = read(fd1, &c, 1);

    if( a == 0)
    {
        write(1,&c,1);
        reverse(fd1);
    }
}