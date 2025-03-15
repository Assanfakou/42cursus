/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsplit_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:04:55 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/15 11:29:40 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	string_leng(char *str, char c)
{
	int	word;
	int	i;
	int	check;

	i = 0;
	word = 0;
	check = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			if (check == 0)
			{
				check = 1;
				word++;
			}
		}
		else
			check = 0;
		i++;
	}
	return (word);
}

int	word_lengt(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

void	fill_str(char *dest, char *src, int leg)
{
	int	i;

	i = 0;
	while (i < leg)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	ft_free(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

char	**fsplit(char *str, char c)
{
	char	**all;
	int		size;
	int		word_len;
	int		i;

	size = string_leng(str, c);
	all = malloc(sizeof(char *) * (size + 1));
	if (!all)
		return (NULL);
	i = 0;
	while (i < size)
	{
		while (*str == c)
			str++;
		word_len = word_lengt(str, c);
		all[i] = malloc(sizeof(char) * (word_len) + 1);
		if (!all[i])
			return (ft_free(all, i), NULL);
		fill_str(all[i++], str, word_len);
		str += word_len;
	}
	all[i] = NULL;
	return (all);
}
