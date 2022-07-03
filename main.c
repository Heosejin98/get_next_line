#include "get_next_line.c"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd;
	char *line;
  	fd = 0;
	fd = open("test/first.txt", O_RDONLY);	
    for(int i=0; i<=3; i++)
    {
		char *line = get_next_line(fd);
        if (!line)
            break;
		//printf("%p\n", line);
		// char c = 0; read(fd, &c, 1);
		printf("%s", line);
		free(line);		
	}
	
	printf("\n");
	printf("\n");
	fd = open("test/second.txt", O_RDONLY);
	for(int i=0; i<=3; i++)
    {
		char *line = get_next_line(fd);
        if (!line)
            break;
		//printf("%p\n", line);
		printf("%s", line);
		free(line);		
	}
	printf("\n");
	printf("\n");
	fd = open("test/third.txt", O_RDONLY);
	for(int i=0; i<=3; i++)
    {
		char *line = get_next_line(fd);
        if (!line)
            break;
		//printf("%p\n", line);
	
		printf("%s", line);
		free(line);		
	}
	//system("leaks a.out");

	return (0);
} 