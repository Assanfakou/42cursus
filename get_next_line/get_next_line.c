#include "get_next_line.h"
#include <string.h>

// char *handle_read_until_newline(int fd, char **buff)
// {
// 	char *str;
// 	int n_reads;
	
// 	free(*buff);
// 	n_reads = read(fd, str, BUFFER_SIZE + 1);
// }

// char *extract_then_update(char **stati)
// {
// 	char *allocated;
// 	char *new_line_pos;
// 	char *cache;

// 	if (!*stati)
// 		return (NULL);
// 	new_line_pos = ft_strchr(*stati, '\n');
// 	if (new_line_pos)
// 	{
// 		allocated = ft_strduptoc(*stati, '\n');
// 		if (*(new_line_pos + 1) != '\0')
// 		{
// 			cache = ft_strduptoc(new_line_pos + 1, '\0');
// 			free(*stati);
// 			*stati = cache;
// 		}
// 		else {
// 			free(*stati);
// 			*stati = NULL;
// 		}
// 		return (allocated);
// 	}
// 	return (NULL);
// }


// char *get_next_line(int fd)
// {
// 	static char *stat = NULL;
// 	ssize_t suit_up;
//  	char *buffer;
// 	char *str_nline_found;
// 	char *temp;

// 	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
// 	//buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	//if (!buffer)
// //		return (NULL);
// 	suit_up = 1;
// 	while (1)
// 	{
// 		str_nline_found = extract_then_update(&stat);
// 		if (str_nline_found)
// 		{
// 			free(buffer);
// 			return (str_nline_found);
// 		}
// 		suit_up = read(fd, buffer, BUFFER_SIZE);
// 		//if (suit_up > 1)
// 		//	buffer[suit_up] = '\0';
// 		if (suit_up < 0)
// 		{
// 			free(stat);
// 			free(buffer);
// 			stat = NULL;
// 			return (NULL);
// 		}	
// 		if (suit_up == 0)
// 		{
// 			free(buffer);
// 			if (stat)
// 			{
// 				temp = ft_strduptoc(stat, '\0');
// 				free(stat);
// 				stat = NULL;
// 				return (temp);
// 			}
// 			return (NULL);
// 		}
// 		temp = ft_strjoin(stat, buffer);
// 		free(stat);
// 		stat = temp;
// 	}
// 	return (NULL);
// }
char *extract_then_update(char **stat)
{
    char *newline_pos;
    char *line;
    char *temp;

    if (!*stat || !**stat)
        return (NULL);
    newline_pos = ft_strchr(*stat, '\n');
    if (newline_pos)
    {
        // Extract line including the newline character
        line = ft_strduptoc(*stat, '\n');
        // Create a new string with leftover data
        temp = ft_strduptoc(newline_pos + 1, '\0');
        free(*stat);
        *stat = temp;
    }
    else
    {
        // If no newline, return the whole static buffer
        line = ft_strduptoc(*stat, '\0');
        free(*stat);
        *stat = NULL;
    }
    return (line);
}

char *get_next_line(int fd)
{
    static char *stat = NULL;
    ssize_t suit_up;
    char *buffer;
    char *str_nline_found;
    char *temp;

    buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
    if (!buffer)
        return (NULL);
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
        buffer[suit_up] = '\0';
        temp = ft_strjoin(stat, buffer);
        free(stat);
        stat = temp;
    }
    return (NULL);
}
