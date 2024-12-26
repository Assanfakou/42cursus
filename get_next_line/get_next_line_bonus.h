/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:32:16 by hfakou            #+#    #+#             */
/*   Updated: 2024/12/26 16:42:55 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

char	*get_next_line(int fd);
char *ft_strdup_nln(const char *str);
char *ft_strdup(const char *str);
size_t ft_strlen(const char *str);
char *ft_strjoin(const char *s1, const char *s2);
char *ft_strchr(char *str, char c);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 66
# endif
#endif