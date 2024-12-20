#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd); // Ensure your get_next_line function is properly declared

int main() {
    // Open the test file
    int fd = open("test_file.txt", O_CREAT | O_RDWR, 0777); // Make sure "test_file.txt" exists
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    write(fd, "Hello, world!\nThis is a test file.\nLet's see if get_next_line works!\n", 70);

    // Read lines using get_next_line
    char *line = get_next_line(fd);
    //while ((line = get_next_line(fd)) == NULL) {
        printf("Line: %s\n", line); // Print each line
       // free(line); // Free the memory returned by get_next_line
    //}
    

    // Close the file descriptor
    close(fd);

    return 0;
}


