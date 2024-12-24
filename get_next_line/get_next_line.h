/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:00:50 by hfakou            #+#    #+#             */
/*   Updated: 2024/12/24 11:05:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif
char *ft_strchr(char *str, char to_find);
size_t ft_strlen(const char *str);
char *ft_calloc(size_t chunk, size_t size);
// char *ft_strduptoc(const char *str, char c);
char *ft_strdup(const char *);
char *ft_strdup_nln(const char *);
char *get_next_line(int fd);
char *ft_strjoin(const char *s1, const char *s2);