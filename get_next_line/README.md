# Get Next Line (GNL)

Read text line by line from any file descriptor.

## Overview
- Reads lines from files or standard input
- Returns each line including the newline character
- Memory-safe implementation
- Configurable buffer size
- No external dependencies

## Usage
```c
char *line = get_next_line(fd);
```

## Build
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=<size> *.c
```

## Files
- `get_next_line.c`
- `get_next_line.h`
- `get_next_line_utils.c`

## Bonus Implementation
- `*_bonus.c/h`: Handles multiple file descriptors
- Uses single static variable

## Requirements
- No global variables
- No libft
- No lseek()
- Must free all allocated memory
- Must handle various buffer sizes
