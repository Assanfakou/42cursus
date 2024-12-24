#include "get_next_line.h"
#include <string.h>

char *extract_then_update(char **stati, char **buffer)
{
	char *allocated;
	char *new_line_pos;
	char *cache;

	if (!*stati)
		return (NULL);
	new_line_pos = ft_strchr(*stati, '\n');
	if (new_line_pos)
	{
		allocated = ft_strdup_nln(*stati);
		if (*(new_line_pos + 1) != '\0')
		{
			cache = ft_strdup(new_line_pos + 1);
			free(*stati);
			*stati = cache;
		}
		else {
			free(*stati);
			*stati = NULL;
		}
		return (allocated);
	}
	else
	{
		free(*buffer);
		*buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	}
	return (NULL);	
}


char *get_next_line(int fd)
{
	static char *stat = NULL;
	ssize_t suit_up;
 	char *buffer;
	char *str_nline_found;
	char *temp;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	suit_up = 1;
	while (1)
	{
		// int s = 69;
		// 	printf("|%d|", s);
		str_nline_found = extract_then_update(&stat, &buffer);
		if (str_nline_found)
		{
			free(buffer);
			// printf("statfirst[%s]",stat);
			// printf("the issue is the first return");
			return (str_nline_found);
		}
		suit_up = read(fd, buffer, BUFFER_SIZE);
		// printf("buffer >>|%s|", buffer);
		if (suit_up < 0)
		{
			free(stat);
			free(buffer);
			stat = NULL;
			return (NULL);
		}	
		if (suit_up == 0)
		{
			free(buffer);
			if (stat)
			{
				// printf("statsecond%s", stat);
				temp = ft_strdup(stat);
				free(stat);
				stat = NULL;
				// printf("the [%s]", temp);
				return (temp);
			}
			return (NULL);
		}
		temp = ft_strjoin(stat, buffer);
		// printf("temp value {%s}", temp);
		// free(buffer);
		free(stat);
		stat = temp;
		// printf("stat [%s]", stat);
		
	}
	return (NULL);
}

