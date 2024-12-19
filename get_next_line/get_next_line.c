/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assankou <assankou@student.4buffer.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: buffer0buffer4/1buffer/16 15:08:15 by hfakou            #+#    #+#             */
/*   Updated: buffer0buffer4/1buffer/18 19:14:40 by assankou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char *handle_read_until_newline(int fd, char **buff)
// {
// 	char *str;
// 	int n_reads;
	
// 	free(*buff);
// 	n_reads = read(fd, str, BUFFER_SIZE + 1);
// }

char *extract_then_update(char **temp)
{
	char *allocated;
	char *new_line_pos;
	char *cache;

	if (!*temp)
		return (NULL);
	new_line_pos = ft_strchr(*temp, '\n');
	if (new_line_pos)
	{
		allocated = ft_strduptoc(*temp, '\n');
		cache = ft_strduptoc(new_line_pos + 1, '\0');
		free(*temp); 
		*temp = cache;
		return (allocated);
	}
	return (NULL);
}

char *get_next_line(int fd)
{
	ssize_t suit_up;
	char *buffer;
	static char temp[BUFFER_SIZE + 1];
	char *str_nline_found;

	buffer = NULL;
	str_nline_found = extract_then_update(&buffer);
	if (str_nline_found)
		return (str_nline_found);
	suit_up = read(fd, temp, (BUFFER_SIZE - 1));
	while (suit_up = read(fd, temp, (BUFFER_SIZE - 1)) > 0)
		temp[suit_up] = 0;
	buffer = ft_strjoin(buffer, temp);
	str_nline_found = extract_then_update(&buffer);
	if (str_nline_found)
		return (str_nline_found);
	
	return (NULL);
}


int main ()
{
	int fd = open("lile_is_passed.txt", O_CREAT | O_RDWR , 0777);
	write(fd, "1hello[\n]", 9);
	lseek(fd, 0, SEEK_SET);
	char *str_to_return = get_next_line(fd);
	if (str_to_return)
	{
		printf("%s", str_to_return);
		free(str_to_return);
	}
	else
		perror("the ereour is occured");
	close(fd);
	// printf("%d", fd);
}

