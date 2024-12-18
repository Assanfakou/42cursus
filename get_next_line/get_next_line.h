/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assankou <assankou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:00:50 by hfakou            #+#    #+#             */
/*   Updated: 2024/12/18 19:46:06 by assankou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE

char *ft_strchr(const char *str, char to_find);
size_t ft_strlen(const char *str);
char *ft_strduptoc(const char *str, char c);
char *get_next_line(int fd);
char *ft_strjoin(const char *s1, const char *s2);