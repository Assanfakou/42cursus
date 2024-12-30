/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:32:23 by hfakou            #+#    #+#             */
/*   Updated: 2024/12/29 09:39:23 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_calloc(size_t numb, size_t size)
{
	char	*reserved;
	size_t	i;
	size_t	total;

	if (numb == 0 || size == 0)
		return (malloc(0));
	if (numb > SIZE_MAX / size)
		return (NULL);
	total = numb * size;
	reserved = malloc(sizeof(char) * total);
	if (!reserved)
		return (NULL);
	i = 0;
	while (i < total)
	{
		reserved[i] = '\0';
		i++;
	}
	return (reserved);
}

char	*ft_isolate_line_and_update(char **static_buffer)
{
	char	*line;
	char	*nln_post;
	char	*afternln;

	if (!*static_buffer)
		return (NULL);
	nln_post = ft_strchr(*static_buffer, '\n');
	if (nln_post)
	{
		line = ft_strdup_nln(*static_buffer);
		if (*(nln_post + 1) != '\0')
		{
			afternln = ft_strdup(nln_post + 1);
			free(*static_buffer);
			*static_buffer = afternln;
		}
		else
		{
			free(*static_buffer);
			*static_buffer = NULL;
		}
		return (line);
	}
	return (NULL);
}

char	*read_result(ssize_t readdd, char **static_buffer, char **buffer)
{
	char	*temp;

	if (readdd < 0)
	{
		free(*buffer);
		free(*static_buffer);
		*static_buffer = NULL;
		return (NULL);
	}
	if (readdd == 0)
	{
		free(*buffer);
		temp = ft_strdup(*static_buffer);
		free(*static_buffer);
		*static_buffer = NULL;
		return (temp);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer[1024];
	char		*buffer;
	char		*reserved;
	ssize_t		readed;
	char		*nlnfound;

	if (BUFFER_SIZE > INT_MAX || fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buffer = ft_calloc((size_t)BUFFER_SIZE + 1, 1);
	while (buffer)
	{
		nlnfound = ft_isolate_line_and_update(&static_buffer[fd]);
		if (nlnfound)
			return (free(buffer), nlnfound);
		else
			(free(buffer), buffer = ft_calloc((size_t)BUFFER_SIZE + 1, 1));
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed <= 0)
			return (read_result(readed, &static_buffer[fd], &buffer));
		reserved = ft_strjoin(static_buffer[fd], buffer);
		free(static_buffer[fd]);
		static_buffer[fd] = reserved;
	}
	return (NULL);
}
