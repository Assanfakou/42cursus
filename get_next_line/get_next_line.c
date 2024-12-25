/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assankou <assankou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 22:28:48 by hfakou            #+#    #+#             */
/*   Updated: 2024/12/25 15:05:51 by assankou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_calloc(size_t chunk, size_t size)
{
	char	*south;
	size_t	i;
	size_t	total;

	if (chunk == 0 || size == 0)
		return (malloc(0));
	if (chunk > SIZE_MAX / size)
		return (NULL);
	total = chunk * size;
	south = malloc(total);
	if (!south)
		return (NULL);
	i = 0;
	while (i < total)
	{
		south[i] = '\0';
		i++;
	}
	return (south);
}

char	*extract_then_update(char **stati)
{
	char	*allocated;
	char	*new_line_pos;
	char	*cache;

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
		else
		{
			free(*stati);
			*stati = NULL;
		}
		return (allocated);
	}
	return (NULL);
}

// freeze = will change and tha names of parammeters too
char	*freeeze(ssize_t readed, char **statttt, char **bufferrrr)
{
	char	*temp;

	if (readed < 0)
	{
		free(*statttt);
		free(*bufferrrr);
		*statttt = NULL;
		return (NULL);
	}
	if (readed == 0)
	{
		free(*bufferrrr);
		temp = ft_strdup(*statttt);
		free(*statttt);
		*statttt = NULL;
		return (temp);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stat;
	ssize_t		suit_up;
	char		*buffer;
	char		*str_nline_found;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	while (1)
	{
		str_nline_found = extract_then_update(&stat);
		if (str_nline_found)
			return (free(buffer), str_nline_found);
		else
		{
			free(buffer);
			buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		}
		suit_up = read(fd, buffer, BUFFER_SIZE);
		if (suit_up <= 0)
			return (freeeze(suit_up, &stat, &buffer));
		temp = ft_strjoin(stat, buffer);
		free(stat);
		stat = temp;
	}
	return (NULL);
}
