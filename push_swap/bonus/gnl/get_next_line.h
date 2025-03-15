/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:00:50 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/15 14:12:33 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strchr(char *str, char to_find);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_strdup_nln(const char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
void	_ft_exit(char **static_buffer);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 69
# endif
#endif
