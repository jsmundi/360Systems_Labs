#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{

	int fd = 0; 
	char ch[256];
	int offset = 0;

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

	offset = lseek(fd, -1, SEEK_END);

	while ((offset) >= 0)
	{
		read(fd, ch, 1);
		write(1, ch, 1);
		offset = lseek(fd, -2, SEEK_CUR);
	}

	close(fd);

	return 0;
}
