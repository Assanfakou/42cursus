/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:00:50 by hfakou            #+#    #+#             */
/*   Updated: 2024/12/26 17:54:22 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strchr(char *str, char to_find);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_strdup_nln(const char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
#endif
