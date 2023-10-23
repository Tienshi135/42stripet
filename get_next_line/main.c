#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int fd;
	char	*buffer;

	fd = open("test.txt", O_RDONLY);
	buffer = get_next_line(5);
	printf("%s", buffer);
	/*while (buffer)
	{
		buffer = get_next_line(fd);
		printf("%s", buffer);
		free(buffer);
	}*/
		buffer = get_next_line(fd);
	printf("%s", buffer);
	free(buffer);
		buffer = get_next_line(fd);
	printf("%s", buffer);
		free(buffer);
		buffer = get_next_line(fd);
	printf("%s", buffer);
		free(buffer);
		buffer = get_next_line(fd);
	printf("%s", buffer);
		free(buffer);
		buffer = get_next_line(fd);
	printf("%s", buffer);
		free(buffer);
	close(fd);
	printf("File parssing finished !");
	return (0);
}