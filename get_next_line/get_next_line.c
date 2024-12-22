#include "get_next_line.h"
#include <string.h>

// char *handle_read_until_newline(int fd, char **buff)
// {
// 	char *str;
// 	int n_reads;
	
// 	free(*buff);
// 	n_reads = read(fd, str, BUFFER_SIZE + 1);
// }

char *extract_then_update(char **somth)
{
	char *allocated;
	char *new_line_pos;
	char *cache;

	if (!*somth)
		return (NULL);
	new_line_pos = ft_strchr(*somth, '\n');
	if (new_line_pos)
	{
		allocated = ft_strduptoc(*somth, '\n');
		if (*(new_line_pos + 1) != '\0')
		{
			cache = ft_strduptoc(new_line_pos + 1, '\0');
			free(*somth); 
			*somth = cache;
		}
		else {
			free(*somth); 
			*somth = NULL;
		}
		return (allocated);

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

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	suit_up = 1;
	while (1)
	{
		str_nline_found = extract_then_update(&stat);
		if (str_nline_found)
		{
			free(buffer);
			return (str_nline_found);
		}
		suit_up = read(fd, buffer, BUFFER_SIZE);
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
				temp = ft_strduptoc(stat, '\0');
				free(stat);
				stat = NULL;
				return (temp);
			}
			return (NULL);
		}
		temp = ft_strjoin(stat, buffer);
		free(stat);
		stat = temp;
	}
	return (NULL);
}

