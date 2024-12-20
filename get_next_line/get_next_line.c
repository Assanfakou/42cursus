#include "get_next_line.h"

// char *handle_read_until_newline(int fd, char **buff)
// {
// 	char *str;
// 	int n_reads;
	
// 	free(*buff);
// 	n_reads = read(fd, str, BUFFER_SIZE + 1);
// }

char *extract_then_update(char **somth)
{
	char *allocated;
	char *new_line_pos;
	char *cache;

	if (!*somth)
		return (NULL);
	new_line_pos = NULL;
	new_line_pos = ft_strchr(*somth, '\n');
	if (new_line_pos)
	{
		allocated = ft_strduptoc(*somth, '\n');
		cache = ft_strduptoc(new_line_pos + 1, '\0');
		free(*somth); 
		*somth = cache;
		return (allocated);
	}
	return (NULL);
}


char *get_next_line(int fd)
{
	ssize_t suit_up;
	static char *stat = NULL;
 	char buffer[BUFFER_SIZE + 1];
	char *str_nline_found;
	//  char *zebi = "fuck off this is a dick";

	if (stat)
	{
		str_nline_found = extract_then_update(&stat);
		if (str_nline_found)
			return (str_nline_found);
	}
	suit_up = read(fd, buffer, (BUFFER_SIZE - 1));
	printf("suit up : (%ld)  ", suit_up);
	// while (suit_up = read(fd, buffer, (BUFFER_SIZE - 1)) > 0)
		if (suit_up > 0)
			buffer[suit_up] = '\0';
	// printf("BUUFR before join: %s\n", buffer);

	stat = ft_strjoin(stat, buffer);
	// printf("stat after join the string /%s/", stat);
	str_nline_found = extract_then_update(&stat);
	if (str_nline_found)
		return (str_nline_found);
	// if read does work 
	// printf("suit up : %ld", suit_up);
	// if (suit_up == 0 && buffer) 
	// {
    // 	str_nline_found = buffer;
    //     stat = NULL; // Clear static buffer
    //     // return (str_nline_found);
	// }
	if (suit_up == -1) { // Error
        free(stat);
        stat = NULL;
        return (NULL);
	}
	return (NULL);
}


// int main ()
// {
// 	int fd = open("lile_is_passed.txt", O_CREAT | O_RDWR , 0777);
// 	write(fd, "1hello[\n]Assan\nsan", 18);
// 	lseek(fd, 0, SEEK_SET);
// 	char *str_to_return = get_next_line(fd);
// 	if (fd != -1)
// 	{	
// 		printf("%s", str_to_return);
// 		 free(str_to_return);
// 	}
// 	else
// 		perror("the ereour is occured");
// 	close(fd);
// 	 printf("%d", fd);
// }

