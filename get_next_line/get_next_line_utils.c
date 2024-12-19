/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:00:43 by hfakou            #+#    #+#             */
/*   Updated: 2024/12/19 16:55:35 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strchr(const char *str, char to_find)
{
	int i;

	if (!str)
	{
		char *str = "the issue";
		return (str);
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == to_find)
			return (void *)(&str[i]);
		i++;
	}
	if (str[i] == '\0')
		return (void *)(&str[i]);
	return (NULL);
}

char *ft_strduptoc(const char *str, char c)
{
	size_t s;
	size_t robe;
	char *allocated;

	robe = 0;
	while (str[robe] && str[robe] != c)
		robe++;
	if (str[robe] != c)
		return (NULL);
    if (c == '\0')
	    allocated = malloc(sizeof(char) * (robe + 1));
    else
        allocated = malloc(sizeof(char) * (robe + 2));
	if (allocated == NULL)
		return (NULL);
	s = 0;
	while (s <= robe)
	{
		allocated[s] = str[s];
		s++;
	}
    if (c != '\0')
	    allocated[s] = '\0';
	return (allocated);
}

size_t ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char *ft_strjoin(const char *s1, const char *s2)
{
	char *final_string;
	size_t i;
	size_t s;
	size_t total;

	if (!s1 || !s2)
		return(NULL);
	total = ft_strlen(s1) + ft_strlen(s2);
	final_string = malloc(sizeof(char) * (total + 1));
	if (!final_string)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		final_string[i] = s1[i];
		i++;
	}
	s = 0;
	while (s2[s])
		final_string[i++] = s2[s++];
	final_string[i] = '\0';
	return (final_string);
}
