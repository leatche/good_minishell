/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:00:01 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/04/28 12:34:52 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		
	}
}
void	ft_unset(int ac, char **av, t_bloc *bloc)
{
	if (ac == 1)
		bloc->erreur = 0;
	else if (ac == 2)
		ft_unset_exe(av, bloc);
		//erreur = 0;
}

void	ft_unset_exe(char **av, t_bloc *bloc)
{
	int		i;
	char	*var;

	if (ft_check_start(av[1]))
	{
		i = ft_search(bloc->tab_env, av[1]);
		if (i != -1)
			bloc->tab_env = ft_delete_var(i, bloc);
		else
			return (0);
	}
	else
		return (0);
}

char	**ft_delete_var(int index, t_bloc *bloc)
{
	int		i;
	int		k;
	char	**tmp;

	i = 0;
	k = 0;
	tmp = malloc(sizeof (char *) * (ft_nb_lines_env(bloc->tab_env) - 1));
	while (bloc->tab_env[i])
	{
		if (index == i)
			i++;
		tmp[k++] = bloc->tab_env[i];
		i++;
	}
	tmp[k] = NULL;
	return (tmp);
}
