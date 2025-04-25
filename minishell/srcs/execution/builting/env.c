#include "minishell.h"

void	ft_env(t_bloc *bloc)
{
	int i;

	i = 0;
	while (bloc->tab_env[i])
	{
		if (ft_strchr(bloc->tab_env[i], '='))
			printf("%s\n", bloc->tab_env[i]);
		i++;
	}
	i = 0;
	while (bloc->secon_env[i])
	{
		if (ft_strchr(bloc->secon_env[i], '='))
			printf("%s\n", bloc->secon_env[i]);
		i++;
	}
}
