#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>


size_t  ft_strlen(const char *s);
char    *ft_strjoin(char const *s1, char const *s2);
char  *get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
void    freeestr(char **str);

#endif