#include "get_next_line.h"

int main()
{
    int fd = open("test_file.txt", O_CREAT | O_RDWR, 0777);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    write(fd, "Hello, world!\nThis is a test file.\nLet's see if get_next_line works!\n", 70);

    char *line = get_next_line(fd);
    //while ((line = get_next_line(fd)) == NULL) {
        printf("Line: %s\n", line); // Print each line
       // free(line);
    // }
    close(fd);

    return 0;
}


