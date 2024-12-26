#include "get_next_line.h"

#ifndef SIZE

# define SIZE 73
#endif

char	*ft_rebuild_extract_(char **statt)
{
	char	*restor;
	char	*nln_pos;
	char	*cash;

	if (!*statt)
		return (NULL);
	nln_pos = ft_strchr(*statt, '\n');
	if (nln_pos)
	{
		restor = ft_strdup_nln(*statt);
		if (*(nln_pos + 1) != '\0')
		{
			cash = ft_strdup(nln_pos + 1);
			free(*statt);
			*statt = cash;
		}
		else
		{
			free(*statt);
			*statt = NULL;
		}
		return (restor);
	}
	return (NULL);
}
char	*get_next_line(int fd)
{
	static char	*stats;
	char		*nln_found;
	char		*temp;
	ssize_t		readed;
	char		*buffer;

	buffer = ft_calloc(SIZE + 1, sizeof(char));
	while (buffer)
	{
		nln_found = ft_rebuild_extract_(&stats);
		if (nln_found)
		{
			free(buffer);
			return (nln_found);
		}
		else
		{
			free(buffer);
			buffer = ft_calloc(SIZE + 1, sizeof(char));
		}
		readed = read(fd, buffer, SIZE);
		if (readed < 0)
		{
			free(buffer);
			free(stats);
			stats = NULL;
			return (NULL);
		}
		if (readed == 0)
		{
			free(buffer);
			temp = ft_strdup(stats);
			free(stats);
			stats = NULL;
			return (temp);
		}
		temp = ft_strjoin(stats, buffer);
		free(stats);
		stats = temp;
	}
	return (NULL);
}
int	main(void)
{
	char *line;

	int fd = open("file.txt", O_RDONLY);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
}