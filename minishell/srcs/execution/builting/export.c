/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:28:47 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/04/28 11:51:48 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(int ac, char **av, t_bloc *bloc)
{
	(void)ac;
	ft_export_many(av, bloc);
	ft_export_simple(bloc);
}

void	ft_export_simple(t_bloc *bloc)
{
	int		i;
	char	**env;

	i = 0;
	env = ft_cpy_tab(bloc);
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
	int		i;
	char	*str;
	char	**tmp;
	int		b;

	if (ft_check_start(av[1]) == -1)
		return ;
	b = ft_whitch(av[1], bloc);
	if (b == 22)
	{
		str = ft_rest(av[1], bloc->tab_env[bloc->index]);
		ft_replace(bloc, bloc->index, bloc->var);
		free (str);
	}
	else if (b == 2)
		ft_replace_all(bloc, bloc->index, av[1]);
	else
	{
		i = ft_nb_lines_env(bloc->tab_env) + 1;
		tmp = add_to_env(bloc->tab_env, av[1], i);
		bloc->tab_env = tmp;
	}
	free (bloc->var);
}

int	ft_whitch(char *av, t_bloc *bloc)
{
	int		sign;

	sign = ft_plus(av);
	bloc->var = ft_pars_add(av);
	bloc->index = ft_search(bloc->tab_env, bloc->var);
	if (bloc->index != -1 && sign == 1)
		return (22);
	else if (bloc->index != -1 && sign != 1)
		return (2);
	else
		return (1);
}
