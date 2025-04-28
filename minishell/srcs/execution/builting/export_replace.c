/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:34:19 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/04/28 22:49:13 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_replace_all(t_bloc *bloc, int a, char *var)
{
	free (bloc->tab_env[a]);
	bloc->tab_env[a] = ft_strdup(var);
}

void	ft_append(t_bloc *bloc, int a, char *var)
{
	char	*tmp;

	tmp = ft_strjoin(bloc->tab_env[a], var);
	free (bloc->tab_env[a]);
	free (var);
	bloc->tab_env[a] = tmp;
}
