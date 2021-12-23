#include<fcntl.h>
#include "get_next_line.h"
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
    static char *rem = NULL;
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
        if(rem)
            rem = ft_strjoin(rem,buff);
        else
            rem = ft_strdup(buff);
        if(gettheline(rem) != -1)
            break ;
    }
    //freeestr(&buff);
    free(buff);
    line = get_line(rem,bytes);
    rem = ft_rem(rem,bytes);
    return (line);
}
int main(void)
{
    char *line;
    int fd;
    fd = open("foo.txt",O_RDONLY);
    line = get_next_line(fd);
    if(line == NULL)
        return ('1');
    while(line)
    {
       printf("%s",line);
       line = get_next_line(fd); 
    }

}