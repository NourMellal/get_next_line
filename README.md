
# Get Next Line Project

## Overview
Get Next Line is a C programming project focused on developing a function that reads a line from a file descriptor. The goal is to handle reading lines from a file, whether they are of variable lengths, and to do so in an efficient and memory-safe manner.

## Features
- Read lines of variable length from a file descriptor.
- Efficient memory management to handle different line lengths.
- Utilize a static variable to manage buffer between function calls.
- Handle different file descriptors simultaneously.

## Usage
To use the `get_next_line` function in your project:
1. Include the `get_next_line.h` header file in your C source file.
2. Call the `get_next_line` function with a valid file descriptor.

Example:
```c
int fd = open("example_file.txt", O_RDONLY);
char *line = get_next_line(fd);
```

## Compilation
Compile your program with the `get_next_line` files. For example:
```bash
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=32 main.c get_next_line.c get_next_line_utils.c
```

## Dependencies
- GCC compiler
- Standard C libraries

## Project Structure
- `get_next_line.c`: Contains the main logic for reading lines.
- `get_next_line_utils.c`: Helper functions used by `get_next_line`.
- `get_next_line.h`: Header file with function prototypes.

## Author
- [nmellal]

## Acknowledgements
This project is part of the [42 School](https://www.42.fr/) coding curriculum.

## License
This project is licensed under the [MIT License](LICENSE).
