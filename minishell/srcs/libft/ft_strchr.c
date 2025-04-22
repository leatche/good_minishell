#include "minishell.h"

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	if (!s)
// 		return (NULL);
// 	i = ft_strlen(s) + 1;
// 	while (--i >= 0)
// 		if (s[i] == (char)c)
// 			return ((char *)(s + i));
// 	return (NULL);
// }
char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if (c == '\0')
        return ((char *)s);
    return (NULL);
}