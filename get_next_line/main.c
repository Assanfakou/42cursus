#include "get_next_line.h"
#include <stdlib.h>
int main ()
{
	int	fd = open("text.txt", O_RDONLY);

	char *line;
	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	char *line2;
	line2 = get_next_line(fd);
	printf("%s", line2);
	free(line2);

	char *line3;
	line3 = get_next_line(fd);
	printf("%s", line3);
	free(line3);

	char *line4;
	line4= get_next_line(fd);
	printf("%s", line4);

	char *line5;
	line5= get_next_line(fd);
	printf("%s", line5);
	free(line5);

	char *line6;
	line6 =get_next_line(fd);
	printf("%s", line6);
	free(line6);

	char *line7;
	line7=get_next_line(fd);
	printf("%s", line7);
	free(line7);
	char *line8;
	line8=get_next_line(fd);
	printf("%s", line8);
	free(line8);
	close(fd);
}
