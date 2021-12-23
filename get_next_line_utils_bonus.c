#include "get_next_line_bonus.h"


void    freeestr(char **str)
{
    free(*str);
    *str = NULL;
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if(!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
static	char	*merge(char const *s1, char const *s2, char *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		a;
	int		b;

	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	p = malloc((a + b) + 1);
	if (!p)
		return (NULL);
	p = merge(s1, s2, p);
	freeestr((char **)&s1);
	return (p);
}
char	*ft_strdup(const char *s1)
{
	size_t	a;
	size_t	i;
	char	*p;

	i = 0;
	a = ft_strlen(s1);
	p = malloc((a + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (i < a)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}