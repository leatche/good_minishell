/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:28:47 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/04/28 23:32:54 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(int ac, char **av, t_bloc *bloc)
{
	// Export peut avoir plusieurs arguments
	(void)ac;
	ft_export_many(av, bloc);
	ft_export_simple(bloc);
}

void	ft_export_simple(t_bloc *bloc)
{
	int		i;
	char	**env;

	i = 0;
	env = ft_cpy_tab(bloc->tab_env);
	env = ft_sorting_env(env);
	while (env[i])
	{
		printf("%s\n", env[i]);
		free(env[i]);
		i++;
	}
	free(env);
}

void	ft_export_many(char **av, t_bloc *bloc)
{
	char	*str;
	char	**tmp;
	int		b;

	if (ft_check_start(av[1]) == -1) // !ft_check_start(av[1])
		return ;
	printf("Arg: %s\n", av[1]);
	b = ft_whitch(av[1], bloc);
	if (b == 22) // if (ENV_APPEND_VARIABLE)
	{
		printf("Append to a variable\n");
		str = ft_rest(av[1], bloc->tab_env[bloc->index]);
		ft_append(bloc, bloc->index, str);
	}
	else if (b == 2) // else if (ENV_REPLACE_VARIABLE)
	{
		printf("Replace a variable\n");
		ft_replace_all(bloc, bloc->index, av[1]);
	}
	else // else if (ENV_NEW_VARIABLE)      < if pas obligatoire, mais aide à faire comprendre pourquoi on est entré dans ce else
	{
		printf("Create a variable\n");
		tmp = add_to_env(bloc->tab_env, av[1]);
		bloc->tab_env = tmp;
	}
}

int	ft_whitch(char *av, t_bloc *bloc)
{
	int		sign;

	sign = ft_plus(av);
	bloc->var = ft_pars_add(av);
	bloc->index = ft_search(bloc->tab_env, bloc->var);
	free(bloc->var);
	if (bloc->index != -1 && sign == 1)
		return (22); // Pas possible ça. # define ENV_APPEND_VARIABLE 2
	else if (bloc->index != -1 && sign != 1)
		return (2); // # define ENV_REPLACE_VARIABLE 1
	return (1); // # define ENV_NEW_VARIABLE 0
}
