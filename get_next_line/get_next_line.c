/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:08:15 by hfakou            #+#    #+#             */
/*   Updated: 2024/12/17 17:33:35 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *handle_read_until_newline(int fd, char **buff)
{
	char *str;
	int n_reads;
	
	free(*buff);
	n_reads = read(fd, str, BUFFER_SIZE + 1);
}

char *extract_then_update(char **buffer)
{
	char *allocated;
	char *new_line_pos;
	char *cache;

	if (!*buffer)
		return (NULL);
	new_line_pos = ft_strchr(*buffer, '\n');
	if (new_line_pos)
	{
		allocated = ft_strduptoc(*buffer, '\n');
		cache = ft_strduptoc(new_line_pos + 1, '\0');
		free(*buffer);
		*buffer = cache;
		return (allocated);
	}
	return (NULL);
}

char *get_next_line(int fd)
{
	int suit_up;
	static char buffer[1030];
	char *str_nline_found;

	suit_up = read(fd, buffer, (BUFFER_SIZE - 1));
	buffer[suit_up] = 0;	
}


// int main ()
// {
// 	printf("%p", ft_strchr("he\0llo", '\0', 5));
// }
// int main ()
// {
// 	int fd = open("lile_is_passed.txt", O_CREAT | O_RDWR , 0777);
// 	write(fd, "hello", 5);
// 	lseek(fd, 0, SEEK_SET);
// 	func(fd);
// 	close(fd);
// }

