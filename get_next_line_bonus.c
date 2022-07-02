#include "get_next_line.h"

char	*file_save(char *result)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (result[i] && result[i] != '\n')
		i++;
	if (!result[i])
	{
		free(result);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(result) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (result[i])
		s[c++] = result[i++];
	s[c] = '\0';
	free(result);
	return (s);
}

char	*get_line(char *file_text)
{
	int		i;
	char	*s;

	i = 0;
	if (!file_text[i])
		return (NULL);
	while (file_text[i] && file_text[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (file_text[i] && file_text[i] != '\n')
	{
		s[i] = file_text[i];
		i++;
	}
	if (file_text[i] == '\n')
	{
		s[i] = file_text[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*get_next_line(int fd)
{
	int				count;
	char			*buf;
	char			*result;
	static char		*file_text[256];

	count = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (count != 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[count] = '\0';
		file_text[fd] = ft_strjoin(file_text[fd], buf);
	}
	result = get_line(file_text[fd]);
	file_text[fd] = file_save(file_text[fd]);
	free(buf);
	return (result);
}
