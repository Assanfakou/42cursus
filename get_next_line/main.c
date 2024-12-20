#include "get_next_line.h"
#include <stdlib.h>
int main ()
{
	int	fd = open("text.txt", O_RDONLY);

	char *line;
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
	char *line2;
	line2 = get_next_line(fd);
	printf("%s", line2);
	free(line2);
	close(fd);
	char *line3;
	line3 = get_next_line(fd);
	printf("%s", line3);
	free(line3);
	close(fd);
}
