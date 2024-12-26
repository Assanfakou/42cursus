/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:32:23 by hfakou            #+#    #+#             */
/*   Updated: 2024/12/26 16:32:25 by hfakou           ###   ########.fr       */
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
char	*ft_isolate_line_and_update(char **stat)
{
	char	*reserved;
	char	*nln_post;
	char	*afternln;

	if (!*stat)
		return (NULL);
	nln_post = ft_strchr(*stat, '\n');
	if (nln_post)
	{
		reserved = ft_strdup_nln(*stat);
		if (*(nln_post + 1) != '\0')
		{
			afternln = ft_strdup(nln_post + 1);
			free(*stat);
			*stat = afternln;
		}
		else
		{
			free(*stat);
			*stat = NULL;
		}
		return (reserved);
	}
	return (NULL);
}
char	*instructions_for_read(ssize_t readdd, char **stattt, char **buffer)
{
	char	*temp;

	if (readdd < 0)
	{
		free(*buffer);
		free(*stattt);
		*stattt = NULL;
		return (NULL);
	}
	if (readdd == 0)
	{
		free(*buffer);
		temp = ft_strdup(*stattt);
		free(*stattt);
		*stattt = NULL;
		return (temp);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*statyc[2048];
	char		*buffer;
	char		*reserved;
	ssize_t		readed;
	char		*nlnfound;

	if (BUFFER_SIZE > INT_MAX)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (buffer)
	{
		nlnfound = ft_isolate_line_and_update(&statyc[fd]);
		if (nlnfound)
			return (free(buffer), nlnfound);
		else
		{
			free(buffer);
			buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		}
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed <= 0)
			return (instructions_for_read(readed, &statyc[fd], &buffer));
		reserved = ft_strjoin(statyc[fd], buffer);
		free(statyc[fd]);
		statyc[fd] = reserved;
	}
	return (NULL);
}
