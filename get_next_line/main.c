#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int fd;
	char	*buffer;

	fd = open("/Users/stripet/Desktop/test.txt", O_RDONLY);
	buffer = get_next_line(fd);
	printf("%s", buffer);
	buffer = get_next_line(fd);
	printf("%s", buffer);
	close(fd);
	printf("File parssing finished !");
	return (0);
}