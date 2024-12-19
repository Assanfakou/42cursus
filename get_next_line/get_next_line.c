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
		//   printf("Extracted line: %s\n", allocated);
		cache = ft_strduptoc(new_line_pos + 1, '\0');
		// printf("Remaining somth (cache): %s\n", cache);
		free(*somth); 
		*somth = cache;
		return (allocated);
	}
	// char *new_line_pos = ft_strchr(*buffer, '\n');
    //  if (new_line_pos) {
    // printf("Newline found at position: %ld\n", new_line_pos - *buffer);
    // char *allocated = ft_strduptoc(*buffer, '\n');
    // printf("Extracted line: %s\n", allocated);
    // char *cache = ft_strduptoc(new_line_pos + 1, '\0');
    // printf("Remaining buffer (cache): %s\n", cache);
    // free(*buffer);
    // *buffer = cache;
	
}


char *get_next_line(int fd)
{
	ssize_t suit_up;
	static char *stat;
 	char buffer[BUFFER_SIZE + 1];
	char *str_nline_found;

	stat = NULL;
	if (stat)
	{
		str_nline_found = extract_then_update(&stat);
		if (str_nline_found)
			return (str_nline_found);
	}
	suit_up = read(fd, buffer, (BUFFER_SIZE - 1));
	//printf("Bytes read: %ld\n", suit_up);
	//printf("Buffer content: %s\n", buffer);
	while (suit_up = read(fd, buffer, (BUFFER_SIZE - 1)) > 0)
		buffer[suit_up] = 0;
	stat = ft_strjoin(stat, buffer);
	//printf("buffer after strjoin : %s", buffer);
	str_nline_found = extract_then_update(&stat);
	if (str_nline_found)
	 	return (str_nline_found);
	// if (suit_up == 0 && buffer) 
	// {
    // 	str_nline_found = buffer;
    //     stat = NULL; // Clear static buffer
    //     return (str_nline_found);
	// }
	// if (suit_up == -1) { // Error
    //     free(stat);
    //     stat = NULL;
    //     return (NULL);
	// }
	return (NULL);
}


int main ()
{
	int fd = open("lile_is_passed.txt", O_CREAT | O_RDWR , 0777);
	write(fd, "1hello[\n]heallo", 15);
	lseek(fd, 0, SEEK_SET);
	char *str_to_return = get_next_line(fd);
	if (fd != -1)
	{
		printf("%s", str_to_return);
		free(str_to_return);
	}
	else
		perror("the ereour is occured");
	close(fd);
	// printf("%d", fd);
}

