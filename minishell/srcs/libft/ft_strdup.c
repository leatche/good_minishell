#include "minishell.h"

char	*ft_strdup(const char *src)
{
	int			i;
	char	*new;

	i = 0;
	if (!src)
		return (NULL);
	new = malloc(sizeof(char) * ft_strlen(src) + 1);
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
