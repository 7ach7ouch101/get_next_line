#include "get_next_line_bonus.h"
void    *ft_memcpy(void *dst, const void *src, size_t n)
{
        const char      *s;
        char            *d;

        d = dst;
        s = src;
        if (!src && !dst)
                return (NULL);
        while (n--)
        {
                *d = *s;
                d++;
                s++;
        }
        return (dst);
}
int gettheline(char *str)
{
    int i;

    i = 0;
    if(!str)
        return (-1);
    while(str[i] != '\n' && str[i] != '\0')
        i++;
    if(str[i] == '\n')
        return i;
    return -1;
}
char *get_line(char *rem,int bytes)
{
    char *line;
    int i;

    i = gettheline(rem);
    if(i >= 0)
    {
        line = malloc(i + 2);
        ft_memcpy(line,rem,i);
        line[i] = '\n';
        line[i + 1] = '\0';
        return(line);
    }
    else if(bytes == 0 && *rem != '\0')
    {
        line = ft_strdup(rem);
        return (line);
    }
    else
        return (NULL);
}
char *ft_rem(char *rem,int bytes)
{
    char *tmp;
    int i;

    i = gettheline(rem);
    if(i >= 0)
    {
        tmp = ft_strdup(rem + i + 1);
        free(rem);
        rem = tmp;
    }
    else if(bytes == 0)
    {
        freeestr(&rem);
        return (NULL);
    }
    return (rem);
}
char  *get_next_line(int fd)
{
    char *buff;
    int bytes;
    static char *rem[256];
    char *line;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    bytes = 1;
    buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if(!buff)
        return (NULL);
    while(bytes)
    {
        bytes = read(fd,buff,BUFFER_SIZE);
        if(bytes == -1)
            return(free(buff),NULL);
        buff[bytes] = '\0';
        if(rem[fd])
            rem[fd] = ft_strjoin(rem[fd],buff);
        else
            rem[fd] = ft_strdup(buff);
        if(gettheline(rem[fd]) != -1)
            break ;
    }
    freeestr(&buff);
    line = get_line(rem[fd],bytes);
    rem[fd] = ft_rem(rem[fd],bytes);
    return (line);
}
#include <stdio.h>
int main()
{
    int fd[4];
    fd[0] = open("get_next_line.c", O_RDWR);
    fd[1] = open("get_next_line_utils.c", O_RDWR);
    fd[2] = open("get_next_line_bonus.c", O_RDWR);
    fd[3] = open("get_next_line.h", O_RDWR);
    char *line;
    int i = 0;
    while(i < 4)
    {
        line = get_next_line(fd[i]);
        while(line)
        {
            printf("%s",line);
            free(line);
            line = get_next_line(fd[i]);
        }
        i++;
    }
}