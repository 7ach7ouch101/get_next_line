This project is about programming a function that returns a line
read from a file descriptor.

Mandatory Part:

Function Name->: get_next_line.

Prototype->: char *get_next_line(int fd).

Parameters: fd - The file descriptor to read from.

Return value->: Read line: correct behavior. (NULL)= There is nothing else to read, or an error occurred.

External functions->: read, malloc, free.

Description->: Implement a function that reads a line from a file descriptor (fd). 
Repeated calls to get_next_line() should read the text file pointed to by the file descriptor one line at a time.
The function should return the line that was read. If there is nothing else to read or if an error occurs, it should return NULL.
The returned line should include the terminating \n character, except if the end of the file is reached and does not end with a \n character.
The header file get_next_line.h must contain at least the prototype of the get_next_line() function.
Helper functions should be added to the get_next_line_utils.c file.

Additional Requirements->:
The BUFFER_SIZE macro should be defined to specify the buffer size for the read() function.
The code should be compiled with the option -D BUFFER_SIZE=n, where n is the buffer size value.
The code should be able to compile with and without the -D BUFFER_SIZE flag.
The function should still work with different BUFFER_SIZE values.
The function should not read the whole file at once but read as little as possible each time get_next_line() is called.

Bonus Part->:
Implement get_next_line() using only one static variable.
The function should be able to manage multiple file descriptors at the same time.
The bonus files should have the suffix _bonus.c and _bonus.h.
The bonus part will only be evaluated if the mandatory part is perfect.
That summarizes the requirements for the get_next_line function and its related files, both for the mandatory part and the bonus part (if attempted).
