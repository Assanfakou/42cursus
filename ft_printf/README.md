# ft_printf

A custom implementation of the printf function in C. This project is part of the 42 school curriculum, focusing on creating a simplified version of the standard C library's printf function.

## Description

ft_printf is a custom implementation that mimics the behavior of the original printf function. It supports various format specifiers and provides essential string formatting capabilities.

## Features

Supported format specifiers:
- `%c` - Print a single character
- `%s` - Print a string
- `%p` - Print a pointer in hexadecimal format
- `%d` - Print a decimal (base 10) number
- `%i` - Print an integer in base 10
- `%u` - Print an unsigned decimal number
- `%x` - Print a number in hexadecimal (base 16) lowercase format
- `%X` - Print a number in hexadecimal (base 16) uppercase format
- `%%` - Print a percent sign

## Usage

### Compilation

```bash
make        # Compile the library
make clean  # Remove object files
make fclean # Remove object files and library
make re     # Recompile the library
```

### Example Usage

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "world");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hexadecimal: %x\n", 255);
    return (0);
}
```

### Compilation with Your Program

```bash
gcc your_program.c libftprintf.a -o program
```

## Function Prototypes

```c
int ft_printf(const char *firspar, ...);
```

Returns: The number of characters printed (excluding the null byte used to end output to strings)

## Implementation Details

- Uses variadic functions to handle variable arguments
- Implements custom number conversion functions
- No use of global variables
- Follows 42 school's norm
