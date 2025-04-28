/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:34:19 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/04/28 11:34:31 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_replace_all(t_bloc *bloc, int a, char *var)
{
	free (bloc->tab_env[a]);
	bloc->tab_env[a] = malloc(sizeof(char *) * (ft_strlen(var) + 1));
	bloc->tab_env[a] = ft_strdup(var);
	bloc->tab_env[a][ft_strlen(bloc->tab_env[a]) + 1] = '\0';
}

void	ft_replace(t_bloc *bloc, int a, char *var)
{
	int		i;
	int		l;
	char	*tmp;

	i = 0;
	l = 0;
	tmp = malloc(sizeof(char *) * (ft_strlen(var) + 1));
	while (bloc->tab_env[a][i])
	{
		tmp[l++] = bloc->tab_env[a][i];
		i++;
		if (bloc->tab_env[a][i + 1] == '"')
			i++;
	}
	free (bloc->tab_env[a]);
	bloc->tab_env[a] = malloc(sizeof(char *)
			* (ft_strlen(var) + ft_strlen(tmp) + 1));
	bloc->tab_env[a] = ft_strjoin(tmp, var);
	bloc->tab_env[a][ft_strlen(bloc->tab_env[a]) + 1] = '\0';
	free (tmp);
}
