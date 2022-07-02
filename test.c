#include "test.h"
#include <stdio.h>

/*
//개행을 찾아서 한줄만 읽어서 반환 
char 	*chekc_newline(char *buf, int fd)
{
	char	*buf;
	char	

	read(fd, buf, BUFFER_SIZE);
}
*/

char	*get_next_line(int fd)
{
	int				count;
	char			*buf;
	static char		*result;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
   	int i = 0;
	int j = 0;
	while( 0 < ( count = read( fd, buf, BUFFER_SIZE - 1))){  //  4 byte씩 읽씁니다.
        buf[count]  = '\0';  
		result[j++] += buf[i]; 
		if (i == count)
			i = 0;
	}
	
	free(buf);

	return (result);
}

int	main(void)
{
	int fd;

	fd = 0;
	fd = open("ttt.txt", O_RDONLY);
	char *line = get_next_line(fd);
	//printf("%p\n", line);
	printf("%s", line);

	return (0);
}