/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:45:17 by assankou          #+#    #+#             */
/*   Updated: 2024/12/28 13:06:32 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <stdio.h>
// int main ()
// {
// 	int	fd = open("text.txt", O_RDONLY);

// 	char *line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);

// 	}

// 	close(fd);
// }
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(2000);
	printf("%s", line);
	free(line);
	line = get_next_line(1025);
	printf("%s", line);
	free(line);
	// line = get_next_line(fd);
	//  printf("%s", line);
	// free(line);
	close(fd);
	return (0);
}
