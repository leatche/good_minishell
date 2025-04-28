/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:53:41 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/04/28 11:46:57 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_bloc *bloc)
{
	int	i;

	i = 0;
	while (bloc->tab_env[i])
	{
		if (ft_strchr(bloc->tab_env[i], '='))
			printf("%s\n", bloc->tab_env[i]);
		i++;
	}
}
